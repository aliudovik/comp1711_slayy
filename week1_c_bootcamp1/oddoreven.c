#include <stdio.h>
    
    int main() {
        int i;
        int c;
        printf("Odd or Even\n");
        printf("Enter your integer:\n");
        scanf("%d", &i);
        c = i % 2;
        
        if (c == 0) {
            printf("Your number is even!");
        } else {
            printf("Your number is odd!\n");
        }
        return 0;
    }