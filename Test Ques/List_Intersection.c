//!Question : Intersection of the elements of two lists inputed by user.
#include <stdio.h>
#include <stdlib.h>
#define max 50
struct node
{
    int data;
    struct node *next;
};
struct node *newnode = NULL;
struct node *front = NULL;
struct node *rear = NULL;
struct node *temp = NULL;

struct node2
{
    int data2;
    struct node2 *next2;
};

struct node2 *newnode2 = NULL;
struct node2 *front2 = NULL;
struct node2 *rear2 = NULL;
struct node2 *temp2 = NULL;

void list1_ins()
{
    int val, ch;
    printf("Enter the data to be inserted :\n");
    scanf("%d", &val);
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->next = NULL;
    if (front == NULL)
    {
        front = newnode;
        rear = newnode;
    }
    else
    {
        printf("From where to insert?\n1:Front\n2:Rear\n\n");
        scanf("%d", &ch);
        if (ch == 1)
        {
            newnode->next = front;
            front = newnode;
        }
        else if (ch == 2)
        {
            rear->next = newnode;
            rear = newnode;
        }
        else
        {
            printf("\nInvalid Choice\n");
        }
    }
}

void list2_ins()
{
    int val, ch;
    printf("Enter the data to be inserted :\n");
    scanf("%d", &val);
    newnode2 = (struct node2 *)malloc(sizeof(struct node2));
    newnode2->data2 = val;
    newnode2->next2 = NULL;
    if (front2 == NULL)
    {
        front2 = newnode2;
        rear2 = newnode2;
    }
    else
    {
        printf("From where to insert?\n1:Front\n2:Rear\n\n");
        scanf("%d", &ch);
        if (ch == 1)
        {
            newnode2->next2 = front2;
            front2 = newnode2;
        }
        else if (ch == 2)
        {
            rear2->next2 = newnode2;
            rear2 = newnode2;
        }
        else
        {
            printf("\nInvalid Choice\n");
        }
    }
}

void disp1()
{
    if (front == NULL)
    {
        printf("\nList Empty\n");
    }
    else
    {
        temp = front;
        do
        {
            printf("\t%d", temp->data);
            temp = temp->next;
        } while (temp != NULL);
    }
}
void disp2()
{
    if (front2 == NULL)
    {
        printf("\nList Empty\n");
    }
    else
    {
        temp2 = front2;
        do
        {
            printf("\t%d", temp2->data2);
            temp2 = temp2->next2;
        } while (temp2 != NULL);
    }
}
void intersection()
{
    int arr[max], comm[max], i, k = 0, j = 0;
    temp = front;
    do
    {
        arr[j] = temp->data; // *inserting elements of List 1
        temp = temp->next;
        j++;
    } while (temp != NULL);

    temp2 = front2;
    printf("\nElements of List 2:\n\n");
    while (temp2 != NULL)
    {
        printf("\t%d", temp2->data2);
        temp2 = temp2->next2;
    }
    printf("\n");

    printf("\nElements of List 1:\n\n");
    for (i = 0; i < j; i++)
    {
        printf("\t%d", arr[i]);
    }
    printf("\n");

    for (i = 0; i < j; i++)
    {
        temp2 = front2; // *reset temp2 to front2
        do
        {
            if (temp2->data2 == arr[i])
            {
                comm[k] = arr[i];
                k++;
            }
            temp2 = temp2->next2;
        } while (temp2 != NULL);
    }

    printf("\nThe Intersection of List Elements:\n\n");
    for (i = 0; i < k; i++)
    {
        printf("\t%d", comm[i]);
    }
}

int main()
{
    int ch;
    while(1)
    {
    printf("\n\tSelect :\n");
    printf("1:Insert in List 1\n");
    printf("2:Insert in List 2\n");
    printf("3:Display in List 1\n");
    printf("4:Display in List 2\n");
    printf("5:Intersection:\n");
    printf("6:Exit\n");
    scanf("%d",&ch);
    if(ch==1)
    {
        list1_ins();
    }
    if(ch==2)
    {
        list2_ins();
    }
    if(ch==3)
    {
        disp1();
    }
    if(ch==4)
    {
        disp2();
    }
    if(ch==5)
    {
        intersection();
    }
    if(ch == 6)
    {
        exit(0);
    }
}
    
    return 0;
}