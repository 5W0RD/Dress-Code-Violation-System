#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "violations.h"

void recordViolation() {

    FILE *fp, *temp;

    struct Student s;

    char id[20];

    int found = 0;
    int choice;

    fp = fopen("records.txt", "r");

    if(s.strikes == 3) {

    s.communityService += 1;

    printf("\n===== WARNING =====\n");

    printf("%s reached 3 STRIKES!\n",
           s.name);

    printf("Added 1 HOUR of COMMUNITY SERVICE!\n");

    printf("Total Community Service Hours: %d\n",
           s.communityService);

    s.strikes = 0;
}
    temp = fopen("temp.txt", "w");

    getchar();

    printf("Enter Student ID: ");
    fgets(id, sizeof(id), stdin);

    id[strcspn(id, "\n")] = '\0';

    while(fscanf(fp,
        "%19[^|]|%99[^|]|%99[^|]|%d|%d\n",
        s.studentID,
        s.name,
        s.violation,
        &s.strikes,
        &s.communityService) != EOF) {

        if(strcmp(s.studentID, id) == 0) {

            found = 1;

            printf("Enter Violation Number: ");
            scanf("%d", &choice);

            switch(choice) {

                case 1:
                    strcpy(s.violation,
                    "Sleeveless shirts");
                    break;

                case 2:
                    strcpy(s.violation,
                    "Torn and tattered jeans");
                    break;

                case 3:
                    strcpy(s.violation,
                    "Rubber slippers and sandals");
                    break;

                case 4:
                    strcpy(s.violation,
                    "Earrings");
                    break;

                case 5:
                    strcpy(s.violation,
                    "Unnatural hair colors");
                    break;

                case 6:
                    strcpy(s.violation,
                    "Tube/Spaghetti strap blouses");
                    break;

                case 7:
                    strcpy(s.violation,
                    "Short pants");
                    break;

                case 8:
                    strcpy(s.violation,
                    "Micro miniskirts");
                    break;

                case 9:
                    strcpy(s.violation,
                    "See-through attire");
                    break;

                case 10:
                    strcpy(s.violation,
                    "Plunging neckline blouses");
                    break;

                case 11:
                    strcpy(s.violation,
                    "Midriff blouses");
                    break;

                default:
                    strcpy(s.violation,
                    "Unknown Violation");
            }

            s.strikes++;

            if(s.strikes >= 3) {

                s.communityService++;

                printf("\nWARNING!\n");
                printf("Student reached 3 strikes.\n");

                printf("Added 1 Hour Community Service.\n");

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

        printf("\n===== VIOLATIONS =====\n");

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

        printf("\nEnter Violation Number: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                strcpy(newStudent.violation,
                "Sleeveless shirts");
                break;

            case 2:
                strcpy(newStudent.violation,
                "Torn and tattered jeans");
                break;

            case 3:
                strcpy(newStudent.violation,
                "Rubber slippers and sandals");
                break;

            case 4:
                strcpy(newStudent.violation,
                "Earrings");
                break;

            case 5:
                strcpy(newStudent.violation,
                "Unnatural hair colors");
                break;

            case 6:
                strcpy(newStudent.violation,
                "Tube/Spaghetti strap blouses");
                break;

            case 7:
                strcpy(newStudent.violation,
                "Short pants");
                break;

            case 8:
                strcpy(newStudent.violation,
                "Micro miniskirts");
                break;

            case 9:
                strcpy(newStudent.violation,
                "See-through attire");
                break;

            case 10:
                strcpy(newStudent.violation,
                "Plunging neckline blouses");
                break;

            case 11:
                strcpy(newStudent.violation,
                "Midriff blouses");
                break;

            default:
                strcpy(newStudent.violation,
                "Unknown Violation");
        }

        newStudent.strikes = 1;
        newStudent.communityService = 0;

        fprintf(temp,
        "%s|%s|%s|%d|%d\n",
        newStudent.studentID,
        newStudent.name,
        newStudent.violation,
        newStudent.strikes,
        newStudent.communityService);

        printf("\nViolation Recorded!\n");
    }

    fclose(fp);
    fclose(temp);

    remove("records.txt");
    rename("temp.txt", "records.txt");
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

    printf("Enter Student ID: ");
    fgets(id, sizeof(id), stdin);

    id[strcspn(id, "\n")] = '\0';

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