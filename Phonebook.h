#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#define NAME_SIZE 50
#define NUMBER_SIZE 20
#define EMAIL_SIZE 60
#define ADDRESS_SIZE 100
#define MAX_NUMBERS 5

typedef struct Contact
{
    char name[NAME_SIZE];
    char numbers[MAX_NUMBERS][NUMBER_SIZE];
    int number_count;
    char email[EMAIL_SIZE];
    char address[ADDRESS_SIZE];

    struct Contact *next;
} Contact;

/* Contact operations */
void create_contact(Contact **head);
void print_contacts(Contact *head);
void find_contact(Contact *head);
void delete_contact(Contact **head);
void edit_contact(Contact *head);

/* File operations */
void save_contacts(Contact *head);
void load_contacts(Contact **head);

/* Utility */
int contact_exists(Contact *head, const char *name);
void free_contacts(Contact *head);

#endif
