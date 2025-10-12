#include "post.h"

struct Platform {
  Post* postList;
  Post* lastViewedPost;
  int countPost;
};
typedef struct Platform Platform;

extern Platform* platform;
