#include <stdio.h>
#include <stdlib.h>
#include  <math.h>

#define maxNum 256

#define F(x)   ((x)*(x)*(x) + 4*(x)*(x) - 10)//I do not know why all these extra brackets.
#define dF(x)  (3*(x)*(x) + 8 * (x))

int main(void)
{
    double x1 = 1.5, x2, tol = 10.0e-6;//I need clarification on tolerance.

    double fx1, fx2, dfx1;

    fx1 = F(x1);
    dfx1 = dF(x1);

    for(int i = 1; i <= maxNum; i++)
    {
        x2 = x1 - fx1/dfx1;
        fx2 = F(x2);

        if(fabs(fx2) <= tol)
        {
            printf("Root = %lf, Itr = %d\n",x2,i);
            return EXIT_SUCCESS;
        }

        x1 = x2;
        fx1 = fx2;
        dfx1 = dF(x2);
    }

    printf("Iteration overflow happened!!!\n");
    return EXIT_FAILURE;
}
