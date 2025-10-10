#ifndef COMMENT_H
#define COMMENT_H
#include "reply.h"

struct Comment {
  char* username;
  char* content;
  int replyCount;
  Reply* repliesHead;
  // Reply* repliesEnd;
  struct Comment* next;
};
typedef struct Comment Comment;

#endif
