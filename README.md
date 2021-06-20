# Keylogger for macOS

Elementary Keylogger, logs your keystrokes and their time and saves them in a file.
Detects the current username and the current keyboard layout.
I got a couple more ideas, which I'll add in the future.

# Install

1. Compile the Keylogger using Make (just open the terminal, browse to the corresponding folder and type: make)

2. Put the Keylogger Program in /usr/local/bin/

3. To launch it from startup put the plist (contains the infos for launchd) in one of the following directories:
/System/Library/LaunchDaemon
/Library/LaunchDaemon (recommended)
(Admin Password needed)

4. Restart and the Keylogger will start recording your keystrokes and log them all in /var/log/kv5a.log

Note: You can also launch the Keylogger from the terminal yourself instead but you have to use sudo.

# Disclaimer

This Keylogger is for educational purposes only.

# TODO: Short Explanation

macOS uses the Mach Kernel or is partly build on it at least.
Therefore it uses the Mach ports, they are the native communication channels for the macOS Kernel.

...
