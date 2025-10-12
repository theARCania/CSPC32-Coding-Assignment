#ifndef POST_H
#define POST_H
#include "comment.h"

struct Post {
  char* username;
  char* caption;
  Comment* comments;
};
typedef struct Post Post;

Post* createPost(char* username, char* caption);
#endif
