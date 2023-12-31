#include "BankSystem.h"

void Add_NewCustomer(void)
{
    //Create New customer
    CustomerNode *NewCustomer = malloc(sizeof(CustomerNode));
    if(NewCustomer != NULL)
    {
        CustomerNumber++;
        NewCustomer->CustomerNumber = CustomerNumber;
        
        //Check if the queue is empty
        if(Head == NULL)
        {
            Head = NewCustomer;
            Tail = NewCustomer;
            Tail->Ptr = NULL;
        }
        else
        {
            Tail->Ptr = NewCustomer;
            Tail = NewCustomer;
            Tail->Ptr = NULL;
        }
        printf("\nCustomer was added successfully to the queue!\n\n");
    }
    else
    {
        printf("\nFailed to allocate memory\n\n");
        free(NewCustomer);
    }
}

void Serve_Customer()
{
    int window;

    while (1) {
        printf("\n\nWhich window is done? (Enter 1 or 2)\n");
        if (scanf("%d", &window) != 1) {
            // Invalid input, clear the input buffer
            while (getchar() != '\n');
            printf("Invalid input. Please enter a number.\n");
            continue;
        }

        switch (window) {
            case 1:
                if (Window1 == NULL) {
                    printf("\nWindow 1 is already available!!\n\n");
                } else {
                    free(Window1);
                    Window1 = NULL;
                }
                break;

            case 2:
                if (Window2 == NULL) {
                    printf("\nWindow 2 is already available!!\n\n");
                } else {
                    free(Window2);
                    Window2 = NULL;
                }
                break;

            default:
                printf("\nError: Not a valid choice, you can only choose 1 or 2 (window 1 or window 2)\n\n");
                continue;  // Go back to the beginning of the loop
        }

        // If we reach this point, the input was valid and the switch statement was executed
        break;  // Exit the loop
    }
}

void Move_CustomerToWindow(void)
{
    if(Head == NULL)
    {
        //No customer are waiting
        printf("\nNo customer are waiting to serve!\n\n");
    }
    //Since it is a queue we can only pop the first element that entered the queue (the customer that waited the most)
    else if(Window1 != NULL && Window2 != NULL)
    {
        printf("\nCan't move any customer to any windows, All windows are busy!\n\n");
    }
    else if(Window1 == NULL && Window2 != NULL)
    {
        //only window1 is ready to receive new customer
        //Now pop from the queue and move the customer to the window
        Window1 = Head;
        Head = Head->Ptr;
        Window1->Ptr = NULL;
        printf("\nCustomer %d is now at window 1\n\n",Window1->CustomerNumber);
    }
    else if(Window2 == NULL && Window1 != NULL)
    {
        //only window2 is ready to receive new customer
        //Now pop from the queue and move the customer to the window
        Window2 = Head;
        Head= Head->Ptr;
        Window2->Ptr = NULL;
        printf("\nCustomer %d is now at window 2\n\n",Window2->CustomerNumber);
    }
    else
    {
        //All windows are available
        //So we will add to window 1 by default
        //Now pop from the queue and move the customer to the window
        Window1 = Head;
        Head = Head->Ptr;
        Window1->Ptr = NULL;
        printf("\nCustomer %d is now at window 1\n\n",Window1->CustomerNumber);
    }
}

int Check_Window(CustomerNode *window)
{
    if(window == NULL)
    {
        return 0;
    }
    else 
    {
        return 1;
    }
}

int NumberOfCustomers(void)
{
    if(Head == NULL)
    {
        //No customer are waiting
        return 0;
    }
    else
    {
        CustomerNode *Temp = Head;
        int number = 0;
        while(Temp != NULL)
        {
            number++;
            Temp = Temp->Ptr;
        }
        return number;
    }
}

int customerNumberAtwindow(CustomerNode *Window)
{
    if(Window == NULL)
    {
        printf("\nWindow is not serving a customer right now!\n\n");
        return 0;
    }
    else
    {
        return Window->CustomerNumber;
    }
}

int main()
{
    MainProgram:int Choice;
    printf("*****************************Banking-System*****************************\n");
    printf("Window1: %s\n",(Check_Window(Window1) == 0? "Available" : "Busy"));
    printf("Window2: %s\n",(Check_Window(Window2) == 0? "Available\n" : "Busy"));
    printf("There are %d customers waiting",NumberOfCustomers());
    printf("\n1)Add New Customer to wait\n2)Serve one customer at window\n3)Move one customer to one of the windows to be served\n4)Customer number at window 1\n5)Customer number at window 2\n");
    printf("Choice: ");
    scanf("%d",&Choice);

    switch(Choice)
    {
        case 1:
        Add_NewCustomer();
        goto MainProgram;
        break;

        case 2:
        Serve_Customer();
        goto MainProgram;
        break;

        case 3:
        Move_CustomerToWindow();
        goto MainProgram;
        break;

        case 4:
        //Who is at window 1
        int Customer_number_AtOne = customerNumberAtwindow(Window1);
        if(Customer_number_AtOne == 0)
        {
            goto MainProgram;
        }
        printf("Customer at window 1 number is: %d\n\n",Customer_number_AtOne);
        goto MainProgram;
        break;

        case 5:
        //Who is at window 2
        int Customer_number_AtTwo = customerNumberAtwindow(Window2);
        if(Customer_number_AtTwo == 0)
        {
            goto MainProgram;
        }
        printf("Customer at window 2 number is: %d\n\n",Customer_number_AtTwo);
        goto MainProgram;
        break;

        default:
        printf("\n\nError: Not a proper choice, please choose options from 1 to 3 only\n\n");
        goto MainProgram;
        break;
    }
}