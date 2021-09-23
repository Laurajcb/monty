# Monty Interpreter
Monty Bytecode Interpreter  is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

## Monty byte code file
Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:

```
Holberton:~/monty$ cat -e bytecodes/000.m
push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$
Holberton:~/monty$
```

### compilation
```
$ gcc -Wall -Werror -Wextra -pedantic *.c -o monty

```

### Usage
```
$ ./monty bytecode_file

```
## Files

| **NAME** | CONTENT |
|---|---|
|[__push_](./opcode_funct1.c)|Push a new element in the stack|
|[__pall_](./opcode_funct1.c)|Print the elements in a stack|
|[__pint_](./opcode_funct1.c)|Function that get the value of the top of the stack|
|[__pop_](./opcode_funct1.c)|Function that removes the top element of the stack|
|[__swap_](./opcode_funct1.c)|Fuction that swaps the top two elements of the stack|
|[__add_](./opcode_funct2.c)|Function that adds the top two elements of the stack|
|[__nop_](./opcode_funct2.c)|Function nop doesn’t do anything|
[__sub_](./opcode_funct2.c)|Function that subs the top two elements of the stack|
[__div_](./opcode_funct2.c)|Function that divides the top two elements of the stack|
[__mul_](./opcode_funct3.c)|Function that multiplies the top two elements of the stack|
[__mod_](./opcode_funct3.c)|Function that modules the top two elements of the stack|
[__pchar_](./opcode_funct3.c)|Function that Prints the char at the top of the stack|
[__pstr_](./opcode_funct3.c)|Function prints the string starting at the top of the stack|
[__rotl_](./opcode_funct3.c)|Function that Rotates the stack to the top|
[__pushmode_](./opcode_funct4.c)|Function Push a new element in the stack depent if is stack or queue|
[__stack_](./opcode_funct4.c)|Function Converts a queue to a stack|
[___queue_](./opcode_funct4.c)|Function Converts a stack to a queue|
[__check_mode_](./opcode_funct4.c)|Function that Checks if a stack_t linked list is in stack or queue mode.|


### Example

```
Monty byte code file:

monty]\--> cat -e bytecodes/00.m
push 1$
push 2$
push 3$
pall$

Output:

monty]\--> ./monty bytecodes/00.m
3
2
1
monty]\-->

```