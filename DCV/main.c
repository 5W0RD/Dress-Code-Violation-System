#include <stdio.h>
#include "violations.h"

int main() {

    int choice;

    do {

        printf("\n===== UNIFORM / DRESS CODE VIOLATION LOG =====\n");

        printf("1. Record Violation\n");
        printf("2. View Violations\n");
        printf("3. Search Student\n");
        printf("0. Exit\n");

        printf("\nEnter Choice: ");
        scanf("%d", &choice);

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

            case 0:
                printf("\nExiting Program...\n");
                break;

            default:
                printf("\nInvalid Choice!\n");
        }

    } while(choice != 0);

    return 0;
}