#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 512

// Run a while loop for ten seconds and print occasionally
int main (int argc, char *argv[]) {
  printf("Type 'exit' to quit program\n");
	for (;;) {
    printf("Enter a word: ");

    char input[MAX_INPUT];
    if (strcmp(fgets(input, MAX_INPUT, stdin), "exit\n") == 0){
      exit(0);
    }
    else {
      printf("You entered: %s", input);
    }

  }

	return 0;
}
