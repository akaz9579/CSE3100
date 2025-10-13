#include "linked_list.h"

node * create_node(int v) 
{
    node	* p = malloc(sizeof(node)); 
    assert(p != NULL);		

    p->v = v;		
    p->next = NULL;  
    return p;			
}

void insert(node **head, node *newnode)
{
    if((*head) == NULL)
    {
        *head = newnode;
    }
    node *p = (*head);
	node *q = p;
	while(p->next != NULL && newnode->v > p->v)
	{
		
        if(p->next->v > newnode->v)
        {
            newnode->next = p->next;
            p->next = newnode;
        }
        p = p->next;

	}
	if(newnode->v > p->v)
	{
        newnode->next = p->next;
        p->next = newnode;
	}

	return;
}

void insert_last(node **head, node **tail, node *newnode)
{
	if((*head) == NULL)
	{
		(*head) = (*tail) = newnode;
	}
	else
	{
		(*tail)->next = newnode;
		(*tail) = newnode;
	}
}


node * remove_first(node **head) 
{
    node *p;
    p = (*head);
    if((*head)!=NULL) (*head) = (*head)->next;
    return p;
}

void print_list(node *head)
{
	node *p = head;
	while(p!=NULL)
	{
		printf("%d ", p->v);
		p = p->next;
	}
	printf("\n");
}

node * merge(node **p1, node **p2)
{
	node *head = NULL, *tail = NULL;
	node *q1 = (*p1), *q2 = (*p2), *p;

	if(q1 == NULL && q2 == NULL) return NULL;
	if(q1 != NULL && q2 == NULL) 
	{
		p = q1;
		(*p1) = NULL;
		return p;
	}
	if(q1 == NULL && q2 != NULL) 
	{
		p = q2;
		(*p2) = NULL;
		return p;
	}

	while(q1 != NULL && q2!= NULL)
	{
        if(q1->v > q2->v)
        {
            insert_last(&head, &tail, q2);
            q2 = q2->next;
        }
        else if (q1->v < q2->v)
        {
            insert_last(&head, &tail, q1);
            q1 = q1->next;
        }
        else
        {
            insert_last(&head, &tail, q1);
            q1 = q1->next;
            insert_last(&head, &tail, q2);
            q2 = q2->next;
        }
	}
	while(q1 != NULL)
	{
        insert_last(&head, &tail, q1);
        q1 = q1->next;
	}
	while(q2 != NULL)
	{	
        insert_last(&head, &tail, q2);
        q2 = q2->next;
	}
	*p1 = NULL;
	*p2 = NULL;
	return 	head;
}
int main(int argc, char *argv[])
{
	assert(argc == 2);
	int n = atoi(argv[1]);
	
	int a[n];
	int b[n];
	
	for(int i = 0; i < n; i++)
	{
		a[i] = i;
		b[i] = 2*i;
	}

	node *p1 = NULL, *p2 = NULL;

	for(int i = 0; i < n; i++)
	{
		node *p = create_node(a[i]);
 		insert(&p1, p);
	}
	print_list(p1);

	for(int i = 0; i < n; i++)
    {
        node *p = create_node(b[i]);
        insert(&p2, p);
    }
	print_list(p2);
	
	node *p = merge(&p1, &p2);
	print_list(p);
	printf("%p\n", p1);
	printf("%p\n", p2);

	while(p != NULL)
    {
        node *temp = remove_first(&p);
        free(temp);
    }

	return 0;
}