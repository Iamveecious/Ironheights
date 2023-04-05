#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

#define MAX_PRISONERS 2

struct prisoner
{
    char name[50];
    char crime[50];
    char date[11];
    char age[10];
    bool life;
};

void print_error(char *msg)
{
    fprintf(stderr, "Error: %s\n", msg);
}

int main()
{
    // Open the database
    sqlite3 *db;
    int rc = sqlite3_open("prisoners.db", &db);
    if(rc != SQLITE_OK)
    {
        print_error("Unable to open database");
        return 1;
    }

    // Create the table
    char *create_table = "CREATE TABLE IF NOT EXISTS prisoners (id INTEGER PRIMARY KEY AUTOINCREMENT, name TEXT, age TEXT, date TEXT, crime TEXT);";
    rc = sqlite3_exec(db, create_table, NULL, NULL, NULL);
    if(rc != SQLITE_OK)
    {
        print_error("Unable to create table");
        return 1;
    }

    // Prompt the user for prisoner information
    printf("You will be required to fill in the details in the following order: Name, Age, Date in, Crime\n");
    struct prisoner jail[MAX_PRISONERS];
    for(int i = 0; i < MAX_PRISONERS; i++)
    {
        printf("Enter prisoner %d information:\n", i+1);
        printf("Name: ");
        scanf("%s", jail[i].name);
        printf("Age: ");
        scanf("%s", jail[i].age);
        printf("Date in the form dd/mm/yy with the month in words: ");
        scanf("%s", jail[i].date);
        printf("Crime: ");
        scanf("%s", jail[i].crime);

        // Insert the prisoner information into the database
        char insert_query[200];
        sprintf(insert_query, "INSERT INTO prisoners (name, age, date, crime) VALUES ('%s', '%s', '%s', '%s');", jail[i].name, jail[i].age, jail[i].date, jail[i].crime);
        rc = sqlite3_exec(db, insert_query, NULL, NULL, NULL);
        if(rc != SQLITE_OK)
        {
            print_error("Unable to insert data");
            return 1;
        }
    }

    // Close the database
    sqlite3_close(db);

    return 0;
}
