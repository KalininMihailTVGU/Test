#include "Queue.h"

queue::queue() // Пустой конструктор в случае, если его вызывают без параметров

{
	head = new(queue_ob);
	tail = head;
	head->value = 0; // Записываем значение, равное нулю по умолчанию
	head->addr = 0;
	size = 1;
}

int queue::stack_size() // Функция возвращает размер очереди (кол-во элементов)
{
	return size;
}