
#include<stdio.h>
int main()
{
    int num;
    printf("Enter the num\n");
    scanf("%d", &num);
    printf("Multiplication table of %d is \n", num);
    for(int i = 1; i < 11; i++) {
        printf("%d X %d = %d\n", num, i, num*i);
    }
    return 0;
}
