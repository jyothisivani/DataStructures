#include<stdio.h>
#include<stdlib.h>
#define MAX 50

void Enqueue(int);
int Dequeue();
void display();

int Q[MAX], Front = -1, Rear = -1;

int Isfull(){
    return Rear == MAX -1;
    }
  
int Isempty(){
    return Front == -1;
    }
  
int main()
{
  int choice,item;
  while(1)
  {
    printf("1.Insert 2.Delete 3.Display \n");
    printf("Enter your choice:");
    scanf("%d", &choice);
    switch(choice)
    {
      case 1:  
               scanf("%d",&item);
               Enqueue(item);
               break;
               
      case 2:  item = Dequeue();
               printf("%d",item);
               break;
               
      case 3:  display();
               break;
               
      default:
               printf("Wrong choice \n");
               
    }
  }
}


void Enqueue(int item)
{
 if(Isfull() == 1)
 {
  printf("Overflow \n");
  return;
 }
 if(Front == -1)
    Front = Rear = 0;
 else
    Rear += 1;
    Q[Rear] = item;
}


int Dequeue()
{
 int item;
 if(Isfull() == 1)
 {
  printf("Underflow \n");
  exit(0);
 }
 item = Q[Front];
 if(Front == Rear)
    Front = Rear = -1;
 else
    Front += 1;
 return item;
}

 
void display()
{
 int i;
 if(Front == -1)
   printf("Queue is empty \n");
 else
 {
  printf("Queue is : \n");
  for(i = Front; i <= Rear; i++)
      printf("%d",Q[i]);
  printf("\n");
 }
}
