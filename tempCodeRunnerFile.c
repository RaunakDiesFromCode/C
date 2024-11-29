#include <stdio.h>
#include <stdlib.h>

typedef struct tree
{
  int data;
  struct tree *left;
  struct tree *right;
} tree;

tree *create(int value)
{
  tree *result = (tree *)malloc(sizeof(tree));

  if (result != NULL)
  {
    result->data = value;
    result->left = NULL;
    result->right = NULL;
  }
  return result;
}

void printTree(tree *root, int level)
{
  // Base case: if the current node is NULL, just return
  if (root == NULL)
  {
    return;
  }

  // Indentation based on tree depth
  for (int i = 0; i < level; i++)
  {
    printf("  "); // Add two spaces per level for visual hierarchy
  }

  // Print the current node's data
  printf("Node Data: %d\n", root->data);

  // Print left child, if exists
  if (root->left != NULL)
  {
    for (int i = 0; i < level; i++)
    {
      printf("  "); // Maintain indentation for children
    }
    printf("Left Child of %d:\n", root->data);
    printTree(root->left, level + 1);
  }
  else
  {
    for (int i = 0; i < level; i++)
    {
      printf("  ");
    }
    printf("Left Child of %d: NULL\n", root->data);
  }

  // Print right child, if exists
  if (root->right != NULL)
  {
    for (int i = 0; i < level; i++)
    {
      printf("  ");
    }
    printf("Right Child of %d:\n", root->data);
    printTree(root->right, level + 1);
  }
  else
  {
    for (int i = 0; i < level; i++)
    {
      printf("  ");
    }
    printf("Right Child of %d: NULL\n", root->data);
  }
}

int main()
{
  // Create nodes
  tree *n1 = create(13);
  tree *n2 = create(10);
  tree *n3 = create(15);
  tree *n4 = create(54);

  // Build tree structure
  n1->left = n2;
  n1->right = n3;
  n2->right = n4;

  // Print the tree starting from root
  printTree(n1, 0);

  return 0;
}
