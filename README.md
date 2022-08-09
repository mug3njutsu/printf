# Recreation of the stdio library function -> Printf
![Printf-meme-you-can-never-be-too-serious](https://pics.me.me/developers-gdb-ide-100s-of-printf-statements-printf-s-i-n-pretty-function-line-38789494.png)

> ## Swiss Army Knife
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
For `x` conversions, `0x` is prepended for non-zero numbers, ergo, making them hex values.
For `X` conversions, `0X` is prepended for non-zero numbers, ergo, making them hex values.

- Example:
```C
int main(void)
{
	_printf("%x\n", 1337);
}
```
```bash
➜  printf git:(main) ✗ ./example 
539
```

`(space) || (" ")`
* A blank is left before a positive number or empty string produced by a signed conversion.

- Example:
```C
int main(void)
{
	_printf("% d\n", 1337);
}
```
```bash
➜  printf git:(main) ✗ ./example 
 1337
```

`+`
* An addition sign is always placed before a number produced by signed conversion.

- Example:
```C
int main(void)
{
    _printf("%+d\n", 1337);
}
```
```bash
➜  printf git:(main) ✗ ./example 
+1337
```

`0`
* For `d`,`i`,`o`,`u`,`x` and `X` conversions, the converted value is padded on the left with zeroes rather than blanks.
If the `0` flag is provided to a numeric conversion with a specified precision, it is ignored.

- Example:
```C
int main(void)
{
    _printf("%05d\n", 1337);
}
```
```bash
➜  printf git:(main) ✗ ./example 
01337
```

`-`
* The converted value is left-justified, which means it's padded on the right with blanks instead of on the left with blanks or zeroes.

- Example:
```C
int main(void)
{
    _printf("%-5d1337\n", 1337);
}
```
```bash
➜  printf git:(main) ✗ ./example 
1337 1337
```

> #### Field Width
* After flags, a minimum field with may be specified by a decimal digit string. The first digit must be a non-zero value. If the converted value has fewer characters than the provided width, the output is padded on the left or right with spaces, then again depending on whether the `-` flag was provided.

- Example:
```C
int main(void)
{
    _printf("%7d\n", 1337);
}
```
```bash
➜  printf git:(main) ✗ ./example 
   1337
```

> #### Precision
* After any flags or provided width, a precision may be specified by a `.` followed by a decimal digit string. For `d`,`i`,`o`,`u`,`x` and `X` conversions, the precision specifies the number of digits to appear. For `s` and `S` conversions, the precision specifies the maximum characters to be printed.

- Example:
```C
int main(void)
{
    _printf("%.7d\n", 1337);
}
```
```bash
➜  printf git:(main) ✗ ./example 
0001337
```
* Alternatively, precision may be provided as an argument using the `*` character after the `.`.

> #### Length Modifiers
* After flags, width, and precision and before a conversion specifier, one of the following length modifiers may be provided:

`h`
* Specifies that an integer conversion corresponds to a `short int` or `unsigned short int` argument.

- Example:
```C
int main(void)
{
    _printf("%hd\n", SHRT_MAX);
}
```
```bash
➜  printf git:(main) ✗ ./example 
32767
```

`L`
* Specifies that an integer conversion corresponds to a `long int` or `unsigned long int` argument.

- Example:
```C
int main(void)
{
    _printf("%ld\n", LONG_MAX);
}
```
```bash
➜  printf git:(main) ✗ ./example 
9223372036854775807
```

> #### Conversion Specifiers
* The conversion specifier, introduced by `%` is a character that specifies the type of conversion to be applied. The `_printf` function supports the following conversion specifiers.

`d, i`
* The `int` argument is converted is signed decimal notation.

- Example:
```C
int main(void)
{
    _printf("%d\n", 1337);
}
```
```bash
➜  printf git:(main) ✗ ./example 
1337
```

`o, u, x, X`
* The `unsigned int` argument is converted to unsigned octal, unsigned decimal, or unsigned hexadecimal.

- Example:
```C
int main(void)
{
    _printf("%o\n", 1337);
}
```
```bash
➜  printf git:(main) ✗ ./example 
2471
```

`c`
* The `int` argument is converted to an `unsigned char`.

- Example:
```python
>>> chr(65)
'A'
```
```C
int main(void)
{
    _printf("%c\n", 65);
}
```
```bash
➜  printf git:(main) ✗ ./example 
A
```

`s`
* The `const char *` argument is expected to be a pointer to a character array. Characters from the array, `char s[]`, are written starting from the  first element of the array and terminated with the null byte.

- Example:
```C
int main(void)
{
    _printf("%s\n", "Clean code!");
}
```
```bash
➜  printf git:(main) ✗ ./example 
Clean code!
```

`p`
* The address of the argument is written, in hexadecimal.

- Example:
```C
int main(void)
{
    char *str = "Clean code!";
    _printf("%p\n", (void *)str);
}
```
```bash
➜  printf git:(main) ✗ ./example 
0x562a30796004
```
