#include<stdio.h>
#include<stdlib.h>

struct Node
{
 int data;
 struct Node *next;

};

void Insert_begin(struct Node **, int);
void Insert_middle(struct Node *, int, int);
void Insert_end(struct Node **, int);
void Delete_begin(struct Node **);
void Delete_middle(struct Node *, int);
void Delete_end(struct Node **);
void Traversal(struct Node *);
struct Node*search(struct Node *, int);

int main()
{
 int choice, wantcontinue, pos, data, key;
 printf("Enter choice 1.Insert at begin 2.Insert at middle 3.Insert at end 4.Delete from begin 5.Delete from middle 6.Delete from end 7.Traversal 8.Search \n");
 struct Node *head=NULL, *r;
 do
 {
  printf("Enter choice \n");
  scanf("%d", &choice);
  switch(choice)
  {
   case 1: printf("Enter value \n");
   	   scanf("%d", &data);
   	   Insert_begin(&head, data);
   	   break;
   	   
   case 2: printf("Enter value and position \n");
   	   scanf("%d %d", &data, &pos);
   	   Insert_middle(head, data, pos);
   	   break;
   	   
   case 3:   printf("Enter value \n");
   	   scanf("%d", &data);
   	   Insert_end(&head, data);
   	   break;
   	   
   case 4: Delete_begin(&head);
   	   break;
   	    	   
   case 5: printf("Enter position to delete \n");
   	   scanf("%d", &pos);
   	   Delete_middle(head, pos);
   	   break;
   	   
   case 6: Delete_end(&head);
   	   break;
   	   
   case 7: Traversal(head);
   	   break;
   	   
   case 8: printf("Enter the key \n");
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


void Insert_begin(struct Node **head, int data)
{
 struct Node *p, *temp;
 temp = (struct Node*)malloc(sizeof(struct Node));
 temp->data = data;
 p = *head;
 if(*head == NULL)
 {
  temp->next = temp;
  *head = temp;
 }
 else
 {
  while(p->next != *head)
  {
   p = p->next;
  }
  temp->next = *head;
  p->next = temp;
  *head = temp;
 }
}


void Insert_middle(struct Node *head, int data, int pos)
{
 struct Node *temp, *p, *q;
 int k = 1;
 temp = (struct Node *)malloc(sizeof(struct Node));
 temp->data = data;
 p = head;
 while(k<pos)
 {
  q = p;
  p = p->next;
  k++;
 }
 q->next = temp;
 temp->next = p;
}


void Insert_end(struct Node **head, int data)
{
 struct Node *p, *temp;
 temp = (struct Node *)malloc(sizeof(struct Node));
 temp->data = data;
 p = *head;
 if(*head == NULL)
 {
  temp->next = temp;
  *head =  temp;
 }
 else
 {
  while(p->next != *head)
  p = p->next;
  p->next = temp;
  temp->next = *head;
 }
}


void Delete_begin(struct Node **head)
{
 struct Node *p = *head;
 if(*head == NULL)
 {
  printf("Empty CLL \n");
  return;
 }
 if((*head)->next == *head)
 {
  *head = NULL;
  free(p);
 }
 else
 { 
  while(p->next != *head)
  {
   p = p->next;
  }
  *head = (*head)->next;
  p->next = *head;
  free(p);
 }
}


void Delete_middle(struct Node *head, int pos)
{
 struct Node *p, *q;
 int k = 1;
 p = head;
 while(k<pos)
 {
  q = p;
  p = p->next;
  k++;
 }
 q->next = p->next;
 free(p);
}


void Delete_end(struct Node **head)
{
 struct Node *p = *head, *q;
 if(*head == NULL)
 {
  printf("Empty CLL \n");
  return;
 }
 if((*head)->next == *head)
 {
  *head = NULL;
  free(p);
 }
 else
 {
  while(p->next != *head)
  {
   q = p;
   p = p->next;
  }
  q->next = *head;
  free(p);
 }
}


void Traversal(struct Node *head)
{
 struct Node *p;
 p = head;
 do
 {
  printf("%d \t", p->data);
  p = p->next;
 }
 while(p != head);
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
