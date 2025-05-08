#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
	struct node *Newodd;
	struct node *Neweven;
	//int pos;
};
void createlist(int n, int arr[],struct node*h)
{ 
 for(int i=0;i<n;i++)
 {  
    h->data=arr[i];
	if(i==n-1)
	{h->next = NULL;
	}
	else
	{
	h->next=(struct node*)malloc(sizeof(struct node));
	h=h->next;}
 }
}
void newlink(struct node*h)
{  int pos=0; //for even 
	struct node *ptr = h;
//	ptr->pos =1;
//	while(ptr->next!=NULL)
//    {ptr->next->pos = ptr->pos+1;
//    p = ptr->next->pos;
//    ptr=ptr->next;
//	}
//	ptr->pos =p+1;
//	ptr=h;
//	while(ptr->next->next!=NULL)
//	{neighbour = ptr->next->next; 
//	if(ptr->pos%2!=0)
//	{   ptr->Newodd = neighbour;
//	}
//	else
//	{   ptr->Neweven = neighbour;
//	}
//	ptr=ptr->next;
//}
//	ptr->Newodd=NULL;
//	ptr->Neweven=NULL;
//	ptr=ptr->next;
//	ptr->Neweven=NULL;
//	ptr->Newodd=NULL;
	
if(ptr->next->next!=NULL)
{
ptr->Newodd=ptr->next->next;
ptr=ptr->next;
}
while(ptr->next->next!=NULL)
{   if(pos=0)
	{
	    ptr->Neweven = ptr->next->next;
	    //ptr->Neweven->next = NULL;
	    pos=1;
	}
	else  //for odd 
	{
		ptr->Newodd = ptr->next->next;
		//ptr->Newodd->next =NULL;
		pos=0;
	}
	ptr=ptr->next;	
} 
	ptr->Newodd=NULL;
	ptr->Neweven=NULL;
	ptr=ptr->next;
	ptr->Neweven=NULL;
	ptr->Newodd=NULL;
}
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
			while(ptr->Newodd != NULL)
        	{  
		        printf("%d->",ptr->data);
		        ptr = ptr->Newodd;
	        }
        	printf("%d",ptr->data);
        	printf("\n");
        	break;
        case 2:
		   ptr=ptr->next;	
		   	while(ptr->Neweven != NULL)
        	{   
		        printf("%d->",ptr->data);
		        ptr = ptr->Neweven;
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
	int arr[10],n,ch;
	printf("Enter array size:" );
	scanf("%d",&n);
	printf("enter array elements:\n");
	for(int i =0;i<n;i++)
	{
		scanf("%d",&arr[i]);
	}
	do
	{
	printf("1.create linkedlist\n");
	printf("2.display original list\n");
	printf("3.display new list created\n");
	printf("4.exit\n");
	printf("enter choice: ");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			head = (struct node*)malloc(sizeof(struct node));
	        createlist(n,arr,head);
	        printf("\n");
	        break;
		case 2:
			displayold(head);
			printf("\n");
			break;
		case 3:
			newlink(head);
		    displayNew(head);
			printf("\n");
			break;
		default:
		    printf("wrong choice");	
	}
}while(ch!=4);	
return 0;
}


//if(ptr->next->next!=NULL) ptr->newodd=ptr->next->next; else ptr->newodd=NULL;
  //if(ptr->next->next!=NULL) ptr->newodd=ptr->next->next; else ptr->newodd=NULL; 
  	//ptr->neweven=ptr->next;
