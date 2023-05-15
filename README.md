<br/>
<p align="center">
  <a href="https://holbertonschool.uy/">
    <img src="https://blog.holbertonschool.com/wp-content/uploads/2020/04/unnamed-2.png" alt="Logo" width="80" height="80">
  </a>

  <h3 align="center">C - Stacks, Queues - LIFO, FIFO </h3>

  <p align="center">
    Holberton School project
    <br/>
    <br/>
    <a href="https://github.com/cristian-encalada/holbertonschool-monty"><strong>Explore the docs »</strong></a>
    <br/>
    <br/>
  </p>
</p>

## Table Of Contents

1. [About the Project](#about-the-project)
    * [The Monty language](#the-monty-language)
    * [Requirements](#requirements)
2. [Implementation](#implementation) 
    * [Flowchart](#flowchart) 
    * [File Structure](#file-structure)
3. [Mandatory Tasks](#mandatory-tasks)
4. [Advanced Tasks](#advanced-tasks)
5. [Authors](#authors)

## About The Project

### The Monty language
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

__Monty byte code files__

Files containing Monty byte codes usually have the `.m` extension. 

Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. 

There can be any number of spaces before or after the opcode and its argument:
```sh
julien@ubuntu:~/monty$ cat -e bytecodes/000.m
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
julien@ubuntu:~/monty$
```
Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account:
```sh
julien@ubuntu:~/monty$ cat -e bytecodes/001.m
push 0 Push 0 onto the stack$
push 1 Push 1 onto the stack$
$
push 2$
  push 3$
                   pall    $
$
$
                           $
push 4$
$
    push 5    $
      push    6        $
$
pall This is the end of our program. Monty is awesome!$
julien@ubuntu:~/monty$
```
### Requirements

- Allowed editors: `vi`, `vim`, `emacs`
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

## Implementation

### Flowchart

![Screen Shot](https://upload.wikimedia.org/wikipedia/commons/2/2e/Monty_flowchart.drawio.png?20230512150507)

### File Structure

<b>The repository containing this project has these files:</b>

[monty.h](./monty.h): holds prototypes of functions spread across all files, as well as structures used.

[main.c](./main.c): holds the entry for the program.

[monty_logic.c](./monty_logic.c): holds functions called by the main file.

[get_opcode.c](./get_opcode.c): gets the function corresponding to the opcode.

[unction_opcodes.c](./functions_opcodes.c): holds functions for push, pall, pint and pop opcodes.

[function_opcodes2.c](./functions_opcodes2.c): holds functions for swap, add, nop, sub and div opcodes

[function_opcodes3.c](./functions_opcodes3.c): holds functions for mul and mod opcodes

## Mandatory Tasks

<b> `push` and `pall` opcodes: </b>
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
<b> `pint` opcode: </b>
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
<b> `pop` opcode: </b>
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
<b> `swap` opcode: </b>
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

<b> `add` opcode: </b>
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
## Advanced Tasks

<b> `sub` opcode: </b>
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

<b> `div` opcode: </b>
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

<b> `mul` opcode: </b>
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

<b> `mod` opcode: </b>
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

## Authors

* **Cristian Encalada** - *Holberton Student* - [Cristian Encalada](https://github.com/cristian-encalada) - *Author*
* **Luisina Llugdar** - *Holberton Student* - [Luisina Llugdar](https://github.com/LuisinaLlugdar) - *Author*