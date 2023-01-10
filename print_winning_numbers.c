/* File: print_winning_numbers.c
 * Author: Frandy Slueue
 */

#include "myPowerBall.h"

void print_winning_numbers(int white_balls[5], int power_ball) {
    printf("Winning numbers: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", white_balls[i]);
    }
    printf("Powerball: %d\n", power_ball);
}
