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
struct node* newlink(struct node*h)
{ int c;
  struct node *ptr=h,*q=NULL,*even=NULL,*odd=NULL;
if(ptr->data%2==0)
{c=1;
 even=ptr;} 
else
{
c=-1;
odd=ptr;}
while(ptr->next!=NULL)
{
	if(c==1)
	{
		if(even->next->data%2==0)
		{   c=1;
			even->link= even->next;
			even->link->link=NULL;
			even=even->next;
		}
		else
		{ c=-1;
		if(odd==NULL)
		{odd=even->next;
		q=odd;}
		else
		{odd->link=even->next;
		odd->link->link=NULL;
		odd=even->next;}
	}
	}
	else{
		if(odd->next->data%2!=0)
		{   c=-1;
			odd->link= odd->next;
			odd->link->link=NULL;
			odd=odd->next;
		}
		else
		{ c=1;
		if(even==NULL)
		{
		even=odd->next;
		q=even;}
		else
		{
		even->link = odd->next;
		even->link->link=NULL;
		even=odd->next;}
	}
	}
	ptr=ptr->next;
}
return q;
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
void displayNew(struct node*q,struct node*h)
{   int c;
	struct node*odd,*even;
	printf("1.Display odd elements in list\n");
	printf("2.Display even elements in list\n");
	printf("enter choice:");
	scanf("%d",&c);
	switch(c)
	{
		case 1:
			if(h->data%2!=0)
			odd = h;
			else
			odd = q;
			while(odd->link != NULL)
        	{  
		        printf("%d->",odd->data);
		        odd = odd->link;
	        }
        	printf("%d",odd->data);
        	printf("\n");
        	break;
        case 2:	
            if(h->data%2==0)
            even=h;
            else
            even=q;
		   	while(even->link!= NULL)
        	{   
		        printf("%d->",even->data);
		        even = even->link;
	        }
        	printf("%d",even->data);
        	printf("\n");
        	break;
        default:
		    printf("incorrect option\n");	
    }
}
int main()
{   struct node*head=NULL,*q;
	int arr[8]={13,24,34,45,55,67,78,89};
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
			q = newlink(head);
			printf("New link created\n");
		    displayNew(q,head);
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


//   if(ptr->data %2 == 0)
//   	even=ptr;
//   	else
//   	odd = ptr;
//   	ptr=ptr->next;
//   	while(ptr->next!=NULL)
//   	{
//   		if(ptr->data %2== 0)
//	   {
//		if(even!=NULL) 
//   		{
//   			even->link= ptr;
//   			even->link->link=NULL;
//   			even=ptr;
//		   }
//		else
//		{
//			even=ptr;
//		}
//	}
//	else
//	{
//		if(odd!=NULL)
//		{
//		    odd->link= ptr;
//   			odd->link->link=NULL;
//   			odd=ptr;
//		}
//		else
//		{
//			odd=ptr;
//		}
//   	 }
//		
//		ptr=ptr->next;
//	}
//}
