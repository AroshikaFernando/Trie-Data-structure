#include "AutoCompleteImpl.h" 

#define ALPHABET_SIZE (26)


//create node function
struct TrieNode *createTrieNode() {
	struct TrieNode *node;
	int i;
	
    node = (struct TrieNode *)malloc(sizeof(TrieNode));
    
    for(i=0; i<ALPHABET_SIZE ; i++){
		node->children[i] = NULL;		
	}

	node->isEndOfWord = false;
    return node;
}

//insert function
void insert(struct TrieNode *root, const char *word) {

	int i;
	
	for(i=0 ; i<strlen(word) ; i++){
		int j = word[i] - 97 ;
		
		if(!(root->children[j])){
			root->children[j] = createTrieNode();
			
		}
		root->children[j]->label = word[i];
		//root->children[j]->isEndOfWord  = false;
		
		if(i == strlen(word)-1){
			root->isEndOfWord  = true;
		}
		
		root = root->children[j];
		
	}
	
}

//search function
struct TrieNode *search(struct TrieNode *root, const char *word) {
	int i;
	
	struct TrieNode *rootNode = root;
	struct TrieNode *prev;
 
    for (i = 0; i < strlen(word); i++)
    {
        int j = word[i] - 97;
 
        if (!rootNode->children[j]){
			return NULL;
		}
		//prev = rootNode;
		rootNode = rootNode->children[j];
    }
 
return rootNode;
}

//traverse function
void traverse(char prefix[], struct TrieNode *root) {
   
   struct TrieNode *prefixEnd = search(root , prefix);
   
   printWords(prefixEnd , prefix);
 
}

void printWords(struct TrieNode *node , char prefix[]) {
  char words[1000];

  printPathsRecur(node, words, 0 , prefix);
}

void printPathsRecur(struct TrieNode *node, char word[], int wordLen , char prefix[] ) {
	
	if (node==NULL) return;

	word[wordLen] = node->label;
	wordLen++;
	  
	int i;

	if(node->isEndOfWord){
		printArray(word , wordLen , prefix);
	}
	
		for(i=0; i< ALPHABET_SIZE; i++){
			if(node->children[i]){
				printPathsRecur(node->children[i] , word , wordLen , prefix);
		}
	}		

}

void printArray(char word[], int len , char prefix[] ) {
  int i;
  
 
  for(i=0; i< strlen(prefix); i++ ){
	printf("%c",prefix[i]);
	
  }
 
  
  for (i=1; i<len; i++) {
    printf("%c", word[i]);
  }
  printf("\n");
}
