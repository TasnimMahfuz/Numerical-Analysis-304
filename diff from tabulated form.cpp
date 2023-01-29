#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define maxNum 10

int main()
{
    double x[maxNum + 1] = {0.0, 0.2, 0.4, 0.6, 0.8, 1.0, 1.2,1.4, 1.6, 1.8,2.0};

    double f[maxNum + 1] = {1.0,1.04,1.16,1.36,1.64, 2.0, 2.44, 2.96, 3.56, 4.24, 5.0};

    double df[maxNum + 1];

    double h = x[1] - x[0];

    for(int i = 1;  i < maxNum;i++)
        df[i] = (f[i+ 1] - f[i - 1])/(2*h);

    printf("- - - - - - - - - - - - - - - - - - - -\n");
    printf("  i    x[i]       f[i]       df[i]\n");
    printf("- - - - - - - - - - - - - - - - - - - -\n");

    printf("%3d \t %10lf \t %10lf \t   invalid\n",0,x[0],f[0]);
    for (int i=0 +1 ; i<= maxNum - 1; i++)
        printf("%3d \t %10lf \t %10lf \t %10lf\n",i,x[i],f[i],df[i] );

    printf("%3d \t %10lf \t %10lf \t   invalid\n",maxNum,x[maxNum],f[maxNum]);
    printf("- - - - - - - - - - - - - - - - - - - -\n");


    return EXIT_SUCCESS;

}
