#include <wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <time.h>
#include <math.h>

int main(){
  printf("_%d_ about to create 2 child processes.\n",getpid());
  pid_t p;
  p = fork();
  if(p<0){
    perror("fork fail");//output to stderr instead of stdout
    exit(1);
  } else if ( p == 0){
    srand(time(NULL));
    int rando = rand();
    rando = 1+5*floor(rando/2147483647);
    int myPid = getpid();
    printf("PID: %d %d\n", myPid,rando);
    sleep(rando);
    printf("%d FINISHED after %d sec\n",myPid,rando);
  }else{
      pid_t p2;
      p2 = fork();
      if(p2<0){
        perror("fork fail");//output to stderr instead of stdout
        exit(1);
      } else if ( p2 == 0){
        srand(time(NULL)+1);
        int rando = rand();
        rando = 1+5*floor(rando/2147483647);
        int myPid = getpid();
        printf("PID: %d %d\n", myPid,rando);
        sleep(rando);
        printf("%d FINISHED after %d sec\n",myPid,rando);
      }else{
          int* status;
          pid_t deadchild;
          deadchild = wait(&status);
          srand(time(NULL));
          int rando;
          rando = rand();
          rando = 1+5*floor(rando/2147483647);
          printf("Main Process %d is done. Child %d slept for %d sec.",getpid(),deadchild,rando);
      }
  }

  return 0;
}
