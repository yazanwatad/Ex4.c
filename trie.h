#ifndef _TRIE_H_
#define _TRIE_H_
#define TEXT 26
#define NUM_LETTERS 26

typedef struct node node;
node* NodeAdd(char);
node* Set(node*, char);
int LeafCheck(node*);
void SetFree(node*);
void TriePrint(node*,char*,int);
void PrintReverse(node*,char*,int);

#endif
