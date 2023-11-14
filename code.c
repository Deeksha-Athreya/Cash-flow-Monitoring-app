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

        for (int j = 0; j < n; j++) {
            if(i!=j){
            printf("Enter the amount owed by %s to %s: ", persons[i].name, names[j]);
            scanf("%d", &persons[i].debts[j]);
            persons[i].amount += persons[i].debts[j];
        }
        else{
            continue;
        }
        }
    }
}

void settleAmounts(struct Person* persons, char** names, int n) {
    // Calculate net amount for each person
    int* netAmounts = malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) {
        netAmounts[i] = 0;
        for (int j = 0; j < n; j++) {
            netAmounts[i] += persons[j].debts[i];
            netAmounts[i] -= persons[i].debts[j];
        }
    }

    while (1) {
        // Find the maximum debtor and maximum creditor
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

        // If both a debtor and creditor are found, settle the amount
        if (debtorIndex != -1 && creditorIndex != -1) {
            int minAmount = (maxDebit < maxCredit) ? maxDebit : maxCredit;

            persons[debtorIndex].amount += minAmount;
            persons[creditorIndex].amount -= minAmount;

            // Update net amounts
            netAmounts[debtorIndex] += minAmount;
            netAmounts[creditorIndex] -= minAmount;

            // Print the transaction
            printf("%s owes %d to %s\n", names[debtorIndex], minAmount, names[creditorIndex]);
        } else {
            // If no valid transaction can be performed, exit the loop
            break;
        }
    }

    free(netAmounts);
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

    // Free allocated memory
    for (int i = 0; i < n; i++) {
        free(names[i]);
        free(persons[i].debts);
    }
    free(names);
    free(persons);

    return 0;
}
