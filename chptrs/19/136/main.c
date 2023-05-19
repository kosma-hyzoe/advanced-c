#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int val;
    struct node *next;
} node_t;

node_t *ndcreate(int val)
{
    node_t *nd = malloc(sizeof(node_t));
    if (!nd)
        exit(1);
    nd->next = NULL;
    nd->val = val;
    return nd;
}
void ndprint(node_t *nd)
{
    node_t *tmp = nd;
    while (tmp != NULL) {
        printf("%d->", tmp->val);
        tmp = tmp->next;
    }
    printf("NULL\n");
}
void ndinsbeg(node_t **nd, int val)
{
    node_t *tmp = *nd;
    node_t *head = ndcreate(val);
    head->next = tmp;
    *nd = head;
}
void ndinsend(node_t **nd, int val)
{
    node_t *tmp = *nd;
    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    tmp->next = ndcreate(val);
}
int ndinsat(node_t **nd, int pos, int val)
{
    if (pos < 0) {
        return EXIT_FAILURE;
    } else if (pos == 0) {
        ndinsbeg(nd, val);
        return EXIT_SUCCESS;
    }

    node_t *tmp = *nd;
    for (int i = 1; i < pos; i++) {
        tmp = tmp->next;
        if (!tmp)
            return EXIT_FAILURE;
    }
    node_t *insert = ndcreate(val);
    insert->next = tmp->next;
    tmp->next = insert;
    return EXIT_SUCCESS;
}
int nddelat(node_t **nd, int pos)
{
    if (pos < 0) {
        return EXIT_FAILURE;
    } else if (pos == 0) {
        *nd = (*nd)->next;
        return EXIT_SUCCESS;
    }

    node_t *tmp = *nd;
    for (int i = 1; i < pos; i++) {
        tmp = tmp->next;
        if (!tmp)
            return EXIT_FAILURE;
    }
    node_t *ndtodel = tmp->next;
    tmp->next = ndtodel->next;
    free(ndtodel);
    return EXIT_SUCCESS;
}
int ndsearch(const node_t *nd, int val)
{
    int pos = 0;
    while (nd != NULL) {
        if (nd->val == val) {
            return pos;
        }
        nd = nd->next;
        pos++;
    }
    return -1; /* value not found */
}
int ndupdate(node_t **nd, int pos, int val)
{
    node_t *tmp = *nd;
    for (int i = 0; i < pos; i++) {
        tmp = tmp->next;
        if (!tmp)
            return EXIT_FAILURE;
    }
    tmp->val = val;
    return EXIT_SUCCESS;
}

int main()
    node_t node = 
    printf("Enter the value(s) for a new linked list and press 'q' when done: ")
    while (1)
    {
        int ch = '\0';
        printf("\n0. Create new node")
        printf("\n1. Insert node at beginning");
        printf("\n2. Insert node at end");
        printf("\n3. Insert node at a specific position");
        printf("\n4. Delete Node from any Position");
        printf("\n5. Update Node Value");
        printf("\n6. Search Element in the linked list");
        printf("\n7. Display List");
        printf("\n8. Exit\n");
        printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
		case 1:
		    insertNodeAtTheBeginning();
		    break;
		case 2:
		    insertNodeAtTheEnd();
		    break;
		case 3:
		    insertNodeAtPosition();
		    break;
		case 4:
		    deletePosition();
		    break;
		case 5:
		    updateValue();
		    break;
		case 6:
		    search();
		    break;
		case 7:
		    display();
		    break;
		case 8:
		    printf("\n...Exiting...\n");
		    return 0;
		default:
		    printf("\n...Invalid Choice...\n");
		    break;
		}
    }
    return 0;
 }

}