/* by Gerard Renardel and Malvin Gattinger */

#ifndef LIBQUEUE_H
#define LIBQUEUE_H

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef struct Queue {
  int *array;
  int back;
  int front;
  int size;
} Queue;

Queue newQueue(int s);
int isEmptyQueue(Queue q);
void queueEmptyError();
void doubleQueueSize(Queue *qp);
void enqueue(int item, Queue *qp);
int dequeue(Queue *qp);
void freeQueue(Queue q);

#endif
