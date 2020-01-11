#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define CHAR_TO_INDEX(c) ((int)c - (int)'a')
#define NUM_LETTERS (int(26))
#define Word_length 32
typedef enum {TRUE =1 ,FALSE = 0} boolean;
typedef struct TrieNode{
    char letter;
    long unsigned int count;
    struct node *children[NUM_LETTERS];
    bool isEndOfWord;  
}TrieNode;
struct TrieNode *getNode(void) 
{ 
    struct TrieNode *pNode = NULL; 
  
    pNode = (struct TrieNode *)malloc(sizeof(struct TrieNode)); 
  
    if (pNode) 
    { 
        int i; 
        pNode->count = 0;
        pNode->isEndOfWord = false; 
        for (i = 0; i < ALPHABET_SIZE; i++) 
            pNode->children[i] = NULL; 
    } 
  
    return pNode; 
} 
void insert(struct TrieNode *root, const char *key) 
{ 
    int level; 
    int length = strlen(key); 
    int index; 
    boolean isFound = FALSE;
    isFound = search(root,&key);
    if(isFound==TRUE){
        return;
    }
    struct TrieNode *pCrawl = root; 
    for (level = 0; level < length; level++) 
    { 
        index = CHAR_TO_INDEX(key[level]);      
        if (!pCrawl->children[index]) 
            pCrawl->children[index] = getNode(); 
  
        pCrawl = pCrawl->children[index]; 
    } 
    // mark last node as leaf 
    pCrawl->isEndOfWord = true; 
} 
bool search(struct TrieNode *root, const char *key) 
{ 
    int level; 
    int length = strlen(key); 
    int index; 
    struct TrieNode *pCrawl = root; 
    boolean isFound = FALSE;
    for (level = 0; level < length; level++) 
    { 
        index = CHAR_TO_INDEX(key[level]); 
  
        if (!pCrawl->children[index]) 
            return false; 
  
        pCrawl = pCrawl->children[index]; 
    } 
    if(pCrawl != NULL && pCrawl->isEndOfWord){
         isFound = TRUE;
         pCrawl->count++;
    }
    return isFound; 
}
void trieFree(struct TrieNode* root) 
{
    if(root != NULL)
    {
        int i;
        for(i = 0; i < NUM_LETTERS; i++)
        {
            if(root->children[i] != NULL)
            {
                free(root->children[i]);
            }
        }
        free(root);
    }
}
 int main(int argc,int *argv[]){
     // note strcpy is neccessary to use
    char *string = NULL;
    struct  TrieNode *root = getNode();
     while(//put the file here//){
         string = (char *)malloc(Word_length*(sizeof(char)));
         strcpy(string,);// in the second one put the second string because you can't put string =.
        insert(root,&string);
         free(string);
     }
     return 0;
 }
 