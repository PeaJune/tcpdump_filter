#ifndef __FILTER_DATA_H__
#define __FILTER_DATA_H__
#include "list.h"

struct list_head e_head;

typedef struct
{
	struct list_head node; 
	unsigned int 	length;
	unsigned char 	data[0];
}e_node_t;

void filter_init(); 
//int add_filter_node(unsigned int length, const unsigned char *data);
int find_filter_node(unsigned int length, const unsigned char *data);
void filter_uninit();

#endif
