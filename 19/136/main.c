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
{
    node_t *ndptr = ndcreate(0);
    printf("Initialised a linked list with starting value 0.\n");

    int choice = '\0';
    int pos, val;
    while (1) {
        printf("\n1. insert a node at the beginning\n"
               "2. insert a node at end\n"
               "3. insert a node at position\n"
               "4. delete a node at position\n"
               "5. update node value\n"
               "6. search element\n"
               "7. display the linked list\n");
        printf("\n\nYour choice: ");

        if (scanf(" %d", &choice) == EOF)
            break;
        switch (choice) {
        case 1:
            printf("\n\nEnter the value: ");
            scanf("%d", &val);
            ndinsbeg(&ndptr, val);
            ndprint(ndptr);
            break;
        case 2:
            printf("\n\nEnter the value: ");
            scanf("%d", &val);
            ndinsend(&ndptr, val);
            ndprint(ndptr);
            break;
        case 3:
            printf("\n\nEnter the positon: ");
            scanf("%d", &pos);
            printf("Enter the value: ");
            scanf("%d", &val);
            if (ndinsat(&ndptr, pos, val) == EXIT_SUCCESS)
                ndprint(ndptr);
            else
                printf("\nOperation failed: non-zero exit status.");
            break;
        case 4:
            printf("\n\nEnter the positon: ");
            scanf("%d", &pos);
            if (nddelat(&ndptr, pos) == EXIT_SUCCESS)
                ndprint(ndptr);
            else
                printf("Operation failed: non-zero exit status.\n");
            break;
        case 5:
            printf("\n\nEnter the positon: ");
            scanf("%d", &pos);
            printf("Enter the value: ");
            scanf("%d", &val);
            if (ndupdate(&ndptr, pos, val) == EXIT_SUCCESS)
                ndprint(ndptr);
            else
                printf("\nOperation failed: non-zero exit status.\n");
            break;
        case 6:
            printf("\nEnter the value: ");
            scanf("%d", &val);
            int searchresult = ndsearch(ndptr, val);
            if (searchresult != -1)
                printf("Value '%d' found at [%d].", val, searchresult);
            else
                printf("Value '%d' not found.", val);
            break;
        case 7:
            printf("\n\n");
            ndprint(ndptr);
            break;
        default:
            printf("\n\nInvalid Choice.");
            break;
        }
    }
}
