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
  char *needsrepairs;
  int hangarcount = 0;
  int runwaycount = 0;

  Queue Runway = newQueue(maxRunway);
  Stack Hangar = newStack(maxHangar);

  printf("Asking for planes\n"); //remove this later
  for (int i = 0; i < n; i++) {
    scanf("%d, %s\n", &planeID, needsrepairs);
    if (strcmp(needsrepairs, "yes") == 0) { //Moving planes into Hangar
      push (planeID, &Hangar);
      hangarcount++;
      if (hangarcount == maxHangar) { //When hangar is full
        printf("Ready for takeoff!\n");
        for (i = 0; i < runwaycount; i++) { //Clearing Runway
          dequeue (&Runway);
        } 
        for (i = 0; i < maxHangar; i++) { //Moving planes from Hangar to Runway
          enqueue (pop (&Hangar), &Runway);
        }
      }
    }
    else {                            //Moving planes into Runway
      enqueue (planeID, &Runway);
      runwaycount++;
      if (runwaycount == maxRunway) { //Clearing runway when runway is full
        printf("Ready for takeoff!\n");
        for (i = 0; i < runwaycount; i++) {
          dequeue (&Runway);    
        }
      }
    }
  }

  return 0;

}
