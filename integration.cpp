#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define maxNum 10
#define pi 3.1415926

int main()
{
    int i;
    double sumX = 0.0, sumO = 0.0, sumE = 0.0;

    double x[maxNum+ 1]={0.0, 0.2, 0.4, 0.6, 0.8, 1.0, 1.2, 1.4, 1.6, 1.8, 2.0};
    double y[maxNum + 1]={1.0, 1.04, 1.16, 1.36, 1.64, 2.0, 2.44, 2.96, 3.56, 4.24, 5.0};


    double h = x[1] - x[0];

    double trapInt, simpInt;

    sumX += (y[0] + y[maxNum]);

    for(i = 1;i < maxNum; i += 2)
        sumO += y[i];

    for(i = 2; i < maxNum; i += 2)
        sumE += y[i];

    trapInt  = h*(sumX + 2 * (sumE + sumO))/2.0;
    simpInt = h * (sumX + 4 * sumO + 2 * sumE)/3.0;

    printf("- - - - - - - - - - - - - - - - - - - -\n");
    printf("  Integration (Trap) = %lf\n",trapInt);
    printf("  Integration (Sim3) = %lf\n",simpInt);
    printf("- - - - - - - - - - - - - - - - - - - -\n");


    //to find integral value point by point.


    double integ[maxNum + 1], prefix[maxNum + 1];

    integ[0] = 0;
    prefix[0] = 0;

    for(i = 1; i <= maxNum; i++)
    {
        integ[i] = h*(y[i] + y[i-1])/2.0;
        prefix[i] = prefix[i- 1] + integ[i];
    }

    printf("--------------------------------------------\n");

    for(i = 0; i <= maxNum; i++)
        printf("X = %lf\t integ[%d] = %lf\t prefix[%d] = %lf\n",x[i],i,integ[i],i,prefix[i]);

    printf("---------------------------------------------\n");

    //This can be used to plot displacement from velocity values.
    // velocity can be measured with speed guns.
    //Now, do not ask me about the inner workings of speed guns.
    // I simply do not know.
  return EXIT_SUCCESS;
}
