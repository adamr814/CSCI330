/************************************************************************
CSCI 330
FALL 2022
PROGRAM : HW1 (Calculating interest)
AUTHOR  : Adam Roy
*************************************************************************
DESCRIPTION OF VARIABLES:
r     | Anual interest rate        | Assume 0.22
B     | Amount borrowed            | Assume $5000
P     | Payment amount             | Assume $500/mo
I[o]  | Interest after first month | Formula: I[o] = (r/12)*B
I[n]  | Interest after nth month   | Formula: I[n] = (r/12)*(B-P+I[n-1])
total | Total interest collected   |
month | Data placeholder for month |
*************************************************************************/

/* Preprocessor directives */
#include <stdio.h>
#include <stdlib.h>

/* Main function */
int main(void)
{
	/* Declare variables */
	float B, r, P, total = 0, interest = 1;
	int month = 1, i;

	/* Get input data from user */
	printf("Enter Borrowed Amount  >  ");
	scanf("%f", &B);
	printf("\nEnter Interest Rate    >  ");
	scanf("%f", &r);
	printf("\nEnter Monthly Payment  >  ");
	scanf("%f", &P);

	/* Calculations and data printing */
	printf("\n\nMonth | Interest | Remaining Balance\n");
	for (i = 1; i < 1000; i++) {
		if (B < 0) {
			break;
		}
		interest = (r/12) * B;
		printf("  %2d", month);
		printf("      %4.2f ", interest);
		printf("        %6.2f\n", B);
		total += interest;
		month ++;
		B = B - P + interest;
	}
	printf("\nTotal Interest Paid  >  $%.2f\n\n", total);
	return 0;
}
