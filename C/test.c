#include <stdio.h>

int main()
{
    int a[11];
    for (int i = 0; i < 16; i++)
        // a[i] = i * 100 + i + 10;
        a[i] = 0;
    for (int i = 0; i < 16; i++)
        printf("%d  --%d\n", a[i], i+1);
    printf("size is : %d", sizeof(a) / sizeof(int));

    return 0;
}
