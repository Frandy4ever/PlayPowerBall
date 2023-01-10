/* File: myPowerBall
 * Author: Frandy Slueue
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_WHITE_BALLS 69
#define NUM_POWER_BALLS 26
#define TICKET_PRICE 2

void print_winning_numbers(int white_balls[5], int power_ball) {
    printf("Winning numbers: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", white_balls[i]);
    }
    printf("Powerball: %d\n", power_ball);
}

int main(void) {
    int winning_white_balls[5];
    int winning_power_ball;
    int player_white_balls[5];
    int player_power_ball;
    int num_matches;
    int prize;

    // Seed the random number generator
    srand(time(0));

    // Generate the winning numbers
    for (int i = 0; i < 5; i++) {
        winning_white_balls[i] = rand() % NUM_WHITE_BALLS + 1;
    }


    // Get the player's numbers
    printf("Enter your 5 white balls (separated by spaces): ");
    scanf("%d %d %d %d %d", &player_white_balls[0], &player_white_balls[1], &player_white_balls[2], &player_white_balls[3], &player_white_balls[4]);
    printf("Enter your Powerball: ");
    scanf("%d", &player_power_ball);

    winning_power_ball = rand() % NUM_POWER_BALLS + 1;

    // Print the winning numbers
    print_winning_numbers(winning_white_balls, winning_power_ball);

    // Compare the player's numbers to the winning numbers
    num_matches = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (player_white_balls[i] == winning_white_balls[j]) {
                num_matches++;
                break;
            }
        }
    }
    if (player_power_ball == winning_power_ball) {
        num_matches++;
    }

    // Determine the prize based on the number of matches
    if (num_matches == 6) {
        prize = 1000000000;
    } else if (num_matches == 5) {
        prize = 1000000;
    } else if (num_matches == 4) {
        prize = 100;
    } else if (num_matches == 3) {
        prize = 7;
    } else if (num_matches == 2) {
        prize = 7;
    } else if (num_matches == 1) {
        prize = 4;
    } else {
        prize = 0;
    }

    // Print the prize
    printf("You won $%d!\n", prize);

    return 0;
}
