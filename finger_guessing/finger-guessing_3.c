//猜拳游戏第三版，五局三胜,输出胜局情况

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int player_choice, computer_choice;
    int player_wins = 0, computer_wins = 0;  // Track wins for each side
    int round = 1;  // Track current round
    time_t start_time, current_time;
    
    srand((unsigned int)time(NULL));
    printf("=====Welcome to Rock-Paper-Scissors (Best of 5)======\n");
    printf("First to 3 wins takes the game!\n");
    printf("Please enter your choice: 1=Rock, 2=Scissors, 3=Paper \n\n");
    
    // Continue until one side reaches 3 wins
    while (player_wins < 3 && computer_wins < 3) {
        printf("----- Round %d -----\n", round);
        // Reset timer for each round
        start_time = time(NULL);
        printf("Please enter your choice: ");
        
        // Wait for user input with timeout check
        int input_received = 0;
        while (!input_received) {
            current_time = time(NULL);
            if (difftime(current_time, start_time) > 10) {
                printf("\nTime out! You lose this round!\n");
                computer_wins++;
                input_received = 1;
                continue;
            }
            
            // Check if input is available
            if (scanf("%d", &player_choice) == 1) {
                input_received = 1;
            }
        }
        
        // If we timed out, we already updated the score, so move to next round
        if (player_choice < 1 || player_choice > 3) {
            printf("Invalid input! You lose this round!\n");
            computer_wins++;
            round++;
            continue;
        }
        
        // Computer's choice
        computer_choice = rand() % 3 + 1;
        printf("Computer chooses: ");
        if (computer_choice == 1) printf("Rock\n");
        else if (computer_choice == 2) printf("Scissors\n");
        else printf("Paper\n");
        
        // Determine the result
        if (player_choice == computer_choice) {
            printf("It's a tie! This round doesn't count.\n");
        }
        else if ((player_choice == 1 && computer_choice == 2) || 
                 (player_choice == 2 && computer_choice == 3) || 
                 (player_choice == 3 && computer_choice == 1)) {
            printf("You win this round!\n");
            player_wins++;
            round++;
        }
        else {
            printf("Computer wins this round!\n");
            computer_wins++;
            round++;
        }
        
        // Display current score after each round
        printf("Current score - You: %d | Computer: %d\n\n", player_wins, computer_wins);
    }

    // Determine and display final result
    if (player_wins >= 3) {
        printf("Congratulations! You won the game by %d-%d!\n", player_wins, computer_wins);
    } else {
        printf("Computer won the game by %d-%d! Better luck next time!\n", computer_wins, player_wins);
    }
    
    return 0;
}
