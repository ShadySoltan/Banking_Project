#ifndef _BANKINGSYSTEM_H_
#define _BANKINGSYSTEM_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct CustomerNode{
    int CustomerNumber;
    struct CustomerNode *Ptr;
}CustomerNode;

CustomerNode *Head = NULL, *Tail = NULL;
static int CustomerNumber = 0;

//Bank Customer Service Windows
CustomerNode *Window1 = NULL, *Window2 = NULL;

void Add_NewCustomer(void);
void Serve_Customer();
void Move_CustomerToWindow(void);
int Check_Window(CustomerNode *window);
int NumberOfCustomers(void);;
int customerNumberAtwindow(CustomerNode *Window);

#endif