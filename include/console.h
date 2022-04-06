#ifndef HEADER_FILE
#define HEADER_FILE

extern void print_character(char);
extern void print_string(char*);
extern void print_line(char*);

extern char* const VGA_MEMORY = (char*) 0xb8000;
extern const int VGA_WIDTH = 80;
extern const int VGA_HEIGHT = 25;
extern unsigned int CURS_POS = 0;


#endif
