#include "implementationThread.h"
#include "stenography.h"
#include <pthread.h>

pthread_t threadId[10];
int i = 0;

void createThreadHiding(void* list){
    pthread_create(&threadId[i], NULL, hiding,  list);
    i++;
}

void createThreadUnveiling(void* list){
    pthread_create(&threadId[i], NULL,  unveiling,  list);
    i++;
}