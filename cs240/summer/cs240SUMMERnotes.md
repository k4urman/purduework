
version3
```c
// version 3 of z = x * y
// reads the numbers to be subtracted from keyboad
// using the standard I/O library function scanf()
// and outputs the result on the terminal
// using printf()

#include <stdio.h>

int main()
{
int x;
int y, z;

// read input
  scanf("%d %d", &x, &y);

/* compute multiplication */
  z = x * y;

// print result
  printf("%d * %d = %d\n", x, y, z);

}
```

main() -> calls scanf() to do something for it, the two inputs that should be read from the user, should be stored into int x and y. 
This is done by putting every function from MAIN MEMORY, they get their own working area. It allocated for the function to use. It is allocated to allow main() to call and use scanf(). Passing functions means to use it. 

Alice and Bob are friends. She writes him two letters placing them in mailbox 5 and 7 at the UPS office. Bob comes in later and opens 5 and 7 for each letter. Alice and Bob are the main and the memory and the letters are the functions. 

Imagine memory as a bunch of slots that allow you to place data like bytes. Each slot allows 8 bits. The mmeory slots start at 0 index and maximum till 2 to the power of n-bit -1 slots. Ints take up 4 bits.

**How is this different than printf?**: main() calls printf() what to print on the terminal. It will print just the input of the variable. There is no need to store anything. Scanf needs to know gthe adress while pritf doesn't

Segmentation Fault. You try to access a data value that the OS does not give access to. 

version4
```c
/* 	version 4 of z = x * y
	same as version 3 but supports
	real numbers */

#include <stdio.h>

int main()
{
float x, y, z;

// read input
  scanf("%f %f",&x,&y);

// multiply
  z = x * y;

// print result
  printf("result of %f times %f is %f\n", x, y, z);

}
```

version5
```c
/* 	version 5 of z = x * y
	same as version 4 but uses separate
	function multiply2() to perform multiplication */

#include <stdio.h>

float multiply2(float, float);

void main()
{
float x, y, z;

// read input
  scanf("%f %f",&x,&y);

// compute
  z = multiply2(x,y);

// print result
  printf("result of %f * %f is %.3f\n", x, y, z);

}


/*	function multiply2(a,b) takes two
	arguments of type float, multiplies a
	and b, and returns the result to
	the calling function */

float multiply2(float a, float b)
{
float c;

// multiply a with b
// and store the result in local variable c
  c = a * b;

// return value of c to calling function
  return c;
}
```
