#include <stdio.h>
#include <stdlib.h>

typedef struct seznam {
	int podatek;
	struct seznam *s;
}Seznam;


Seznam* arr2list (int *arr, int len) {

	if(len==0) return NULL;
	Seznam *a = malloc(sizeof(Seznam));
	a->podatek = arr[len-1];
	a->s = arr2list(arr, len-1);
	return a;

}

void printList(Seznam *l) {
	if(l==NULL) return;
	printf("%d\n", l->podatek);
	printList(l->s);
}

int main() {
	//array = tabela
	//list = seznam

	int tab[5] = {1000, 2, 3, 7, 50};
	Seznam *a = arr2list(tab, 5);
	printList(a);
}