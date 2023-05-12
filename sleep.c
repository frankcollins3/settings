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
        if (ch == 'l') {
            printf("logout");
            // system("logout");        // .run() => returns error: sh: line 0: logout: not login shell: use `exit'
            system("osascript -e 'tell application \"loginwindow\" to  «event aevtrlgo»'");
        }
    } while (ch == 'y');

    printf("Exiting program...\n");

    return 0;
}
