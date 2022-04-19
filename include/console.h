#ifndef _CONSOLE_H
#define _CONSOLE_H

typedef enum {
        BLACK = 0,
        BLUE,
        GREEN,
        CYAN,
        RED,
        PURPLE,
        BROWN,
        GRAY,
        DARK_GRAY,
        LIGHT_BLUE,
        LIGHT_GREEN,
        LIGHT_CYAN,
        LIGHT_RED,
        LIGHT_PURPLE,
        YELLOW,
        WHITE
} Color;

static char* const VGA_MEMORY;
static int VGA_WIDTH;
static int VGA_HEIGHT;

void print_character(char);
void print_string(char*);
void print_line(char*);

void set_terminal_font_color(Color);
void print_character_with_color(char, Color);
void print_string_with_color(char*, Color);
void print_line_with_color(char*, Color);
void shift_terminal_up();


#endif
