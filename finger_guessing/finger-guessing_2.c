//猜拳小游戏第二版，增加10s超时限制，时间限制我没搞懂，直接喊AI增加进来的

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int player_choice, computer_choice;
    int is_player_win = 0;
    time_t start_time, current_time;
    
    srand((unsigned int)time(NULL));
    printf("=====Welcome to Rock-Paper-Scissors (input within 10 seconds)======\n");
    printf("Please enter your choice: 1=Rock, 2=Scissors, 3=Paper \n");
    
    while (!is_player_win) {
        // Reset timer for each round
        start_time = time(NULL);
        printf("Please enter your choice: ");
        
        // Wait for user input with timeout check
        int input_received = 0;
        while (!input_received) {
            current_time = time(NULL);
            if (difftime(current_time, start_time) > 10) {
                printf("\nTime out! Game over!\n");
                return 0;
            }
            
            // Check if input is available
            if (scanf("%d", &player_choice) == 1) {
                input_received = 1;
            }
        }
        
        if (player_choice < 1 || player_choice > 3) {
            printf("Invalid input, please try again!\n");
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
            printf("It's a tie! Let's try again!\n");
        }
        else if ((player_choice == 1 && computer_choice == 2) || 
                 (player_choice == 2 && computer_choice == 3) || 
                 (player_choice == 3 && computer_choice == 1)) {
            printf("You win!\n");
            is_player_win = 1;
        }
        else {
            printf("You lose! Let's try again!\n");
        }
    }

    printf("Congratulations on your victory! Game over!\n");
    return 0;
}
