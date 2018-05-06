#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>

/* Brandon Edwards <drraid@gmail.com>
 * to compile with Visual Studio Express:
 * cl.exe /GS- /MD hello.c
 * /GS- turns off stack cookies and other security features
 * /MD dynamically links against msvcrt.dll
 */

int main(int argc, char *argv[])
{
	unsigned int x;
	unsigned char y;

	signed char z;

	printf("\n Integer overflow:\n");
	
	/* set x to the maximum value! */
	x = 0xFFFFFFFF;
	printf(" x maximum value is: %u (%x)\n", x, x);	

	x += 1;
	printf(" adding +1 causes overflow: %u (%x)\n", x, x);

	/* x is now 0 */

	printf("\n Subtracting from minimum value wraps the bits back around..\n");
	printf(" x minimum value is: %u (%x)\n", x, x);

	/* for this example, let's subtract 10 from the minumum value */
	x -= 10;
	printf(" x - 10 = %u (%x)\n", x, x);
	
	
	printf("\n Datatype Truncation:\n");
	printf(" y is only 8-bits, but x is 32-bits\n");
	printf(" assigning y = x ...\n");
	y = x;
	printf(" y now is: %u\n", y);

	printf("\n Datatype Promotion\n");
	printf(" z is a signed char (8-bits)\n");
	printf(" assigning it with a value which sets it's signed bit to true:\n");
	z = 0xff;
	printf(" z = 0xff\n");
	printf(" now, if we assign x (32-bits) with the value of z (8-bits)...\n");
	x = z;
	printf(" a promotion happens, causing a sign-extension..\n");
	printf(" instead of x just becoming 0xff, x = %x\n", x);

	printf("\n\n");

	
	
	exit(0);
}
