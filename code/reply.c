#include "reply.h"
#include <stdio.h>
#include <stdlib.h>


Reply* createReply(char* username, char* content) {
  Reply* reply = (Reply*) malloc(sizeof(Reply));
  if (reply == NULL) {
    perror("Memory allocation failed. Reply not created.");
    exit(0);
  }
  reply->content = content;
  reply->username = username;
  return reply;
}
