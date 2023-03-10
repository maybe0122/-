#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "linkedlist.h"

int main(void)
{

	ST_INFO* head = NULL;
	ST_INFO* result = NULL;

	// ���Ḯ��Ʈ�� ������ ���� ����
	PrintList(head);
	Insert(&head, 1, "��浿", 83);
	PrintList(head);
	Insert(&head, 2, "���浿", 70);
	PrintList(head);
	Insert(&head, 3, "�ٱ浿", 80);
	Insert(&head, 4, "��浿", 55);
	Insert(&head, 5, "���浿", 76);
	Insert(&head, 6, "ȫ�浿", 90);
	PrintList(head);

	// id�� name �ʵ带 �̿��� �˻�
	result = SearchById(head, 3);
	PrintNode(result);
	result = SearchById(head, 10);
	PrintNode(result);
	result = SearchByName(head, "ȫ�浿");
	PrintNode(result);

	// id�� �̿��Ͽ� �ش�Ǵ� ��� �˻��Ͽ� ����
	head = DeleteNodeById(head, 4);
	PrintList(head);
	head = DeleteNodeById(head, 1);
	PrintList(head);

	// ��ü ���Ḯ��Ʈ ����
	head = DeleteList(head);
	PrintList(head);

	return 0;
}
