#include <stdio.h> 
#include <stdlib.h> 
#include <string.h>

#define NUM_LETTERS 26

typedef struct node{
long unsigned int count;
char letter;
struct node* children[NUM_LETTERS];
}node;

node* NodeAdd(char letter){
	
	node* s=(node*)malloc(sizeof(node));
	(*s).count=0;	//to allow the value of count to s 
	(*s).letter=letter;	// to allow the value of givven letter to s 

 
	for(int i=0;i<NUM_LETTERS;i++){
		(*s).children[i]=NULL;
	}
	return s;
}

node* Set(node *s, char c){
	//here we set a char into s 
	if((*s).children[c-'a'] == NULL)
    //here we check if the value of children to us is null then we have to make a new node to hold {
	    node *s1 = NodeAdd(c);
    	(*s).children[c-'a'] = *s1;
    	return (*s).children[c-'a'];
	}
	return (*s).children[c-'a'];
}

int LeafCheck(node* s){
	//  check if the held value by childern in index isn't null  
	for(int i=0;i<NUM_LETTERS;i++){
		if((*s).children[i]!=NULL)
 			return 0; 
	}
	return 1; //otherwise return 1
}
void SetFree(node* s){
	if(s==NULL) 	// first we check if the node is null then we return
		return;
	if(LeafCheck(s))
    {
  		free(s);
		return;
	}
	for(int i=0;i<NUM_LETTERS;i++){
    	freeNode((*s).children[i]); // do the same thing again and again for all the 26 
	}
	free(s);
}

}

void TriePrint(node* s,char* c,int i){
	//first we check if s is leaf
	if (LeafCheck(s)){
		//we check if its the last one 
		c[i] = '\0';
		printf("%s %d\n", c, (*s).count);
		return;
	}
	//then we check if the value of count to s is zero
	if ((*s).count>0){
		c[i] = '\0'; 	// then we check if its the last one
		printf("%s %d\n", c, (*s).count);
	}
	int j;
	for (j=0; j<NUM_LETTERS; j++) //go over all the 26 using j checking if its not null{
        		if (s->children[j]!=NULL){
			//then we change the char c in the right index
			c[i] = s->children[j]->letter;
			TriePrint((*s).children[j], c, i+1);	// same thing with the following index over and over again            

		}}}

void PrintReverse(node* s,char* c,int i) {

	if (LeafCheck(s))// the first case we check if its a leaf then we change the char c in the right i and print{ 
    	c[i] = '\0';
    	printf("%s %d\n", c, (*s).count);
		return;
	}
	//secnod case we check if the value is larger of count to s than zero, do the change and print
	if (s->count > 0){
		c[i] = '\0';
		printf("%s %d\n", c, (*s).count);
	}
	int j;

    for (j=NUM_LETTERS-1; j>=0; j--) //go over the 26 letters in decreasing order{
		if (s->children[j]!=NULL){
			c[i] = s->children[j]->letter;
			PrintReverse(s->children[j], c, i+1);
		}
	}
}
