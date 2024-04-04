#include<stdio.h>

int main()
{
    int marks[2][4]={{2,5,8,9},
                      {7,1,6,9}};

    for(int i =0; i< 2;i++)
    {
        for(int j = 0; j< 4; j++)
        {
            printf("%d ",marks[i][j]);

        }
        printf("\n");
    }
    return 0;
}
