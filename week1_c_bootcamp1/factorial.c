#include <stdio.h>
    
    int main() {
        int i = 1;
        int a;
        int b = 1;
        printf("ur int");
        scanf("%d", &a);

        while (i < (a+1)){
            b = b * i;
            i++;
        }

        printf("%d", b);
        return 0;
    }