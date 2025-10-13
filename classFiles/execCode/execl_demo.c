#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  char *cmd1 = "./adder";
  pid_t child = fork();
  if (child == 0) {
    printf("In child!\n");
    execl(cmd1, cmd1, "1", "2", "3", "10", NULL);
		printf("Done with adder\n");
    return -1;
  } else {
    wait(NULL);
		printf("In parent\n");

  }

  return 0;
}
