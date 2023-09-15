#include <stdio.h>

int fibo(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else if (n == 1 || n == 2)
    {
        return 1;
    }
    else
    {
        return fibo(n - 1) + fibo(n - 2);
    }
}
int main()
{
    int n;
    printf("Enter the number of fibonacci series to find out:");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", fibo(i));
    }
    return 0;
}