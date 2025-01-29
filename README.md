
## Push Swap

Push Swap is a sorting algorithm project that involves manipulating two stacks (a and b) using a set of predefined operations to sort a given list of numbers in ascending order with the least number of moves possible.


## Rules

There are two stacks: **a** and **b**.

Initially:

- Stack a contains a random amount of unique positive and/or negative numbers.

- Stack b is empty.

- The goal is to sort the numbers in stack a in ascending order using the allowed operations.

## Allowed Operations

**Swap:**

- sa (swap a): Swap the first two elements of stack a.

- sb (swap b): Swap the first two elements of stack b.

- ss: Perform sa and sb simultaneously.

**Push:**

- pa (push a): Move the first element from stack b to the top of stack a.

- pb (push b): Move the first element from stack a to the top of stack b.

**Rotate:**

- ra (rotate a): Shift all elements of stack a up by one position, moving the first element to the last position.

- rb (rotate b): Shift all elements of stack b up by one position, moving the first element to the last position.

- rr: Perform ra and rb simultaneously.

**Reverse Rotate:**

- rra (reverse rotate a): Shift all elements of stack a down by one position, moving the last element to the first position.

- rrb (reverse rotate b): Shift all elements of stack b down by one position, moving the last element to the first position.

- rrr: Perform rra and rrb simultaneously.

## Sorting Algorithm 

The algorithm used in push_swap is inspired by efficient sorting strategies, particularly the approach described in [this article.](https://medium.com/@ayogun/push-swap-c1f5d2d41e97) The key approach is to reduce stack a to only three nodes and then push each remaining node to stack b in the correct descending order. This ensures that when elements are pushed back to a, they are already sorted.

Each number in a is assigned a target position in b to maintain order. The algorithm then calculates the cheapest number to push, ensuring that the sorting process is done with the minimum number of operations possible.


## Compilation/Usage
```bash
make
```
```bash
./push_swap <list of integers>
```

* The program should output the shortest possible sequence of instructions to sort stack a.

* Instructions must be separated by \n.

* If no parameters are provided, the program should return without displaying anything.

* If an error occurs, the program should output Error\n to the standard error output.

## Errors

The program must handle and display Error\n if:

* The input contains non-integer values.

* The input contains integers exceeding the valid range.

* Duplicate numbers are detected
  
