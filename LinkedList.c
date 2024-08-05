#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

struct record
{
    int roll;
    char name[100];
};

typedef struct record RD;

struct Node
{
    RD info;
    struct Node *next;
};

typedef struct Node ND;

void insert_begin(ND **ptr, RD item)
{
    printf("\n");
    ND *temp = (ND *)malloc(sizeof(ND));
    if (!temp)
    {
        printf("Memory allocation failed\n");
        return;
    }
    temp->info = item;
    temp->next = *ptr;
    *ptr = temp;
}

void insert_end(ND **ptr, RD item)
{
    printf("\n");
    ND *temp = (ND *)malloc(sizeof(ND));
    if (!temp)
    {
        printf("Memory allocation failed\n");
        return;
    }
    temp->info = item;
    temp->next = NULL;
    if (*ptr == NULL)
    {
        *ptr = temp;
        return;
    }
    ND *current = *ptr;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = temp;
}

void insert_before(ND **ptr, int item)
{
    printf("\n");
    ND *temp = (ND *)malloc(sizeof(ND));
    if (!temp)
    {
        printf("Memory allocation failed\n");
        return;
    }
    printf("Enter the roll number: ");
    scanf("%d", &temp->info.roll);
    printf("Enter the name: ");
    scanf("%s", temp->info.name);

    ND *current = *ptr;
    ND *prev = NULL;
    while (current)
    {
        if (current->info.roll == item)
            break;
        prev = current;
        current = current->next;
    }
    if (!current)
    {
        printf("Node not found\n");
        free(temp);
        return;
    }
    if (prev == NULL)
    {
        temp->next = *ptr;
        *ptr = temp;
    }
    else
    {
        prev->next = temp;
        temp->next = current;
    }
}

void insert_after(ND *ptr, int item)
{
    printf("\n");
    ND *current = ptr;
    while (current)
    {
        if (current->info.roll == item)
            break;
        current = current->next;
    }
    if (!current)
    {
        printf("Node not found\n");
        return;
    }
    ND *temp = (ND *)malloc(sizeof(ND));
    if (!temp)
    {
        printf("Memory allocation failed\n");
        return;
    }
    printf("Enter the roll number: ");
    scanf("%d", &temp->info.roll);
    printf("Enter the name: ");
    scanf("%s", temp->info.name);
    temp->next = current->next;
    current->next = temp;
}

void delete_node(ND **ptr, int item)
{
    printf("\n");
    ND *current = *ptr;
    ND *prev = NULL;
    while (current)
    {
        if (current->info.roll == item)
            break;
        prev = current;
        current = current->next;
    }
    if (!current)
    {
        printf("Node not found\n");
        return;
    }
    printf("Roll number: %d\n", current->info.roll);
    printf("Name: %s\n", current->info.name);
    if (prev == NULL)
    {
        *ptr = current->next;
    }
    else
    {
        prev->next = current->next;
    }
    free(current);
}

int count_nodes(ND *ptr)
{
    printf("\n");
    int count = 0;
    while (ptr)
    {
        count++;
        ptr = ptr->next;
    }
    return count;
}

ND *search_node(ND *ptr, int item)
{
    printf("\n");
    while (ptr)
    {
        if (ptr->info.roll == item)
            return ptr;
        ptr = ptr->next;
    }
    return NULL;
}

void traverse(ND *ptr)
{
    printf("\n");
    if (!ptr)
    {
        printf("The list is empty.\n");
        return;
    }

    printf("Linked list contents:\n");
    printf("Roll number\tName\n");
    while (ptr)
    {
        
        printf("%d\t\t%s\n", ptr->info.roll, ptr->info.name);
        ptr = ptr->next;
    }
}

int main()
{
    printf("\n");
    ND *start = NULL;
    RD rec;
    int choice = 1, s;

    while (choice != 9)
    {
        printf("\n1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert before a node\n");
        printf("4. Insert after a node\n");
        printf("5. Delete a node\n");
        printf("6. Count the number of nodes\n");
        printf("7. Search a node\n");
        printf("8. Traverse the list\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter the roll number: ");
            scanf("%d", &rec.roll);
            printf("Enter the name: ");
            scanf("%s", rec.name);
            insert_begin(&start, rec);
            break;
        case 2:
            printf("\nEnter the roll number: ");
            scanf("%d", &rec.roll);
            printf("Enter the name: ");
            scanf("%s", rec.name);
            insert_end(&start, rec);
            break;
        case 3:
            printf("\nEnter the roll number before which you want to insert: ");
            scanf("%d", &s);
            insert_before(&start, s);
            break;
        case 4:
            printf("\nEnter the roll number after which you want to insert: ");
            scanf("%d", &s);
            insert_after(start, s);
            break;
        case 5:
            printf("\nEnter the roll number to delete: ");
            scanf("%d", &s);
            delete_node(&start, s);
            break;
        case 6:
            printf("\nNumber of nodes: %d\n", count_nodes(start));
            break;
        case 7:
            printf("\nEnter the roll number to search: ");
            scanf("%d", &s);
            ND *node = search_node(start, s);
            if (node != NULL)
            {
                printf("Roll number: %d\n", node->info.roll);
                printf("Name: %s\n", node->info.name);
            }
            else
            {
                printf("Node not found\n");
            }
            break;
        case 8:
            traverse(start);
            break;
        case 9:
            break;
        default:
            printf("\nInvalid choice\n");
        }
    }
    return 0;
}
