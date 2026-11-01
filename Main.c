#include <stdio.h>
#include <stdlib.h>
#include "phonebook.h"

int main(void)
{
    Contact *head = NULL;
    char choice;

    /* Load previously saved contacts */
    load_contacts(&head);

    while (1)
    {
        printf("MENU");
        printf("c/C : Create a new contact\n");
        printf("p/P : Print all contacts\n");
        printf("d/D : Delete contact\n");
        printf("f/F : Find contact\n");
        printf("e/E : Edit a contact\n");
        printf("s/S : Save the contacts in the file\n");
        printf("q/Q : Quit from app\n");
        printf("\n");

        printf("Enter choice: ");
        scanf(" %c", &choice);

        switch (choice)
        {
            case 'c':
            case 'C':
                create_contact(&head);
                break;

            case 'p':
            case 'P':
                print_contacts(head);
                break;

            case 'd':
            case 'D':
                delete_contact(&head);
                break;

            case 'f':
            case 'F':
                find_contact(head);
                break;

            case 'e':
            case 'E':
                edit_contact(head);
                break;

            case 's':
            case 'S':
                save_contacts(head);
                break;

            case 'q':
            case 'Q':
                /* Save before exiting so latest changes are preserved */
                save_contacts(head);
                free_contacts(head);
                printf("Application closed.\n");
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}
