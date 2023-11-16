#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person {
    char name[50];
    int* debts;
    int amount;
};

void initializePersons(struct Person* persons, char** names, int n) {
    for (int i = 0; i < n; i++) {
        strcpy(persons[i].name, names[i]);
        persons[i].debts = malloc(n * sizeof(int));
        persons[i].amount = 0;

        for (int j = 0; j < n; j++) {
            if (i != j) {
                printf("Enter the amount owed by %s to %s: ", persons[i].name, names[j]);
                scanf("%d", &persons[i].debts[j]);
                persons[i].amount += persons[i].debts[j];
            }
        }
    }
}

void settleAmounts(struct Person* persons, char** names, int n) {
    int* netAmounts = malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        netAmounts[i] = 0;
        for (int j = 0; j < n; j++) {
            netAmounts[i] += persons[j].debts[i];
            netAmounts[i] -= persons[i].debts[j];
        }
    }

    while (1) {
        int maxDebit = 0, maxCredit = 0;
        int debtorIndex = -1, creditorIndex = -1;

        for (int i = 0; i < n; i++) {
            if (netAmounts[i] < 0 && -netAmounts[i] > maxDebit) {
                maxDebit = -netAmounts[i];
                debtorIndex = i;
            } else if (netAmounts[i] > 0 && netAmounts[i] > maxCredit) {
                maxCredit = netAmounts[i];
                creditorIndex = i;
            }
        }

        if (debtorIndex != -1 && creditorIndex != -1) {
            int minAmount = (maxDebit < maxCredit) ? maxDebit : maxCredit;

            persons[debtorIndex].amount += minAmount;
            persons[creditorIndex].amount -= minAmount;

            netAmounts[debtorIndex] += minAmount;
            netAmounts[creditorIndex] -= minAmount;

            printf("%s owes %d to %s\n", names[debtorIndex], minAmount, names[creditorIndex]);
        } else {
            break;
        }
    }

    free(netAmounts);
}

void addNewPerson(struct Person** persons, char*** names, int* n) {
    (*n)++;
    *names = realloc(*names, (*n) * sizeof(char*));
    (*names)[*n - 1] = malloc(50 * sizeof(char));
    printf("Enter the name of the new person: ");
    scanf("%s", (*names)[*n - 1]);

    *persons = realloc(*persons, (*n) * sizeof(struct Person));
    strcpy((*persons)[*n - 1].name, (*names)[*n - 1]);
    (*persons)[*n - 1].debts = malloc((*n) * sizeof(int));
    (*persons)[*n - 1].amount = 0;

    for (int i = 0; i < *n - 1; i++) {
        printf("Enter the amount owed by %s to %s: ", (*names)[i], (*names)[*n - 1]);
        scanf("%d", &((*persons)[i].debts[*n - 1]));
        (*persons)[i].amount += (*persons)[i].debts[*n - 1];
        (*persons)[*n - 1].debts[i] = 0;
    }
}

int main() {
    int n;
    printf("Enter the number of persons: ");
    scanf("%d", &n);

    char** names = malloc(n * sizeof(char*));
    for (int i = 0; i < n; i++) {
        names[i] = malloc(50 * sizeof(char));
        printf("Enter the name of person %d: ", i + 1);
        scanf("%s", names[i]);
    }

    struct Person* persons = malloc(n * sizeof(struct Person));
    initializePersons(persons, names, n);

    printf("\nSettlements:\n");
    settleAmounts(persons, names, n);

    printf("Would you like to add a new person? (y for yes and n for no)\n");
    char c;
    scanf(" %c", &c);

    while (c == 'y') {
        addNewPerson(&persons, &names, &n);
        printf("\nUpdated Settlements:\n");
        settleAmounts(persons, names, n);

        printf("Would you like to add a new person? (y for yes and n for no)\n");
        scanf(" %c", &c);
        if (c=='n'){
            break;
        }
    }

    for (int i = 0; i < n; i++) {
        free(names[i]);
        free(persons[i].debts);
    }
    free(names);
    free(persons);

    return 0;
}
