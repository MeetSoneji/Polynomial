#include <stdio.h>
#include <stdlib.h>
struct Term {
    int coefficient;
    int exponentX;
    int exponentY;
    struct Term* next;
};
struct Term* createTerm(int coefficient, int exponentX, int exponentY) {
    struct Term* newTerm = (struct Term*)malloc(sizeof(struct Term));
    if (newTerm == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newTerm->coefficient = coefficient;
    newTerm->exponentX = exponentX;
    newTerm->exponentY = exponentY;
    newTerm->next = NULL;
    return newTerm;
}
void insert(struct Term** polynomial, int coefficient, int exponentX, int exponentY) {
    struct Term* newTerm = createTerm(coefficient, exponentX, exponentY);
    if (*polynomial == NULL) {
        *polynomial = newTerm;
    } else {
        struct Term* temp = *polynomial;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newTerm;
    }
}
void display(struct Term* polynomial) {
    if (polynomial == NULL) {
        printf("Polynomial is empty!\n");
        return;
    }
    struct Term* temp = polynomial;
    printf("Polynomial: ");
    while (temp != NULL) {
        printf("%d", temp->coefficient);
        if (temp->exponentX > 0) {
            printf("x^%d", temp->exponentX);
        }
        if (temp->exponentY > 0) {
            printf("y^%d", temp->exponentY);
        }
        if (temp->next != NULL) {
            printf(" + ");
        }
        temp = temp->next;
    }
    printf("\n");
}
int main() {
    struct Term* polynomial = NULL;
    insert(&polynomial, 2, 3, 2);
    insert(&polynomial, -4, 1, 4);
    insert(&polynomial, 1, 0, 0);
    insert(&polynomial, 3, 2, 3);
    display(polynomial);

    return 0;
}
