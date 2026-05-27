#ifndef VIOLATIONS_H
#define VIOLATIONS_H

struct Student {

    char studentID[20];
    char name[100];
    char violation[100];
    int strikes;
    int communityService;
};

void recordViolation();
void viewViolations();
void searchStudent();
void editStudent();
void cleanRecord();

#endif
