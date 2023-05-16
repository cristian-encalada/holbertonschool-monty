<br/>
<p align="center">
  <a href="https://holbertonschool.uy/">
    <img src="https://blog.holbertonschool.com/wp-content/uploads/2020/04/unnamed-2.png" alt="Logo" width="80" height="80">
  </a>

  <h1 align="center">
      C - Monty bytecodes Interpreter 
  </h1>

  <p align="center">
    Holberton School project
  </p>
</p>

## Table Of Contents

1. [About the Project](#about-the-project)
    * [The Monty language](#the-monty-language)
2. [Requirements](#requirements)
    * [General](#general)
    * [The monty program](#the-monty-program)
    * [Compilation and Output](#compilation-and-output)
3. [Implementation](#implementation) 
    * [Flowchart](#flowchart) 
    * [File Structure](#file-structure)
4. [Mandatory Tasks](#mandatory-tasks)
5. [Advanced Tasks](#advanced-tasks)
6. [Authors](#authors)

## About The Project

### The Monty language

Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

__Monty byte code files__

Files containing Monty byte codes usually have the `.m` extension. 

Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. 


## Requirements

### General

- Allowed editors: `vi`, `vim`, `emacs`, `vscode`.
- All the files will be compiled on `Ubuntu 20.04 LTS` using gcc, using the options `-Wall -Werror -Wextra -pedantic`
- All the files should end with a new line
- A `README.md` file, at the root of the folder of the project is mandatory
- The code should use the `Betty` style. It will be checked using [betty-style.pl](https://github.com/hs-hq/Betty/blob/main/betty-style.pl) and [betty-doc.pl](https://github.com/holbertonschool/Betty/wiki)
- You allowed to use a maximum of one global variable
- No more than 5 functions per file
- You are allowed to use the C standard library
- The prototypes of all your functions should be included in your header file called `monty.h`
- Don’t forget to push your header file
- All your header files should be include guarded
- You are expected to do the tasks in the order shown in the project

### The monty program

- Usage: `monty file`
  - where `file` is the path to the file containing Monty byte code
- If the user does not give any file or more than one argument to your program, print the error message `USAGE: monty file`, followed by a new line, and exit with the status `EXIT_FAILURE`
- If, for any reason, it’s not possible to open the file, print the error message `Error: Can't open file <file>`, followed by a new line, and exit with the status `EXIT_FAILURE`
  - where <file> is the name of the file
- If the file contains an invalid instruction, print the error message `L<line_number>: unknown instruction <opcode>`, followed by a new line, and exit with the status `EXIT_FAILURE`
  - where is the line number where the instruction appears.
  - Line numbers always start at 1
- The monty program runs the bytecodes line by line and stop if either:
  - it executed properly every line of the file
  - it finds an error in the file
an error occured
- If you can’t malloc anymore, print the error message `Error: malloc failed`, followed by a new line, and exit with status `EXIT_FAILURE`.
- You have to use `malloc` and `free` and are not allowed to use any other function from `man malloc` (realloc, calloc, …)

### Compilation and Output

Your code will be compiled this way:
```
$ gcc -Wall -Werror -Wextra -pedantic *.c -o monty
```
- Any output must be printed on `stdout`
- Any error message must be printed on `stderr`


## Implementation

### Flowchart

![Screen Shot](https://upload.wikimedia.org/wikipedia/commons/2/2e/Monty_flowchart.drawio.png?20230512150507)

### File Structure

The project file structure is organized as follows:

|File|Description|
|--|--|
|[monty.h](./monty.h)|Contains prototypes of functions spread across all files, as well as structures used.|
|[main.c](./main.c)|Contains he entry for the program.|
|[monty_logic.c](./monty_logic.c)|Contains functions called by the main file.|
|[get_opcode.c](./get_opcode.c)|Holds the corresponding function to select the proper opcode|
|[function_opcodes.c](./functions_opcodes.c)|Contains functions for push, pall, pint and pop opcodes.|
|[function_opcodes2.c](./functions_opcodes2.c)|Contains functions for nop, add, swap, sub and div opcodes|
|[function_opcodes3.c](./functions_opcodes3.c)|Contains functions for mul, mod, pchar, pstr and rotl opcodes|
|[function_opcodes4.c](./functions_opcodes4.c)|Contains functions for rotr opcode and a helper function push_queue|

## Mandatory Tasks

### 0. `push` and `pall` opcodes

Implement the `push` and `pall` opcodes.

__The push opcode__

The opcode `push` pushes an element to the stack.

- Usage: `push <int>`
  - where `<int>` is an integer
- if `<int>` is not an integer or if there is no argument given to `push`, print the error message L<line_number>: usage: push integer, followed by a new line, and exit with the status `EXIT_FAILURE`
  - where is the line number in the file
- You won’t have to deal with overflows. Use the `atoi` function

__The pall opcode__

The opcode `pall` prints all the values on the stack, starting from the top of the stack.

- Usage `pall`
- Format: see example
- If the stack is empty, don’t print anything

__Example:__

- Input:  
```sh
julien@ubuntu:~/monty$ cat -e bytecodes/00.m
push 1$
push 2$
push 3$
pall$
julien@ubuntu:~/monty$ ./monty bytecodes/00.m
```
- Output:
```sh
3
2
1
```
### 1. `pint` opcode

Implement the `pint` opcode.

__The pint opcode__

The opcode `pint` prints the value at the top of the stack, followed by a new line.

- Usage: `pint`
- If the stack is empty, print the error message `L<line_number>: can't pint, stack empty`, followed by a new line, and exit with the status `EXIT_FAILURE`

__Example:__

- Input:  
```sh
julien@ubuntu:~/monty$ cat bytecodes/06.m 
push 1
pint
push 2
pint
push 3
pint
julien@ubuntu:~/monty$ ./monty bytecodes/06.m 
```
- Output:
```sh
1
2
3
```
### 2. `pop` opcode

Implement the `pop` opcode.

__The pop opcode__

The opcode `pop` removes the top element of the stack.

- Usage: `pop`
- If the stack is empty, print the error message `L<line_number>: can't pop an empty stack`, followed by a new line, and exit with the status EXIT_FAILURE

__Example:__

- Input:  
```sh
julien@ubuntu:~/monty$ cat bytecodes/07.m 
push 1
push 2
push 3
pall
pop
pall
pop
pall
pop
pall
julien@ubuntu:~/monty$ ./monty bytecodes/07.m 
```
- Output:
```sh
3
2
1
2
1
1
```
### 3. `swap` opcode

Implement the `swap` opcode.

__The swap opcode__

The opcode `swap` swaps the top two elements of the stack.

- Usage: `swap`
- If the stack contains less than two elements, print the error message `L<line_number>: can't swap, stack too short`, followed by a new line, and exit with the status `EXIT_FAILURE`

__Example:__

- Input:  
```sh
julien@ubuntu:~/monty$ cat bytecodes/09.m 
push 1
push 2
push 3
pall
swap
pall
julien@ubuntu:~/monty$ ./monty bytecodes/09.m 
```
- Output:
```sh
3
2
1
2
3
1
```

### 4. `add` opcode

Implement the `add` opcode.

__The add opcode__

The opcode `add` adds the top two elements of the stack.

- Usage: `add`
- If the stack contains less than two elements, print the error message `L<line_number>: can't add, stack too short`, followed by a new line, and exit with the status `EXIT_FAILURE`
- The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
  - The top element of the stack contains the result
  - The stack is one element shorter

__Example:__

- Input:  
```sh
julien@ubuntu:~/monty$ cat bytecodes/12.m 
push 1
push 2
push 3
pall
add
pall 
```
- Output:
```sh
3
2
1
5
1
```

### 5. `nop` opcode

Implement the `nop` opcode.

__The nop opcode__

The opcode `nop` doesn’t do anything.

Usage: `nop`


__Example:__

- Input:  
```sh
 ~/holbertonschool-monty$ cat bytecodes/04.m 
push 98
push 402
nop Holberton
pall
```
- Output:
```sh
402
98
```

## Advanced Tasks

### 6. `sub` opcode

Implement the `sub` opcode.

__The sub opcode__

The opcode `sub` subtracts the top element of the stack from the second top element of the stack.

- Usage: `sub`
- If the stack contains less than two elements, print the error message `L<line_number>: can't sub, stack too short`, followed by a new line, and exit with the status `EXIT_FAILURE`
- The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
  - The top element of the stack contains the result
  - The stack is one element shorter

__Example:__

- Input:  
```sh
 ~/holbertonschool-monty$ cat bytecodes/06.m 
push 1
push 2
push 10
push 3
sub
pall
```
- Output:
```sh
 ~/holbertonschool-monty$ ./monty bytecodes/06.m
7
2
1
```

### 7. `div` opcode

Implement the `div` opcode.

__The div opcode__

The opcode `div` divides the second top element of the stack by the top element of the stack.

- Usage: `div`
- If the stack contains less than two elements, print the error message `L<line_number>: can't div, stack too short`, followed by a new line, and exit with the status `EXIT_FAILURE`
- The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
  - The top element of the stack contains the result
  - The stack is one element shorter
- If the top element of the stack is `0`, print the error message `L<line_number>: division by zero`, followed by a new line, and exit with the status `EXIT_FAILURE`

__Example:__

- Input:  
```sh
 ~/holbertonschool-monty$ cat bytecodes/07.m 
push 7
push 5
push 12
push 0
div
pall
```
- Output:
```sh
 ~/holbertonschool-monty$ ./monty bytecodes/07.m
L5: division by zero
```

### 8. `mul` opcode

Implement the `mul` opcode.

__The mul opcode__

The opcode `mul` multiplies the second top element of the stack with the top element of the stack.

- Usage: `mul`
- If the stack contains less than two elements, print the error message `L<line_number>: can't mul, stack too short`, followed by a new line, and exit with the status `EXIT_FAILURE`
- The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
  - The top element of the stack contains the result
  - The stack is one element shorter

__Example:__

- Input:  
```sh
 ~/holbertonschool-monty$ cat bytecodes/08.m 
push -4
push 7
mul
push 5
push -6
pall
```
- Output:
```sh
 ~/holbertonschool-monty$ ./monty bytecodes/08.m
-6
5
-28
```

### 9. `mod` opcode

Implement the `mod` opcode.

__The mod opcode__

The opcode `mod` computes the rest of the division of the second top element of the stack by the top element of the stack.

- Usage: `mod`
- If the stack contains less than two elements, print the error message `L<line_number>: can't mod`, stack too short, followed by a new line, and exit with the status `EXIT_FAILURE`
- The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
  - The top element of the stack contains the result
  - The stack is one element shorter
- If the top element of the stack is 0, print the error message `L<line_number>: division by zero`, followed by a new line, and exit with the status `EXIT_FAILURE`

__Example:__

- Input:  
```sh
 ~/holbertonschool-monty$ cat bytecodes/09.m 
push 7
push 5
push -5
push 2
mod
push 3
push 15
push 4
mod
pall
```
- Output:
```sh
 ~/holbertonschool-monty$ ./monty bytecodes/09.m
3
3
-1
5
7
```
### 10. comments `#`

Every good language comes with the capability of commenting. When the first non-space character of a line is `#`, treat this line as a comment (don’t do anything).

__Example:__

- Input:  
```sh
 ~/holbertonschool-monty$ cat bytecodes/10.m 
#push 12
#pall
push 4
# comment
pall
```
- Output:
```sh
 ~/holbertonschool-monty$ ./monty bytecodes/10.m
4
```
### 11. `pchar` opcode

Implement the `pchar` opcode.

__The pchar opcode__

The opcode `pchar` prints the char at the top of the stack, followed by a new line.

- Usage: `pchar`
- The integer stored at the top of the stack is treated as the ascii value of the character to be printed
- If the value is not in the ascii table (man ascii) print the error message `L<line_number>: can't pchar`, value out of range, followed by a new line, and exit with the status `EXIT_FAILURE`
- If the stack is empty, print the error message L<line_number>: `can't pchar, stack empty`, followed by a new line, and exit with the status `EXIT_FAILURE`

__Example:__

- Input:  
```sh
 ~/holbertonschool-monty$ cat bytecodes/11.m 
push 65
pchar
```
- Output:
```sh
 ~/holbertonschool-monty$ ./monty bytecodes/11.m
A
```
### 12. `pstr` opcode

Implement the `pstr` opcode.

__The pstr opcode__

The opcode `pstr` prints the string starting at the top of the stack, followed by a new line.

- Usage: `pstr`
- The integer stored in each element of the stack is treated as the ascii value of the character to be printed
- The string stops when either:
  - the stack is over
  - the value of the element is 0
  - the value of the element is not in the ascii table
- If the stack is empty, print only a new line

__Example:__

- Input:  
```sh
 ~/holbertonschool-monty$ cat bytecodes/12.m 
push 1
push 2
push 3
push 4
push 0
push 110
push 0
push 108
push 111
push 111
push 104
push 99
push 83
pstr
```
- Output:
```sh
 ~/holbertonschool-monty$ ./monty bytecodes/12.m
School
```

### 13. `rotl` opcode

Implement the `rotl` opcode.

__The rotl opcode__

The opcode rotl rotates the stack to the top.

- Usage: `rotl`
- The top element of the stack becomes the last one, and the second top element of the stack becomes the first one
- `rotl` never fails

__Example:__

- Input:  
```sh
 ~/holbertonschool-monty$ cat bytecodes/13.m 
push 1
push 2
push 3
push 4
push 5
pall
rotl
pall
```
- Output:
```sh
 ~/holbertonschool-monty$ ./monty bytecodes/13.m
5
4
3
2
1
4
3
2
1
5
```
### 14. `rotr` opcode

Implement the `rotr` opcode.

__The rotr opcode__

The opcode `rotr` rotates the stack to the bottom.

- Usage: `rotr`
- The last element of the stack becomes the top element of the stack
- `rotr` never fails

__Example:__

- Input:  
```sh
 ~/holbertonschool-monty$ cat bytecodes/14.m 
push 1
push 2
push 3
push 4
push 5
pall
rotr
pall
```
- Output:
```sh
 ~/holbertonschool-monty$ ./monty bytecodes/14.m
5
4
3
2
1
1
5
4
3
2
```
### 15. `stack` and `queue` opcodes

Implement the `stack` and `queue` opcodes.

__The stack opcode__

The opcode `stack` sets the format of the data to a `stack` (LIFO). This is the default behavior of the program.

- Usage: `stack`

__The queue opcode__

The opcode `queue` sets the format of the data to a queue (FIFO).

- Usage: `queue`

When switching mode:

  - The top of the stack becomes the front of the queue
  - The front of the queue becomes the top of the stack

__Example:__

- Input:  
```sh
 ~/holbertonschool-monty$ cat bytecodes/15.m 
queue
push 1
push 2
push 3
pall
stack
push 4
push 5
push 6
pall
add
pall
queue
push 11111
add
pall
```
- Output:
```sh
 ~/holbertonschool-monty$ ./monty bytecodes/15.m
1
2
3
6
5
4
1
2
3
11
4
1
2
3
15
1
2
3
11111
```
__Note__: Currently our program has an issue printing values after switching to `queue` mode, all other opcodes are working as expected.

## Authors

* **Cristian Encalada** - *Holberton Student* - [Cristian Encalada](https://github.com/cristian-encalada) - *Author*
* **Luisina Llugdar** - *Holberton Student* - [Luisina Llugdar](https://github.com/LuisinaLlugdar) - *Author*