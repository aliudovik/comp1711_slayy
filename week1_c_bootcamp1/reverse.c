#include <stdio.h>
#include
    
    int main() {
        char word[20];
        printf("Enter your word:\n");
        scanf("%s", word);
        printf("%zu\n", strlen(word));
        return 0;
    }