# include "../include/console.h"

static char* const VGA_MEMORY = (char*) 0xb8000;
static int VGA_WIDTH = 80;
static int VGA_HEIGHT = 25;
unsigned int current_position = 0;

void print_character(char c) {
		VGA_MEMORY[current_position] = c;
		VGA_MEMORY[current_position + 1] = 0x07;
		current_position = current_position + 2;
}

void print_string(char* str) {
	unsigned int i = 0;
	
	while (str[i] != '\0') {
		print_character(str[i]); 
		i++;
	} 
}

void print_line(char* str) {
	print_string(str);
	const unsigned int line_no = current_position / (VGA_WIDTH * 2);
	current_position = (line_no + 1) * (VGA_WIDTH * 2);
}