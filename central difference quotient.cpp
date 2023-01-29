#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define maxNum 100
#define F(x) sin(x)
//#define F(x)      ( (x)*(x) + 1 )

int main(void)
{
    double a = 0.0, b = 6.3, h;

    h = (b - a)/maxNum;

    double x[maxNum + 1], f[maxNum + 1], df[maxNum + 1];

    for(int i = 0; i <= maxNum ; i++){
        x[i] = h*i + a;
        f[i] = F(x[i]);
    }

    df[0] = (f[1] - f[0])/h;
    df[maxNum] = (f[maxNum] - f[maxNum - 1])/h;

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

