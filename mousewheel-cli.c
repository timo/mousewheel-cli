#include <X11/extensions/XTest.h>
#include <X11/Xlib.h>
#include <X11/X.h>

#include <stdio.h>

int main(int argc, char **argv)
{
  if(argc == 1) {
    fprintf(stderr, "Usage: %s u/d", argv[0]); return 1; }

  if(argv[1][0] != 'u' && argv[1][0] != 'd') {
    fprintf(stderr, "Usage: %s u/d", argv[0]); return 1; } 

  Display * dpy = XOpenDisplay(NULL);
  if(!dpy) {
    fprintf(stderr, "Could not open X display :("); return 1; }

  int _;
  if(!XQueryExtension(dpy, "XTEST", &_, &_, &_)) {
    fprintf(stderr, "XTEST extension is not supported by X server, enable it in your X server configuration."); return 1; }

  if(argv[1][0] != 'u')
    XTestFakeButtonEvent(dpy, 4, True, 0);
  else
    XTestFakeButtonEvent(dpy, 5, True, 0);
  return 0;
}
