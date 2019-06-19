#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"
#include "filter_data.h"

void filter_init()
{
	INIT_LIST_HEAD(&e_head);
}

int add_filter_node(unsigned int length, const unsigned char *data)
{
	e_node_t *n_p = NULL;

	n_p = (e_node_t *)malloc(sizeof(e_node_t)+length);
	if(n_p == NULL)
	{
		fprintf(stderr, "malloc memory failed!\n");
		return -1;
	}
	n_p->length = length;
	memcpy(n_p->data, data, n_p->length);
	list_add(&n_p->node, &e_head);

	return 0;
}

int find_filter_node(unsigned int length, const unsigned char *data)
{
	struct list_head *nl = NULL;
	e_node_t *np = NULL;

	nl = e_head.next;
	while(nl != &e_head)	
	{
		np = (e_node_t*)nl;
		if(np->length == length)
		{
			if(memcmp(np->data, data, np->length) == 0)
			{
				return 1;
			}
		}
		nl = nl->next;
	}

	return add_filter_node(length, data);
}

void filter_uninit()
{
	struct list_head *nl = NULL;	
	struct list_head *tnl = NULL;

	nl = e_head.next;
	
	while(nl != &e_head)
	{
		tnl = nl->next;
		list_del(nl);
		nl = tnl;
	}
}
