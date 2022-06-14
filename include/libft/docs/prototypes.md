---
layout: default
tittle: Libft Prototypes
---

# Libft Documentation

### ft_atoi

Parse a full number string into a number.

```c
int ft_atoi(const char *str);
```

### ft_bzero

Writes n zeroed bytes to string s. If n is zero, does nothing.

```c
void  ft_bzero(void *s, size_t n);
```

### ft_calloc

Allocate memory for count objects. Returns a pointer to the allocated memory filled with 
bytes of value zero.

```c
void  *ft_calloc(size_t count, size_t size);
```

### ft_digits_base

Return number of digits of a number n with base format base.

```c
int ft_digits_base(unsigned long  n, int  base);
```

### ft_digits

Return number of digits of n.

```c
int ft_digits(int n);
```

### ft_isalnum(int c)

Return 1 if character c is alphanumeric else 0.

```c
int ft_isalnum(int c);
```

### ft_isalpha

Return 1 if character c is alphabetic else 0.

```c
int ft_isalpha(int  c);
```

### ft_isascii(int c)

Return 1 if c is an ascii character else 0.

```c
int ft_isascii(int c);
```

### ft_isdigit(int c)

Return 1 if character c is a number else 0.

```c
int ft_isdigit(int c);
```

### ft_isprint(int c)

Return 1 if character c is printable.

```c
int ft_isprint(int c);
´´´

### ft_itoa_base

Convert a number n into string str with a base base. Return a pointer of str.
c is direction of str.

```c
char  *ft_itoa_base(char *str, unsigned long n , int base, int c);
```

### ft_itoa

Convert number n into a string. Allocate space  and return pointer to allocated memory.

```c
char  *ft_itoa(int n);
```

### ft_lstadd_back

Add element new at the end of list lst.

```c
void  ft_lstadd_back(t_list **lst, t_list *new);
```

### ft_lstadd_front

Add element new at the fron of list alst.

```c
void  ft_lstadd_front(t_list **alst, t_list new);
```

### ft_lstclear

Delete and free each element of list lst. Pointer of lst turns NULL.

```c
void  ft_lstclear(t_list **lst, void (*del)(void *));
´´´

### ft_lstdelone

Take given element of a list and free it.

```c
void  ft_lstdelone(t_list *lst, void (*del)(void*));
```

### ft_lstiter

Iterate list lst and apply given function to each element.

```c
void  ft_lstiter(t_list *lst, void (*f)(void *));
```

### ft_lstlast

Return last element of list lst.

```c
t_list  *ft_lstlast(t_list *lst);
```

### ft_lstmap

Iterate list lst and apply given function to each element content.

```c
t_list  *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
```

### ft_lstnew

Allocate memory and give a new element for a list.

```c
t_list  *ft_lstnew(void *content);
```

### ft_lstsize

Return number of elements of list lst.

```c
int ft_lstsize(t_list *lst);
```

### ft_memccpy

Copies bytes from string src to string dst. If character c as unsigned char occurs on src, 
the copy stops and a pointer to the byte after the copy of in dst is returned. Otherwise, 
n bytes are copied, and a NULL pointer is returned.
src and dst should not overlap, as the behaviour is undefined.

```c
void  *ft_menccpy(void *dst, const void *src, int c, size_t n);
```

### ft_menchr

Locates the first occurrence of c as unsigned char in string s.

```c
ft_memchr(const void *s, int c, size_t n);
```

### ft_memcmp

Returns zero if the two strings are identical, otherwise returns the difference between 
the first two different bytes.

```c
void  *ft_menchr(const void *s, int c, size_t n);
```

### ft_memcpy

Copies n bytes from memory src to dst. If dst and src overlap, behaviour is undefined.

```c
void  *ft_memcpy(void ^dst, vonst void *src, size-t n);
```

### ft_memmove

Copies len bytes from string src to dst. Two strings may overlap, the copy is always 
done in a non-destructive manner.

```c
void  *ft_memmove(void *dst, const void *src, size_t len);
```

