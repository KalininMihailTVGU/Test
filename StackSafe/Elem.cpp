#include "stdafx.h"
#include "Elem.h"


/* нанесение элемента в стек. */
void _push(int num, Elem **top) {
	Elem *curr = new Elem;
	curr -> num = num;

	if (*top == NULL) {
		curr -> prev = NULL;
	}
	else {
		curr -> prev = *top;
	}

	*top = curr;
}

/* получение верхнего элемента из стека. */
int _pop(Elem **top){
	if (*top == NULL) {
		return -1;
	}
	int tmp = (*top)->num;
	Elem *tmp_top = *top;
	*top = (**top).prev;
	delete tmp_top;

	return tmp;

}