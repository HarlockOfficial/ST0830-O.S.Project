#include <stdio.h>
#include <stdlib.h>
#include "commandList.h"
#include "utilities.h"
#include "manageFile.h"

int main(void) {
    int choice = 0;
    Node *l = NULL;
    do {
        help();
        fflush(stdin);
        scanf("%d", &choice);
        system("clear||cls");
        switch (choice) {
            case 1:
                currentPath();
                PAUSE
            case 2:
                showContent();
                PAUSE
            case 3:
                changeDirectory();
                PAUSE
            case 4:
                createTXT(inputNameFile(1));
                PAUSE
            case 5:
                printTXT(inputNameFile(1));
                PAUSE
            case 6:
                insertByInput(1, &l);
                executeHiding(l);
                PAUSE
            case 7:
                insertByInput(-1, &l);
                executeUnveiling(l);
                PAUSE
            case 0:
                printf("Thanks");
                break;
            default:
                perror("Command not found.\n");
                PAUSE
        }
    } while (choice != 0);
    return 0;
}
