#include<stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node* next;
    struct node* prev;
};
void insert_at_beginning(struct node** head,int value)
{
    struct node*temp=(struct node*)malloc(1*sizeof(struct node));
    //checking if memory allocation failed or not
    if(!temp)
    {
        printf("Memory allocation failed");
        return;
    }
    temp->data=value;
    //if the list is empty
    if(!(*head))
    {
        temp->next=temp;
        temp->prev=temp;
    }
    //constant case
    else
    {
        struct node* end= (*head)->prev;
        temp->next=*head;
        temp->prev=end;
        (*head)->prev=temp;
        end->next=temp;
    }
    *head=temp;
}
void insert_at_end(struct node** head,int value)
{
     struct node*temp=(struct node*)malloc(1*sizeof(struct node));
    //checking if memory allocation failed or not
    if(!temp)
    {
        printf("Memory allocation failed");
        return;
    }
    temp->data=value;
    //if the list is empty
    if(!(*head))
    {
        temp->next=temp;
        temp->prev=temp;
        *head=temp;
        return;
    }
    //constant case
    //inserting at last element of linkedlist
    struct node*end=(*head)->prev; //pointing end at the last node because of doubly circular linked list
    temp->next=*head;
    temp->prev=end;
    end->next=temp;
    (*head)->prev=temp;
}
void insert_before_k(struct node** head,int value,int k)
{
     struct node*temp=(struct node*)malloc(1*sizeof(struct node));
    //checking if memory allocation failed or not
    if(!temp)
    {
        printf("Memory allocation failed");
        return;
    }
    temp->data=value;
    //if the list is empty
    if(!(*head))
    {
        temp->next=temp;
        temp->prev=temp;
        *head=temp;
        return;
    }
    //if the first node is equal to k
    struct node*itr=*head;
    if(itr->data==k)//you can also write it as (*head)->data==k
    {
        temp->next=*head;
        temp->prev=(*head)->prev;//connecting to the last node
        itr->prev->next=temp;
        *head=temp;
        return;
    }
    while(itr->next!=*head && itr->next->data!=k)//traversing till we reach the last node or before k
    {
        itr=itr->next;
    }
    if(itr->next==*head && itr->data!=k)
    {
        printf("\n%d node not found\n",k);
        return;
    }
    temp->next=itr->next;
    temp->prev=itr;
    itr->next=temp;
    temp->next->prev=temp;
}
void insert_after_k(struct node** head,int value, int k)
{
     struct node*temp=(struct node*)malloc(1*sizeof(struct node));
    //checking if memory allocation failed or not
    if(!temp)
    {
        printf("Memory allocation failed");
        return;
    }
    temp->data=value;
    //if the list is empty
    if(!(*head))
    {
        temp->next=temp;
        temp->prev=temp;
        *head=temp;
        return;
    }
    struct node*itr=*head;
    do
    {
        if(itr->data==k)
        {
            temp->next=itr->next;
            temp->prev=itr;
            itr->next=temp;
            temp->next->prev=temp;
            return;
        }
        itr=itr->next;
    }while(itr!=itr->next);
    printf("%d not found",k);//when k is not present in the linked list
}
void delete_by_value(struct node** head,int k)
{
    //when the list is empty
   if(!(*head))
   {
        printf("\nEmpty list");
        return;
   }
   struct node*temp=*head,*temp1=(*head)->next; //temp1 will be pointing one node ahead of temp
   if(temp->data==k)//when it is the first node
   {
        if (*head == (*head)->next)//when there is only single node
        {
            free(*head);
            *head=NULL;
            return;
        }
        else //when the k is present on the first node but there are n number of nodes
        {
            temp1->prev=temp->prev;
            temp->prev->next=temp1;
            free(temp);
            *head=temp1;
            return;
        }
   }
        while(temp1!=*head)//traversing till the last node
        {
            if(temp1->data==k)
            {
                temp->next=temp1->next;
                temp1->next->prev=temp;
                free(temp1);
                return;
            }
            temp=temp1;
            temp1=temp->next;
        }
        //when node is not present in the linked list
   printf("Node with value %d not found\n",k );
}  
void delete_head(struct node** head)
{
    //checking whether list is empty or not
    if(!(*head))
    {
        printf("\nEmpty list\n");
        return;
    }
    struct node*temp=(*head)->prev;//pointing at the last node
    struct node*temp1=(*head);
    //if only single node is present
    if((*head)==(*head)->prev)
    {
        free(*head);
        *head = NULL;//emptying the list
    }
    else
    {
        temp->next=(*head)->next;
        (*head)->next->prev=temp;
        *head=(*head)->next;
        free(temp1);
    }
}
void delete_tail(struct node** head)
{
    //checking whether list is empty or not
    if(!(*head))//or you can write it as *head==NULL
    {
        printf("\nEmpty list\n");
        return;
    }
   struct node *end=(*head)->prev;//pointing at the last node
   struct node*end1=end->prev;//pointing at the second last node
   if(*head==end)//if single node is present
   {
        free(*head);
        *head=NULL;
        return;
   }
   end1->next=*head;
   (*head)->prev=end1;
   free(end);
}
void display_head(struct node** head)
{
    //checking whether list is empty or not
    if(!(*head))
    {
        printf("\nEmpty list\n");
        return;
    }
    //printing while traversing till last node
    struct node *itr=*head;
    do
    {
        printf("%d ----> ", itr->data);
        itr=itr->next;
    }while(itr!=(*head));//traversing till the last node
    printf("(head)\n");
}
void display_tail(struct node** head)
{
    //checking whether list it empty or not
    if(!(*head))
    {
        printf("\nEmpty list\n");
        return;
    }
    // Traverse backward from the tail to the head
    struct node* tail = (*head)->prev;
    struct node* itr = tail;

    do
    {
        printf("%d ----> ", itr->data);
        itr = itr->prev;
    } while (itr != tail);

    printf("(head)\n");
}
int main()
{
    struct node * head=NULL;
    char ch;
    int choice,data,value;
    do
    {
       printf("Enter your choice:\n\n1-Insert at beginning\n2-insert at end\n3-insert before a given value\n4-insert after a given value\n5-delete a node by value\n6-delete first node\n7-delete last node\n8-display node from head to tail\n9-display node form tail to head: \n");
       scanf("%d",&choice);
       switch (choice)
       {
            case 1:
            {
                printf("\nEnter the data to be inserted at the beginning: ");
                scanf("%d",&data);
                insert_at_beginning(&head,data);
                break;
            }
            case 2:
            {
                printf("\nEnter the data to be inserted at the end: ");
                scanf("%d",&data);
                insert_at_end(&head,data);
                break;
            }
            case 3:
            {
                printf("\nEnter the data to be inserted: ");
                scanf("%d",&data );
                printf("\nInsert before which value? ");//inserting before that value
                scanf("%d",&value);
                insert_before_k(&head,data,value);
                break;
            }
            case 4:
            {
               //inserting after k
               printf("\nEnter the data to be inserted : ");
               scanf("%d", &data);             
               printf("\nAfter what number you want to enter this element? ");
               scanf("%d",&value);
               insert_after_k(&head,data,value);
               break;
            }
            case 5:
            {
                //deleting a node by value
                printf("\nEnter the value of the node you want to delete: ");
                scanf("%d",&value);
                delete_by_value(&head,value);
                break;
            }
            case 6 :
            {
                //delete first node
                delete_head(&head);
                break;
            }
            case 7:
            {
                //delete last node
                delete_tail(&head);
                break;
            }
            case 8:
            {
                //display node from head to tail
                display_head(&head);
                break;
            }
            case 9:
            {
                //display node from tail to head
                display_tail(&head);
                break;
            }
            default:
            {
                printf("\nInvalid argument\n");
            }
        }
        printf("\nDo you want to continue: Y-yes or N-no: ");
        scanf(" %c",&ch);
    }while(ch=='y'||ch=='Y');
    while (head) 
    {
        struct node* temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}
