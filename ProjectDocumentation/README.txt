Switches -

switch                                                 check advance winnable game
-m N           *at most N moves played from game file            X       X
-o <filename>  *output file name                                 X
-x             *output game in exchange format                   X
-c             *Use a hashtable                                          X
-f             *Force safe moves to foundation                           X
-v             *verbose mode                                             X
-f <filename>  *File to get game configuration from                             X
-s <seed>      *Initialize the game with a seed                                 X
-1             *Turn one card over                                              X
-3             *Turn 3 cards over                                               X
-l <L>         *L is the number of waste resets                                 X

check: All it is doing is checking the game configuration to see if it is valid.
Correct number of cards, tableau order correct.

advance: uses check to verify file is correct, then checks if the moves are all
valid.

winnable: uses advance to find valid moves.

game: is the gui in a terminal window

Keeping track of moves. For advance, it limits how many of the moves it
can check, so if the move limit is reached, it stops even if there are more moves.
Winnable just specifies how many moves max can be played.

Creating a hash:
The moves are .(turn card over), r (reset waste), w->x (waste to columsn or foundation), 1->x(column to column or column
to foundation).
Assign a value to each move.
1 = 1
2 = 2
3 = 3
4 = 4
5 = 5
6 = 6
7 = 7
w = 8
f = 9
. = 10
r = 11

Example of series of moves-
w->1 . 2->f 3->4 w->5

Create the hash as follows-
8*1 + 1*2 + 10*3 + 2*4 + 9*5 + 3*6 + 4*7 + 8*8 + 5*9
8 + 2 + 30 + 8 + 45 + 18 + 28 + 64 + 45
248

Program Flow: Winnable gets a file, invokes Advance which calls on Check to see if the file is valid. Advance is able to
write the exchange format of the file to standard output. Winnable can call advance using popen and give the file name
then the advance output will be the exchange format. Checking new moves means that Winnable will need to write the
file.

Part of the requirements for Check, Advance, and Winnable is for them to read from a file or STDIN. If winnable is
reading from stdin then in order for check to read Winnable would need to pipe it's input to check. Check does it's job,
but then STDIN is empty. Sooooo:

Run Check only: File or STDIN, can hold the contents of the file as long as the program is running.
Run Advance: Can take a filename or stdin, but needs to run Check. Can have check set to read from STDIN, but that means
Advance has nothing to parse. If a file name is provided, no issue, it is just passed to Check to read the file.
I think if Advance reads from STDIN, then it will need to write the file out then give it to check as an argument.

Winnable will need to work much like Advance.

STDIN -> Winnable -> Winnable copies everything to a file -> file is given to advance as an argument -> which advance
can give to check as an argument.

Advance has the capability to write a configuration file, should it be the only one writing the file? Technically, when
it reads a file it will essentially output it in exchange format without any comments and in a standard format. So if
Winnable gets a STDIN then it can just pass to Advance. Advance can write the file out verbatim and pass to check then
it can parse the file if it checks out as okay.