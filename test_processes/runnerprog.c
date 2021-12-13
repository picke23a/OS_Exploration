#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"


/*
Authors: Anna Picket and Emily Gitlin
Date: 12/12/21

Runnerprog is a program that can run multiple programs concurrently, 
and is able wait on those programs to finish. 

One goal for the program in the future is to be able to use it
to record important events in the steps of running a process to calculate 
the Average Turnaround Time, and Average Response Time.

*/
int main(int argc, char * argv[]) {
  //Set up super basic fork and exec

  int n, pid;
  int numProgs = 6;
  //progs is a list of processes to run. 
  //All processes must be accessable from a given filepath. 
  //Still bugs with using ioheavyprocess. 
  char progs[6][16] = {
    "longprocess",
    "shortprocess",
    "longprocess",
    "shortprocess",
    "longprocess",
    "shortprocess",
  };
  
  //cycle through all the programs we want to fork and exec. 
  for(n = 0; n < numProgs; n++){
    //One potential place where we could measure a process 
    //being added to the process queue is when it is forked. Is this the right place?
    //How long after executing the following line will it take for the 
    //process to actually get added to the queue?
    printf(1, "#forking p:%d at %d#\n",n, gettime());
    pid = fork();
    
    if (pid == 0){
      char* empty[1];
      empty[0] = 0; //defining the arguments for exec
      printf(1, "Running %s (from runnerprog)\n", progs[n]);
      int ret = exec(progs[n], &empty[0]);
      printf(1, "Done trying to run program, ret = %d\n", ret);
      exit();

    }

    //if the pid that fork returned is greater than 0, 
    //we know the process is the parent, and should thus be 
    //waiting for its forked children. It will wait for any of its children,
    //so the order that they finish doesn't matter. 
    else if (pid > 0){
      printf(1, "I am parent %d\n", n);
      continue;
    }

  }
  //trying to wait for each program to finish
  for(n = 0; n < numProgs; n++){
    wait();
  }

  printf(1, "now exiting runnerprog");
  exit();
  return 1;
}
