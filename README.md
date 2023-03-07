# push_swap
<br>
My version of push_swap.<br>
<br>
• You have 2 stacks named a and b.<br>
• At the beginning:<br>
◦ The stack a contains a random amount of negative and/or positive numbers which cannot be duplicated.<br>
◦ The stack b is empty.<br>
• The goal is to sort in ascending order numbers into stack a. To do so you have the following operations at your disposal:<br>
<b>sa</b> (swap a): Swap the first 2 elements at the top of stack a.<br>
Do nothing if there is only one or no elements.<br>
<b>sb</b> (swap b): Swap the first 2 elements at the top of stack b.<br>
Do nothing if there is only one or no elements.<br>
<b>ss</b> : sa and sb at the same time.<br>
<b>pa</b> (push a): Take the first element at the top of b and put it at the top of a.<br>
Do nothing if b is empty.<br>
<b>pb</b> (push b): Take the first element at the top of a and put it at the top of b.<br>
Do nothing if a is empty.<br>
<b>ra</b> (rotate a): Shift up all elements of stack a by 1.<br>
The first element becomes the last one.<br>
<b>rb</b> (rotate b): Shift up all elements of stack b by 1.<br>
The first element becomes the last one.<br>
<b>rr</b> : ra and rb at the same time.<br>
<b>rra</b> (reverse rotate a): Shift down all elements of stack a by 1.<br>
The last element becomes the first one.<br>
<b>rrb</b> (reverse rotate b): Shift down all elements of stack b by 1.<br>
The last element becomes the first one.<br>
<b>rrr</b> : rra and rrb at the same time.<br>
<br>
For 100 variables the average is 580 computations.<br>
For 500 variables the average is about 5100 computations.<br>
Which is the maximum score for the evaluation.<br>
<br>
How to use this code:<br>
<br>
Make to compile<br>
example:<br>
./push_swap 2 5 8 6 1 0<br>
or<br>
./push_swap "2 5 8 6 1 0"<br>
<br>
You can give it negative and positive <b>integers</b><br>
Anything that shouldn't work, ex. duplicates, letters, will give an error message on error output.<br>
