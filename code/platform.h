#include "post.h"

struct Platform {
  Post* postList;
  Post* lastViewedPost;
};
typedef struct Platform Platform;

extern Platform* platform;
