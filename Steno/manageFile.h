#ifndef ST0830_O_S_PROJECT_MANAGEFILE_H
#define ST0830_O_S_PROJECT_MANAGEFILE_H
#include <stdio.h>
void createTXT(char *file_name);
void printTXT(char *file_name);

/**
 * This method get the length of file.
 * @param f as File.
 * @return the length.
 */
long getFileLength(FILE *f);

/**
 * This method set the offset of File .
 * @param f as File.
 */
void setFileOffset(FILE *f, long offset);

/**
 * This method reads the next byte if possible.
 * @param B as actual Byte.
 * @param f as File.
 * @return -1 if it can't read another byte because B is last.
 *         0 if it don't find an error.
 *         1 else.
 */
int readNextByte(byte *B, FILE *f);

/**
 * This method check error on file.
 * @param f as File to check.
 * @return 0 if it don't find an error.
 *         1 else.
 */
int fileErrorCheck(FILE *f);
#endif //ST0830_O_S_PROJECT_MANAGEFILE_H
