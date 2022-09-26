/* by Gerard Renardel and Malvin Gattinger */

#ifndef LIBSTACK_H
#define LIBSTACK_H

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef struct Stack {
  int *array;
  int top;
  int size;
} Stack;

Stack newStack(int s);

void push(int value, Stack *stp);
int pop(Stack *stp);

void doubleStackSize(Stack *stp);
int isEmptyStack(Stack st);
void stackEmptyError();
void freeStack(Stack st);

#endif
