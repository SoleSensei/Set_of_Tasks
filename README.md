# Set of Tasks #1
Some casual tasks for C beginners. 

## Set
### Task 1
Calculating `sqrt(x)` with set precision `epsiolon` with [Newton's iterative method.](https://en.wikipedia.org/wiki/Newton%27s_method)

![Newton's iterative method](https://image.ibb.co/cGvvPm/newton.png)

### Task 2
Calculating `polynomial f(x)` and `f'(x)` with `an, an−1, ... , a0` with [Horner's method.](https://en.wikipedia.org/wiki/Horner%27s_method)

    input: x, an, an-1, ..., a0

### Task 3
Calculating `Fi` in [Fibonacci sequence.](https://en.wikipedia.org/wiki/Fibonacci_number) Iterative and recursive methods.

    input: i

### Task 4
Converting `char*` string to `double` number.

    input: string

### Task 5
Creating `List of words`. Then excluding all words from `List`, which coincide with the last `List` word. 

### Task 6
Creating `binary search tree` with commands.

Commands:
    
    +<unsigned integer> - add element to the tree
    -<unsigned integer> - remove element from the tree
    ?<unsigned integer> - find element in the tree

### Task 7
Calculator. 

    input: <0-9> <operation> <0-9> <operaton ...
    operations: ^, *, /, +, -

## Launch

    gcc -Wall -g Task2.x.c -o tx
    ./tx

Full [documentation](./task2.pdf) on russian.


