#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Node {
	struct Node *left , *right;
	char c;
}Node;

typedef struct b_tree {
	Node *root;
}b_tree;

int get_end_bracket(char *str, int ix) {

	int num_brack = 0, num_end_brack = 0;

	for(int i = ix+1; str[i] != '\0' ; i++) {	
		if(str[i] == '{')
			num_brack++;
		else if(str[i] == '}')
			num_end_brack++;
		else if(str[i] == ',')
			continue;
		
		if(num_brack == num_end_brack) {
			return i; 
		}
	}

	return -1;
}

char *substring_n(char *src, int start, int end) {
	char *dest = malloc(sizeof(char)*(end-start+1));

	for(int i = start; i<end; i++) {
		dest[i-start] = src[i];
	}

	dest[end] = '\0';
	return dest;
}


//binary tree (serialized) exmpl: 
// A{B{E,F},C{G,H{I,J}}}
void build_btree(char *str, Node* parent) {
	if(str[0] == '\0')
		return;

	//for each not inside the parantheses => 
	//		if(number of brackets to the left -equals- number of ending brackets to the left

	int num_brack, num_end_brack = 0;
	for(int i = 0; i<strlen(str); i++) {
		//counting brackets
		if(str[i] == '{')
			num_brack++;
		else if(str[i] == '}')
			num_end_brack++;

		//skipping commas
		else if(str[i] == ',')
			continue;

		//split tree - go one level deeper
		else if(num_brack == num_end_brack) {
			Node *n = (Node *) malloc(sizeof(Node));
			n->c = str[i];

			if(parent->left == NULL) {
				parent->left = n;
				if(str[i+1] == '{') { //this should always be true
					int loc = get_end_bracket(str,i);
					if(loc != -1) {
						char *substr = substring_n(str, i+2, loc);
						build_btree(substr, n); //build the subtree
					}
				}
			} else { 
				parent->right = n;
				if(str[i+1] == '{') {
					int loc = get_end_bracket(str,i);
					if(loc != -1) {
						char *substr = substring_n(str, i+2, loc);
						build_btree(substr, n);
					}
				}
			}
		}
	}
}


void print_tree(Node *n, int lvl) {
	if(n == NULL)
		return;
	
	print_tree(n->left,lvl+1);
	for(int i = 0; i<lvl; i++) {printf("	");}printf("%c\n",n->c);
	print_tree(n->right,lvl+1);
}

int main() {
	/*FILE *f;
	f = fopen("","r");

	if(f == NULL){ return 1; }

	***	
	***

	int r = fclose(f);
	return r;*/


	b_tree *tree = (b_tree *) malloc(sizeof(b_tree));	

	//exmpl. of a serialized binary tree
	char str[25]= "A{B{E,F},C{G,H{I,J}}}";
	Node *n = (Node *) malloc(sizeof(Node));
	n->c = str[0];

	tree->root = n;


	int loc = get_end_bracket(str,0);
	if(loc != -1) {
		char *substr = substring_n(str, 0+2, loc); //get children (string wise)
		build_btree(substr, n); //it builds a binary tree even if the string does not
	}

	//it prints the tree sideways
	print_tree(tree->root,0);

	return 0;
}
