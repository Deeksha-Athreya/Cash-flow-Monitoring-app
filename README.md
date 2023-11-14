# Cash Settlement Algorithm Implementation
## Algorithm Implemented

This program implements a cash settlement algorithm using a Greedy approach to minimize the total cash flow among a group of friends who owe money to each other. The algorithm works as follows:

    - Input Debt and Credit Information:
        Users provide the amount owed by each person to every other person.

    - Calculate Net Amounts:
        Calculate the net amount for each person by computing the difference between the sum of debts owed to them and the sum of debts they owe to others.

    - Settle Debts:
        Iteratively identify the maximum debtor and maximum creditor.
        Settle the debt between them by choosing the minimum of the maximum debit or maximum credit and updating the balances accordingly.

## Data Structures Used

   - Struct Person:
        Contains the name of the person and arrays to store their debts to other individuals.
        - `name`: Name of the person.
        - `debts`: Array to store debts owed to other individuals.
        - `amount`: Total amount owed by the person.
   - `newAmount`: Array to store the updated amounts after each settlement.

## Functionalities Implemented

   - Input Debt Information:
        Users can enter the amount owed by each person to every other person.

    - Calculate Settlements:
        The program calculates and executes settlements between individuals to minimize the total cash flow.

    - Display Settlements:
        Shows the transactions executed to settle debts among friends.

## How to Use

   - Run the program.
   - Enter the number of persons involved.
   - Enter the names of each person.
   - Enter the amounts owed by each person to every other person as prompted.

## Notes

    This algorithm uses a greedy strategy to optimize the cash flow but may not always result in the absolutely minimal cash flow.
    It's essential to provide accurate debt and credit information for optimal results.
