#include <stdio.h>
#include "violations.h"

int main() {

    int choice;

    do {

        printf("\n===== DRESS CODE VIOLATION SYSTEM =====\n");

        printf("1. Record Violation\n");
        printf("2. View Violations\n");
        printf("3. Search Student\n");
        printf("4. Edit Student\n");
        printf("5. Clean Record\n");
        printf("6. Exit\n");

        printf("\nEnter Choice: ");

        while(scanf("%d", &choice) != 1) {

            printf("Invalid input! Numbers only.\n");

            while(getchar() != '\n');

            printf("Enter Choice: ");
        }

        switch(choice) {

            case 1:
                recordViolation();
                break;

            case 2:
                viewViolations();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                editStudent();
                break;

            case 5:
                cleanRecord();
                break;

            case 6:
                printf("Exiting Program...\n");
                break;

            default:
                printf("Invalid Choice!\n");
        }

    } while(choice != 6);

    return 0;
}
