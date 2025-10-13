#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  char *args[] = {"ls", "-l", NULL}; // "ls -l" command

  printf("Executing ls -l command...\n");

  execvp(args[0], args);

	printf("Liberty liberty liiiiberty liiiiiiiberty\n");
  perror("execvp failed");
  return 1;
}
