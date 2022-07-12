
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>  //Header file for sleep(). man 3 sleep for details.
#include <pthread.h>
 
// A normal C function that is executed as a thread
// when its name is specified in pthread_create()
void *myThreadFun(void *vargp)
{
    sleep(1);
    printf("Printing GeeksQuiz from Thread \n");
    return NULL;
}
  
int main()
{
    pthread_t t1;
    printf("Before Thread\n");
    pthread_create(&t1, NULL, myThreadFun, NULL);
    pthread_join(t1, NULL);
    printf("After Thread\n");
    exit(0);
}