#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>   /////   This is for timing library



void clearScreen() {
    system("clear");
}

void printWelcomeMessage() {
    printf("                                   #######################################\n");
    printf("                                   !!                                   !!\n");
    printf("                                   !!     WELCOME TO MOSARAF WORLD      !!\n");
    printf("                                   !!                                   !!\n");
    printf("                                   #######################################\n\n\n");
}

void connectToServer() {
    char serverAddress[100];
    char user[100];
    char password[100];

    printf("Enter the server IP address: ");
    scanf("%s", serverAddress);
    printf("Enter your target name: ");
    scanf("%s", user);
    printf("Enter password: ");
    scanf("%s", password);

    printf("Trying to connect to %s@%s...\n", user, serverAddress);
    char command[200];
    sprintf(command, "sshpass -p %s ssh %s@%s", password, user, serverAddress);    
    int exitCode = system(command);
    if (exitCode == 0) {
        printf("SSH connection established.\n");
    } else {
        printf("Failed to establish SSH connection.\n");
    }
    exit(0);
}

int main() {
    char name[100];
    char choice[5];

    while (1) {
        printf("Who are you? and What's your name?  ");
        scanf("%s", name);

        if (strcmp(name, "Kamal") == 0 || strcmp(name, "kamal") == 0) {
            printf("\nOh Wow, You are mine Dear sir\n");
            sleep(3);
            printf("\nWhat would you like to do here? All are yours\n");
            sleep(2);
            printf("1 - Connect via ssh\n");
            printf("2 - Option\n");
            printf("3 - Option\n");
            printf("4 - Option\n");
            printf("5 - Option\n");
            printf("6 - Something else..\n");
            printf("7 - Exit\n\n");
            scanf("%s", choice);

            switch (atoi(choice)) {
                case 1:
                    connectToServer();
                    break;
                case 2:
                    printf("You typed option 2.\n");
                    break;
                case 3:
                    printf("You typed option 3.\n");
                    break;
                case 4:
                    printf("You typed option 4.\n");
                    break;
                case 5:
                    printf("You typed option 5.\n");
                    break;
                case 6:
                    printf("Have to add so many cool things.\n");
                    break;
                case 7:
                    exit(0);
                default:
                    printf("You didn't enter an appropriate choice.\n");
            }
        } else {
            printf("Sorry! You are not permanent\n");
        }

        printf("Would you like to run the code again? (yes/no) ");
        scanf("%s", choice);

        if (strcmp(choice, "no") == 0 || strcmp(choice, "NO") == 0 || strcmp(choice, "n") == 0 || strcmp(choice, "N") == 0) {
            break;
        }
    }

    printf("Exiting program...\n");
    return 0;
}

