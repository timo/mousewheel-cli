#include <unistd.h>
#include <X11/extensions/XTest.h>
#include <X11/Xlib.h>
#include <X11/X.h>

#include <stdio.h>

void usage(char *appname)
{
  fprintf(stderr, "Usage: %s u/d", appname);
  _exit(1);
}

int main(int argc, char **argv)
{
  if(argc == 1) {
      usage(argv[0]);
  }

  if(argv[1][0] != 'u' && argv[1][0] != 'd') {
    usage(argv[0]);
  }

  Display * dpy = XOpenDisplay(NULL);
  if(!dpy) {
    fprintf(stderr, "Could not open X display :("); return 1; }

  int _;
  if(!XQueryExtension(dpy, "XTEST", &_, &_, &_)) {
    fprintf(stderr, "XTEST extension is not supported by X server, enable it in your X server configuration."); return 1; }

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
