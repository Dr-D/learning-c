# basic varargs

Functions like printf allow a string value to be passed with any number of following arguments.

```c
int printf(const char *format, ...);
```

This is indicated by the elipses or `...` shown as the second argument.

The code example calculates a factorial from a list of integer values.

```
man va_start
```
Shows the macros in stdarg.h used for varargs.

Of note the varargs must be the last parameter of the method. It must follow a non-varargs parameter. Each va_start requires a va_end.

The type of each vargs element in the list must be known, as this is the only way to find where the next element can be found. This is the way printf works as each varargs value must correspond to a placeholder in the string provided.

See also `man vprintf`that takes a va_list parameter.
