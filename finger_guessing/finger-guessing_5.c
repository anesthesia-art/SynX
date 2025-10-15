//五局三胜变三局两胜


#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int player_choice, computer_choice;
    int player_wins = 0, computer_wins = 0;
    int round = 1;
    time_t start_time, current_time;
    
    srand((unsigned int)time(NULL));
    printf("=====Welcome to Rock-Paper-Scissors (Best of 3)======\n");
    printf("First to 2 wins takes the game!\n");
    printf("Please enter your choice: 1=Rock, 2=Scissors, 3=Paper \n\n");
    
    while (player_wins < 2 && computer_wins < 2) {
        printf("----- Round %d -----\n", round);
        start_time = time(NULL);
        printf("Please enter your choice: ");
        
        int input_received = 0;
        int timeout_occurred = 0; 
        
        while (!input_received) {
            current_time = time(NULL);
            if (difftime(current_time, start_time) > 10) {
                printf("\nTime out! You lose this round!\n");
                computer_wins++;
                input_received = 1;
                timeout_occurred = 1;
                round++;  
                continue;
            }
            
           
            if (scanf("%d", &player_choice) == 1) {
                input_received = 1;
            }
        }
        
       
        if (timeout_occurred) {
            printf("Current score - You: %d | Computer: %d\n\n", player_wins, computer_wins);
            continue;
        }
        
        if (player_choice < 1 || player_choice > 3) {
            printf("Invalid input! You lose this round!\n");
            computer_wins++;
            round++;
        }       
        else {
            printf("You chose: ");
            if (player_choice == 1) printf("Rock\n");
            else if (player_choice == 2) printf("Scissors\n");
            else printf("Paper\n");
            
            computer_choice = rand() % 3 + 1;
            printf("Computer chooses: ");
            if (computer_choice == 1) printf("Rock\n");
            else if (computer_choice == 2) printf("Scissors\n");
            else printf("Paper\n");
            
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
        }
              
        printf("Current score - You: %d | Computer: %d\n\n", player_wins, computer_wins);
    }

    if (player_wins >= 2) {
        printf("Congratulations! You won the game by %d-%d!\n", player_wins, computer_wins);
    } else {
        printf("Computer won the game by %d-%d! Better luck next time!\n", computer_wins, player_wins);
    }
    
    return 0;
}
