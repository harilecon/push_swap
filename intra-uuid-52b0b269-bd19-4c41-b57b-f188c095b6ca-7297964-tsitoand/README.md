*This project has been created as part of the 42 curriculum by tsitoand.*

# ft_printf

## Description
The `ft_printf` project consists of recreating the standard C library function `printf()`.
### protype
`int ft_printf(const char *format, ...);`

### Return value:
The number of characters printed.

### Format Specifiers

| Specifier | Description                             |
| --------- | --------------------------------------- |
| `%c`      | Prints a single character               |
| `%s`      | Prints a string                         |
| `%p`      | Prints a pointer address in hexadecimal |
| `%d`      | Prints a signed decimal integer         |
| `%i`      | Prints a signed integer                 |
| `%u`      | Prints an unsigned decimal integer      |
| `%x`      | Prints a hexadecimal number (lowercase) |
| `%X`      | Prints a hexadecimal number (uppercase) |
| `%%`      | Prints a percent sign                   |


## Instructions
Clone the repos with the command
```shell
git clone git@vogsphere.42antananarivo.mg:vogsphere/intra-uuid-f00f7486-a49b-4084-9d4b-bf73207c8ec9-7242676-tsitoand ft_printf
cd ft_printf
```
Build the library with make
```shell
make all      # Compile the libftprintf.a library
make clean    # Remove object files (.o)
make fclean   # Remove object files and the libftprintf.a library
make re       # Clean everything and recompile (same as fclean + make all)
```
#### Exemple
On your `main.c` file add the libary with `#include "ft_printf.h"`

```c
#include "ft_printf.h"

int	main(void)
{
	ft_printf("welcome to %d Antananarivo\n", 42);
	return (0);
}
```
Then compile your `main.c` with the libary
```c
cc -Wall -Wextra -Werror main.c libftprintf.a
```


## Implementation Details
* **Address Management:** I used long formats for printing addresses to prevent any data loss and ensure full pointer precision across different architectures.
* **Security & Conciseness:** Direct indexing was implemented to handle values securely. This approach reduces boilerplate code while maintaining memory safety.
* **Code Structure & Readability:** While the base-conversion algorithms share a similar logic, I deliberately modularized them into separate functions. This design choice prioritizes readability and eases the debugging/review process over dry code consolidation.

## Resources
[ft_printf guide book](https://42-cursus.gitbook.io/guide/1-rank-01/ft_printf)<br>
[man page](https://koor.fr/C/cstdio/fprintf.wp)<br>
[Les fonctions variadiques en C](https://x0r.fr/blog/31)

### Use of **AI**
This project was developed as part of the `42 curriculum`.
AI tools may have been used for:
* Understanding specific concepts
* Reviewing code
* Improving documentation

However, all code was written, understood, and validated by the author.
