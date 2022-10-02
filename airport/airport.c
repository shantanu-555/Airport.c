#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "libs/LibStack.h"
#include "libs/LibQueue.h"

// some global constants
const int maxHangar = 5;
const int maxRunway = 7;


int main(int argc, char *argv[]) {
  int n; // number of planes to read
  printf("Asking for n\n"); //remove this later
  scanf("%d",&n);
  
  int planeID;
  char *needsrepairs[4];
  int hangarcheck = 0;
  int runwaycheck = 0;

  Queue Runway = newQueue(maxRunway);
  Stack Hangar = newStack(maxHangar);

  printf("Asking for planes\n"); //remove this later
  for (int i = 0; i < n; i++) {
    scanf("%d, %s\n", &planeID, &needsrepairs);
    if (strcmp(needsrepairs, "yes") == 0) { //Moving planes into Hangar
      push (planeID, &Hangar);
      hangarcheck++;
    }
    if (strcmp(needsrepairs, "no") == 0) {//Moving planes into Runway
      enqueue (planeID, &Runway);
      runwaycheck++;
    }
  }

  return 0;
}
