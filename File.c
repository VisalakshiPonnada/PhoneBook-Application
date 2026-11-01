#include <stdio.h>
#include <stdlib.h>
#include "phonebook.h"

void save_contacts(Contact *head)
{
    FILE *fp;
    Contact *temp = head;

    fp = fopen("contacts.dat", "wb");

    if (fp == NULL)
    {
        printf("Unable to open file.\n");
        return;
    }

    while (temp != NULL)
    {
        fwrite(temp, sizeof(Contact) - sizeof(Contact *), 1, fp);
        temp = temp->next;
    }

    fclose(fp);
    printf("Contacts saved successfully.\n");
}

void load_contacts(Contact **head)
{
    FILE *fp;
    Contact *new_node;
    Contact *temp;

    fp = fopen("contacts.dat", "rb");

    if (fp == NULL)
        return;

    while (1)
    {
        new_node = malloc(sizeof(Contact));

        if (new_node == NULL)
            break;

        if (fread(new_node, sizeof(Contact) - sizeof(Contact *), 1, fp) != 1)
        {
            free(new_node);
            break;
        }

        new_node->next = NULL;

        if (*head == NULL)
            *head = new_node;
        else
        {
            temp = *head;

            while (temp->next != NULL)
                temp = temp->next;

            temp->next = new_node;
        }
    }

    fclose(fp);
}
