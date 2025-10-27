#include "platform.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Platform* platform = NULL;

Platform* createPlatform() {
    platform = (Platform*)malloc(sizeof(Platform));

    if (platform == NULL) {
        perror("Failed to allocate memory for platform");
        exit(0);
    }

    platform->PostList = NULL;
    platform->lastViewedPost = NULL;
    return platform;
}



bool addPost(char* username, char* caption) {
    struct Post* newPost = createPost(username, caption);
    
    if (newPost == NULL) {
        return false;
    }
    newPost->next = platform->PostList;
    platform->PostList = newPost;
    
    if (platform->lastViewedPost == NULL) {
        platform->lastViewedPost = newPost;
    }
    return true;
}



static void freeComments(struct Post* post) {
    
    struct Comment* current = post->comments;
    while (current != NULL) {
        
        struct Comment* next = current->next;
        free(current->username);
        free(current->content);
        free(current);
        current = next;
    }
}


bool deletePost(int n) {
    // no posts
    if (platform->PostList == NULL || n <= 0) {
        return false;
    }
    

    struct Post* temp = platform->PostList;
    struct Post* prev = NULL;
    
    // if only one post in list
    if (n == 1) {
        platform->PostList = temp->next;
        if (platform->lastViewedPost == temp) {
            platform->lastViewedPost = platform->PostList;
        }
        freeComments(temp);
        free(temp->username);
        free(temp->caption);
        free(temp);
        return true;
    }

    // standard linked list deletion algo

    for (int i = 1; i < n && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        return false;
    }

    prev->next = temp->next;
    if (platform->lastViewedPost == temp) {
        platform->lastViewedPost = platform->PostList;
    }
    
    freeComments(temp);
    free(temp->username);
    free(temp->caption);
    free(temp);
    
    return true;
}

struct Post* viewPost(int n) {
    if (n <= 0) return NULL;
    
    struct Post* current = platform->PostList;
    for (int i = 1; i < n && current != NULL; i++) current = current->next;
    
    
    if (current != NULL) {
        platform->lastViewedPost = current;
    }
    
    return current;
}

struct Post* currPost() {
    if (platform->lastViewedPost != NULL) {
  
      return platform->lastViewedPost;
    }

    if (platform->PostList != NULL) {
        platform->lastViewedPost = platform->PostList;
        return platform->lastViewedPost;
    }
    return NULL;
}

struct Post* nextPost() {
    struct Post* current = currPost();

    if (current == NULL) {
        return NULL;
    }


    if (current->next != NULL) {

        platform->lastViewedPost = current->next;
        return current->next;
    }
    

    return current;
}

struct Post* previousPost() {
    struct Post* current = currPost();
    if (current == NULL || current == platform->PostList) {
        return current;
    }

    
    struct Post* temp = platform->PostList;
    
    while (temp != NULL && temp->next != current) {
        temp = temp->next;
    }

    if (temp != NULL) {
        platform->lastViewedPost = temp;
        return temp;
    }
    
    return current;
}

bool addComment(char* username, char* content) {
    struct Post* post = currPost();
    if (post == NULL) {
        return false;
    }

    
    struct Comment* newComment = createComment(username, content);
    // check for failed memory allocation...
    if (newComment == NULL) return false;

    
    newComment->next = post->comments;
    post->comments = newComment;
    return true;
}

bool deleteComment(int n) {
    struct Post* post = currPost();
    if (post == NULL || post->comments == NULL || n <= 0) {
        return false;
    }

    struct Comment* temp = post->comments;
    struct Comment* prev = NULL;

    if (n == 1) {
        post->comments = temp->next;
        free(temp->username);
        free(temp->content);
        free(temp);
        return true;
    }

    for (int i = 1; i < n && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        return false;
    }

    prev->next = temp->next;
    free(temp->username);
    free(temp->content);
    free(temp);

    return true;
}

struct Comment* viewComments() {
    struct Post* post = currPost();
    if (post == NULL) return NULL;
    return post->comments;
}

























































