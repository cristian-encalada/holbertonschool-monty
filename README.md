<br/>
<p align="center">
  <a href="https://github.com/cristian-encalada/holbertonschool-monty">
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

* [About the Project](#about-the-project)
* [Getting Started](#getting-started)
  * [Prerequisites](#prerequisites)
* [Usage](#usage)
* [Authors](#authors)

## About The Project

![Screen Shot](https://upload.wikimedia.org/wikipedia/commons/2/2e/Monty_flowchart.drawio.png?20230512150507)

### Monty language
Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

## Getting Started

### Prerequisites

<b>The repository containing this project has these files:</b>

```monty.h```: holds prototypes of functions spread across all files, as well as structures used.
```main.c```: holds the entry for the program.
```monty_logic.c```: holds functions called by the main file.
```get_opcode.c```: gets the function corresponding to the opcode.
```function_opcodes.c```: holds functions for push, pall and pint opcodes.
```function_opcodes2.c```: holds functions for swap, add and nop opcodes

## Usage

<b> For push and pall opcodes: </b>
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
<b> For pint opcode: </b>
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
<b> For pop opcode: </b>
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
<b> For swap opcode: </b>
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

<b> For add opcode: </b>
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


## Authors

* **Cristian Encalada** - *Holberton Student* - [Cristian Encalada](https://github.com/cristian-encalada) - *Author*
* **Luisina Llugdar** - *Holberton Student* - [Luisina Llugdar](https://github.com/LuisinaLlugdar) - *Author*