#include<stdio.h>
int main() {
int num;
printf("Enter a no less than 10\n");
scanf("%d", &num);
if(num <= 10) {
    printf("no is less than 10");

}
else{
    printf("no is greater than 10");
}
return 0;
}
