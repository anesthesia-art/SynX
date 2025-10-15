//三局两胜，有作弊，made by Deepseek
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main() {
    char input[10];
    int player_wins = 0, computer_wins = 0;
    int player_choice, computer_choice;
    int cheat_mode = 0;
    
    // Initialize random seed
    srand(time(NULL));
    
    printf("=== Rock Paper Scissors Game ===\n");
    printf("Best of 3 - Win 2 rounds to win the game\n");
    printf("0 - Rock\n");
    printf("1 - Scissors\n");
    printf("2 - Paper\n");
    printf("Special code: 'zzz' for cheat mode\n\n");
    
    while(player_wins < 2 && computer_wins < 2) {
        printf("=== Round %d ===\n", player_wins + computer_wins + 1);
        printf("Player: %d | Computer: %d\n", player_wins, computer_wins);
        
        // Get player input with 10-second timeout
        time_t start_time, current_time;
        time(&start_time);
        
        printf("You have 10 seconds: ");
        fflush(stdout); // Ensure prompt is displayed immediately
        
        int timed_out = 1;
        int i = 0;
        
        // Read input character by character with timeout
        while (i < sizeof(input) - 1) {
            // Check if time has exceeded 10 seconds
            time(&current_time);
            if (difftime(current_time, start_time) >= 10.0) {
                timed_out = 1;
                break;
            }
            
            // Check if input is available
            if (scanf("%c", &input[i]) == EOF) {
                break;
            }
            
            // If newline is entered, we have the complete input
            if (input[i] == '\n') {
                input[i] = '\0'; // Replace newline with null terminator
                timed_out = 0;
                break;
            }
            
            i++;
        }
        
        if (timed_out) {
            printf("\nTime's up! You lose this round.\n");
            computer_wins++;
            printf("\n");
            
            // Clear any remaining input in buffer
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            continue;
        }
        
        // Check for cheat code
        if (strcmp(input, "zzz") == 0) {
            printf("Cheat mode activated! You will win automatically.\n");
            cheat_mode = 1;
            player_wins = 2;
            break;
        }
        
        // Convert input to integer
        player_choice = atoi(input);
        
        // Validate input
        if (player_choice < 0 || player_choice > 2) {
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
            printf("It's a tie! This round doesn't count.\n\n");
        }
        else if((player_choice == 0 && computer_choice == 1) ||  // Rock vs Scissors
                (player_choice == 1 && computer_choice == 2) ||  // Scissors vs Paper
                (player_choice == 2 && computer_choice == 0)) {  // Paper vs Rock
            printf("You win this round!\n\n");
            player_wins++;
        }
        else {
            printf("Computer wins this round!\n\n");
            computer_wins++;
        }
    }
    
    // Display final result
    printf("=== Final Result ===\n");
    printf("Player: %d | Computer: %d\n", player_wins, computer_wins);
    
    if(cheat_mode) {
        printf("You won using cheat mode!\n");
    }
    else if(player_wins == 2) {
        printf("Congratulations! You won the game!\n");
    }
    else {
        printf("Computer won the game. Better luck next time!\n");
    }
    
    return 0;
}