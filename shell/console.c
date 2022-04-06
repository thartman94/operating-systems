# include "../include/console.h"

void print_character(char c) {
		VGA_MEMORY[CURS_POS] = c;
		VGA_MEMORY[CURS_POS + 1] = 0x07;
}

void print_string(char* str) {
	unsigned int i = 0;
	
	while (str[i] != '\0') {
		print_character(str[i]); 
		i++;
		CURS_POS = CURS_POS + 2;
	} 
}

void print_line(char* str) {
	print_string(str);
	const line_no = CURS_POS / (VGA_WIDTH * 2);
	CURS_POS = (line_no + 1) * (VGA_WIDTH * 2);
}