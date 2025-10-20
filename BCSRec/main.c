#include <stdio.h>
#include <stdbool.h>
#include <assert.h>
#include "main.h"


#ifndef UNIT_TEST
void main() {
    int length = 1;
    int width = 1;
    bool continueProgram = true;
    while (continueProgram) {
        printWelcomeMenu();
        printOptions();
        int menuInput = getIntInput("Enter menu option number:");

        switch (menuInput)
        {
        case 1:
            printf("\nThe Rectangle has a length of %i and a width of %i\n\n", length, width);
            break;
        case 2:
        {
            int input = getIntInput("Please enter the length of the rectangle:");
            setLength(input, &length);
            break;
        }
        case 3:
        {
            int input = getIntInput("Please enter the width of the rectangle:");
            setWidth(input, &width);
            break;
        }
        case 4:
            printf("\nThe Rectangle has a perimeter of %i\n\n", getPerimeter(&length, &width));
            break;
        case 5:
            printf("\nThe Rectangle has an area of %i\n\n", getArea(&length, &width));
            break;
        case 6:
            continueProgram = false;
            break;
        default:
            printf("\nInvalid value entered.\n\n");
            break;
        }
    }
}
#endif


int getIntInput(char message[]) {
    int input, scannedValues;
    do {
        printf("\n%s\n", message);
        scannedValues = scanf_s("%i", &input);
        int buf;
        while ((buf = getchar()) != '\n' && buf != EOF);
    } while (scannedValues != 1);
    return input;
}

void setLength(int input, int* length) {
    if (input >= 1 && input <= 99) *length = input;
}

void setWidth(int input, int* width) {
    if (input >= 1 && input <= 99) *width = input;
}

int getPerimeter(int* length, int* width) {
    return 2 * (*length + *width);
}

int getArea(int* length, int* width) {
    return (*length) * (*width);
}

void printWelcomeMenu() {
    printf(" **********************\n");
    printf("**     Welcome to     **\n");
    printf("**    Assignment 02   **\n");
    printf(" **********************\n");
}

void printOptions() {
    printf("1. Get Rectangle Length & Width\n");
    printf("2. Change Rectangle Length\n");
    printf("3. Change Rectangle Width\n");
    printf("4. Get Rectangle Perimeter\n");
    printf("5. Get Rectangle Area\n");
    printf("6. Exit\n");
}


#ifdef UNIT_TEST

// Task 1
void test_getPerimeter() { int l = 5, w = 3; assert(getPerimeter(&l, &w) == 16); }
void test_getArea() { int l = 5, w = 3; assert(getArea(&l, &w) == 15); }

// Task 2
void test_setLength_valid() { int l = 0; setLength(50, &l); assert(l == 50); }
void test_setLength_min() { int l = 10; setLength(1, &l); assert(l == 1); }
void test_setLength_invalid() { int l = 20; setLength(0, &l); assert(l == 20); }

void test_setWidth_valid() { int w = 0; setWidth(75, &w); assert(w == 75); }
void test_setWidth_max() { int w = 50; setWidth(99, &w); assert(w == 99); }
void test_setWidth_invalid() { int w = 40; setWidth(100, &w); assert(w == 40); }

int main() {
    test_getPerimeter(); test_getArea();
    test_setLength_valid(); test_setLength_min(); test_setLength_invalid();
    test_setWidth_valid(); test_setWidth_max(); test_setWidth_invalid();
    printf("All 8 unit tests passed!\n");
    return 0;
}

#endif
