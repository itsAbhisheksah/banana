#include<stdio.h>
int main () {
int age;
printf("enter the age\n");
scanf("%d", &age);
{
    if(age>=18)
    {
        printf("you are elegible for vote");
    }
    else{
        printf("you are not elegible for vote");
    }
}
return 0;
}
