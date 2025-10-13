#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int p = 10;

int main() {
  int b = 11;
  printf("Before fork %d\n", getpid());
  int pid = fork();
  if (pid == 0) {
    printf("in Child %d p=%d,b = %d\n", getpid(), p, b);
    b++;
  } else {
		int status;
		wait(&status);
    printf("in Parent %d p=%d,b = %d\n", getpid(), p, b);
    p++;
  }
  return 0;
}
