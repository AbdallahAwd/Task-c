#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_USERS 10

struct User {
    char username[50];
    char password[50];
    bool loggedIn;  // New flag to track login status
};

struct User users[MAX_USERS];

int numUsers = 0;

// Function to register a new user
void registerUser() {
    if (numUsers >= MAX_USERS) {
        printf("Sorry, maximum number of users reached.\n");
        return;
    }

    printf("Enter a username: ");
    scanf("%s", users[numUsers].username);

    printf("Enter a password: ");
    scanf("%s", users[numUsers].password);

    int loginFlag;
    printf("Enter a login flag (1 for true, 0 for false): ");
    scanf("%d", &loginFlag);

    // Convert the integer to a boolean value
    users[numUsers].loggedIn = (loginFlag != 0);

    printf("Registration successful!\n");
    numUsers++;
}

// Function to log in
void loginUser() {
    char username[50];
    char password[50];

    printf("Enter your username: ");
    scanf("%s", username);

    printf("Enter your password: ");
    scanf("%s", password);

    for (int i = 0; i < numUsers; i++) {
        if (strcmp(username, users[i].username) == 0 && strcmp(password, users[i].password) == 0) {
            if (users[i].loggedIn) {
                printf("Login successful!\n");
            } else {
                printf("Login failed. User not allowed to log in.\n");
            }
            return;
        }
    }

    printf("Login failed. Invalid username or password.\n");
}

int main() {
    int choice;

    while (1) {
        printf("Choose an option:\n");
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                printf("Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
