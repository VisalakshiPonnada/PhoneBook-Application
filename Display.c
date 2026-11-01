#include <stdio.h>
#include "phonebook.h"

void print_contacts(Contact *head)
{
    int i;

    if (head == NULL)
    {
        printf("No contacts available.\n");
        return;
    }
    while (head != NULL)
    {
        printf("Name %s\n", head->name);
        for (i = 0; i < head->number_count; i++)
        {
            printf("Number-%d: %s\n", i + 1, head->numbers[i]);
        }
        if (head->email[0] != '\0')
            printf("Email %s\n", head->email);
        else
            printf("Email Not available\n");
        if (head->address[0] != '\0')
            printf("Address %s\n", head->address);
        else
            printf("Address Not available\n");
         head = head->next;
    }

    printf("\n");
}
