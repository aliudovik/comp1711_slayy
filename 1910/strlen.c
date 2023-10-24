#include <stdio.h>

char str[100];
char a[100];
int i;

int str_len(a) {
    for(i=0; str[i]!='\0'; i++);
       return i;
}

int main()
{
    printf("Enter a string: \n");
    scanf("%s",str);
    printf("String length: %d\n", str_len(str));
    return 0;
}

