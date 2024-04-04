#include<stdio.h>
int main()
{
    int a;
    printf("Enter the num\n");
    scanf("%d", &a);
    if(a%2==0)
    {
        printf("the num is even:");
    }
    else{
        printf("The num is odd");
    }
    return 0;

}
