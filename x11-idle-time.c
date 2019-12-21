/*
 * Adapted from https://metacpan.org/release/X11-IdleTime/source/IdleTime.pm
 */

#include <stdio.h>
#include <stdlib.h>
#include <X11/extensions/scrnsaver.h>

int main () {
  Display *display;
  XScreenSaverInfo *info;
  int event, error, screen;
  unsigned long idle_time;

  display = XOpenDisplay(NULL);

  if(display == NULL) {
    printf("Can't open display\n");
    return EXIT_FAILURE;
  }

  if(!XScreenSaverQueryExtension(display, &event, &error)) {
    printf("XScreenSaver extension not available\n");
    return EXIT_FAILURE;
  }

  screen = DefaultScreen(display);
  info = XScreenSaverAllocInfo();

  XScreenSaverQueryInfo(display, RootWindow(display, screen), info);
  idle_time = info->idle / 1000;

  XFree(info);
  XCloseDisplay(display);

  printf("%lu\n", idle_time);
  return EXIT_SUCCESS;
}
