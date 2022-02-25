#include<stdio.h>
#include<stdlib.h>

int i = -1, top = -1, item, save_index = 0;
int a[50], REDO[50];

void display()
{
    if(i<0)
    {
        printf("NO elements to display");
        return;
    }
    printf("Elements are: ");
    for(int j=0;j<i+1;j++)
    {
        printf("%d ",a[j]);
    }
}

void insert()
{
    if(i>50)
    {
        printf("Stack overflow");
        return;
    }
    printf("Enter the element: ");
    scanf("%d",&item);

    a[++i]=item;
    top = -1;
    display();
}

void save()
{
    save_index = i;
    printf("Stack saved");
}


void undo()
{
    if(i<0)
    {
        printf("No element present");
        return;
    }
    if(i<=save_index)
    {
        printf("Cant undo saved stack");
        return;
    }
    REDO[++top] = a[i--];
    printf("UNDO done\n");
    display();
}

void redo()
{
    if(top==-1)
    {
        printf("No elements to redo");
        return;
    }
    a[++i] = REDO[top--];
    printf("REDO done\n");
    display();
}


void main()
{

    for(; ;)
    {
        printf("\n1: INSERT\n2: UNDO\n3: REDO\n4: DISPLAY\n5: SAVE\n6: EXIT\n");
        int ch;
        printf("Enter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1 : insert();
                break;
            case 2 : undo();
                break;
            case 3 : redo();
                break;
            case 4 : display();
                break;
            case 5 : save();
                break;
            case 6 : exit (0);
            default:
                printf("Enter valid input");
        }
    }
}
