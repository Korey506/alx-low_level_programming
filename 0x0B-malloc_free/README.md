Automatic and dynamic allocation, malloc and free
The malloc function is used to allocate a certain amount of memory during the execution of a program. It will request a block of memory from the heap. If the request is granted, the operating system will reserve the requested amount of memory and malloc will return a pointer to the reserved space.

When the amount of memory is not needed anymore, you must return it to the operating system by calling the function free.

Automatic allocation
When you declare variables or when you use strings within double quotes, the program is taking care of all the memory allocation. You do not have to think about it.

Special case: string literals

One special case we have seen so far is the memory used to store strings that we put within double quotes (") in our programs.

The string "Holberton" that was just declared is stored automatically in memory when the program is launched. But, the memory that stores the string is only readable. In fact, if you try to change a character using str, you will have a little surprise :)

Why would I need dynamic allocation?

So far we only have seen functions and programs that had fixed inputs. What happens when we do not know in advance how much memory you need and we will only know this at runtime, after compilation?

For instance, imagine we have to create a program that will store all the words contained in a file in an array. That file is passed as an argument to our program. There is no way we could know in advance how many words the file will contain. We can not declare a big array like char *words[1024]; and assume that there will never be more than 1024 words in the file. That’s when malloc and friends come to the rescue, and will permit us to allocate dynamically the amount of memory we need.

Dynamic allocation
Malloc
The malloc function allocates a specific number of bytes in memory and returns a pointer to the allocated memory. This memory will have read and write permissions.

Prototype: void *malloc(size_t size);
where void * means it is a pointer to the type of your choice
and size is the number of bytes your need to allocate

memory

Contrary to local variables and function parameters, the memory that is allocated with malloc is not automatically released when the function returns.

The memory is not initialized

Just like with automatic allocation, the memory allocated by malloc is not initialized.

Free
When you are using malloc, you have to handle the memory yourself. This means that:

You need to keep track of all the addresses of the allocated memory (in a variable of type pointer)
You have to deallocate every memory space you previously allocated yourself. If you do not do this, then your program can run out of memory. Your operating system could even kill your program while it is running

The free function frees the memory space which have been allocated by a previous call to malloc (or calloc, or realloc).

Prototype: void free(void *ptr);
where ptr is the address of the memory space previously allocated by and returned by a call to malloc

Valgrind
When writing big and complex programs, it is not always easy to keep track of all allocated and deallocated memory. We can use the program Valgrind in order to ensure we are freeing all allocated memory. It is a programming tool for memory debugging, memory leak detection, and profiling.

Don’t trust anyone
On error, malloc returns NULL. As for any other C library function, you should always check the malloc return value before using it. If you don’t you will run into segfaults.

String literals and .rodata (advanced)
The string literals are stored in your executable at compilation. The way it is stored is actually dependent on both the operating system you are using and the linker. This is what happens when you compile the program on most modern operating systems:

The compiler puts the string into a read-only data-section, usually .rodata
The linker collects all the data in such read-only sections and puts them into a single segment. This segment resides in the executable file and is flagged with a “read only”-attribute.
When you run the program, the operation system executable loader loads the executable (or maps it into memory to be more exact). Once this is done, the loader walks the sections and sets access-permissions for each segment. For a read-only data segment it will most likely disable code-execute and write access. Code (for example, your functions) gets execute rights but no write access. Ordinary data like static variables gets read and write access and so on…

One very easy way to check that the string literal is actually stored in your executable is to use the command strings (man strings).

String literals are not always read-only

On most modern operating system, string literals will be read-only. But this is (and certainly was) not always the case. It actually depends which operating system and linker you are using. For instance, if you were to compile segf.c for DOS, the program would not segfault. It would actually run because the memory where the string “Holberton” would be stored would have write access. This would happen because the DOS loader does not know about read-only sections.

String literals are not always stored as strings in the executable

Note that we are using a 64-bit machine for the following example

Wait… WAT?

So how does the program know what to print, without actually using the string? Well, sometimes (actually more often than you think), the compiler will optimize your code and modify it, without telling you. Let’s analyse what happens with objdump:

This is the beginning of the string Holberton! We are just missing two chars: n and \0. This is what the line 4005bb: 66 c7 45 e8 6e 00 mov WORD PTR [rbp-0x18],0x6e is taking care of:

0x6e is the ASCII value of the char n
mov WORD ensures that you actually moves 0x006e, as a WORD is two-byte long*, and 0x00 is the ASCII code for the \0 char, that marks the end of a C string
* In this context, a WORD is 2-byte long, as we are referring to the Intel assembly language

After the execution of the line mov WORD PTR [rbp-0x18],0x6e, the memory looks like this:
And you have the complete string Holberton stored in the array. In other words, it is possible that a string is stored as “code” and not as “data” in your executable.

The way the program strings works: strings prints the printable character sequences that are at least 4 characters long and are followed by an unprintable character. It doesn’t know about sections and tries to interpret every bytes of the executable as a char. Therefore, as our executable contains the bytes 48 b8 48 6f 6c 62 65 72 74 6f, immediately followed by the bytes 48 89 45 e0,






0. Float like a butterfly, sting like a bee
mandatory
Write a function that creates an array of chars, and initializes it with a specific char.

Prototype: char *create_array(unsigned int size, char c);
Returns NULL if size = 0
Returns a pointer to the array, or NULL if it fails


1. The woman who has no imagination has no wings
mandatory
Write a function that returns a pointer to a newly allocated space in memory, which contains a copy of the string given as a parameter.

Prototype: char *_strdup(char *str);
The _strdup() function returns a pointer to a new string which is a duplicate of the string str. Memory for the new string is obtained with malloc, and can be freed with free.
Returns NULL if str = NULL
On success, the _strdup function returns a pointer to the duplicated string. It returns NULL if insufficient memory was available
FYI: The standard library provides a similar function: strdup. Run man strdup to learn more.

2. He who is not courageous enough to take risks will accomplish nothing in life
mandatory
Write a function that concatenates two strings.

Prototype: char *str_concat(char *s1, char *s2);
The returned pointer should point to a newly allocated space in memory which contains the contents of s1, followed by the contents of s2, and null terminated
if NULL is passed, treat it as an empty string
The function should return NULL on failure

3. If you even dream of beating me you'd better wake up and apologize
mandatory
Write a function that returns a pointer to a 2 dimensional array of integers.

Prototype: int **alloc_grid(int width, int height);
Each element of the grid should be initialized to 0
The function should return NULL on failure
If width or height is 0 or negative, return NULL

4. It's not bragging if you can back it up
mandatory
Write a function that frees a 2 dimensional grid previously created by your alloc_grid function.

Prototype: void free_grid(int **grid, int height);
Note that we will compile with your alloc_grid.c file. Make sure it compiles.


5. It isn't the mountains ahead to climb that wear you out; it's the pebble in your shoe
#advanced
Write a function that concatenates all the arguments of your program.

Prototype: char *argstostr(int ac, char **av);
Returns NULL if ac == 0 or av == NULL
Returns a pointer to a new string, or NULL if it fails
Each argument should be followed by a \n in the new string


6. I will show you how great I am
#advanced
Write a function that splits a string into words.

Prototype: char **strtow(char *str);
The function returns a pointer to an array of strings (words)
Each element of this array should contain a single word, null-terminated
The last element of the returned array should be NULL
Words are separated by spaces
Returns NULL if str == NULL or str == ""
If your function fails, it should return NULL
