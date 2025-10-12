#include "reply.h"
#include <stdlib.h>


Reply* createReply(char* username, char* content) {
  Reply* reply = (Reply*) malloc(sizeof(Reply));
  reply->content = content;
  reply->username = username;
  return reply;
}
