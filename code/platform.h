#ifndef PLATFORM_H
#define PLATFORM_H

#include "comment.h"
#include "post.h"
#include <stdbool.h>

struct Platform {
  Post* PostList; // exception in camelcase here.
  Post* lastViewedPost;
  // int countPost; unnecessary implementation.
};
typedef struct Platform Platform;

Platform* createPlatform();
bool addPost(char* username, char* caption);
bool deletePost(int n);
Post* viewPost(int n);
Post* currPost();
Post* nextPost();
Post* previousPost();
bool addComment(char* username, char* content);
Comment* viewComments();
bool deleteComment(int n);
bool addReply(char* username, char* content, int n);
bool deleteReply(int n, int m);



extern Platform* platform;

#endif
