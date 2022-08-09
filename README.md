# Recreation of the stdio library function -> Printf
![Printf-meme-you-can-never-be-too-serious](https://pics.me.me/developers-gdb-ide-100s-of-printf-statements-printf-s-i-n-pretty-function-line-38789494.png)

> ### Swiss Army Knife
This project was coded on a `Debian 5.18.5-1kali6 x86_64 GNU/Linux` and compiled with `gcc (Debian 11.3.0-5) 11.3.0.`

> ### Usage
In order to make use of this custom function, make sure to compile the `*.c` files in this repository.

> ### Description
`Printf()` in C takes a formatting string and couple of optional variables as input and outputs strings to console while converting input variables to strings. It has one string argument (str) and rest are variable arguments. Variable arguments are managed by macros like va_start, va_arg and va_end.

It supports varieties of formatting. C is for character, d for decimal integer, f for floating point, x for hexadecimal and s for strings. We match the formatting and pick the argument variable using va_arg(). Argument variable is then converted to string format and appends to the output string.

> #### Prototype
`int _printf(const char *format, ...);`

> #### Return Value
On successful return, `_printf` returns the number of characters printed, otherwise, it returns -1.

> #### Format of an Argument String
The format string argument is a constant character string composed of zero or more directives: ordinary characters which are copied unchanged to the output stream and conversion specifications. Conversion specification is introduced by the character `%` and ends with a conversion specifier. 

> #### Flag Characters
The character `%` may be followed by some of these flags:
For `o` conversions, the first character of the output string is prefixed with `0`.
For `x` conversions, `0x` is prepended for non-zero numbers.
For `x` conversions, `0x` is prepended for non-zero numbers.

- Example:
