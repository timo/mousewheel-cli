#include <string.h>
#include <unistd.h>
#include <X11/extensions/XTest.h>
#include <X11/Xlib.h>
#include <X11/X.h>

#include <stdio.h>

void usage(char *appname)
{
    fprintf(stderr, "Usage: %s u/d\n", appname);
    _exit(1);
}

int main(int argc, char **argv)
{
    if (argc == 1) {
        usage(argv[0]);
    }

    char *command = argv[1];
    if ((strcmp(command, "u") != 0) && (strcmp(command, "d") != 0)) {
        usage(argv[0]);
    }

    Display *dpy = XOpenDisplay(NULL);
    if (!dpy) {
        fputs("Could not open X display :(\n", stderr);
        return 1;
    }

    int _;
    if (!XQueryExtension(dpy, "XTEST", &_, &_, &_)) {
        fputs("XTEST extension is not supported by X server, ", stderr);
        fputs("enable it in your X server configuration.\n", stderr);
        return 1;
    }

    if (command[0] == 'u') {
        XTestFakeButtonEvent(dpy, 4, True, CurrentTime);
        XTestFakeButtonEvent(dpy, 4, False, CurrentTime);
    }
    else {
        XTestFakeButtonEvent(dpy, 5, True, CurrentTime);
        XTestFakeButtonEvent(dpy, 5, False, CurrentTime);
    }

    XFlush(dpy);

    return 0;
}
