#pragma once
#include <iostream>

using namespace std;

class queue // ����� �������
{
private:
	struct queue_ob // ��������� ��� �������� ��������� �������
	{
		int value; // ���� ��� �������� �������� �������� �������
		queue_ob *addr; // ���� ��� �������� ���������� ��������
	};

	queue_ob *head; // ���������, �������� ����� ������ �������
	queue_ob *tail; // ���������, �������� ����� ������ �������
	int size; // ������� ������ �������

public:
	queue(int x) // ����������� ������
				 // � �������� ���������� ������ �������
	{
		head = new(queue_ob); // �������� ������ ��� �������
		tail = head; // ��� �������� ������� ����� � ������ �������� ����� � ��� �� ���������
		head->value = x; // ���������� ��������
		head->addr = 0; // ����� ����� ����, ��� ��� ���������� �������� ���� ���
		size = 1; // ����� ��������� ������ � ���������� ����� ��������� ������� ����� ����� ������ 1
	}

/*	queue() // ������ ����������� � ������, ���� ��� �������� ��� ����������

	{
		head = new(queue_ob);
		tail = head;
		head->value = 0; // ���������� ��������, ������ ���� �� ���������
		head->addr = 0;
		size = 1;
	}

	int stack_size() // ������� ���������� ������ ������� (���-�� ���������)
	{
		return size;
	}*/

	void append(int value) // ��������� (����������) ������� � �������
	{
		size++; // ���-�� ��������� ������� �������������
		queue_ob *temp = new(queue_ob); // �������� ������ ��� ����� ����� �������
		temp->addr = 0; // ���������� � ���� ������ ������ ������ ����, ��� ��� �� ��� ������ ����
		temp->value = value; //��������� ���� �������� ������ ������
		tail->addr = temp; // ���������� � ���� ������ ������� ������ ����� ������ ������
		tail = temp; // ���������� � ������� ������ ����� ��������������� ������
	}

	void extract(int *ret) // ������� ������� (�����������) � ���������� ���
						   // �� ������, ���������� � ret, ���������� �������� ��������� ������
	{
		if (size == 0)
		{
			cout << "Stack is empty - nothing to delete!" << endl;
			return;
		}

		queue_ob *temp = head; // ���������� ����� ������
		*ret = head->value; // ���������� �������� ������
		head = head->addr; // �������� ����� ������
		delete temp;  // ������� ������ ������
		size--; // ��������� ������
	}

	void output(int *ret) // ��������� �������� �� ������, ������������� � ��������
	{
		if (size == 0) // ���� ������� �����(size == 0), �� ������ �� ���������
		{
			cout << "Stack is empty!" << endl;
			return;
		}
		*ret = head->value; // ��������� �������� ������
	}

}; // ����� ������ �������