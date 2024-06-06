// Implements a dictionary's functionality

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#include "diccionario.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

#define N 676

// Hash table (as it is global, it is initialized to 0)
node *table[N];

//Represents de size of the dictionary
unsigned int dictionarySize;

bool strcasecmp(char *a, char *b){
    int i;
    for (i = 0; a[i] != '\0' && b[i] != '\0'; i++) {
        if (toupper(a[i]) != toupper(b[i])) {
            return false;
        }
    }
    // Check if both strings end simultaneously
    if (a[i] == '\0' && b[i] == '\0') {
        return true;
    }
    return false;
}

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    char wordcopy[LENGTH + 1];
    strcpy(wordcopy, word);
    node *cursor;
    unsigned int index = hash(word);
    cursor = table[index];
    while (cursor != NULL) {
        if (strcasecmp(wordcopy, cursor->word)) {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    unsigned int index= toupper(word[0]) - 'A';

    if(word[1]=='\0'){
        index = 0;
    }else{
        unsigned int index= toupper(word[0]) - 'A';
        if(isalpha(toupper(word[1]))){
            index+=toupper(word[1]) - 'A';
        }else{
            index+=toupper(word[2]) - 'A';
        }
    }
    return index;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open the dictionary file
    FILE * source=fopen(dictionary, "r");
    if(source==NULL){
        return false;
    }

    // Read each word in the file and add them to the hash table
    char buffer[LENGTH];
    unsigned int index;


    while(fscanf(source, "%s", buffer)!=EOF){

        node *n = malloc(sizeof(node));
        if(n==NULL){
            return false;
        }
        strcpy(n->word, buffer);
        n->next = NULL;
        index=hash(buffer);
        n->next = table[index];
        table[index]=n;
        dictionarySize++;

    }

    // Close the dictionary file
    fclose(source);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    return dictionarySize;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    node *cursor;
    node *temp;
    for(int i=0; i<N; i++){
        cursor = table[i];
        while(cursor!=NULL){
            temp=cursor;
            cursor=cursor->next;
            free(temp);
        }
    }
    return true;
}
