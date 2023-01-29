//This program is very similar to the secant method!
//There must be some slight dissimilarity. I need to think about that.


#include <stdio.h>
#include <stdlib.h>
#include  <math.h>

#define maxNum 256

#define F(x)   ((x)*(x)*(x) + 4*(x)*(x) - 10)//I do not know why all these extra brackets are here.
#define dF(x)  (3*(x)*(x) + 8 * (x))

int main(void)
{
   int itrVar = 1;
   double a = 1.25, b = 1.5, tol = 10.0e-6;
   double c, fa, fb, fc;

   fa = F(a); fb =F(b);

   for(int i = 0; i <= 22; i++)
        printf("- ");
    printf("\n");

    printf("Iter\ta\tb\tc\tf(a)\tf(b)\tf(c)\n");

    for(int i = 0; i <= 22; i++)
        printf("- ");

    printf("\n\n");

   if(fa *fb > 0)
   {
       printf("Ehhe, no root in x belonging to [%lf,%lf],sorry!\n",a,b);
       return EXIT_FAILURE;
   }

   for( ; itrVar <= maxNum; itrVar++)
   {
       //c = a + (b - a)/2.0;

       c = b - fb *(b-a)/(fb - fa);

       fc = F(c);

        printf("%d\t%lf\t%lf\t%lf\t%lf\t%lf \t%lf\n",itrVar,a,b,c,fa,fb,fc);

       if(fabs(fc) <= tol)
       {
           printf("\n\nNumber of iteration:%d\t|| Approximate Root: %lf\n",itrVar,c);

           for(int i = 0; i <= 22; i++)
                printf("- ");
           return EXIT_SUCCESS;

       }else if(fa*fc < 0)
       {
           b = c;
           fb = fc;
       }else
       {
           a = c;
           fa = fc;
       }

   }
   printf("Iteration overflow happened, sorry!\n");
   return EXIT_FAILURE;
}



