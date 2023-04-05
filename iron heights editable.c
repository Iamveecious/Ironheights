#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PRISONERS 2

struct prisoner
{
    char name[50];
    char crime[50];
    char date[11];
    char age[10];
    bool life;
};

void display_prisoner(struct prisoner p)
{
    printf("Name: %s\n", p.name);
    printf("Age: %s\n", p.age);
    printf("Date in: %s\n", p.date);
    printf("Crime: %s\n", p.crime);
    printf("Life sentence: %s\n", p.life ? "Yes" : "No");
}

int main()
{
    printf("You will be required to fill in the details in the following order: Name,Age,Date in,crime\n");
    printf("Enter names:\n");
    struct prisoner jail[MAX_PRISONERS];
    for(int i = 0; i < MAX_PRISONERS; i++)
    {
        scanf("%s", jail[i].name);
    }

    printf("Enter ages:\n");
    for(int i = 0; i < MAX_PRISONERS; i++)
    {
        scanf("%s", jail[i].age);
    }

    printf("Enter dates in the form dd/mm/yy with the month in words:\n");
    for(int i = 0; i < MAX_PRISONERS; i++)
    {
        scanf("%s", jail[i].date);
    }

    printf("Enter crime:\n");
    for(int i = 0; i < MAX_PRISONERS; i++)
    {
        scanf("%s", jail[i].crime);
    }

    // Allow the user to view and edit prisoner information
    while (true) {
        printf("Enter a prisoner number to view/edit (1-%d) or 0 to exit: ", MAX_PRISONERS);
        int choice;
        scanf("%d", &choice);
        if (choice == 0) {
            break;
        } else if (choice < 1 || choice > MAX_PRISONERS) {
            printf("Invalid choice, please try again.\n");
            continue;
        }
        struct prisoner p = jail[choice-1];
        printf("Prisoner %d:\n", choice);
        display_prisoner(p);
        printf("Enter a field number to edit (1-4) or 0 to go back: ");
        int field_choice;
        scanf("%d", &field_choice);
        if (field_choice == 0) {
            continue;
        } else if (field_choice < 1 || field_choice > 4) {
            printf("Invalid choice, please try again.\n");
            continue;
        }
        printf("Enter new value: ");
        char new_value[50];
        scanf("%s", new_value);
        switch (field_choice) {
            case 1:
                strcpy(p.name, new_value);
                break;
            case 2:
                strcpy(p.age, new_value);
                break;
            case 3:
                strcpy(p.date, new_value);
                break;
            case 4:
                strcpy(p.crime, new_value);
                break;
        }
        jail[choice-1] = p;
    }

    return 0;
}
