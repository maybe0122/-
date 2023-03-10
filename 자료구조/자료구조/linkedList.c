#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>

#include "linkedlist.h"

//연결리스트의 마지막 노드 다음에 새로운 노드 추가
//오류인 경우 -1, 정상인 경우 0 리턴
int Insert(ST_INFO** head, int id, char* name, int score)
{
	// make new node
	ST_INFO* new_node;
	ST_INFO* p;

	printf("\nInsert a node {%d, %s, %d}\n", id, name, score);
	new_node = (ST_INFO*)malloc(sizeof(ST_INFO));
	if (new_node == NULL) {
		printf("memory allocation error \n");
		return -1;
	}

	new_node->id = id;
	strcpy(new_node->name, name);
	new_node->score = score;
	new_node->link = NULL;

	if (*head == NULL) {
		*head = new_node;
	}
	else {
		p = *head;
		while (p->link) p = p->link;
		p->link = new_node;
	}
	return 0;

}

void PrintList(ST_INFO* head)
{
	printf("\nPrint Linked List \nHead -> ");
	while (head) {
		printf("{%d, %s, %d} -> ", head->id, head->name, head->score);
		head = head->link;
	}
	printf("NULL\n");

	return;
}

// Print a node
void PrintNode(ST_INFO* node)
{
	printf("\nPrint A Node \n");
	if (node)
		printf("{%d, %s, %d} \n", node->id, node->name, node->score);
	else
		printf("NULL\n");
}

ST_INFO* SearchById(ST_INFO* head, int id)
{
	printf("\nSearchById %d\n", id);
	while (head) {
		if (head->id == id) {
			return head;
		}
		head = head->link;
	}
	return NULL;
}

ST_INFO* SearchByName(ST_INFO* head, char* name)
{
	printf("\nSearchByName %s\n", name);
	while (head) {
		if (!strcmp(head->name, name)) return head;
		head = head->link;
	}
	return NULL;
}

ST_INFO* DeleteNodeById(ST_INFO* head, int id)
{
	ST_INFO* p = head;
	ST_INFO* q = NULL;

	printf("\nDeleteNodeByID %d\n", id);

	while (p) {
		if (p->id == id) {
			//첫번째 노드인 경우
			if (p == head) {
				head = head->link;
				free(p);
				break;
			}
			else {
				q->link = p->link;
				free(p);
				break;
			}
		}
		q = p;
		p = p->link;
	}
	return head;
}

ST_INFO* DeleteList(ST_INFO* head)
{
	ST_INFO* p;
	printf("\nDeleteList\n");
	if (head) {
		p = head;
		head = head->link;
		free(p);
	}
	return NULL;
}