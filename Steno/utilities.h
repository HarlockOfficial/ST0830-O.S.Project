#ifndef OSPROJECT_UTILITIES_H
#define OSPROJECT_UTILITIES_H
#include <stdio.h>
#include "constants.h"
#include "list.h"

/**
 * This method check the extension of file passed by param.
 * @param string
 *                  the name of file to check.
 * @return  1 - ".txt"
 *          0 - other file
 *         -1 - ".bmp"
 */
int extensionFileCheck(char string[MAX_LENGTH_STRING]);

/**
 * This method take in input a file name to return.
 * @return
 *          a file name;
 */
char *inputNameFile(int state);

/**
 * This method bring in input the element of List
 * @param l in/out param used to pass and retrieve the list's head node
 */
void insertByInput(int isHiding, Node** l);

//    /**
//    * This method split a string.
//    * @param string
//    *                  the name of file to check.
//    * @return
//    *                  firstElement on the list
//    */
//    Node* split(char str[]);

//    /**
//    * This method count token in a string .
//    * @param string
//    *                   for the count token.
//    * @return
//    *                  count of token in this string.
//    */
//    int getNumberToken(char str[]);

#endif //OSPROJECT_UTILITIES_H
