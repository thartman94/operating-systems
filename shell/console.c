# include "../include/console.h"

unsigned int vga_position = 0;
unsigned int terminal_font_color = GRAY;

void set_terminal_font_color(Color color) {
		terminal_font_color = color;
}

void shift_terminal_up(){
	unsigned int i;
  for (i = VGA_WIDTH * 2; i < VGA_WIDTH * 2 * VGA_HEIGHT; i++) {
		VGA_MEMORY[i - VGA_WIDTH * 2] = VGA_MEMORY[i];
		VGA_MEMORY[i] = 0;
	}
}

void print_character(char c) {
		VGA_MEMORY[vga_position] = c;
		VGA_MEMORY[vga_position + 1] = terminal_font_color;
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
	unsigned int line_return = 1;

	if (line_no >= VGA_HEIGHT - 1) {
		shift_terminal_up();
		line_return = 0;
	}
	vga_position = (line_no + line_return) * (VGA_WIDTH * 2);
}

void print_character_with_color(char c, Color clr) {
	set_terminal_font_color(clr);
	print_character(c);
}

void print_string_with_color(char* str, Color clr) {
	set_terminal_font_color(clr);
	print_string(str);
}

void print_line_with_color(char* str, Color clr) {
	set_terminal_font_color(clr);
	print_line(str);
}


