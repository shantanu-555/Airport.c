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
  scanf("%d",&n);
  
  int* planeID;
  char* needsRepairs[4];

  Queue Runway = newQueue(maxRunway);
  Stack Hangar = newStack(maxHangar);

  for (int i=0; i<n; i++) {
    scanf("%d %s", &planeID, &needsRepairs);
    if (*needsRepairs = "no") {
      enqueue (planeID, &Runway);
    }
    else {
      push(planeID, &Hangar);
    }
  }

  return 0;
}
