#include <stdio.h>

int main()
{
    double buff, data = 0.0;
    int i;

    for (i =0 ; i < 12; i++) {
        scanf("%lf", &buff);
        data += buff;
    }

    data /= 12.0;

    data = (double)((int)((data * 100) + 0.5))/100;

    printf("$%.2lf\n",data);

	return 0;
}
