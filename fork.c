#include <wait.h>
#include <unistd.h>

int main(){


  int f1= fork();
  int f2 = fork();
  printf("%d",f1);
  printf("%d",f2);
}
