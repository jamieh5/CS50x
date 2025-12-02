#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int computeScore(string str);
void calculateWinner(int scoreUser1, int scoreUser2);

int main(void) {

    string inputUser1 = get_string("Player 1: ");
    string inputUser2 = get_string("Player 2: ");

    int scoreUser1 = computeScore(inputUser1);
    int scoreUser2 = computeScore(inputUser2);

    calculateWinner(scoreUser1, scoreUser2);
}

// Calculating the Scores
int computeScore(string str){
    int sum = 0;
    int scores[] = {1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};

    // Iterate over str[] and add the value to sum
    for (int i = 0, length = strlen(str); i < length; i++) {
        if (isupper(str[i])) {
            sum += scores[str[i] - 'A'];
        } else if (islower(str[i])) {
            sum += scores[str[i] - 'a'];
        }
    }
    printf("%i\n", sum);
    return sum;
}


// Figuring out the Winner
void calculateWinner(int scoreUser1, int scoreUser2) {
    if (scoreUser1 > scoreUser2) {
        printf("Player 1 wins\n");
    } else if (scoreUser1 < scoreUser2) {
        printf("Player 2 wins\n");
    } else if (scoreUser1 == scoreUser2) {
        printf("Tie!\n");
    }
 }
