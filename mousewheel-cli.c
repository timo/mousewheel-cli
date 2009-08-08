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
  if(argc == 1) {
      usage(argv[0]);
  }

  if ((strcmp(argv[1], "u") != 0) && (strcmp(argv[1], "d") != 0)) {
    usage(argv[0]);
  }

  Display * dpy = XOpenDisplay(NULL);
  if(!dpy) {
    fprintf(stderr, "Could not open X display :(\n"); return 1; }

  int _;
  if(!XQueryExtension(dpy, "XTEST", &_, &_, &_)) {
    fprintf(stderr, "XTEST extension is not supported by X server, enable it in your X server configuration.\n"); return 1; }

  if(argv[1][0] == 'u')
  {
    XTestFakeButtonEvent(dpy, 4, True, CurrentTime);
    XTestFakeButtonEvent(dpy, 4, False, CurrentTime);
  } else {
    XTestFakeButtonEvent(dpy, 5, True, CurrentTime);
    XTestFakeButtonEvent(dpy, 5, False, CurrentTime);
  }
  XFlush(dpy);
  return 0;
}
