#include <stdlib.h>
#include <stdio.h>
#include "post.h"
#include <string.h>

Post* createPost(char* username, char* caption) {

  // username cannot contain spaces
  if (strrchr(username, ' ') != NULL) {
    perror("Post not created. Username must not contain spaces.");
    exit(1);
  }

  Post* newPost = (Post*) malloc(sizeof(Post));
  if (!newPost) {
    perror("Post not created. Memory allocation failed.");
    exit(0);
  }

  newPost->caption = caption;
  newPost->username = username;
  return newPost;
}



