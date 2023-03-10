#pragma once

#ifndef _LINKEDLIST_H_
#define _LINKEDLIST_H_

typedef struct st_info {
	int id;
	char name[20];
	int score;
	struct st_info* link;
}ST_INFO;

//prototype
int Insert(ST_INFO** head, int id, char* name, int score);
void PrintList(ST_INFO* head);
void PrintNode(ST_INFO* node);
ST_INFO* SearchById(ST_INFO* head, int id);
ST_INFO* SearchByName(ST_INFO* head, char* name);
ST_INFO* DeleteNodeById(ST_INFO* head, int id);
ST_INFO* DeleteList(ST_INFO* head);

#endif