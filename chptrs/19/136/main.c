typedef struct node {
    int val;
    struct node *next;
} node_t;

// TODO zero or one arguments?
node_t *ndcreate()
{
    node_t nd = malloc(sizeof(node_t));
    if (!nd)
        return 0;
	nd.next = NULL;
    return &node_t;
}

void ndinsertbeg(node_t *nd, int val)
{
    node_t *tail = ndcreate();

    tail->val = val;
    tail->next = nd;
	nd = tail;
}

void *ndinsertend(node_t *nd, int val)
{
	node_t *head = ndcreate();
	head->val = val;
	nd->next = head;
}
void *ndinsertat(node *nd, int val, int pos)
{
	int i = 0;
	node_t *tmp = nd;
	while (i != pos) {
		if (tmp->next == NULL)
			exit(1);
		tmp = nd->next;
		i++;
	}
}
node_t *nddelat();
node_t *ndsearch();
node_t *ndupdate();
void nddisplay();

int main()
{
    node_t llist = ndcreate();
    int choice = '\0';

    while (true) {
        printf("1: Insert node at beginning");
        printf("2: Insert node at end");
        printf("3: Insert node at a specific position");
        printf("4: Delete Node from any Position");
        printf("5: Update Node Value");
        printf("6: Search Element in the linked list");
        printf("7: Display List");
        printf("8: Exit");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            ndinsertbeg();
            break;
        case 2:
            ndinsertend();
            break;
        case 3:
            ndinsertat();
            break;
        case 4:
            nddelat();
            break;
        case 5:
            ndupdate();
            break;
        case 6:
            ndsearch();
            break;
        case 7:
            nddisplay();
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
