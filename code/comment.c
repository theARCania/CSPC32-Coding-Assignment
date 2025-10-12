#include "comment.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Comment* createComment(char* username, char* content) {
  Comment* newComment = (Comment*) malloc(sizeof(Comment));
  if (newComment == NULL) {
    perror("Comment not created. Memory allocation failed.");
    exit(0);
  }
  newComment->content = content;
  newComment->username = username;
  return newComment;
}
