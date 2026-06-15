#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
struct node{
	char name[25];
	struct node **children;
	bool isfile;
	int count;
	int capacity;
};
struct node *play(struct node *root,char *name,bool isfile);
void display(struct node *root);
struct node *create(char *name,bool isfile,int count,int capacity){
	struct node *newnode=malloc(sizeof(struct node));
	strcpy(newnode->name,name);
	newnode->children=NULL;
	newnode->isfile=isfile;
	newnode->count=count;
	newnode->capacity=capacity;
	return newnode;
}

void addchild(struct node *root,bool isfile,char *name){
		if(root->children==NULL){
			root->count=0;
			root->children=malloc(sizeof(struct node*));
			root->children[root->count]=create(name,isfile,0,0);
			root->count++;
			root->capacity=1;
			return;
}
if(root->count==root->capacity){
	root->capacity=root->capacity*2;
	root->children=realloc(root->children,root->capacity*sizeof(struct node*));
	root->children[root->count]=create(name,isfile,0,0);
	root->count++;
	return;
}
else if(root->count<root->capacity){
	root->children[root->count]=create(name,isfile,0,0);
	root->count++;
	return;
}
}
void display(struct node *root){
if(root==NULL){
	return;
}
	for(int i=0;i<=root->count-1;i++)
{    
	printf("|__%s\n",root->children[i]->name);
	display(root->children[i]);
}
}
void addfile(struct node *root){
	printf("creating file \n");
			int choice=0;
			char name[25];
			do{
			printf("1.create file in root\n");
			printf("2.create file in folder\n");
			printf("enter the choice\n");
			scanf("%d",&choice);
			switch(choice){
			case 1:
			    printf("creating file in root\n");
			    printf("enter the file name to add in the root\n");
			    scanf("%s",name);
		             addchild(root,true,name);
			     break;
			case 2:
			     printf("creating file in folder\n");
			     printf("enter the file name to search in the file manager\n");
			     scanf("%s",name);
			   struct node *newnode=NULL;
				  newnode=play(root,name,true);
			   printf("enter the file name to enter in the folder\n");
			   scanf("%s",name);
			   addchild(newnode,true,name);
			   break;
                	case 3:
			     printf("exit\n");
			     break;
			     default:
			     printf("invaild number try again!\n");
			     break;
			}
			}while(choice!=3);
			}
struct node *play(struct node *root,char *name,bool isfile){
	if(root==NULL){
		return NULL;
	}
	for(int i=0;i<=root->count-1;i++){
		if(strcmp(root->children[i]->name,name)==0){
			return root->children[i];
			break;
		}
		play(root->children[i],name,isfile);
	}
	return NULL;
}
void addfolder(struct node *root){
  printf("creating folder\n");
           int choice=0;
          char name[25];
do{
	printf("1.create folder in root\n");
	printf("2.create folder in folder\n");
	printf("3.exit\n");
	printf("enter the choice\n");
	scanf("%d",&choice);
	switch(choice){
	case 1:
printf("creating folder in root\n");
 printf("enter the folder name to add in the root\n");
 scanf("%s",name);
addchild(root,false,name);
 break;
case 2:
printf("creating folder in folder\n");
printf("enter the folder name to search in the file manager\n");
scanf("%s",name);
struct node *newnode=NULL;
   newnode=play(root,name,false);
printf("enter the folder name to enter in the folder\n");
scanf("%s",name);
 addchild(newnode,false,name);
 break;
case 3:
printf("exit\n");
break;
default:
 printf("invaild number triy again!\n");
 break;
}
}while(choice!=3);
}
int main(){
         struct node *root=NULL;
	 root=create("root",false,0,0);
	printf("file manager in c with tree style \n");
	int choice=0;
	do{
	printf("1.create file\n");
	printf("2.create folder\n");
	printf("3.display\n");
	printf("enter the choice\n");
	scanf("%d",&choice);
switch(choice){
	case 1:
		addfile(root);
		break;
	case 2:
		addfolder(root);
		break;
	case 3:
		printf("%s",root->name);
		display(root);
		break;
	case 4:
		printf("exit\n");
		break;
	default:
		printf("invalid number try again\n");
		break;
}
	}while(choice!=4);
free(root);
return 0;
}
