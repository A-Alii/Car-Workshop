#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "queue.h"
#include "global.h"

void display_menu ();
void Copy_Queue(QueueType *q, QueueType *q_copy);
void Copy_Stack(QueueType *q, StackType *s);
int main()
{
    QueueType customers;
    CreateQueue(&customers);
    EntryType data;
    int choice;
    display_menu();
    scanf("%d", &choice);
    QueueType q_copy;
    StackType s;
    while(1)
    {
        switch(choice)
        {
        case 1:
            if(!QueueFull(customers))
            {
                printf("Please Enter the id of customers: ");
                scanf("%d", &data.ID);
                printf("Please Enter the name of customers: ");
                scanf("%s", &data.Name);
                Enqueue(data, &customers);
            }
            else
                printf("Queue Is Full. \n");
        break;
        case 2:
            if(!QueueEmpty(customers))
            {
                Dequeue(&data, &customers);
                printf("the served customer with ID -> %d and Name -> %s\n",data.ID,data.Name);
            }
            else
                printf("Queue Is Empty. \n");
        break;
        case 3:
            CreateQueue(&q_copy);
            Copy_Queue(&customers, &q_copy);
            int i = 1;
            printf("The waiting customers: \n");
            while(!QueueEmpty(q_copy))
            {
                Dequeue(&data, &q_copy);
                printf("%d- Customer With ID -> %d\n", i++, data.ID);
            }
        break;
        case 4:
            CreateStack(&s);
            QueueType tmp;
            CreateQueue(&tmp);
            Copy_Queue(&customers, &tmp);
            Copy_Stack(&tmp, &s);
            i = 1;
            printf("The waiting customers in reverse order: \n");
            while(!StackEmpty(s))
            {
                Pop(&data, &s);
                printf("%d- Customer With ID -> %d\n", i++, data.ID);
            }
        break;
        case 5:
            exit(0);

        default :
            printf("Please Enter valid choice from menu. \n");
        }
        display_menu();
        scanf("%d", &choice);
    }
    return 0;
}

void display_menu ()
{
    printf("1. Add a New Customer.\n");
    printf("2. Serve a Customer.\n");
    printf("3. Display Customers Information.\n");
    printf("4. Display Customers information in the most-recent Order.\n");
    printf("5. Exit menu.\n");
}

void Copy_Queue(QueueType *q, QueueType *q_copy)
{
    QueueType tmp;
    CreateQueue(&tmp);
    EntryType data;
    while(!QueueEmpty(*q))
    {
        Dequeue(&data, q );
        Enqueue(data, &tmp);
    }

    while(!QueueEmpty(tmp))
    {
        Dequeue(&data, &tmp);
        Enqueue(data, q_copy);
        Enqueue(data, q);
    }
}

void Copy_Stack(QueueType *q, StackType *s)
{
    EntryType data;
    while(!QueueEmpty(*q))
    {
        Dequeue(&data, q);
        Push(data, s);
    }
}
