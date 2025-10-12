#include "platform.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

Platform* platform;

void createPlatform() {
  platform = (Platform*) malloc(sizeof(Platform));
  if (platform == NULL) {
    perror("Memory allocation failed during platform creation.");
    exit(0);
  }
  platform->lastViewedPost = NULL;
  platform->postList = NULL;
}


bool addPost(char* username, char* caption) {
  bool posted = 0;

  

  return posted;
}





