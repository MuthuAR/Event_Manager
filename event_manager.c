#include<stdio.h>
#include<stdlib.h>
#include"../include/module.h"
#define BITWISE_LSHIFT(x) (1<<x)
void search_node(int);
void display_dbase();

struct Module_node
{
int module_ID;
int eve;
void (*q)();
struct Module_node *next;
}*head=NULL,*temp=NULL,*p=NULL,*last=NULL;

struct Module_node* create_module_node(int,int);

//Registering the events with the Modules
void register_event(int mod_ID,int event_list)
{
int i,j;
p=create_module_node(mod_ID,event_list);
if(head==NULL)
{
head=p;last=p;
}
last->next=p;
last=p;
}

//Displaying the Database created
void display_dbase()
{
printf("The Database created is:\n");
p=head;
if(p!=NULL)
{
while(p!=NULL)
{
printf("*****\nModule ID = %d\n",p->module_ID);
printf("Event_Id's = %d\n*****\n",p->eve);
p=p->next;
}
}
else
{
printf("The Database has not yet created\n");
}
}

//Function definition for event()
void event(int eve_ID)
{
search_node(eve_ID);
}

//Searching whether the event is registereed for the Modules
void search_node(int eve_ID)
{
int i,need=0;
printf("You have requested an event\n");
if(head==NULL)
printf("No Module is associated with events\n");
else
{
p=head;
while(p!=NULL)
{
need=(BITWISE_LSHIFT(eve_ID-1)&(p->eve));
if((need>>(eve_ID-1))==1)
p->q();
p=p->next;
}
}
}

//Function to Create the Data Structure for storing the events interested in Modules
struct Module_node* create_module_node(int mod_ID,int p)
{
int i;
temp=(struct Module_node*)malloc(sizeof(struct Module_node));
temp->module_ID=mod_ID;
temp->eve=p;
temp->next=NULL;
switch(mod_ID)
{
case 1: temp->q=add;break;
case 2: temp->q=sub;break;
case 3: temp->q=mul;break;
case 4: temp->q=division;break;
}
return(temp);
}