### ft_memset

Writes len bytes of value c as unsigned char to string b.

```c
void  *ft_memset(void *b, int c, size_t len);
```

### ft_putchar_fd

Set character c to direction fd.

```c
void  ft_putchar_fd(char c, int fd);
```

### ft-putendl_fd

Set string s to direction fd with '\n' at the end.

```c
void  ft_putendl_fd(char *s, int fd);
```

### ft_putnbr_base

Display number n wit base base.
```c
int ft_putnbr_base(unsigned long n, char *base);
```

### ft_putnbr_fd

Set number n to direction fd.

```c
void  ft_putnbr_fd(int n, int fd);
```

### ft_putstr_fd

Set string s to direction fd.

```c
void ft_putstr_fd(char *s, int fd);
```

### ft_split

Take string s and return a double pointer filled with elements of str separated by character c.

```c
char  **ft_split(char const *s, char c);
```

### ft_strchr

Return pointer of the first character c found in string s. If there isn't c, return NULL.

```c
char  *ft_strchr(const char *s, int c);
```


### ft_strcpy

Copy characters of string src into dst. Return a pointer of dst.

```c
char  *ft_strcpy(char *dst, const char *src);
```

### ft_strdup

Allocate memory sufficetn memory for a copy of the string s1, does the copy and returns a 
pointer to it. It there isn't memory availabe, NULL is returned.

```c
char  *ft_strdup(const char *s1);
```

### ft_strffnotof

Return zero if all the characters of string str are equal to c.

```c
int ft_strffnotof(const char *str, int c);
```

### ft_strjoin

Allocates memory in one for two strings, s1 and s2. If there isn't memory availabe or parameters 
are empty, returns NULL. Otherwise returns a pointer to the allocated memory.

```c
char  *ft_strjoin(char const *s1, char const *s2);
```

### ft_strlcat

Appends string src to the end of dst. It will append at most dstsize. It will NUL-terminate, unless 
dstsize is 0 or original dst string was longer than dstsize.

```c
char  *ft_strlcat(char *dst, const char *src, size_t dstsize;
```

### ft_strlcpy

Copies up to dstsize -1 characters from the string src to dst, NUL-termination if there is room.

```c
size_t ft_strlcat(char *dst, const char *src, size_t dstsize);
```

### ft_strlen

Return length of string s

```c
size_t  ft_strlen(const char *s);
```

### ft_strmapi

Applicates function f to each character of string s. Allocates memory and return a pointer to the 
memory allocated.

```c
char  *ft_strmapi(char const *s, char (*f)(unsigned int, char));
```

### ft_strncmp

Compares not more than n characters of s1 and s2. Return difference of the first change. NUL 
characters are not compared.

```c
int ft_strncmp(const char *s1, const char *s2, size_t n);
```

### ft_strnstr

Locates first occurrence of the string needle in haystack, where not more than len characters are 
searched. Return the pointer of the first occurrence found in haystack. Otherwise NULL.

```c
char  *ft_sstrnstr(const char *hastack, const char *needle, size_t len);
```

### ft_strrchr

Return the last occurrence of c in the string pointed to by s.

```c
char  *ft_strrchr(const char *s, int c);
```


### ft_strstr

Return the first occurrence of c in the string pointed to by s.

```c
char  *ft_strstr(const char *s, int c);
```


### ft_strtrim

Allocates memory and returns a copy of s1 with characters of set deleted from the start and 
the end.

```c
char  *ft_strtrim(char const *s1, char const *set);
```

### ft_substr

Allocates memory and return a pointer of a copy of the string s starting from index start.

```c
char  *ft_substr(char const *s, unsigned int start, size_t len);
```

### ft_tolower

Return lower case of the character c.

```c
int ft_tolower(int c);
```

### ft_toupper

Return upper case of the character c.

```c
int ft_toupper(int c);
```

### ft_uitoa

Return a pointer of a number with base. Transform the number to a string. Allocates memory.

```c
char  *ft_uitoa(unsigned int nb);
```








