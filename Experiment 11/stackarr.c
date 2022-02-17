#include<stdio.h>
#include<stdlib.h>
#define max 11

int Top = 0;
int Stack[11];

int IsEmpty(){ 
 return Top < 0;
}

int IsFull(){ 
 return Top == max - 1;
}

void push(int);
int pop();
void display();

int main()
{
 int choice, item;
 printf("1.Push 2.Pop 3.Display 4.Quit\n");
 do
 {
  printf("Enter choice: \n");
  scanf("%d", &choice);
  switch(choice)
  {
   case 1: printf("Enter the element to push:\n");
           scanf("%d", &item);
           push(item);
           break;
           
   case 2: pop();
           break;
           
   case 3: display();
           break;
           
   case 4: break;
   
   default: printf("Wrong choice \n ");
  }
 }
 while(choice != 4);
 return 0;
}

 
void push(int item)
{
 if(IsFull()== 1)
 {
  printf("Overflow \n");
 }
 else 
 {
  Top += 1;
  Stack[Top] = item;
 }
}

 
int pop()
{
 int x;
 if(IsEmpty() == 1)
 {
  printf("Underflow \n");
 }
 else 
 {
  x = Stack[Top];
  Top --;
  return x;
 }
}
 

void display()
{
  int i;
  if(Top<0)
  {
   printf("Stack is empty \n");
  }
  else
  printf("Stack:");
  for(i=1;i <= Top;i++)
  {
   printf("%d\n",Stack[i]);
  }
}
