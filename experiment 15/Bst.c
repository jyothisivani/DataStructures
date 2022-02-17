#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node *l_child,*r_child;
};
struct node* Insert(struct node*,int);
struct node* Delete(struct node*,int);
struct node* Search(struct node*,int);
void Inorder(struct node*);
void Preorder(struct node*);
void Postorder(struct node*);
struct node* new_node(int);
struct node* find_min(struct node*);
int main(){
	int choice,want_continue,data,key;
	printf("Enter choice 1.insert, 2.delete, 3.search, 4.inorder, 5.preorder, 6.postorder\n");
	struct node *head = NULL,*root,*r;
	do{
		printf("Enter choice:\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:printf("Enter value:");
			       scanf("%d",&data);
			       root = Insert(root,data);
			       break;
			case 2:printf("Enter item to be deleted:");
			       scanf("%d",&data);
			       root = Delete(root,data);
			       break;
			case 3:printf("Enter the key:");
			       scanf("%d",&key);
			       r = Search(root,key);
			       if(r == NULL){
			       printf("not found\n");
			       }else{
			       printf("Successful\n");
			       }
			       break;
		       case 4:Inorder(root);
		              break;
		       case 5:Preorder(root);
		              break;
		       case 6:Postorder(root);
		              break;
		              }printf("Want to continue, enter 1:");
		               scanf("%d",&want_continue);
		               }while(want_continue == 1);
		               
		       return 0;
}
struct node* Insert(struct node* root,int x){
	if(root == NULL){
		return new_node(x);
	}else if(x>(root->data)){
		root->r_child = Insert(root->r_child,x);
	}else{
		root->l_child = Insert(root->l_child,x);
	}
	return root;
}

struct node* Delete(struct node *root, int x)
{
	if(root==NULL)
		return NULL;
	if (x>root->data)
		root->r_child = Delete(root->r_child, x);
	else if(x<root->data)
		root->l_child = Delete(root->l_child, x);
	else
	{
	//No Children
	if(root->l_child==NULL && root->r_child==NULL)
	{
		free(root);
		return NULL;
	}
	//One Child
	else if(root->l_child==NULL || root->r_child==NULL)
	{
		struct node *temp;
		if(root->l_child==NULL)
		temp = root->r_child;
	else
		temp = root->l_child;
	free(root);
	return temp;
	}
	//Two Children
	else
	{
		struct node *temp = find_min(root->r_child);
		root->data = temp->data;
		root->r_child = Delete(root->r_child, temp->data);
	}
   }
   return root;
}

struct node* Search(struct node* root,int x){
	if(root == NULL || root->data == x){
		return root;
	}else if(x<root->data){
		return Search(root->l_child,x);
	}else{
		return Search(root->r_child,x);
	}
}

void Inorder(struct node *root){
	if(root == NULL){
		return;
	}
	Inorder(root->l_child);
	printf("%d ",root->data);
	Inorder(root->r_child);
}

void Preorder(struct node *root){
	if(root == NULL){
		return;
	}
	printf("%d ",root->data);
	Preorder(root->l_child);
	Preorder(root->r_child);
}

void Postorder(struct node *root){
	if(root == NULL){
		return;
	}
	Postorder(root->l_child);
	Postorder(root->r_child);
	printf("%d ",root->data);
}
		 
struct node* new_node(int x){
	struct node *p;
	p = malloc(sizeof(struct node));
	p->data = x;
	p->l_child = NULL;
	p->r_child = NULL;
	return p;
}

struct node* find_min(struct node* root){
	if(root = NULL)
		return NULL;
	else if(root->l_child != NULL)
		return find_min(root->l_child);
        return root;
}	
		       
