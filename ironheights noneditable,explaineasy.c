#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_PRISONERS 10

struct prisoner
{
    char name[50];
    int age;
    char date[15];
    char crime[50];
    bool life;
};

int main()
{
    struct prisoner jail[MAX_PRISONERS];
    printf("You will be required to fill in the details in the following order: Name, Age, Date in, Crime, Life sentence\n");

    // Get input from user
    for (int i = 0; i < MAX_PRISONERS; i++) {
        printf("Enter details for prisoner %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", jail[i].name);
        printf("Age: ");
        scanf("%d", &jail[i].age);
        printf("Date in (dd/mm/yyyy): ");
        scanf("%s", jail[i].date);
        printf("Crime: ");
        scanf("%s", jail[i].crime);
        printf("Life sentence (0 for false, 1 for true): ");
        scanf("%d", &jail[i].life);
    }

    // Open file for writing
    FILE *fp;
    fp = fopen("prisoners.txt", "w");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    // Write data to file
    for (int i = 0; i < MAX_PRISONERS; i++) {
        fprintf(fp, "Name: %s\n", jail[i].name);
        fprintf(fp, "Age: %d\n", jail[i].age);
        fprintf(fp, "Date in: %s\n", jail[i].date);
        fprintf(fp, "Crime: %s\n", jail[i].crime);
        fprintf(fp, "Life sentence: %d\n\n", jail[i].life);
    }

    // Close file
    fclose(fp);

    printf("Data written to file!\n");

    return 0;
}
