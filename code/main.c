#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "platform.h"

void printPost(struct Post* post) {
    if (post != NULL) {
        printf("%s %s\n", post->username, post->caption);
    } else {
        printf("Post does not exist.\n");
    }
}

void printComments(struct Comment* comments) {
    if (comments == NULL) {
        return;
    }
    printComments(comments->next);
    printf("%s %s\n", comments->username, comments->content);
}

int main() {
    char command[100];
    char buffer1[1024];
    char buffer2[1024];
    int n, m;

    while (scanf("%s", command) != EOF) {
        if (strcmp(command, "create_platform") == 0) {
            if (platform == NULL) {
                createPlatform();
            }
        } else if (strcmp(command, "add_post") == 0) {
            scanf("%s", buffer1);
            scanf("%s", buffer2);
            if (platform != NULL) {
                addPost(buffer1, buffer2);
            }
        } else if (strcmp(command, "delete_post") == 0) {
            scanf("%d", &n);
            if (platform != NULL) {
                deletePost(n);
            }
        } else if (strcmp(command, "view_post") == 0) {
            scanf("%d", &n);
            if (platform != NULL) {
                struct Post* post = viewPost(n);
                printPost(post);
            }
        } else if (strcmp(command, "current_post") == 0) {
            if (platform != NULL) {
                struct Post* post = currPost();
                printPost(post);
            }
        } else if (strcmp(command, "next_post") == 0) {
            if (platform != NULL) {
                struct Post* post = nextPost();
                printPost(post);
            }
        } else if (strcmp(command, "previous_post") == 0) {
            if (platform != NULL) {
                struct Post* post = previousPost();
                printPost(post);
            }
        } else if (strcmp(command, "add_comment") == 0) {
            scanf("%s", buffer1);
            scanf("%s", buffer2);
            if (platform != NULL) {
                addComment(buffer1, buffer2);
            }
        } else if (strcmp(command, "delete_comment") == 0) {
            scanf("%d", &n);
            if (platform != NULL) {
                deleteComment(n);
            }
        } else if (strcmp(command, "view_all_comments") == 0 || strcmp(command, "view_comments") == 0) {
            if (platform != NULL) {
                struct Comment* comments = viewComments();
                if (comments == NULL) {
                    struct Post* p = currPost();
                    if (p == NULL) {
                        
                    }
                } else {
                    printComments(comments);
                }
            }
        } else {
            
        }
    }

    return 0;
}






















































