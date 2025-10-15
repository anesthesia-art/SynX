//猜拳小游戏第一版


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int player_choice, computer_choice;
    
    // Initialize random seed
    srand(time(NULL));
    
    printf("=== Rock Paper Scissors Game ===\n");
    printf("Game Rule: Win once to exit the game\n");
    printf("0 - Rock\n");
    printf("1 - Scissors\n");
    printf("2 - Paper\n\n");
    
    while(1) {
        // Player input
        printf("Enter your choice (0-Rock, 1-Scissors, 2-Paper): ");
        scanf("%d", &player_choice);
        
        // Input validation
        if(player_choice < 0 || player_choice > 2) {
            printf("Invalid input! Please enter 0, 1, or 2.\n\n");
            continue;
        }
        
        // Computer random choice
        computer_choice = rand() % 3;
        
        // Display choices
        printf("You chose: ");
        switch(player_choice) {
            case 0: printf("Rock"); break;
            case 1: printf("Scissors"); break;
            case 2: printf("Paper"); break;
        }
        
        printf("  VS  ");
        
        printf("Computer chose: ");
        switch(computer_choice) {
            case 0: printf("Rock"); break;
            case 1: printf("Scissors"); break;
            case 2: printf("Paper"); break;
        }
        printf("\n");
        
        // Determine winner
        if(player_choice == computer_choice) {
            printf("It's a tie! Continue playing...\n\n");
        }
        else if((player_choice == 0 && computer_choice == 1) ||  // Rock vs Scissors
                (player_choice == 1 && computer_choice == 2) ||  // Scissors vs Paper
                (player_choice == 2 && computer_choice == 0)) {  // Paper vs Rock
            printf("Congratulations! You won! Game over.\n");
            break;
        }
        else {
            printf("You lost! Continue playing...\n\n");
        }
    }
    
    return 0;
}