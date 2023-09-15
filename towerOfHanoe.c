#include <stdio.h>
#include <conio.h>

void towerOfHanoi(char from, char to, char other, int n)
{
    if (n <= 0)
        printf("\nILLEGAL NUMBER OF DISKS");
    if (n == 1)
        printf("\nMOVE DISK FROM %c TO %c", from, other);
    if (n > 1)
    {
        towerOfHanoi(from, other, to, n - 1);
        towerOfHanoi(from, to, other, 1);
        towerOfHanoi(to, from, other, n - 1);
    }
}
int main()
{
    int num;

    printf("\nENTER NUMBER OF DISKS: ");
    scanf("%d", &num);
    printf("\nTOWER OF HANOI FOR %d NUMBER OF DISKS:\n", num);
    towerOfHanoi('A', 'B', 'C', num);
    return 0;
}
