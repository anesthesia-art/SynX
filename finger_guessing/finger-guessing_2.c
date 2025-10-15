//猜拳小游戏第二版，增加10s超时限制

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
    int player_choice,computer_choice;
    int is_player_win = 0;
    time_t start_time,current_time;
    srand((unsigned int)time(NULL));
    printf("=====欢迎来到猜拳小游戏（限十秒内输入）======\n");
    printf("请输入你的选择:1=石头,2=剪刀,3=布 \n");
    while(1){
        current_time = time(NULL);
        if (difftime(current_time,start_time)>10){
            printf("输入超时，游戏结束！\n");
            return 0;
        }
    }
    while (!is_player_win){
        printf("请输入你的选择：");
        scanf("%d",&player_choice);
        if(player_choice<1 || player_choice>3){
            printf("输入错误，请重新输入！\n");
            continue;
        }
        
        computer_choice = rand()%3+1;
        if(computer_choice==1)printf("石头\n");
        else if(computer_choice==2)printf("剪刀\n");
        else if(computer_choice==3)printf("布\n");
        if(player_choice==computer_choice){
            printf("平局！\n");
        }
        else if(player_choice==1 && computer_choice==2){
            printf("你输了！\n");
        }
        else if(player_choice==1 && computer_choice==3){
            printf("你赢了！\n");
            is_player_win = 1;
        }
        else if(player_choice==2 && computer_choice==1){
            printf("你赢了！\n");
            is_player_win = 1;
        }
        else if(player_choice==2 && computer_choice==3){
            printf("你输了！\n");
        }
        else if(player_choice==3 && computer_choice==1){
            printf("你输了！\n");
        }
        else if(player_choice==3 && computer_choice==2){
            printf("你赢了！\n");
            is_player_win = 1;
        }
    }

    return 0;

}
