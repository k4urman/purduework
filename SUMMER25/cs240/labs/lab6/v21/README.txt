All my functions are in main.c, with all my libraries and decalrarions in funcs21.h

copyprompt - same thing as streq, this function was created to reduce redundancy. It
traveses through a src*, to make sure it fits the MAX_PROMPT requirement and placement
ar src index exists, it will copy to the dest*. Used for the c string function in minsh
since my code had errors. I pulled the code out and made a seperate function to debug and
kept it for better reading. If user prompt checks oyt, it will be stored in the buffer.

main - does all the minsh logic. hold two char from prompt and another form the command.
Loops forever, until broken and does all the same logic instructed in the lab
instructions.
