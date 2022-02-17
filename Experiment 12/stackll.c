#include<stdio.h>
#include<stdlib.h>

struct SNode
{
 int data;
 struct SNode *next;
};

void push(struct SNode**, int);
int pop(struct SNode**);
void display(struct SNode*);

int main()
{
 int choice, p, data;
 printf("1.Push 2.Pop 3.Display 4.Quit \n");
 struct SNode *head = NULL;
 do
 {
  printf("Enter choice:\n");
  scanf("%d", &choice);
  switch(choice)
  {
   case 1: printf("Enter a element to push:\n");
           scanf("%d", &data);
           push(&head, data);
           break;
           
   case 2: p = pop(&head);
           printf("Popped element is: %d\n", p);
           break;
           
   case 3: display(head);
           break;
           
   case 4: break;
   
   default: printf("Wrong choice \n ");
  }
 }
 while(choice != 4);
 return 0;
}


void push(struct SNode **head, int data)
{
 struct SNode *temp;
 temp = (struct SNode *) malloc(sizeof(struct SNode));
 temp -> data = data;
 temp ->next = (*head);
 (*head) = temp;
}


int pop(struct SNode **head)
{
 struct SNode *p;
 int x;
 x = (*head) -> data;
 p = *head;
 (*head) = (*head) -> next;
 free(p);
 return x;
}


void display(struct SNode* head)
{
 int i;
 struct SNode* p;
    p=head;
    if(p==NULL)
    {
     printf("Stack is empty\n");
    }
    else
      printf("Stack elements:");
      while(p!=NULL)
      {
       printf("%d\n",p->data);
       p = p->next;
      }
}
