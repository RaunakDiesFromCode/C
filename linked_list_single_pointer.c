#include <stdio.h>
void insert_beg(int);
void insert_end(int);
void insert_before(int);
void insert_after(int);
void del_beg();
void del_end();
void del_pos();
void count();
void display();

typedef struct node
{
  int info;
  struct node *next;
} ND;
ND *start = NULL;

void main()
{
  int opt, val;
  clrscr();
  while (1)
  {
    printf("\n1:insert at beginning\n2:insert at end\n3:insert before a node\n4:insrt after a node\n5:delete at beginning\n6:delete at end\n7:delete at any position\n8:display\n9:count\n10:reverse\n11:reverse display\n12:exit\nenter your option: ");
    scanf("%d", &opt);
    switch (opt)
    {
    case 1:
      printf("enter the value to be inserted at beginning:\n");
      scanf("%d", &val);
      insert_beg(val);
      break;
    case 2:
      printf("enter the value to be inserted at end:\n");
      scanf("%d", &val);
      insert_end(val);
      break;
    case 3:
      printf("enter value to be inserted:\n");
      scanf("%d", &val);
      insert_before(val);
      break;
    case 4:
      printf("enter value to be inserted:\n");
      scanf("%d", &val);
      insert_after(val);
      break;
    case 5:
      del_beg();
      break;
    case 6:
      del_end();
      break;
    case 7:
      del_pos();
      break;
    case 8:
      display();
      break;
    case 9:
      count();
      break;
    case 10:
      reverse();
      break;
    case 11:
      rev_display(start);
      break;
    case 12:
      exit(1);
      break;
    default:
      printf("wrong input\n");
    }
  }
}

void insert_beg(int data)
{
  ND *newnode;
  newnode = (ND *)malloc(sizeof(ND));
  newnode->info = data;
  if (start == NULL)
  {
    newnode->next = NULL;
    start = newnode;
  }
  else
  {
    newnode->next = start;
    start = newnode;
  }
}

void insert_end(int data)
{
  ND *newnode, *temp = start;
  newnode = (ND *)malloc(sizeof(ND));
  newnode->info = data;
  newnode->next = NULL;
  if (start == NULL)
  {
    start = newnode;
  }
  else
  {
    while (temp->next != NULL)
    {
      temp = temp->next;
    }
    temp->next = newnode;
  }
}

void insert_before(int data)
{
  int x;
  ND *newnode;
  ND *temp = start, *temp1 = start;
  newnode = (ND *)malloc(sizeof(ND));
  newnode->info = data;
  printf("enter the node before the newnode is inserted:");
  scanf("%d", &x);
  while (temp != NULL)
  {
    if (temp->info == x)
    {
      if (temp == temp1)
      {
        newnode->next = temp;
        start = newnode;
        return;
      }
      temp1->next = newnode;
      newnode->next = temp;
      return;
    }
    temp1 = temp;
    temp = temp->next;
  }
  printf("\nnode not found\n");
}

void insert_after(int data)
{
  int x;
  ND *newnode;
  ND *temp = start, *temp1 = start;
  newnode = (ND *)malloc(sizeof(ND));
  newnode->info = data;
  printf("enter the node after the newnode is inserted:");
  scanf("%d", &x);
  while (temp != NULL)
  {
    temp1 = temp->next;
    if (temp->info == x)
    {
      temp->next = newnode;
      newnode->next = temp1;
      return;
    }
    temp = temp->next;
  }
  printf("\nno node found\n");
}

void del_beg()
{
  ND *temp = start;
  if (start == NULL)
    printf("\nlist is already  empty\n");
  else
  {
    start = start->next;
    free(temp);
  }
  printf("\n no node found!\n");
}

void del_end()
{
  ND *temp = start, *temp1;
  if (start == NULL)
    printf("list is already empty\n");
  else
  {
    while (temp->next != NULL)
    {
      temp1 = temp;
      temp = temp->next;
    }
    temp1->next = NULL;
    free(temp);
  }
}

void del_pos()
{
  int x;
  ND *temp = start;
  ND *prev = NULL;
  ND *temp1;
  printf("enter node which will be deleted:");
  scanf("%d", &x);
  if (start == NULL)
  {
    printf("list is already emty\n");
    return;
  }
  while (temp != NULL)
  {
    if (temp->info == x)
    {
      if (temp == start)
      {
        start = start->next;
        free(temp);
        return;
      }
      prev = temp;
      temp = temp->next;
      temp1->next = prev->next;
      free(prev);
      return;
    }
    temp1 = temp;
    temp = temp->next;
  }
  printf("\nnode not found\n");
}

void display()
{
  ND *temp = start;
  if (start == NULL)
    printf("list is empty\n");
  else
  {
    while (temp->next != NULL)
    {
      printf("%d->", temp->info);
      temp = temp->next;
    }
    printf("%d->null\n", temp->info);
  }
  getch();
}

void count()
{
  ND *temp = start;
  int count = 0;
  if (start == NULL)
    printf("list is empty\n");
  else
  {
    while (temp != NULL)
    {
      count++;
      temp = temp->next;
    }
    printf("number of elements in the list is : %d\n", count);
  }
  getch();
}
