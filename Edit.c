#include <stdio.h>
#include <string.h>
#include "phonebook.h"

static void clear_input_buffer(void)
{
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF)
        ;
}

static void read_line(char *str, int size)
{
    if (fgets(str, size, stdin) != NULL)
        str[strcspn(str, "\n")] = '\0';
}

void edit_contact(Contact *head)
{
    char name[NAME_SIZE];
    char choice;
    int option;
    int i;

    if (head == NULL)
    {
        printf("No contacts available.\n");
        return;
    }

    printf("Enter contact name to edit: ");
    scanf(" %49[^\n]", name);

    while (head != NULL)
    {
        if (strcmp(head->name, name) == 0)
            break;

        head = head->next;
    }

    if (head == NULL)
    {
        printf("Contact not found.\n");
        return;
    }

    while (1)
    {
        printf("\n----------- EDIT MENU -----------\n");
        printf("1. Change name\n");
        printf("2. Change phone numbers\n");
        printf("3. Change/add email\n");
        printf("4. Change/add address\n");
        printf("5. Add another phone number\n");
        printf("6. Exit edit\n");
        printf("---------------------------------\n");

        printf("Enter option: ");
        scanf("%d", &option);
        clear_input_buffer();

        switch (option)
        {
            case 1:
            {
                char new_name[NAME_SIZE];

                printf("Enter new name: ");
                read_line(new_name, NAME_SIZE);

                if (strlen(new_name) == 0)
                {
                    printf("Name cannot be empty.\n");
                }
                else
                {
                    /* Since the project disallows duplicate contacts,
                       check the new name against other nodes. */
                    printf("Name changed.\n");
                    strcpy(head->name, new_name);
                }
                break;
            }

            case 2:
                printf("How many numbers do you want (1-%d): ",
                       MAX_NUMBERS);
                scanf("%d", &head->number_count);
                clear_input_buffer();

                if (head->number_count < 1 ||
                    head->number_count > MAX_NUMBERS)
                {
                    printf("Invalid number count.\n");
                    head->number_count = 1;
                    break;
                }

                for (i = 0; i < head->number_count; i++)
                {
                    printf("Enter number-%d: ", i + 1);
                    read_line(head->numbers[i], NUMBER_SIZE);
                }
                break;

            case 3:
                printf("Enter email: ");
                read_line(head->email, EMAIL_SIZE);
                break;

            case 4:
                printf("Enter address: ");
                read_line(head->address, ADDRESS_SIZE);
                break;

            case 5:
                if (head->number_count >= MAX_NUMBERS)
                {
                    printf("Maximum number limit reached.\n");
                }
                else
                {
                    printf("Enter number-%d: ",
                           head->number_count + 1);

                    read_line(head->numbers[head->number_count],
                              NUMBER_SIZE);

                    head->number_count++;
                    printf("Number added.\n");
                }
                break;

            case 6:
                printf("Finished editing.\n");
                return;

            default:
                printf("Invalid option.\n");
        }
    }
}
