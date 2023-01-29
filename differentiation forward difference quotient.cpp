#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define maxNum 100
#define pi 3.1415926
#define F(x)      ( (x)*(x) + 1 )
int main()
{

    //how do I plot these points in c?
    // I remember I have done this in python in some distant past and it was so satisfying!
    //So, I want these points come alive at some point.

    int i;
    double a = 0.0, b = 2.0, h;

    h = (b - a)/maxNum;

    double x[maxNum + 1], f[maxNum + 1], df[maxNum + 1];

    x[0] = a;

    for(i = 1; i < maxNum; i++)
        x[i] = x[i - 1] + h;

    x[maxNum] = b;

    //okay, so I have maxNum number of blocks with width h.
    //maxNum + 1 number of points mark these boxes.

    for(i = 0; i <= maxNum; i++)
        f[i] = F(x[i]);


    df[0] = (f[1] - f[0])/(x[1] - x[0]);

    for(i = 1; i < maxNum; i++)
        df[i] = (f[i + 1] - f[i])/(h);

    //In the last point, this needs to be handled differently.

    df[maxNum] = (f[maxNum] - f[maxNum - 1])/h;

    printf("- - - - - - - - - - - - - - - - - - - -\n");
    printf("  i    x[i]       f[i]       df[i]\n");
    printf("- - - - - - - - - - - - - - - - - - - -\n");

    for (i=0; i< maxNum; i++)
        printf("%3d \t %10lf \t %10lf \t %10lf\n",i,x[i],f[i],df[i] );

    printf("%3d \t %10lf \t %10lf \t   invalid\n",maxNum,x[maxNum],f[maxNum]);
    printf("- - - - - - - - - - - - - - - - - - - -\n");


    return EXIT_SUCCESS;
}
