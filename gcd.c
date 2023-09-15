#include <stdio.h>

int gcd(int a, int b)
{
    if (a % b == 0)
    {
        return b;
    }
    else
    {
        return gcd(b % a, a);
    }
}

int main()
{
    int a, b;
    printf("Enter any two numbers to find the gcd of: ");
    scanf("%d %d", &a, &b);
    printf("The gcd of %d and %d is %d", a, b, gcd(a, b));

    return 0;
}