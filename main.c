  #include "trie.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc,char const *argv[]) {
  char c=getchar(), *key=(char*)malloc (sizeof(char)*300);
  char *c1=NULL;
  int keysize=300 ,count=0;
    node *root=NodeAdd('\0');
    char check;

    while (c!=EOF) {
        if ((c >='A'&& c <= 'Z') || (c >='a' && c<='z')) 
         {
         c = c+32;
        }
        if (c >= 'a' && c <= 'z' && c != ' ' && c != '\n' && c != '\0' && c != '\t')
         {
            if (c == keysize) {
                c1 = (char*) realloc(key, sizeof(char)*(keysize + TEXT));
                keysize = keysize +TEXT;

                 //in case realloc didnt work
                if (c1 == NULL && key != NULL)
                {
                    free(key);
                    return -1;
                }
                key = (char*)calloc(keysize, sizeof(char));
                strcpy(key, c1);
                free(c1);
            }
            key[count] = c;
            count++;
        }
        if (c== EOF || c == ' ' || c == '\n' || c == '\0' || c == '\t') {
            key[count] = '\0';
            if (key[0] != ' ' && count >= 1) {
               Set(&root, key);
            }
            count = 0;
        } 
        c = getchar();
    }
    //Checks whether to print reverse or normal
    if(argc>1)
    check=*argv[1];
    if(get=='r')
    {
        PrintReverse(&root,key,0);
    }
else{
        TriePrint(&root,key,0);
    }
   SetFree(&root);
    free(key);
    return 0;
}
