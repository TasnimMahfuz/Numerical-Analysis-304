#include <stdio.h>
#include <stdlib.h>
#include  <math.h>

#define maxNum 256

#define F(x)   ((x)*(x)*(x) + 4*(x)*(x) - 10)//I do not know why all these extra brackets are here.
#define dF(x)  (3*(x)*(x) + 8 * (x))

int main(void)
{
    double x0 = 2.0, x1 = 1.5, x2, tol = 10e-6;
    double fx0, fx1,fx2;

    //to experiment.
    x0 = .2;
    x1 = 100.63;

    /*
    from this experimenting, I found that [x0,x1] can contain the root,
    or the root can be either in the left side of x0 or right side of x1. In all
    three cases, the algorithm will get to the correct root eventually.

    But in the case of false position method, the root must situate between [a,b]

    Here, a and b are indicating a range.
    x0,x1 however does not indicate any range. These two points are taken for calculating derivative.

    secant method, thus, is more flexible for finding roots.
    */

    int iterationVariable = 1;

    fx0 = F(x0);
    fx1 = F(x1);

    for(int i = 0; i <= 22; i++)
        printf("- ");
    printf("\n");

    printf("Iter\tx0\tx1\tx2\tf(x0)\tf(x1)\tf(x2)\n");

    for(int i = 0; i <= 22; i++)
        printf("- ");

    printf("\n\n");

    for( ; iterationVariable <= maxNum; iterationVariable++)
    {
        x2 = x1 - fx1*(x1- x0)/(fx1 - fx0);
        fx2 = F(x2);

        printf("%d\t%lf\t%lf\t%lf\t%lf\t%lf\t%lf\n",iterationVariable,x0,x1,x2,fx0,fx1,fx2);

        if(fabs(fx2)<= tol)
        {
            printf("Number of iterations: %d\t|| Approximate Root = %lf\n",iterationVariable,x2);

            for(int i = 0; i <= 22; i++)
                printf("- ");

            printf("\n\n");

            return EXIT_SUCCESS;
        }

        x0 = x1;
        x1 = x2;
        fx0 = fx1;
        fx1 = fx2;
    }

    printf("Iteration overflow happened! :(\n");
    return EXIT_FAILURE;
}

