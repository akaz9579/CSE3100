#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  pid_t pid;
  int status;
  pid = fork();
  if (pid == -1) {
    printf("can't fork, error occurred\n");
    exit(EXIT_FAILURE);
  } else if (pid == 0) {
    printf("In child\n");
    int *a=NULL;
    a[25] = 1;
    printf("%d\n",a[25]);
    /* int b = a[25]; */
    /* free(a); */
    /* free(a); */
  } else {
    /* int status */
    wait(NULL);
    printf("parent process, pid = %u\n", getppid());
  }
  return 0;
}
