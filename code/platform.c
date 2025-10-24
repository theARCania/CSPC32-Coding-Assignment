#include "platform.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define MAX_SIZE_STACK 1000

Platform* platform;

struct PostStack {
  int top;
  Post* stack[MAX_SIZE_STACK];
};
typedef struct PostStack PostStack;

PostStack* poststack;

PostStack* createStack() {
  if (poststack != NULL) return poststack;

  poststack = (PostStack*) malloc(sizeof(PostStack));
  if (poststack == NULL) {
    perror("Memory allocation failed during stack creation.");
    exit(0);
  }
  poststack->top = -1;
  return poststack;
}

bool pushPost(Post* post) {
  if (poststack->top == MAX_SIZE_STACK-1) {
    printf("Post-stack full. Cannot post.");
    return false;
  }
  poststack->stack[++poststack->top] = post;
  return true;
}


Platform* createPlatform() {
  if (platform != NULL) return platform;
  // return variable directly
  // to avoid multiple instantiation

  platform = (Platform*) malloc(sizeof(Platform));
  if (platform == NULL) {
    perror("Memory allocation failed during platform creation.");
    exit(0);
  }
  platform->lastViewedPost = NULL;
  platform->postList = NULL;
  return platform;
}


bool addPost(char* username, char* caption) {
  bool posted = false;
  Post* newPost = createPost(username, caption);
  if (newPost == NULL) posted = false;
  else posted = true;

  if (!posted) return posted;
  else {
    if (pushPost(newPost) == false) posted = false;
    else posted = true;
    return posted;
  }
}

bool stackDeletionAdjust(int n) {
  int top = poststack->top;
  for (int i = top - n; i < top; i++) {
    poststack->stack[i] = poststack->stack[i+1];
  }
  poststack->stack[top] = NULL;
  return true; // keeping a bool return value was needed
  // to maintain code modularity and regularity.
}


bool deletePost(int n) {
  // 0th indexing on n is assumed here.
  if (stackDeletionAdjust(n)) return true;
  else return false;
}

Post* viewPost(int n) {
  if (poststack->stack[poststack->top]) {

  }
}


