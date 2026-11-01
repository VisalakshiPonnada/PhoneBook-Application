#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "phonebook.h"

static void clear_input_buffer(void)
{
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

static void read_line(char *str, int size)
{
    if (fgets(str, size, stdin) != NULL)
    {
        str[strcspn(str, "\n")] = '\0';
    }
}

int contact_exists(Contact *head, const char *name)
{
    while (head != NULL)
    {
        if (strcmp(head->name, name) == 0)
            return 1;

        head = head->next;
    }

    return 0;
}

void create_contact(Contact **head)
{
    Contact *new_contact;
    char answer;

    new_contact = malloc(sizeof(Contact));

    if (new_contact == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    memset(new_contact, 0, sizeof(Contact));

    clear_input_buffer();

    printf("Enter contact name: ");
    read_line(new_contact->name, NAME_SIZE);

    if (strlen(new_contact->name) == 0)
    {
        printf("Name cannot be empty.\n");
        free(new_contact);
        return;
    }

    if (contact_exists(*head, new_contact->name))
    {
        printf("Duplicate contact. Contact already exists.\n");
        free(new_contact);
        return;
    }

    printf("Enter number-1: ");
    read_line(new_contact->numbers[0], NUMBER_SIZE);
    new_contact->number_count = 1;

    while (new_contact->number_count < MAX_NUMBERS)
    {
        printf("Do you want to add another number to the same name (Y/N): ");
        scanf(" %c", &answer);
        clear_input_buffer();

        if (answer == 'Y' || answer == 'y')
        {
            printf("Enter number-%d: ", new_contact->number_count + 1);
            read_line(new_contact->numbers[new_contact->number_count],
                      NUMBER_SIZE);

            new_contact->number_count++;
        }
        else if (answer == 'N' || answer == 'n')
        {
            break;
        }
        else
        {
            printf("Please enter Y or N.\n");
        }
    }

    if (new_contact->number_count == MAX_NUMBERS)
        printf("Maximum number of phone numbers reached.\n");

    printf("Do you want to add email (Y/N): ");
    scanf(" %c", &answer);
    clear_input_buffer();

    if (answer == 'Y' || answer == 'y')
    {
        printf("Enter email: ");
        read_line(new_contact->email, EMAIL_SIZE);
    }

    printf("Do you want to add address (Y/N): ");
    scanf(" %c", &answer);
    clear_input_buffer();

    if (answer == 'Y' || answer == 'y')
    {
        printf("Enter address: ");
        read_line(new_contact->address, ADDRESS_SIZE);
    }

    new_contact->next = NULL;

    if (*head == NULL)
    {
        *head = new_contact;
    }
    else
    {
        Contact *temp = *head;

        while (temp->next != NULL)
            temp = temp->next;

        temp->next = new_contact;
    }

    printf("Contact created successfully.\n");
}

void free_contacts(Contact *head)
{
    Contact *temp;

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}
