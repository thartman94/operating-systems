/* static char* const VGA_MEMORY = (char*) 0xb8000;

static const int VGA_WIDTH = 80;
static const int VGA_HEIGHT = 25; */

void kernel_early(void) {
}

int main(void) {
	char* str1 = "HELLO";
	char* str2 = "WORLD";
	char* str3 = "TODAY";

	print_string(str1);
	print_line(str2);
	print_string(str3);

	return 0;
}