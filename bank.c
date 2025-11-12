#include <stdio.h>

// Function prototypes
// These declare the functions before main() so the compiler knows about them
void deposit(float *balance);      // Function to deposit money into balance
void withdraw(float *balance);     // Function to withdraw money from balance
void checkBalance(float balance);  // Function to display current balance

int main() {
    float balance = 0.0;  // Initialize account balance to 0
    int choice;            // Variable to store user menu choice

    // Menu loop - keeps running until user chooses to exit
    do {
        printf("\n==== Bank Simulator ====\n");
        printf("1. Deposit\n2. Withdraw\n3. Check Balance\n4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);  // Read user's choice

        // Perform action based on user's choice
        switch (choice) {
            case 1: 
                deposit(&balance);   // Call deposit function, passing address of balance
                break;
            case 2: 
                withdraw(&balance);  // Call withdraw function, passing address of balance
                break;
            case 3: 
                checkBalance(balance); // Call check balance function
                break;
            case 4: 
                printf("Thank you!\n"); // Exit message
                break;
            default: 
                printf("Invalid choice!\n"); // Handle invalid input
        }
    } while (choice != 4);  // Repeat until user chooses 4 (Exit)

    return 0;
}

// Function to deposit money
void deposit(float *balance) {
    float amount;
    printf("Enter deposit amount: ");
    scanf("%f", &amount);  // Read deposit amount
    *balance += amount;    // Add amount to balance using pointer
    printf("Deposited %.2f successfully.\n", amount); // Confirmation message
}

// Function to withdraw money
void withdraw(float *balance) {
    float amount;
    printf("Enter withdraw amount: ");
    scanf("%f", &amount);  // Read withdrawal amount

    // Check if balance is sufficient
    if (amount > *balance)
        printf("Insufficient balance!\n"); // Not enough money
    else {
        *balance -= amount; // Subtract amount from balance
        printf("Withdrawn %.2f successfully.\n", amount); // Confirmation message
    }
}

// Function to display current balance
void checkBalance(float balance) {
    printf("Current Balance: ₹%.2f\n", balance); // Print balance
}