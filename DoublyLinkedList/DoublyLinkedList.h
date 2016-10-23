#pragma once

// Реализация двусвязного списка (С)Swamp_Dok 09.04.2014
#include<iostream>

using namespace std;

class doubly_linked_list // Объявляем класс двусвязного списка
{
private:

	struct node // Создаем структуру для хранения элемента списка
				// Теперь ячеек адреса две
	{
		int value; // Тут значение элемента стека
		node *prev; // Указатель на элемент справа в сторону хвоста
		node *next; // На элемент слева
	};
	
	node(int k)
	{
		node *temp = value;
		node->value = k;
	};

	node *head; // Указатель на голову списка
	node *tail; // Указатель на конец списка
	int size; // Кол-во элементов стека

public:
	doubly_linked_list(int value) // Конструктор класса
	{
		head = new(node); // Выделяем память под первый элемент
		head->value = value; // Записываем значение                                
		head->next = 0; // Нули, так как они никуда не ссылаются.
		head->prev = 0;
		size = 1; // Элемент появился, значит ++
	}

	doubly_linked_list() // Пустой конструктор класса
	{
		head = new(node); // Выделяем память под первый элемент
		head->value = 0; // Записываем значение по-умолчанию, то есть 0                             
		head->next = 0; // Нули, так как они никуда не ссылаются.
		head->prev = 0;
		size = 1; // Элемент появился, значит ++
	}

	int list_size() // Возвращает количество элементов списка
	{
		return size;
	}

	void list_add(int value, int k) // Добавляет value на k-е место
									// Элементы списка считаются с нуля
									// При k=0 вставится новая голова
									// При k=size вставится новый хвост
	{
		if (k>size || k<0) // Проверка на позицию
		{
			cout << "Такого элемента нет!";
			return; // Завершаем ф-ю
		}

		size++; // Увеличиваем количество

		node *temp = head; // Записываем адрес головы

		if (k == 0) // Добавляется новая голова
		{

			head = new(node); // Память для новой головы
			temp->next = head; // Записываем в next старой головы
			head->prev = temp; // Записываем в prev новой головы адрес старой
			head->next = 0; // Ноль, так как слева от головы ничего нету
			head->value = value; // Записываем значение в новую голову
			return; // Завершаем функцию и ничего не возвращаем
		}

		for (int i = 1; i<k; i++) temp = temp->prev; // Находим и записываем в temp адрес элемента с номером (k-1) 

													 // temp->prev -- элемент, стоящий справа от вставляемого
													 // temp->next -- элемент, стоящий слева от вставляемого
		node *buff = new(node); // Выделяем память  и записываем адрес выделенной памяти в buf
		buff->next = temp; // Записываем в next нового элемента адрес элемента, стоящего слева.
		buff->prev = temp->prev; // Записываем в prev нового элемента адрес элемента, стоящего справа.

		if (temp->prev != 0) // Проверяем на хвостатость temp
		{
			temp->prev->next = buff; // Записывает в next элемента, стоящего справа от нового, адрес нового
		}
		temp->prev = buff; // Записываем в элемент, стоящий слева от нового, адрес добавленного элемента
		buff->value = value; // записываем значение в новый элемент
	}

	void list_delete(int k, int *ret) // Вытолкнуть k-й элемент в ret
									  // Если k=0, то выталкивается голова
	{
		if (k >= size || k<0) // Проверка
		{
			cout << "There is no such an element!";
			return; // Завершаем ф-ю
		}
		size--; // Уменьшаем кол-во элементов
		node *temp = head; // Записываем адрес головы
		if (k == 0) // Удаляется голова
		{
			*ret = head->value; // Записываем значение головы
			head = head->prev; // Изменяем адрес головы
			delete temp; // Удаляем старую голову
			head->next = 0; // Ноль, так слева от головы ничего нету
			return;
		}

		for (int i = 1; i <= k; i++) temp = temp->prev; // Находим и записываем в temp адрес элемента с номером k 
														// temp->prev -- элемент, стоящий справа от удаляемого
														// temp->next -- элемент, стоящий слева от удаляемого
		*ret = temp->value;
		if (temp->prev != 0) temp->prev->next = temp->next; // Проверяем, является ли удаляемый элемент хвостом
		temp->next->prev = temp->prev;
		delete temp;
	}

	void list_read_elem(int k, int *ret) // Cчитываем k-й и записываем в ret
	{
		if (k >= size || k<0)
		{
			cout << "There is no such an element!";
			return; // Завершаем ф-ю
		}
		node *temp = head;
		for (int i = 0; i<k; i++) temp = temp->prev; // Находим и записываем в temp адрес элемента с номером k 
		*ret = temp->value; // Записываем значение элемента под номером  k
	}

	node* search(int val)
	{
		node* temp = head;

		/* traverse the list */
		while (temp != NULL) {
			/* Target! */
			if (temp->value == val)
			{
				return temp;
			}
			/* move to the next one */
			temp = temp->next;
		}
		return NULL;
	}

	void insert(const T &value)
	{
		node* current = head;
		node* previous = nullptr;

		while (current && !(value < current->value))
		{
			previous = current;
			current = current->next;
		}

		node* pNode = new node{ value, previous, current };

		if (previous == nullptr) head = pNode;
		else previous->next = pNode;

//		if (current == nullptr) tail = pNode;
		else current->prev = pNode;
	}

	void insert_front(int value)
	{
		node* temp = new node(value);

		if (head == NULL)
			head = tail = temp;
		else
		{
			head->prev = temp;
			temp->next = head;
			head = temp;
		}
		size++;
	}

	void insert_back(int value)
	{
		node* temp = new node(value);

		if (tail == NULL)
			head = tail = temp;
		else
		{
			tail->next = temp;
			temp->prev = tail;
			tail = temp;
		}
		size++;
	}

}; // Конец класса