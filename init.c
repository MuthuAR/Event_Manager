#include <stdio.h>
#include "../include/event_manager.h"
#define BITWISE_LSHIFT(x) 1<<x
void main()
{
        int eve_no,i,j,mod_eve_no,eve_ID=1,mod_events,a=0;
        printf("There are 4 number of Modules:\n1. Add\n2. Subtract\n3. Multiply\n4. Divide\n");
        printf("Please Enter the number of USER Events: ");
        scanf("%d",&eve_no);

        printf("\nThe Event ID should be greater than 0 and ranges from 1 to %d\n",eve_no);
        printf("Please provide your Interest of events for each module\n");

        for(i=0;i<4;i++)
        {
        mod_events=0;
        printf("Enter the no of events associated with module %d: ",i+1);
        scanf("%d",&mod_eve_no);
        printf("Enter the ID's of the Events\n");
        //Bitmap Operation
        for(j=0;j<mod_eve_no;j++)
        {
        scanf("%d",&a);
        mod_events= BITWISE_LSHIFT(a-1)|mod_events;
        }
        //Registering the events with the Modules
        register_event(i+1,mod_events);
        }
        display_dbase();
        while(eve_ID)
        {
        printf("Please Enter your choice of Event:1 to %d\n***To exit press 0***\n",eve_no);
        scanf("%d",&eve_ID);
        //Calling the modules associated with the below event ID
        event(eve_ID);
        }
}
