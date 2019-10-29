// AUTHOR:        Anamol Acharya
// FILENAME:      CS2413–002–Lab5–11651561.c
// SPECIFICATION: Create a Doubly Linked List, write a funtion to add, delete, and display the linked list. Moreover, 
//                the program dispays the reversed doubly linked list using recusion.
// FOR:           CS 2413 Data Structure Section 002 


#include <stdio.h>
#include <conio.h>
#include <malloc.h>

struct node                                                 //write a function to struct a node which countaind next and previous pointers
{
    struct node *next;
    int data;
    struct node *prev;
};

struct node *start = NULL;                                  //creathing a function declaration for creating, displaying, inserting and deleting  
struct node *create_ll(struct node *);                      // a node. also reverse the doubly linked list
struct node *display(struct node *);
struct node *insert_beg(struct node *);
struct node *delete_end(struct node *);
struct node *reverse_double(struct node *);


int main()
{
    int option;                                             //create a option integer variable
    do                                                      //Create a do while function to create the switch cases to the option to 
    {                                                       //start the linked list
        printf("\n\n *****MAIN MENU *****");
        printf("\n 1: Create a Doubly Linked List");
        printf("\n 2: Display");
        printf("\n 3: Add a node at the beginning");
        printf("\n 4: Delete a node from the end");
        printf("\n 5: Display the Reversed Double Linked List");
        printf("\n 6: EXIT");
        printf("\n\n Enter your option : ");
        scanf("%d", &option);

        switch(option)
        {
            case 1: start = create_ll(start);
            printf("\n DOUBLY LINKED LIST CREATED");
            break;
            case 2: start = display(start);
            break;
            case 3: start = insert_beg(start);
            break;
            case 4: start = delete_end(start);
            break;
            case 5: start = reverse_double(start);
            display(start);
            break;
        }
    }while(option != 6);                                           //check if the option is not 6
    getch();
    return 0;                                                      // return to 0
}


struct node *create_ll(struct node *start)                          //create a struct funtction to create a node
{
    struct node *new_node, *ptr;                                    //create a pointer *new node and *ptr
    int num;                                                        //create a integer variable name 
    printf("\n Enter the data : ");
    scanf("%d", &num);
    while(num != -1)                                                //create a while loop funtion
    {
        if(start == NULL)
        {
            new_node = (struct node*)malloc(sizeof(struct node));
            new_node -> prev = NULL;
            new_node -> data = num;
            new_node -> next = NULL;
            start = new_node;
        }
        else
        {
            ptr=start;
            new_node = (struct node*)malloc(sizeof(struct node));
            new_node->data=num;
            while(ptr->next!=NULL)
            ptr = ptr->next;
            ptr->next = new_node;
            new_node->prev=ptr;
            new_node->next=NULL;
        }
            printf("\n Enter the data : ");
            scanf("%d", &num);
    }
return start;
}

struct node *display(struct node *start)                                    //create a display function
{
    struct node *ptr;                                                       //struct a* *ptr pointer 
    ptr=start;
    while(ptr!=NULL)                                                        //check if the ptr is null or not 
{
    printf("\t %d", ptr -> data);
    ptr = ptr -> next;
}
return start;                                                               //return to start after finishing the loop
}

struct node *insert_beg(struct node *start)                                 //create a funtion for inserting an element in linked list 
{
    struct node *new_node;                                                  //struct a new node pointer 
    int num;                                                                //create a interger variable num
    printf("\n Enter the data : ");
    scanf("%d", &num);
    new_node = (struct node *)malloc(sizeof(struct node));
    new_node -> data = num;
    start -> prev = new_node;
    new_node -> next = start;
    new_node -> prev = NULL;
    start = new_node;
    return start;                                                           //return to start
}

struct node *delete_end(struct node *start)                                 //create a function to delete an element in the linked list
{
    struct node *ptr;                                                       //struct a ptr pointer to the function
    ptr = start;
    while(ptr -> next != NULL)                                              //check if next pointer is null or not
    ptr = ptr -> next;
    ptr -> prev -> next = NULL;
    free(ptr);
    return start;                                                           //return to start
}

struct node *reverse_double(struct node *start)
{
    if(!start)                                                               // If empty list, return
        return NULL;
       struct node *temp = start-> next;                                     // Otherwise, swap the next and prev 
        start ->next = start->prev;
        start-> prev = temp;
        
        if (!start->prev)                                              // If the prev is now NULL, the list has been fully reversed
                                                                         
            return start;                                                   // Otherwise, keep going 
            return reverse_double(start->prev);
}
