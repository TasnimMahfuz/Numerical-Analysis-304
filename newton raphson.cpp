#include <stdio.h>
#include <stdlib.h>
#include  <math.h>

#define maxNum 256

#define F(x)   ((x)*(x)*(x) + 4*(x)*(x) - 10)//I do not know why all these extra brackets are here.
#define dF(x)  (3*(x)*(x) + 8 * (x))

int main(void)
{
    double x1 = 1.5, x2, tol = 10.0e-6;//I need clarification on tolerance.

    double fx1, fx2, dfx1;

    fx1 = F(x1);
    dfx1 = dF(x1);

    for(int i = 0; i <= 22; i++)
        printf("- ");
    printf("\n");

    printf("Iter\tx0\tx1\tf(x0)\tf'(x0)\tf(x1)\n");

    for(int i = 0; i <= 22; i++)
        printf("- ");

    printf("\n\n");

    for(int i = 1; i <= maxNum; i++)
    {
        x2 = x1 - fx1/dfx1;
        fx2 = F(x2);
        printf("%d\t%lf\t%lf\t%lf\t%lf\t%lf\n",i,x1,x2,fx1,dfx1,fx2);
        if(fabs(fx2) <= tol)
        {
            printf("\n\nRoot = %lf\t|| Number of iterations = %d\n",x2,i);

            for(int i = 0; i <= 22; i++)
                printf("- ");

            return EXIT_SUCCESS;
        }

        x1 = x2;
        fx1 = fx2;
        dfx1 = dF(x2);
    }

    printf("Iteration overflow happened!!!\n");
    return EXIT_FAILURE;
}
