# Cashflow minimization 


## Algorithm Implemented
The greedy algorithm in this program aims to minimize the total amount owed among a group of individuals. It iteratively identifies pairs of individuals where one owes money to the other, then settles the debts between them, effectively reducing the overall owed amount.

## Data Structures Used
- **Struct `Person`**
  - Contains:
    - `name`: String array to store the name of each person.
    - `debts`: Integer pointer used to store the debts owed by each person to others.
    - `amount`: Integer to track the total amount owed by each person.

## Functionalities Implemented
1. **Initialization of Persons and Debts**
   - Users input the number of persons and their names.
   - Amounts owed between each pair of persons are entered, and initial debt amounts for each person are computed.

2. **Debt Settlement Algorithm**
   - Iteratively identifies pairs of individuals with owed amounts.
   - Performs settlements between these individuals to minimize the overall amount owed.

3. **Adding a New Person**
   - Users can include a new person in the existing group.
   - They input the new person's name and the amounts owed between this person and existing group members.
   - Settlements are recalculated considering the new individual.

## How to Use:
 **Input Instructions**
   - Enter the number of persons and their names.
   - Input the amounts each person owes to others when prompted.
   - Choose to add a new person when prompted and provide their owed amounts.

## Test Cases

### Test Case 1: Initialization and Settlements
- **Input:**
  - Three persons: Alice, Bob, Charlie
  - Amounts owed:
    - Alice owes 20 to Bob, 30 to Charlie
    - Bob owes 10 to Alice, 25 to Charlie
    - Charlie owes 15 to Alice, 20 to Bob

- **Expected Output:**
  - Settlements between the three individuals are performed, reducing the overall amount owed.

### Test Case 2: Adding a New Person
- **Input:**
  - Three persons: Alice, Bob, Charlie (as in Test Case 1)
  - Addition of a new person: Dave
  - Amounts owed by Dave to existing persons:
    - Dave owes 10 to Alice, 15 to Bob, 5 to Charlie

- **Expected Output:**
  - Settlements are recalculated with Dave included, reducing the overall amount owed among all individuals.

## Notes
- Ensure correct input of owed amounts to prevent errors in debt calculations.
- The program handles existing debts efficiently and recalculates settlements upon adding a new person.

