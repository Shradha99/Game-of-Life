# Game-of-Life
Language used: C++
The code first asks the user for the dimensions of the 2-dimensional array. Then, it creates a dynamic 2-D array of the required dimensions and populates it with zeros on the boundaries to avoid discrepancies when we reach the boundary.
It then uses the rand() function of C++ to randomly allot 1 or 0 to the remaining cells. A cell having a value of 0 denotes that it is dead and that having value 1 is alive.

Following this, the code works upon the user's discretion. If the user enters a y (denoting yes), then the next generation is displayed otherwise not. The time taken to display each generation can also be seen on the output terminal.

The next_state function is the one which estimates the next state. It uses two one-line buffers(buff1 and buff2). First buffer is used to calculate the successor state for a line, then the second buffer is used to calculate the successor state for the next line. The first buffer is then written to its line and freed to hold the successor state for the third line. The state_buff1 or state_buff2 are variables that store the state of the buffers. If the state of a buffer is 1, it means the buffer is currently being populated. This state is alternated after every iteration. 
An intermediate one-line buffer stores the future state of a line for time-being and after its values have been copied to the relevant buffer(buff1 or buff2), it is deleted. 

The two buffers have been used instead of a complete new array for the purpose of saving memory. 

Here is a snippet of the output(Following the original generation, 2 generations have been determined)::

Enter the no. of rows and columns
10
10
Original Generation
0 0 0 0 0 0 0 0 0 0
0 0 1 1 0 0 0 0 0 0
0 0 0 0 0 1 1 0 1 0
0 0 0 0 0 1 0 0 1 0
0 1 0 1 1 0 1 0 0 0
0 1 0 0 1 0 0 1 0 0
0 0 1 0 1 0 1 0 1 0
0 0 1 1 0 1 0 1 0 0
0 1 1 0 1 1 1 0 0 0
0 0 0 0 0 0 0 0 0 0

Enter y if you want to see the next generation, else enter n
y
Generation 1
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 1 1 1 1 0 0
0 0 0 0 0 0 0 0 0 0
0 0 1 1 1 0 1 1 0 0
0 1 0 0 1 0 1 1 0 0
0 1 1 0 1 0 1 0 1 0
0 0 0 0 0 0 0 1 0 0
0 1 1 0 1 1 1 0 0 0
0 0 0 0 0 0 0 0 0 0

Enter y if you want to see the next generation, else enter n
Time taken:13
y
Generation 2
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 1 1 0 0 0
0 0 0 0 0 1 1 0 0 0
0 0 0 0 0 0 0 0 0 0
0 0 1 1 1 0 1 1 0 0
0 1 0 0 1 0 0 0 1 0
0 1 1 1 0 0 1 0 1 0
0 0 0 0 1 0 0 1 0 0
0 0 0 0 0 1 1 0 0 0
0 0 0 0 0 0 0 0 0 0

Enter y if you want to see the next generation, else enter n
Time taken:39
