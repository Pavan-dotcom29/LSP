//write a program to demonstrate concept I/O direction.

#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
    int iNo1 = 0, iNo2 = 0;
    int iAns = 0;

    scanf("%d",&iNo1);
    scanf("%d",&iNo2);

    iAns = iNo1 + iNo2;

    printf("Addition is : %d\n",iAns);

    return 0;
	
}
