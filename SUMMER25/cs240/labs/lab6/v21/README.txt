All my functions are in main.c, with all my libraries and decalrarions in funcs21.h

copyprompt - same thing as streq, this function was created to reduce redundancy. It 
traveses through a src*, to make sure it fits the MAX_PROMPT requirement and placement
ar src index exists, it will copy to the dest*. Used for the c string function in minsh
since my code had errors. I pulled the code out and made a seperate function to debug and
kept it for better reading. If user prompt checks oyt, it will be stored in the buffer.

main - does all the minsh logic. hold two char from prompt and another form the command.
Loops forever, until broken and does all the same logic instructed in the lab
instructions. For all the specified built in functions it will do as the instructions say:
  
  e: breaks out of the loop and exits to go back to the original borg or escher shell.

  c <string>: will read c and a space after it. Everything after that will be stored, unless   we find it has more than the 11 char prompt length limit we made in the header file. Once w  e make sure that works, we replace our % prompt with the user prompt. 

  l: runs \bin\ls through the argv. 

  L: runs the \bin\ls with the added -l using argv. Gives long list format and shows more 
  detailed overview including the chmod status, the owner/creator, and the date/time last
  edited/opened.

  j: runs \bin\cat and the name of our file 'joke.dat'. do you like me joke? :)

