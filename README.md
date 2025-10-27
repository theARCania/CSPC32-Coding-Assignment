# CSPC32-Coding-Assignment


Implemented Functions

createPlatform(): Initializes the global platform instance. Must be called first.

addPost(char* username, char* caption): Creates and adds a new post to the platform.

deletePost(int n): Deletes the nth most recent post.

viewPost(int n): Returns the nth most recent post and sets it as the lastViewedPost.

currPost(): Returns the lastViewedPost.

nextPost(): Sets the lastViewedPost to the next older post in the list.

previousPost(): Sets the lastViewedPost to the next newer (more recent) post in the list.

addComment(char* username, char* content): Adds a comment to the lastViewedPost.

deleteComment(int n): Deletes the nth most recent comment from the lastViewedPost.

viewComments(): Returns a pointer to the head of the comments list for the lastViewedPost.



Assumptions

Whitespace: All input strings (usernames, captions, contents) are assumed to be single words without any whitespace, as scanf("%s", ...) is used for input.

Indexing: The "nth recent" post or comment is 1-indexed. n=1 refers to the most recent item (the head of the linked list).

Failed memory allocation: As taught in the course Principles of Programming Languages in the same semester as this course, it is important to always check if the malloc function executed as intended. This is handled by immediate conditional checking, and thee porgram termintes with exit code 0 if memory allocation fails anywhere.
