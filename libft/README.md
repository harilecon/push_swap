*This project has been created as part
of the 42 curriculum by tsitoand.*

# libft



## Description
`Libft` is a foundational C programming project from the 42 school curriculum.
It's build deep understanding of low-level memory management, strings, and data structures without relying on standard libraries.<br>
It's divided on 3 part.
<details>
<summary>libc</summary>

| **name** | **Description** | **return value** |
| --------- | ----------- | ------------ |
| **ft_isalpha** | checks for an alphabetic character | 1 if alphabetic, 0 if test fails|
| **ft_isdigit** | checks for a digit (0 through 9) | 1 if digit, 0 if test fails|
| **ft_isalnum** | checks for an alphanumeric character (equivalent to isalpha \|\| isdigit) | 1 if alphanumeric, 0 if test fails|
| **ft_isascii** | checks whether c is on the ASCII table (0 - 127) | 1 if in ASCII table, 0 if not|
| **ft_isprint** | checks for any printable character including space | 1 if printable, 0 if test fails|
| **ft_strlen** | calculates the length of the string s, excluding the terminating null byte | the number of characters in the string|
| **ft_memset** | fills the first n bytes of the memory area pointed to by s with the constant byte c | a pointer to the memory area s|
| **ft_bzero** | erases the data in the n bytes of the memory starting at s by writing zeros | none|
| **ft_memcpy** | copies n bytes from memory area src to memory area dest | a pointer to dest|
| **ft_memmove** | copies n bytes from src to dest, handling overlapping memory areas | a pointer to dest|
| **ft_strlcpy** | copies src to dst with size safety (NUL-terminates if size > 0) | the total length of the string src|
| **ft_strlcat** | appends src to the end of dst with size safety (NUL-terminates) | the initial length of dst plus the length of src|
| **ft_toupper** | converts a lower-case letter to upper-case | the converted character or c if no conversion was possible|
| **ft_tolower** | converts an upper-case letter to lower-case | the converted character or c if no conversion was possible|
| **ft_strchr** | locates the first occurrence of c in the string s | a pointer to the character or NULL if not found|
| **ft_strrchr** | locates the last occurrence of c in the string s | a pointer to the character or NULL if not found|
| **ft_strncmp** | compares s1 and s2 up to n characters | an integer <, ==, or > 0 based on comparison|
| **ft_memchr** | scans the first n bytes of s for the first instance of c | a pointer to the matching byte or NULL if not found|
| **ft_memcmp** | compares the first n bytes of memory areas s1 and s2 | an integer <, ==, or > 0 based on comparison|
| **ft_strnstr** | locates needle in haystack, searching not more than len characters | a pointer to the first character of the occurrence or NULL|
| **ft_atoi** | converts the initial portion of the string pointed to by str to int representation | the converted integer value|
| **ft_calloc** | allocates memory for count objects of size bytes and zeros it | a pointer to the allocated memory or NULL if allocation fails|
| **ft_strdup** | allocates memory for a copy of s1 and does the copy | a pointer to the duplicated string or NULL if allocation fails|

</details>

Implement a set of functions from the libc

<details>
<summary>Additional functions</summary>

| **name** | **Description** | **return value** |
| --------- | ----------- | ------------ |
|**ft_substr** | Allocates memory (using malloc(3)) and returns a substring from the string ’s’. The substring starts at index ’start’ and has a maximum length of ’len’. | The substring NULL if the allocation fails. |
| **ft_strjoin** | Allocates memory (using malloc(3)) and returns a new string, which is the result of concatenating ’s1’ and ’s2’. |  The new string.<br>NULL if the allocation fails. |
| **ft_strtrim** | Allocates memory (using malloc(3)) and returns a copy of ’s1’ with characters from ’set’ removed from the beginning and the end. | The trimmed string.<br>NULL if the allocation fails. |
| **ft_split** | Allocates memory (using malloc(3)) and returns an array of strings obtained by splitting ’s’ using the character ’c’ as a delimiter. The array must end with a NULL pointer. | The array of new strings resulting from the split.<br>NULL if the allocation fails. |
| **ft_itoa** | Allocates memory (using malloc(3)) and returns a string representing the integer received as an argument. Negative numbers must be handled. | The string representing the integer.<br>NULL if the allocation fails. |
| **ft_strmapi** | Applies the function f to each character of the string s, passing its index as the first argument and the character itself as the second. A new string is created (using malloc(3)) to store the results from the successive applications of f. | s: The string to iterate over<br>f: The function to apply to each character. |
| **ft_striteri** | Applies the function ’f’ to each character of the tring passed as argument, passing its index as he first argument. Each character is passed by ddress to ’f’ so it can be modified if necessary. | s: The string to iterate over .<br>f: The function to apply to each character. |
| **ft_putchar_fd** | Outputs the character ’c’ to the specified file descriptor | none |
| **ft_putstr_fd** | Outputs the string ’s’ to the specified file descriptor | none |
| **ft_putendl_fd** | Outputs the string ’s’ to the specified file descriptor followed by a newline. | none |
| **ft_putnbr_fd** | Outputs the integer ’n’ to the specified file descriptor. | none |

