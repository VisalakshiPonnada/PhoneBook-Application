phonebook : main.o contact.o display.o search.o delete.o edit.o file.o
        gcc main.o contact.o display.o search.o delete.o edit.o file.o -o phonebook

main.o : main.c phonebook.h
        gcc -c main.c

contact.o : contact.c phonebook.h
        gcc -c contact.c

display.o : display.c phonebook.h
        gcc -c display.c

search.o : search.c phonebook.h
        gcc -c search.c

delete.o : delete.c phonebook.h
        gcc -c delete.c

edit.o : edit.c phonebook.h
        gcc -c edit.c

file.o : file.c phonebook.h
        gcc -c file.c

clean:
        rm -f *.o phonebook contacts.dat
