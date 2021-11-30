#include <stdio.h>
#include <time.h>
#include <unistd.h>

// Run a while loop for three seconds and print occasionally
int main (int argc, char *argv[]) {
	time_t current_time = time(NULL);
	time_t end_time = current_time + 3;

	while (current_time < end_time) {
		current_time = time(NULL);
		if (current_time % 40 == 0) {
			printf("printing to terminal ");
		}
	}

	return 0;
}
