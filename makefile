keylogger: keylogger.c keycodeToString.c
	gcc -Wall -o keylogger keylogger.c keycodeToString.c -I keylogger.h -framework ApplicationServices
