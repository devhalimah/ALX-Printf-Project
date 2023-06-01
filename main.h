#ifndef printf_h
#define printf_h
int _printf(const char *format, ...);
int p_s(va_list vl, const char *text, int size);
int p_c(va_list vl, const char *text, int size);
int p_d(va_list vl, const char *text, int size);
int p_u(va_list v1, const char *text, int size);
int _putchar(char c);
int print_number(int num, int print_negative_sign);
int print_unsigned_number(unsigned int num);
int digit_length(int num, int include_sign);
int is_pad_key(char c);
int is_format_key(const char *c);
void _reset(int *is_formatted, int*);
int _print_prev(const char *format, int*, int*);
int _print_format(va_list vl, const char *format, int index, int*, int*);
int print_pad(int count, const char *c);
int print_sign(int include_sign, int num);
void process_start_index(const char *format, int *i, int*, int*, int*, int*);
void calculate_pad_size(const char *format, int *i, int, int*, int*);
int print_padded_number(int, int, int, int, int);
#endif
