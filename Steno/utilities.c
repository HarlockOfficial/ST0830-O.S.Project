#include <string.h>
#include "utilities.h"

int extensionFileCheck(char string[MAX_LENGTH_STRING]) {
    //TODO fix: questo software è solo per windows o generico?
    // se è generico, non è necessaria la presenza di una estensione,
    // linux non la richiede e il tipo di file viene deciso da una analisi fatta dal os e non dalla sua estensione
    //Una stringa con meno di cinque caratteri sicuramente non contiene il nome con l'estensione inclusa
    if (strlen(string) >= 5) {
        const char *extension = &string[strlen(string) - 4];
        //TODO fix: dovreste usare un case insensitive strcmp (una estensione .tXt dovrebbe essere accettata secondo me)
        if (strcmp(extension, ".txt") == 0 || strcmp(extension, ".TXT") == 0)
            return 1;
        //TODO fix: same as before, case insensitive strcmp secondo me necessario
        else if (strcmp(extension, ".bmp") == 0 || strcmp(extension, ".BMP") == 0)
            return -1;
    }
    return 0;
}

char *inputNameFile(int state) {
    static char file_name[MAX_LENGTH_STRING];
    do {
        printf("\t!Attention!\nYou must enter the extension at the end of name's file.\n");
        printf("Name's file:\t");

        fflush(stdin);
        scanf("%s", file_name);

        if (extensionFileCheck(file_name) == state)
            return file_name;
        else if (state == 1)
            perror("\nIt's not txt file.\n");
        else if (state == -1)
            perror("\nIt's not bmp file.\n");
        else
            perror("\nThe extension file it's not accepted.\n");
    } while (1);
}

//TODO fix: pure qua passerei il Node* come parametro e non come return type,
// ritornare un valore che viene inizializzato dentro la funz mi puzza di morte
void insertByInput(int isHiding, Node **list) {
    char name_file_txt[MAX_LENGTH_STRING] = "";
    char name_file_bmp[MAX_LENGTH_STRING];

    int number_of_file;
    do {
        //TODO fix: no need del limite a 10
        printf("How many File? MAX 10\n");
        fflush(stdin);
        scanf("%d", &number_of_file);
    } while (number_of_file <= 0 || number_of_file > 10);

    for (int i = 0; i < number_of_file; i++) {
        if (isHiding == 1) {
            printf("\tInsert the .txt file.\n");
            strcpy(name_file_txt, inputNameFile(1));
        }
        printf("\tInsert the .bmp file.\n");
        strcpy(name_file_bmp, inputNameFile(-1));
        //TODO fix: non mi spiego perchè la funzione debba tornare ogni volta l'ultimo elemento della linked list,
        // per aggiornare il valore della var list, prova a usare i puntatori (&list) in effetti ti crea una variabile di output
        insert(list, name_file_txt, name_file_bmp);
    }
}