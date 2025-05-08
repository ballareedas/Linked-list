#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node*next;
};
void createlist(struct node*h,int arr[],int n)
{ int i;//n=sizeof(arr);
 for(i=0;i<n;i++)
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
void display(struct node* h)
{   
	struct node*ptr=h;
	while(ptr->next != NULL)
	{
		printf("%d->",ptr->data);
		ptr = ptr->next;
	}
	printf("%d",ptr->data);
}

//struct node* merge(node*h1,node*h2)
//{
// struct node*m=NULL;
// int c;
// while(h1!=NULL && h2!=NULL)
// { 
//   if(h1!=h2)
//   merge(h1->next,h2->next);
//   else
//   m=h1;
//   break;}
//   return m;
//	 	
//}
//void add2(node *h1,node *h2,int c[4])
//{
////	while(h1->next!=NULL)
////	{
////		h1=h1->next;
////	}
////	while(h2->data!=7)
////	{
////		h2=h2->next;
////	}
////	h1->next=h2;
//while(h1!=NULL ) 
//{
//	h1=h1->next;
//	}
//	while(h2!=NULL)
//	{
//	h2=h2->next;
//      }
//    for(int i=0;i<4;i++)
//    {
//    	h1->data=c[i];
//    	h2->data=c[i];
//    	if(i==3)
//    	{
//    		h1->next=h2->next=NULL;
//		}
//		else
//		{
//			h1->next=(struct node*)malloc(sizeof(struct node));
//	        h1=h1->next;
//	        h2->next=(struct node*)malloc(sizeof(struct node));
//	        h2=h2->next;
//		}
//	}
//}
struct node* merge(struct node* h1, struct node* h2) {
    struct node* ptr1 = h1;
    struct node* ptr2 = h2;

    // Count lengths
    int len1 = 0, len2 = 0;
    while (ptr1) {
        len1++;
        ptr1 = ptr1->next;
    }
    while (ptr2) {
        len2++;
        ptr2 = ptr2->next;
    }

    // Align starts
    ptr1 = h1;
    ptr2 = h2;
    if (len1 > len2) {
        for (int i = 0; i < len1 - len2; i++) ptr1 = ptr1->next;
    } else {
        for (int i = 0; i < len2 - len1; i++) ptr2 = ptr2->next;
    }

    // Find intersection
    while (ptr1 && ptr2) {
        if (ptr1 == ptr2)  // pointer comparison
            return ptr1;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    return NULL; // no intersection
}

//void add2(struct node* h1, struct node* h2, int c[4]) {
//    // Move to end of h1
//    while (h1->next != NULL)
//        h1 = h1->next;
//
//    // Move to end of h2
//    while (h2->next != NULL)
//        h2 = h2->next;
//
//    struct node*p1 = NULL, *p2 = NULL;
//
//    for (int i = 0; i < 4; i++) {
//        p1 = (struct node*)malloc(sizeof(struct node));
//        p2 = (struct node*)malloc(sizeof(struct node));
//        p1->data = p2->data = c[i];
//        p1->next = p2->next = NULL;
//
//        h1->next = p1;
//        h2->next = p2;
//        h1 = h1->next;
//        h2 = h2->next;
//    }
//}
struct node* create_common_list(int c[], int n) {
    struct node* head = NULL, *temp = NULL, *current = NULL;
    for (int i = 0; i < n; i++) {
        temp = (struct node*)malloc(sizeof(struct node));
        temp->data = c[i];
        temp->next = NULL;
        if (head == NULL)
            head = temp;
        else
            current->next = temp;
        current = temp;
    }
    return head;
}

void add2(struct node* h1, struct node* h2, int c[4]) {
    while (h1->next != NULL)
        h1 = h1->next;
    while (h2->next != NULL)
        h2 = h2->next;

    struct node* common = create_common_list(c, 4);
    h1->next = common;
    h2->next = common;
}

int main()
{
	//int arr1[8],arr2[10];
	int arr1[5]= {1,3,5,6,4};
	int arr2[6]= {1,6,3,15,20,25};
	int comm[4]={7,10,12,14};
	struct node*head1,*head2,*m;
	head1= (struct node*)malloc(sizeof(struct node));
	head2= (struct node*)malloc(sizeof(struct node));
	createlist(head1,arr1,5);
	printf("The first list is: \n");
	display(head1);
	createlist(head2,arr2,6);
	printf("\nThe second list is: \n");
	display(head2);
	add2(head1,head2,comm);
	printf("\nAfter adding 1st with 2nd list, the first list becomes: \n");
	display(head1);
	printf("\nThe second list becomes: \n");
	display(head2);
	m = merge(head1,head2);
	if(m==NULL)
	printf("\nthere's no merging point\n");
	else
	printf("\n%d is the merge point data",m->data);
	return 0;
	}
