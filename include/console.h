#ifndef _CONSOLE_H
#define _CONSOLE_H

static char* const VGA_MEMORY;
static int VGA_WIDTH;
static int VGA_HEIGHT;

void print_character(char);
void print_string(char*);
void print_line(char*);

extern unsigned int current_position;


#endif
