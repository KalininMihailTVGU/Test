#include "Queue.h"

queue::queue() // ������ ����������� � ������, ���� ��� �������� ��� ����������

{
	head = new(queue_ob);
	tail = head;
	head->value = 0; // ���������� ��������, ������ ���� �� ���������
	head->addr = 0;
	size = 1;
}

int queue::stack_size() // ������� ���������� ������ ������� (���-�� ���������)
{
	return size;
}