An Estimation of Distribution Algorithm implementaion that attempts to solve
N-Queens problems.

To setup, run the command:
  make all

This will create an obj directory and an nqueens executable in the current
directory.

To run the programme, run the command:
  ./nqueens <number of queens> <maximum number of iterations> <iteration increment>

Where the arguements in "<>" are to be replaced by user variables, or left
empty to use default values. Note, previous variables cannot be left empty and
then later ones specified, so to enter the number of iterations the number of
queens must be entered before.
The <iteration increment> is the value that will be added to the iteration
counter, so can be set to 0 to allow an unbounded number of iterations and run
time.

Default values:
  Number of Queens: 1
  Maximum number of iterations: 1000
  Iteration increment value: 1

Here is an example:
  ./nqueens 6 200 1

This will solve the N-Queens problem for 6 queens (6x6 board) with a maximum of
200 iterations, after which it will return the best solution it has if an ideal
one has not already been found.
