#include <stdio.h>
#include <string.h>
#include "phonebook.h"

void find_contact(Contact *head)
{
    char name[NAME_SIZE];

    if (head == NULL)
    {
        printf("No contacts available.\n");
        return;
    }

    printf("Enter contact name to find: ");
    scanf(" %49[^\n]", name);

    while (head != NULL)
    {
        if (strcmp(head->name, name) == 0)
        {
            int i;

            printf("\nContact found.\n");
            printf("Name    : %s\n", head->name);

            for (i = 0; i < head->number_count; i++)
                printf("Number-%d: %s\n", i + 1, head->numbers[i]);

            printf("Email   : %s\n",
                   head->email[0] ? head->email : "Not available");

            printf("Address : %s\n",
                   head->address[0] ? head->address : "Not available");

            return;
        }

        head = head->next;
    }

    printf("Contact not found.\n");
}
