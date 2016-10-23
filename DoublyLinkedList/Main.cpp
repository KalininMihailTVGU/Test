// DoublyLinkedList.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "DoublyLinkedList.h"

int main()
{
	int b;

	doubly_linked_list a(0); // ������ 7 ��������� � ������
	a.list_add(1, 1);
	a.list_add(2, 2);
	a.list_add(5, 1);
	a.list_add(6, 3);
	a.list_add(7, 2);
	a.list_add(8, 0);
	cout << "This node contains: ";
	for (int i = 0; i<a.list_size(); i++)//������� ���� ������
	{
		a.list_read_elem(i, &b);
		cout << b << " ";
	}

	a.list_delete(3, &b); // ������� 3-� �������
	a.list_delete(5, &b); // ������� 5-� �������
	a.list_delete(4, &b); // ������� 4-� �������

	cout << endl << "node after processing: ";
	for (int i = 0; i<a.list_size(); i++)
	{
		a.list_read_elem(i, &b);
		cout << b << " ";
	}

	cout << endl;
	system("pause");

	return 0;
}

