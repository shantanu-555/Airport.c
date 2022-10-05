#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "libs/LibStack.h"
#include "libs/LibQueue.h"

//some global constants
const int maxHangar = 5;
const int maxRunway = 7; 

//Function to clear Runway
int clearRunway(int rcount, Queue* runway) { 
  printf("Ready for takeoff!\n");  
  for (int i=1; i<=rcount; i++) { 
    printf("%d\n", dequeue(runway));
  }
  return 0;
}

//Function to clear Hangar
int clearHangar(int hcount, Stack* hangar, int rcount, Queue* runway) {
  for (int i=1; i<=hcount; i++) { //Moving planes from Hangar to Runway
    enqueue (pop (hangar), runway);
    rcount++;
  }
  return rcount;
}

int main(int argc, char *argv[]) {
  int n; // number of planes to read
  scanf("%d\n",&n);

  Queue Runway = newQueue(maxRunway);
  Stack Hangar = newStack(maxHangar);

  int planeID;
  char needsrepairs[4];
  
  int hangarcount = 0;
  int runwaycount = 0;

  for (int i=1; i<=n; i++) {
    scanf("%d %s", &planeID, needsrepairs);

    if (strcmp(needsrepairs, "yes") == 0) { //Moving planes into Hangar
      push (planeID, &Hangar);
      hangarcount++;
      if (hangarcount == maxHangar) { //When hangar is full 
        if (runwaycount>0) {
          clearRunway(runwaycount, &Runway); //Clearing Runway
          runwaycount = 0;
        }
        runwaycount = clearHangar(hangarcount, &Hangar, runwaycount, &Runway); //Clearing Hangar
        hangarcount = 0;
      }
    }
    if (strcmp(needsrepairs, "no") == 0) { //Moving planes into Runway
      enqueue (planeID, &Runway);
      runwaycount++;
      if (runwaycount == maxRunway) { //When runway is full
        clearRunway(runwaycount, &Runway); //Clearing Runway
        runwaycount = 0;
      }
    }
  }

  //Clearing leftover planes

  if (hangarcount>0) { //If there are planes in the Hangar
    if (runwaycount>0) {
      clearRunway(runwaycount, &Runway); //Clearing Runway
      runwaycount = 0;
    }
    runwaycount = clearHangar(hangarcount, &Hangar, runwaycount, &Runway); //Clearing Hangar
    hangarcount = 0;
  }

  if (runwaycount>0) { //If there are planes in the Runway
    clearRunway(runwaycount, &Runway); //Clearing Runway
    runwaycount = 0;
  }

  freeQueue(Runway);
  freeStack(Hangar);

  return 0;
}
