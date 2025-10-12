#ifndef REPLY_H
#define REPLY_H

struct Reply {
  char* username;
  char* content;
  struct Reply* next;
};
typedef struct Reply Reply;

Reply* createReply(char* username, char* content); 
#endif
