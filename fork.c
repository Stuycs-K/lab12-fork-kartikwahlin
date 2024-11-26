#include <wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <time.h>
#include <math.h>

int main(){
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
    printf("%d FINISHED\n",myPid);
  }else{
      printf("Hello from Parent!\n");
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
        printf("%d FINISHED\n",myPid);
      }else{
          printf("Hello from Parent2!\n");
      }
  }

  return 0;
}
