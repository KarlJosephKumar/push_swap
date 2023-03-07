# push_swap

My version of push_swap.

• You have 2 stacks named a and b.
• At the beginning:
◦ The stack a contains a random amount of negative and/or positive numbers which cannot be duplicated.
◦ The stack b is empty.
• The goal is to sort in ascending order numbers into stack a. To do so you have the following operations at your disposal:
<b>sa</b> (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.
<b>sb</b> (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.
<b>ss</b> : sa and sb at the same time.
<b>pa</b> (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.
<b>pb</b> (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.
<b>ra</b> (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.
<b>rb</b> (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.
<b>rr</b> : ra and rb at the same time.
<b>rra</b> (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.
<b>rrb</b> (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.
<b>rrr</b> : rra and rrb at the same time.

For 100 variables the average is 580 computations.
For 500 variables the average is about 5100 computations.
Which is the maximum score for the evaluation.

How to use this code:

Make to compile
example:
./push_swap 2 5 8 6 1 0
or
./push_swap "2 5 8 6 1 0"

You can give it negative and positive <b>integers</b>
Anything that shouldn't work, ex. duplicates, letters, will give an error message on error output.
