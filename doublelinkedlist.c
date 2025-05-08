#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node*prev;
	struct node*next;
};
void createnodes(struct node *h)
{   //static struct node*ptr = NULL;
	printf("enter value(put [-99] to end list):");
	scanf("%d",&h->data);
	//h->prev=ptr;
	//h->next=NULL;
	if(h->data !=-99)
	{   //ptr=h;
		h->next=(struct node*)malloc(sizeof(struct node));
		h->next->prev=h;
		createnodes(h->next);
	}
	else
	    h->next=NULL;
	
}
void displaylist(struct node *h)
{
struct node *t=h;
while(t->next != NULL)
{
	printf("%d->",t->data);
	t = t->next;
}
//printf("%d\n Rev list:",t->data);
//
//while(t->prev != NULL)
//{
//	printf("%d->",t->data);
//	t = t->prev;
//}

printf("%d",t->data);
}

struct node* search(struct node*h,int n)
{ while(h!=NULL)
   {
   	if(h->data==n)
   	return h->prev;
   	else
   	h=h->next;
   }
  return NULL; 
}

struct node* insertelement(struct node*h)
{
struct node*ptr=h; 
int c,p,e,pos;
printf("enter the element to be inserted "); 
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
		n->prev=NULL;
		n->next=h;
		h=n;
		return h;
		break;
	case 2:
	    printf("enter the position of insertion "); 
		scanf("%d",&pos);p=2;
		while(ptr->next!=NULL)
	    { 
		  if(pos==p)
		  {n->prev=ptr;
		   n->next=ptr->next;
		   ptr->next=n;
		   n->next->prev=n;
		   return h;
		  }
		  	else
		    {
			p++;
			ptr=ptr->next;
	   	    }
		}break;
	case 3:
	    while(ptr!=NULL)
		{
			if(ptr->next==NULL)
			{   ptr->next=n;
				n->prev=ptr;
				n->next=NULL;
				return h;
			}
			else
			ptr=ptr->next;
		}break;	  
		}	
    }

struct node* deleteele(struct node*h)
{ int d;
 struct node*ptr=h,*s,*curr;
printf("enter the element to be deleted ");  
scanf("%d",&d);
if(h->data==d)
{h=h->next;
 h->prev=NULL;
 free(ptr);
}
else{
s = search(h,d);  //search function called
if(s!=NULL)
{
 if(s->next->next == NULL)
{ curr=s->next;
  s->next = NULL;
  free(curr);
}
else
{ curr=s->next;
  s->next=s->next->next;
  s->next->prev=s;
  free(curr);
}}
else 
printf("element not present in the list\n");
}
return h;
}

void main()
{
	struct node*head,*h;
	int ch,ele, e, d;
	do
	{
	printf("1.create list\n");
	printf("2.display list\n");
	printf("3.search element\n");
	printf("4.insert element\n");
	printf("5.delete element\n");
	printf("6.exit\n");
	printf("enter choice:");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
		    //struct node*head;
	        printf("create list\n");
	        head= (struct node*)malloc(sizeof(struct node));
	        head->prev=NULL;
	        createnodes(head);
            break;
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
		    head = insertelement(head);  
			printf("\n");break;
		case 5:
		   
		    head=deleteele(head); 
			printf("\n");break;
	    default:
	    	printf("invalid option\n");break;
    }
	}while(ch!=6);
}
