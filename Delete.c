#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "phonebook.h"

void delete_contact(Contact **head)
{
    char name[NAME_SIZE];
    Contact *temp;
    Contact *prev;

    if (*head == NULL)
    {
        printf("No contacts available.\n");
        return;
    }

    printf("Enter contact name to delete: ");
    scanf(" %49[^\n]", name);

    temp = *head;
    prev = NULL;

    while (temp != NULL)
    {
        if (strcmp(temp->name, name) == 0)
        {
            if (prev == NULL)
                *head = temp->next;
            else
                prev->next = temp->next;

            free(temp);

            printf("Contact deleted successfully.\n");
            return;
        }

        prev = temp;
        temp = temp->next;
    }

    printf("Contact not found.\n");
}
