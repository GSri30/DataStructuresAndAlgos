#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

struct node{
    int data;
    struct node* link;
};

void Insert(struct node** head, int data)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->link = (*head);
    (*head) = new_node;
}

void Delete(struct node** head, int data)
{
    if((*head) != NULL)
    {
        struct node* prev_node = (*head);
        struct node* temp;
        if(prev_node->data == data)
        {
            (*head) = (*head)->link;
            free(prev_node);
            return;
        }

        while(prev_node!= NULL && prev_node->data != data)
        {
            temp = prev_node;
            prev_node = prev_node->link;
        }

        if(prev_node==NULL)
            return;

        temp->link = prev_node->link;
        free(prev_node);
    }
}

int ABS(int data)
{
    if(data<0)
        return -data;
    else
        return data;
}

int FindMax(struct node* head)
{
    int max = head->data;
    while(head!= NULL)
    {
        if(head->data > max)
            max = head->data;
        head = head->link;
    }
    return max;
}

bool Search(struct node* head, int data)
{
    while (head != NULL)
    {
        if(head->data == data)
            return true;
        head = head->link;
    }
    return false;
}

void printList(struct node* head)
{
    while (head != NULL)
    {
        printf("%d  ",head->data);
        head = head->link;
    }
    printf("NULL\n");
}

bool Possible(struct node** D,int points[],int n, int max, int left, int right)
{
    int array[1000];
    int index = 0;
    int flag = true;
    for(int i = 0; i<left; i++)
    {
        array[index++] = ABS(points[i]-max);
    }
    for(int i = right+1; i<n; i++)
    {
        array[index++] = ABS(points[i]-max);
    }
    int i = 0;

    for(i; i<index; i++)
    {
        if(Search((*D),array[i]))
        {
            Delete(D,array[i]);
        }
        else
        {
            flag = false;
            break;
        }
    }

    for(int j= 0; j<i; j++)
    {
        Insert(D,array[j]);
    }

    return flag;
}


bool Try(int points[], struct node** D, int n, int left, int right)
{
    bool found = false;
    if((*D) == NULL)
        return true;
    
    int max = FindMax((*D));

    if(Possible(D,points,n,max,left,right))
    {
        points[right] = max;
        for(int i = 0; i<left; i++)
        {
            Delete(D,ABS(points[i]-points[right]));
        }
        for(int i = right +1; i<n; i++)
        {
            Delete(D,ABS(points[i]-points[right]));
        }

        found = Try(points,D,n,left,right-1);

        if(found == false)
        {
            for(int i = 0; i<left; i++)
            {
                Insert(D,ABS(points[i]-points[right]));
            }
            for(int i = right +1; i<n; i++)
            {
                Insert(D,ABS(points[i]-points[right]));
            }
        }
    }

    if(Possible(D,points,n,points[n-1]-max,left,right) && found == false)
    {
        points[left] = points[n-1] - max;
        for(int i=0; i<left; i++)
        {
            Delete(D, ABS(points[i]-points[left]));
        }
        for(int i=right +1; i<n; i++)
        {
            Delete(D, ABS(points[i]-points[left]));
        }

        found = Try(points,D,n,left+1,right);

        if(found == false)
        {
            for(int i = 0; i<left; i++)
            {
                Insert(D,ABS(points[i]-points[left]));
            }
            for(int i = right +1; i<n; i++)
            {
                Insert(D,ABS(points[i]-points[left]));
            }
        }
    }
    return found;
}

bool reconstruct(int points[],struct node** D,int n)
{
    points[0] = 0;
    points[n-1] = FindMax((*D));
    Delete(D,FindMax((*D)));
    points[n-2] = FindMax((*D));
    Delete(D,FindMax((*D)));
    if(Search((*D),points[n-1]-points[n-2]))
    {
        Delete(D, points[n-1]-points[n-2]);
        return Try(points,D,n,1,n-3);
    }
    else
        return false;
}

int main()
{
    struct node* D = NULL;
    int given[] = {1,2,2,2,3,3,3,4,5,5,5,6,7,8,10};
    for(int i= 0; i<15; i++)
    {
        Insert(&D,given[i]);
    }
    int points[1000];

    if(reconstruct(points,&D,6))
    {
        printf("Yes we can reconstruct it. The following is one solution -\n");
        for(int i =0; i<6; i++)
        {
            printf("%d  ",points[i]);
        }
        printf("\n");
    }
    else
    {
        printf("Whyy\n");
    }

    return 0;
}