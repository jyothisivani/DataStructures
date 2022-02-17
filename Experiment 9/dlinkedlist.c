#include<stdio.h>
#include<stdlib.h>

struct Node
{
 int data;
 struct Node *next;
 struct Node *prev;
};

void Insert(struct Node **, int, int);
void Delete(struct Node **, int);
void Traversal(struct Node *);
struct Node*search(struct Node *, int);

int main()
{
 int choice, wantcontinue, pos, data, key;
 printf("Enter choice 1.Insert 2.Delete 3.Traversal 4.Search");
 struct Node *head=NULL, *r;
 do
 {
  printf("Enter choice \n");
  scanf("%d", &choice);
  switch(choice)
  {
   case 1: printf("Enter value and position \n");
   	   scanf("%d %d", &data, &pos);
   	   Insert(&head, data, pos);
   	   break;
   	   
   case 2: printf("Enter position to delete \n");
   	   scanf("%d", &pos);
   	   Delete(&head, pos);
   	   break;
   	   
   case 3: Traversal(head);
   	   break;
   	   
   case 4: printf("Enter the key \n");
   	   scanf("%d", &key);
   	   r=search(head, key);
   	   if (r==NULL)
   	      printf("Not Found \n");
   	   else
   	      printf("Successful \n");
  }
  printf("Want to continue, Enter: \n");
  scanf("%d", &wantcontinue);
 }
 while(wantcontinue == 1);
 return 0;
}


void Insert(struct Node **head, int data, int pos)
{
 struct Node *temp, *p;
 int k = 1;
 temp = (struct Node *)malloc(sizeof(struct Node));
 temp->data = data;
 p = *head;
 if(pos == 1)
 { 
  temp->next = *head;
  temp->prev = NULL;
  if(*head)
    (*head)->prev = temp;
    *head = temp;
 }
 else
 {
  while((k<pos-1)&&(p->next != NULL))
  {
   p = p->next;
   k++;
  }
  if(k != pos-1)
   {
    printf("Position doesnot exists");
    return;
   }
   temp->next = p->next;
   temp->prev = p;
   if(p->next)
   {
    p->next->prev = temp;
    p->next = temp;
   }
 }
}


void Delete(struct Node **head, int pos)
{
 struct Node *p, *q;
 int k = 1;
 p = *head;
 if(pos == 1)
 {
  *head = (*head)->next;
  if(*head)
     (*head)->prev = NULL;
  free(p);
 }
 else
 {
  while((k<pos)&&(p->next != NULL))
  {
   p = p->next;
   k++;
  }
  if(k != pos)
  {
   printf("Position doesnot exists \n");
   return;
  }
  q = p->prev;
  q->next = p->next;
  if(p->next)
    p->next->prev = q;
  free(p);
 }
}


void Traversal(struct Node *head)
{
 struct Node *p;
 p = head;
 while(p != NULL)
 {
  printf("%d\t", p->data);
  p = p->next;
 }
}


struct Node*search(struct Node *head,int key)
{
 struct Node *p;
 p = head;
 while(p != NULL)
 {
  if(p->data = key)
  {
   return p;
  }
  p = p->next;
 }
 return NULL;
}
