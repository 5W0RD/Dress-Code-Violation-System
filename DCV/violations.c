#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "violations.h"

void clearInput() {

    while(getchar() != '\n');
}

int isValidStudentID(char id[]) {

    int i;

    for(i = 0; id[i] != '\0'; i++) {

        if(!isdigit(id[i])) {

            return 0;
        }
    }

    return 1;
}

int getValidChoice() {

    int choice;
    char term;

    while(1) {

        if(scanf("%d%c", &choice, &term) != 2 || term != '\n') {

            printf("Invalid input! Numbers only.\n");
            clearInput();

        } else {

            return choice;
        }
    }
}

void setViolation(char violation[], int choice) {

    switch(choice) {

        case 1:
            strcpy(violation, "Sleeveless shirts");
            break;

        case 2:
            strcpy(violation, "Torn and tattered jeans");
            break;

        case 3:
            strcpy(violation, "Rubber slippers and sandals");
            break;

        case 4:
            strcpy(violation, "Earrings");
            break;

        case 5:
            strcpy(violation, "Unnatural hair colors");
            break;

        case 6:
            strcpy(violation, "Tube/Spaghetti strap blouses");
            break;

        case 7:
            strcpy(violation, "Short pants");
            break;

        case 8:
            strcpy(violation, "Micro miniskirts");
            break;

        case 9:
            strcpy(violation, "See-through attire");
            break;

        case 10:
            strcpy(violation, "Plunging neckline blouses");
            break;

        case 11:
            strcpy(violation, "Midriff blouses");
            break;

        default:
            strcpy(violation, "Unknown Violation");
    }
}

void viewViolations() {

    printf("\n===== DRESS CODE VIOLATIONS =====\n");

    printf("1. Sleeveless shirts\n");
    printf("2. Torn and tattered jeans\n");
    printf("3. Rubber slippers and sandals\n");
    printf("4. Earrings\n");
    printf("5. Unnatural hair colors\n");
    printf("6. Tube/Spaghetti strap blouses\n");
    printf("7. Short pants\n");
    printf("8. Micro miniskirts\n");
    printf("9. See-through attire\n");
    printf("10. Plunging neckline blouses\n");
    printf("11. Midriff blouses\n");
}

void inputStudentID(char id[]) {

    while(1) {

        printf("Enter Student ID: ");
        fgets(id, 20, stdin);

        id[strcspn(id, "\n")] = '\0';

        if(isValidStudentID(id)) {

            break;

        } else {

            printf("Invalid Student ID! Numbers only.\n");
        }
    }
}

void recordViolation() {

    FILE *fp, *temp;

    struct Student s;

    char id[20];

    int found = 0;
    int choice;

    fp = fopen("records.txt", "r");

    if(fp == NULL) {

        fp = fopen("records.txt", "w");
        fclose(fp);

        fp = fopen("records.txt", "r");
    }

    temp = fopen("temp.txt", "w");

    getchar();

    inputStudentID(id);

    while(fscanf(fp,
        "%19[^|]|%99[^|]|%99[^|]|%d|%d\n",
        s.studentID,
        s.name,
        s.violation,
        &s.strikes,
        &s.communityService) != EOF) {

        if(strcmp(s.studentID, id) == 0) {

            found = 1;

            viewViolations();

            printf("\nEnter Violation Number: ");
            choice = getValidChoice();

            while(choice < 1 || choice > 11) {

                printf("Invalid choice! Try again: ");
                choice = getValidChoice();
            }

            setViolation(s.violation, choice);

            s.strikes++;

            if(s.strikes >= 3) {

                s.communityService++;

                printf("\n===== WARNING =====\n");

                printf("%s reached 3 STRIKES!\n",
                       s.name);

                printf("Added 1 Hour Community Service!\n");

                s.strikes = 0;
            }

            printf("\nViolation Recorded!\n");

            printf("Current Strikes: %d\n",
                   s.strikes);

            printf("Community Service Hours: %d\n",
                   s.communityService);
        }

        fprintf(temp,
            "%s|%s|%s|%d|%d\n",
            s.studentID,
            s.name,
            s.violation,
            s.strikes,
            s.communityService);
    }

    if(found == 0) {

        struct Student newStudent;

        strcpy(newStudent.studentID, id);

        printf("Enter Student Name: ");
        fgets(newStudent.name,
               sizeof(newStudent.name),
               stdin);

        newStudent.name[
            strcspn(newStudent.name, "\n")] = '\0';

        viewViolations();

        printf("\nEnter Violation Number: ");
        choice = getValidChoice();

        while(choice < 1 || choice > 11) {

            printf("Invalid choice! Try again: ");
            choice = getValidChoice();
        }

        setViolation(newStudent.violation, choice);

        newStudent.strikes = 1;
        newStudent.communityService = 0;

        fprintf(temp,
            "%s|%s|%s|%d|%d\n",
            newStudent.studentID,
            newStudent.name,
            newStudent.violation,
            newStudent.strikes,
            newStudent.communityService);

        printf("\nNew Student Added!\n");
    }

    fclose(fp);
    fclose(temp);

    remove("records.txt");
    rename("temp.txt", "records.txt");
}

