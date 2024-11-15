# Push_swap_42
Push_swap 42


Proyect in progress :part_alternation_mark:

### Sorting algorithm developed
#### Turk Algorithm (first part) and mi own algorithm combined
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
