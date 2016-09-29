// Stack.cpp: определяет точку входа дл¤ консольного приложения.
//

/* простой калькулятор с четыремя действиями. */
#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

#include "Elem.h"


Elem *top;

void push(int num)
{
	_push(num, &top);
}

int pop()
{
	return _pop(&top);
}

int main(void)
{
  int a, b;
  char s[80];

  printf("Calcualtor with four operations\n");
  printf("Press 'q' to exit\n");

  do {
    printf(": ");
    gets(s);
    switch(*s) {
      case '+':
        a = pop();
        b = pop();
        printf("%d\n", a+b);
        push(a+b);
        break;
      case '-':
        a = pop();
        b = pop();
        printf("%d\n", b-a);
        push(b-a);
        break;
      case '*':
        a = pop();
        b = pop();
        printf("%d\n", b*a);
        push(b*a);
        break;
      case '/':
        a = pop();
        b = pop();
        if(a==0) {
          printf("Division by 0.\n");
          break;
        }
        printf("%d\n", b/a);
        push(b/a);
        break;
      case '.': /* показать содержимое вершины стека */
        a = pop();
        push(a);
        printf("Current value at the top of stack: %d\n", a);
        break;
      default:
        push(atoi(s));
    }
  } while(*s != 'q');

  while(pop() != -1);
  
  return 0;
}


