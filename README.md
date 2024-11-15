# Push_swap_42
Push_swap 42


Proyect in progress :part_alternation_mark:

### 1. Project description
Program called push_swap which will receive as argument the stack a in the format of a list of integers. The first argument must be the one on top of the stack. The program must display the shortest possible list of instructions to sort the stack a, from smallest to largest, where the smallest number is at the top of the stack, as well as sort the stack a. This can be done by using another stack called b.

### 2. Available operations
- **sa** swap a: Swaps the first two elements of stack a.
- **sb** swap b: Swaps the first two elements of stack b.
- **ss** swap a and swap b at the same time. 
- **pa** push a: Takes the first element from stack b and puts it first in stack a. Does nothing if b is empty. 
- **pb** push b: Takes the first element from stack a and puts it first in stack b. Does nothing if a is empty. 
- **ra** rotate a: Moves up all elements in stack a one position, so that the first element becomes the last. 
- **rb** rotate b: Moves up all elements in stack b one position, so that the first element becomes the last. 
- **rr** ra and rb at the same time. 
- **rra** reverse rotate a: Shifts down all elements in stack a by one position, so that the last element becomes the first element. 
- **rrb** reverse rotate b: Shifts down all elements in stack b by one position, so that the last element becomes the first element. 
- **rrr** rra and rrb at the same time.

### 3. Error control
- Integers within the range of int.
- No repeated elements.
- No characters.
- No multiple signs in a number (and only before it).
- Control input with a single argument, a string consisting of numbers separated by spaces.
- Control input with several arguments, which are all numbers.
- It does not control a mixed input between a string of several numbers and single numbers as further arguments.

If it finds any element that does not comply with the above it prints Error and a line break.

If no arguments are entered, it returns control to the user, without printing anything.

If everything is correct, the operations performed to sort the stack will be printed followed by a line break. If the elements are already sorted, nothing is printed, since it is checked if the stack is sorted so that the algorithm is not executed.



### 4. Sorting algorithm developed
#### 4.1. Less than 5 elements: case-by-case sorting
From 2 to 5 elements are ordered directly, checking each of the possibilities.

If there is only one element nothing is done.

#### 4.2. More than 5 elements: Turk Algorithm (first part) and mi own algorithm combined
- Push the two elements at the top of the stack a to stack b.
- Sort the two elements of stack b, putting the minor element below.
- Until there are no elements in stack a:
    - For each stack element to calculate its target in b. Its target is the element that is lowest and closest to a element. If we are faced with a number that is minimum, the target will be the largest number in b.
    - Calculate the number of moves needed to put each element in a on the to of the stack.
    - Calculate the number of moves needed to put the targets of each element in a on top of stack b.
    - For each element in a, add the movements calculated in the previous two steps. Adding one extra movement, which corresponds to one pb.
    - Select the element in a, which has the least number of movements.
    - Also, do a pb to move the element on top a (the selected one) to stack b, placing it on top of the target in b.
- Pass all elements from stack b to stack a. That is, make as many pa as there are elements in stack b.
- Find what is the minimum element in stack a, and make it become the top of the stack.

### 5. How to execute the programme
- Clone the repository.
- Execute the command make.
- Execute the program with the desired arguments as follows:
