#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

void createlist(struct node *h)//ead,struct node *newnode,struct node *ptr)
{
	//newnode = (struct node*)malloc(sizeof(struct node));
	printf("enter value(put [-99] to end list):");
	scanf("%d",&h->data);
	h->next=NULL;
	if(h->data !=-99)
	{
		h->next=(struct node*)malloc(sizeof(struct node));
		createlist(h->next);
	}	
}

struct node* reverselist(struct node*h)//struct node*prev)
{
	struct node*ptr=h,*revnext=NULL,*prev=NULL;
	while(ptr!=NULL)
	{   revnext=ptr->next;
    	ptr->next=prev;
    	prev=ptr;
    	ptr=revnext;
    }
    h=prev;
    return h;
//if(ptr->next==NULL)
//{ h=ptr;
//return h;}
//else
//{  
//   revnext=ptr->next;
//   ptr->next=prev;
//   prev=ptr;
//   ptr=revnext;
//   reverselist(ptr,prev);
//}
}

void displaylist(struct node *h)
{
struct node *ptr=h;
while(ptr->next != NULL)
   {
	printf("%d->",ptr->data);
	ptr = ptr->next;
   }
   printf("%d",ptr->data);
}

struct node* search(struct node*h,int n)
{ while(h!=NULL)
   {
   	if(h->next->data==n)
   	return h;
   	else
   	h=h->next;
   }
  return NULL; 
}

struct node* insertelement(struct node*h)
{int e,c,t,pos; struct node*ptr=h;  
printf("enter the element to be inserted"); 
scanf("%d",&e);
struct node*n = (struct node*)malloc(sizeof(struct node));
n->data=e;
printf("3 options available\n");
printf("1. Insert at the beginning\n");
printf("2.insert at any position in between\n");
printf("3.insert at the end\n");
printf("enter your choice:");
scanf("%d",&c);
switch(c)
{
	case 1:
		n->next=h;
		h=n;
		return h;
		break;
	case 2:
	    printf("enter the position of insertion "); 
		scanf("%d",&pos);t=2;
		while(ptr->next!=NULL)
	    { 
		  if(pos==c)
		  {n->next=ptr->next;
		   ptr->next=n;
		   return h;
		  }
		  	else
		    {
			t++;
			ptr=ptr->next;
	   	    }}break;
	case 3:
	    while(ptr!=NULL)
		{
			if(ptr->next==NULL)
			{
				ptr->next=n;
				n->next=NULL;
				return h;
			}
			else
			ptr=ptr->next;
		}break;	  
		}	
    }

//if(p==1)
//{ 
//	h->next=head;
//	head = h;
//}


struct node* deleteele(struct node*h)
{ int d;
 struct node*ptr=h,*s,*curr;
printf("enter the element to be deleted ");  
scanf("%d",&d);
if(h->data==d)
{h=h->next;
 free(ptr);
}
else{
s = search(h,d);  //search function called
if(s!=NULL)
{ //while(ptr!=NULL)
  //{ if(ptr==s){
  curr=s->next;
  s->next=s->next->next;
  free(curr);
  //else
  //ptr=ptr->next;
}
else
printf("element not present in the list\n");
}
return h;
}

void main()
{
	struct node*head=NULL,*h;
	int ch,ele, e, d;
	do
	{
	printf("1.create list\n");
	printf("2.display list\n");
	printf("3.search element\n");
	printf("4.insert element\n");
	printf("5.delete element\n");
	printf("6.Reverse list\n");
	printf("7.exit\n");
	printf("enter choice:");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			printf("create list\n");
        	head= (struct node*)malloc(sizeof(struct node));
	        createlist(head);
			printf("\n");break;
	    case 2:
		    printf("display list\n");
        	displaylist(head); 
			printf("\n");break;
        case 3:
		    printf("enter the element to be searched:"); 
			scanf("%d",&ele);
			h=search(head,ele); 
			if(h==NULL)
			printf("%d is not found in the list",ele);
			else
			printf("%d is present in the list",ele); 
			printf("\n");break;
		case 4:

//		    printf("enter the position of insertion"); int pos;
//		    scanf("%d",&pos);
		    head = insertelement(head);  
			printf("\n");break;
		case 5:
		   
		    head=deleteele(head); 
			printf("\n");break;
		case 6:
		    head=reverselist(head);//,prev);
			break;	
	    }
    }while(ch!=7);
}
