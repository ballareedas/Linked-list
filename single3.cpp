#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
	struct node *link;
};
void createlist(int arr[8],struct node*h)
{ 
 for(int i=0;i<8;i++)
 {  
    h->data=arr[i];
	if(i==7)
	{h->next = NULL;
	}
	else
	{
	h->next=(struct node*)malloc(sizeof(struct node));
	h=h->next;}
 }
}
void newlink(struct node*h)
{  //int pos=0; 
   int c=0;
   struct node *ptr=h,*q=h; 
   while(ptr->next!=NULL)
   {
   if(ptr->next->next==NULL)
   { c++;
   	ptr=q->next;
   }
   else if(c==2)
   break;
   else
   {
	ptr->link=ptr->next->next;
    ptr->link->link = NULL;
    ptr=ptr->next;
	}
 }
}
//printf("\nNew link Head created\n");
//while(ptr->next->next!=NULL)
//{   if(pos==0)
//	{
//	    ptr->Neweven = ptr->next->next;
//	    ptr->Neweven->Neweven=NULL;
//	    pos=1;
//	}
//	else  //for odd 
//	{
//		ptr->Newodd = ptr->next->next;
//		ptr->Newodd->Newodd=NULL;
//		pos=0;
//	}
//	ptr=ptr->next;	
//} 
//}
void displayold(struct node*h)
{
	struct node*ptr=h;
	while(ptr->next != NULL)
	{
		printf("%d->",ptr->data);
		ptr = ptr->next;
	}
	printf("%d",ptr->data);
}
void displayNew(struct node*h)
{   int c;
	struct node*ptr=h;
	printf("1.Display odd pos. elements in list\n");
	printf("2.Display even pos. elements in list\n");
	printf("enter choice:");
	scanf("%d",&c);
	switch(c)
	{
		case 1:
			while(ptr->link != NULL)
        	{  
		        printf("%d->",ptr->data);
		        ptr = ptr->link;
	        }
        	printf("%d",ptr->data);
        	printf("\n");
        	break;
        case 2:
		   ptr=ptr->next;	
		   	while(ptr->link!= NULL)
        	{   
		        printf("%d->",ptr->data);
		        ptr = ptr->link;
	        }
        	printf("%d",ptr->data);
        	printf("\n");
        	break;
        default:
		    printf("incorrect option\n");	
    }
}
int main()
{   struct node*head=NULL;
	int arr[8]={12,23,34,45,56,67,78,89};
	int n,ch;
	printf("the array is:\n");
	for(int i =0;i<8;i++)
	{
		printf("%d\t",arr[i]);
	}
	do
	{
	printf("\n1.create linkedlist\n");
	printf("2.display original list\n");
	printf("3.display new list created\n");
	printf("4.exit\n");
	printf("enter choice: ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			head = (struct node*)malloc(sizeof(struct node));
	        createlist(arr,head);
	        printf("\n");
	        break;
		case 2:
			displayold(head);
			printf("\n");
			break;
		case 3:
			newlink(head);
			printf("New link created\n");
		    displayNew(head);
			printf("\n");
			break;
	    case 4: 
		    printf("exited");
	        break;
		default:
		    printf("wrong choice");	
	}
}while(ch!=4);	
return 0;
}
