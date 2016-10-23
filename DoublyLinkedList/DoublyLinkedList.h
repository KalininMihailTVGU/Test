#pragma once

// ���������� ����������� ������ (�)Swamp_Dok 09.04.2014
#include<iostream>

using namespace std;

class doubly_linked_list // ��������� ����� ����������� ������
{
private:

	struct node // ������� ��������� ��� �������� �������� ������
				// ������ ����� ������ ���
	{
		int value; // ��� �������� �������� �����
		node *prev; // ��������� �� ������� ������ � ������� ������
		node *next; // �� ������� �����
	};
	
	node(int k)
	{
		node *temp = value;
		node->value = k;
	};

	node *head; // ��������� �� ������ ������
	node *tail; // ��������� �� ����� ������
	int size; // ���-�� ��������� �����

public:
	doubly_linked_list(int value) // ����������� ������
	{
		head = new(node); // �������� ������ ��� ������ �������
		head->value = value; // ���������� ��������                                
		head->next = 0; // ����, ��� ��� ��� ������ �� ���������.
		head->prev = 0;
		size = 1; // ������� ��������, ������ ++
	}

	doubly_linked_list() // ������ ����������� ������
	{
		head = new(node); // �������� ������ ��� ������ �������
		head->value = 0; // ���������� �������� ��-���������, �� ���� 0                             
		head->next = 0; // ����, ��� ��� ��� ������ �� ���������.
		head->prev = 0;
		size = 1; // ������� ��������, ������ ++
	}

	int list_size() // ���������� ���������� ��������� ������
	{
		return size;
	}

	void list_add(int value, int k) // ��������� value �� k-� �����
									// �������� ������ ��������� � ����
									// ��� k=0 ��������� ����� ������
									// ��� k=size ��������� ����� �����
	{
		if (k>size || k<0) // �������� �� �������
		{
			cout << "������ �������� ���!";
			return; // ��������� �-�
		}

		size++; // ����������� ����������

		node *temp = head; // ���������� ����� ������

		if (k == 0) // ����������� ����� ������
		{

			head = new(node); // ������ ��� ����� ������
			temp->next = head; // ���������� � next ������ ������
			head->prev = temp; // ���������� � prev ����� ������ ����� ������
			head->next = 0; // ����, ��� ��� ����� �� ������ ������ ����
			head->value = value; // ���������� �������� � ����� ������
			return; // ��������� ������� � ������ �� ����������
		}

		for (int i = 1; i<k; i++) temp = temp->prev; // ������� � ���������� � temp ����� �������� � ������� (k-1) 

													 // temp->prev -- �������, ������� ������ �� ������������
													 // temp->next -- �������, ������� ����� �� ������������
		node *buff = new(node); // �������� ������  � ���������� ����� ���������� ������ � buf
		buff->next = temp; // ���������� � next ������ �������� ����� ��������, �������� �����.
		buff->prev = temp->prev; // ���������� � prev ������ �������� ����� ��������, �������� ������.

		if (temp->prev != 0) // ��������� �� ����������� temp
		{
			temp->prev->next = buff; // ���������� � next ��������, �������� ������ �� ������, ����� ������
		}
		temp->prev = buff; // ���������� � �������, ������� ����� �� ������, ����� ������������ ��������
		buff->value = value; // ���������� �������� � ����� �������
	}

	void list_delete(int k, int *ret) // ���������� k-� ������� � ret
									  // ���� k=0, �� ������������� ������
	{
		if (k >= size || k<0) // ��������
		{
			cout << "There is no such an element!";
			return; // ��������� �-�
		}
		size--; // ��������� ���-�� ���������
		node *temp = head; // ���������� ����� ������
		if (k == 0) // ��������� ������
		{
			*ret = head->value; // ���������� �������� ������
			head = head->prev; // �������� ����� ������
			delete temp; // ������� ������ ������
			head->next = 0; // ����, ��� ����� �� ������ ������ ����
			return;
		}

		for (int i = 1; i <= k; i++) temp = temp->prev; // ������� � ���������� � temp ����� �������� � ������� k 
														// temp->prev -- �������, ������� ������ �� ����������
														// temp->next -- �������, ������� ����� �� ����������
		*ret = temp->value;
		if (temp->prev != 0) temp->prev->next = temp->next; // ���������, �������� �� ��������� ������� �������
		temp->next->prev = temp->prev;
		delete temp;
	}

	void list_read_elem(int k, int *ret) // C�������� k-� � ���������� � ret
	{
		if (k >= size || k<0)
		{
			cout << "There is no such an element!";
			return; // ��������� �-�
		}
		node *temp = head;
		for (int i = 0; i<k; i++) temp = temp->prev; // ������� � ���������� � temp ����� �������� � ������� k 
		*ret = temp->value; // ���������� �������� �������� ��� �������  k
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

}; // ����� ������