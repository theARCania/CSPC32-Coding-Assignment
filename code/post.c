#include <stdlib.h>
#include <stdio.h>
#include "post.h"
#include <string.h>

Post* createPost(char* username, char* caption) {

  // username cannot contain spaces
  if (strrchr(username, ' ') != NULL) {
    perror("Post not created. Username must not contain spaces.");
    return NULL;
  }

  Post* newPost = (Post*) malloc(sizeof(Post));
  if (!newPost) {
    perror("Post not created. Memory allocation failed.");
    return NULL;
  }

  newPost->caption = caption;
  newPost->username = username;
  return newPost;
}



