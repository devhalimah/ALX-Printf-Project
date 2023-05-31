#ifndef printf_h
#define printf_h
int _printf(const char *format, ...);
void p_s(va_list vl, const char *text, int size);
void p_c(va_list vl, const char *text, int size);
void p_d(va_list vl, const char *text, int size);
void p_u(va_list v1, const char *text, int size);
int _putchar(char c);
void print_number(int num, int print_negative_sign);
void print_unsigned_number(unsigned int num);
int digit_length(int num, int include_sign);
void _reset(int *is_formatted, int *size);
int _print_format(va_list vl, const char *format, int index, int *size);
#endif
