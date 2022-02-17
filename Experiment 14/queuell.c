#include<stdio.h>
#include<stdlib.h>

struct Node
{
 int data;
 struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

void Enqueue(int);
void Dequeue();
void display();

int main()
{
 int choice, n, i, data;
 printf("Enter your choice:\n");
 while(choice != 0)
 {
   printf("\n 1.Insert 2.Delete 3.Display \n");
   scanf("%d", &choice);
   switch(choice)
   {
    case 1: 
            printf("Enter your data: \n");
      
             scanf("%d", &data);
             Enqueue(data);
           
            break;
            
    case 2: Dequeue();
            break;
            
    case 3: display();
            break;
            
    default: printf("Wrong choice");
   }
 }
}

void Enqueue(int item)
{
 struct Node *newn;
 newn = (struct Node*)malloc(sizeof(struct Node));
 newn->data = item;
 newn->next = NULL;
 if((front == NULL)&&(rear == NULL))
 {
  front = rear = newn;
 }
 else
 {
  rear->next = newn;
  rear = newn;
 }
}


void Dequeue()
{
 struct Node *temp;
 temp = front;
 if((front == NULL)&&(rear == NULL))
 {
  printf("Queue is Empty");
 }
 else if(front->next)
 {
  front = rear = NULL;
  free(temp);
 }
  else
 {
  front = front->next;
  free(temp);
 }
}


void display()
{
 struct Node *temp;
 if((front == NULL)&&(rear == NULL))
 {
  printf("Queue is Empty");
 }
 else
 {
  temp = front;
  while(temp)
  {
   printf("%d", temp->data);
   temp = temp->next;
  }
 }
}