void searchStudent() {

    FILE *fp;

    struct Student s;

    char id[20];

    int found = 0;

    fp = fopen("records.txt", "r");

    if(fp == NULL) {

        printf("No Records Found!\n");
        return;
    }

    getchar();

    inputStudentID(id);

    while(fscanf(fp,
        "%19[^|]|%99[^|]|%99[^|]|%d|%d\n",
        s.studentID,
        s.name,
        s.violation,
        &s.strikes,
        &s.communityService) != EOF) {

        if(strcmp(s.studentID, id) == 0) {

            found = 1;

            printf("\n===== STUDENT RECORD =====\n");

            printf("Student ID            : %s\n",
                   s.studentID);

            printf("Name                  : %s\n",
                   s.name);

            printf("Latest Violation      : %s\n",
                   s.violation);

            printf("Current Strikes       : %d\n",
                   s.strikes);

            printf("Community Service Hrs : %d\n",
                   s.communityService);
        }
    }

    if(found == 0) {

        printf("\nStudent Not Found!\n");
    }

    fclose(fp);
}

void editStudent() {

    FILE *fp, *temp;

    struct Student s;

    char id[20];
    char newID[20];

    int found = 0;

    fp = fopen("records.txt", "r");

    if(fp == NULL) {

        printf("No Records Found!\n");
        return;
    }

    temp = fopen("temp.txt", "w");

    getchar();

    inputStudentID(id);

    while(fscanf(fp,
        "%19[^|]|%99[^|]|%99[^|]|%d|%d\n",
        s.studentID,
        s.name,
        s.violation,
        &s.strikes,
        &s.communityService) != EOF) {

        if(strcmp(s.studentID, id) == 0) {

            found = 1;

            printf("Enter New Student ID: ");

            fgets(newID, sizeof(newID), stdin);

            newID[strcspn(newID, "\n")] = '\0';

            while(!isValidStudentID(newID)) {

                printf("Invalid Student ID! Numbers only.\n");

                printf("Enter New Student ID: ");

                fgets(newID, sizeof(newID), stdin);

                newID[strcspn(newID, "\n")] = '\0';
            }

            strcpy(s.studentID, newID);

            printf("Enter New Name: ");

            fgets(s.name, sizeof(s.name), stdin);

            s.name[strcspn(s.name, "\n")] = '\0';

            printf("\nStudent Record Updated!\n");
        }

        fprintf(temp,
            "%s|%s|%s|%d|%d\n",
            s.studentID,
            s.name,
            s.violation,
            s.strikes,
            s.communityService);
    }

    fclose(fp);
    fclose(temp);

    remove("records.txt");
    rename("temp.txt", "records.txt");

    if(found == 0) {

        printf("Student Not Found!\n");
    }
}

void cleanRecord() {

    FILE *fp, *temp;

    struct Student s;

    char id[20];

    int found = 0;

    fp = fopen("records.txt", "r");

    if(fp == NULL) {

        printf("No Records Found!\n");
        return;
    }

    temp = fopen("temp.txt", "w");

    getchar();

    inputStudentID(id);

    while(fscanf(fp,
        "%19[^|]|%99[^|]|%99[^|]|%d|%d\n",
        s.studentID,
        s.name,
        s.violation,
        &s.strikes,
        &s.communityService) != EOF) {

        if(strcmp(s.studentID, id) == 0) {

            found = 1;

            s.strikes = 0;
            s.communityService = 0;

            printf("\nStudent Record Cleaned!\n");
        }

        fprintf(temp,
            "%s|%s|%s|%d|%d\n",
            s.studentID,
            s.name,
            s.violation,
            s.strikes,
            s.communityService);
    }

    fclose(fp);
    fclose(temp);

    remove("records.txt");
    rename("temp.txt", "records.txt");

    if(found == 0) {

        printf("Student Not Found!\n");
    }
}
