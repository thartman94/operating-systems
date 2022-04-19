# include "../include/console.h"

unsigned int vga_position = 0;
unsigned int terminal_font_color = GRAY;

void set_terminal_font_color(Color color) {
		terminal_font_color = color;
}

void print_character(char c) {
		VGA_MEMORY[vga_position] = c;
		VGA_MEMORY[vga_position + 1] = 0x07;
		vga_position = vga_position + 2;
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
	const unsigned int line_no = vga_position / (VGA_WIDTH * 2);
	vga_position = (line_no + 1) * (VGA_WIDTH * 2);
}