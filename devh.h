#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xatom.h>
#include <X11/XKBlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <stdio.h>
#include <linux/input.h>

#define FR 1
#define DE 2
#define IT 3
#define ES 4
#define COLEMAK 5
#define DVORAK 6