</details>

Develop a set of functions that are either not included in
the libc, or exist in a different form.

<details>
<summary>linked list</summary>

| **name** | **Description** | **return value** |
| --------- | ----------- | ------------ |
| **ft_lstnew** | Allocates memory (using malloc(3)) and returns a new node. The ’content’ member variable is initialized with the given parameter ’content’. The variable ’next’ is initialized to  NULL. | A pointer to the new node |
| **ft_lstadd_front** | Adds the node ’new’ at the beginning of the list. | none |
| **ft_lstsize** | Counts the number of nodes in the list. | none |
| **ft_lstlast** | Returns the last node of the list. | none |
| **ft_lstadd_back** | Adds the node ’new’ at the end of the list. | lst: The address of a pointer to the first node of a list.<br>new: The address of a pointer to the node to be added. |
| **ft_lstdelone** | Takes a node as parameter and frees its content using the function ’del’. Free the node itself but does NOT free the next node | none |
| **ft_lstclear** | Deletes and frees the given node and all its successors, using the function ’del’ and free(3). Finally, set the pointer to the list to NULL. | none |
| **ft_lstiter** | Iterates through the list ’lst’ and applies the function ’f’ to the content of each node. | none |
| **ft_lstmap** | Iterates through the list ’lst’, applies the function ’f’ to each node’s content, and creates a new list resulting of the successive applications of the function ’f’. The ’del’ function is used to delete the content of a node if needed. | The new list.<br>NULL if the allocation fails. |

</details>
Implement functions using a structure to manipulate linked
list.

## Instructions
First, clone the `libft` repository move into It.
```shell
git clone https://github.com/harilecon/vigilant-octo-invention.git libft
cd libft
```
Use the following `make` commands depending on your needs:

```shell
make all      # Compile the libft library
make clean    # Remove object files (.o)
make fclean   # Remove object files and the libft.a library
make re       # Clean everything and recompile (same as fclean + make all)

```
Exemple of use<br>
On the `main.c` add the header `libft.h`

```c
#include "libft.h"

int	main(void)
{
	ft_putstr_fd("hello world", 1);
	return (0);
}
```
Compile with `main.c`
```shell
cc -Wall -Wextra -Werror main.c libft.a -o my_program   #include "libft.h"
```
Then run `my_proram`
```shell
./my_program
```

## Resources
[Libft | Guide](https://42-cursus.gitbook.io/guide/0-rank-00/libft)<br>
[learn-c](https://www.learn-c.org/en/Linked_lists)
<br>
[README](https://docs.github.com/en/get-started/writing-on-github/getting-started-with-writing-and-formatting-on-github/basic-writing-and-formatting-syntax)

This project was developed by referencing the standard **Unix man pages**, which provided the technical specifications required to accurately replicate the behavior of libc functions. Additionally, various technical articles and tutorials on **C memory management** and pointer arithmetic were consulted to ensure the robustness and efficiency of the library's core utilities, including references such as the **Gitbook Guide**.



## Regarding the use of Artificial Intelligence:
Artificial Intelligence was used specifically to help structure and refine the English phrasing of this README in order to ensure clarity and a professional presentation. It also served as a brainstorming tool to identify complex edge cases and to better understand new concepts in functions such as **ft_split**, as well as to suggest refactoring patterns aimed at improving code readability while strictly complying with the **42 School Norm**.
