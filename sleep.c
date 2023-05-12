#include <stdio.h>
#include <stdlib.h>

int main() {
    char ch;
    do {
        printf("Do you want to continue? (y/n) Do you want to sleep? (s)\n");
        scanf(" %c", &ch);
        if (ch == 's') {
            system("pmset sleepnow");
            printf("hey we want to sleep right now \n");
            printf("\n");
            printf("\n");
            printf("\n");            
        }
    } while (ch == 'y');

    printf("Exiting program...\n");

    return 0;
}
