#include <stdio.h>
#include <cs50.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

// ASCII Values = Spaces (32), ! (33), . (46), ? (63), A - Z (65 - 90), a - z (97 - 122)
// Formula: index = 0.0588 * L - 0.296 * S - 15.8
// L = average number of letters per 100 words; S = average number of sentences per 100 words;

float calculateText(string str);
void printGrade(int grade);

int main(void) {
    string txt = get_string("Text: ");
    int grade = calculateText(txt);

    printGrade(grade);
}

float calculateText(string str) {
    int words = 1;
    int letters = 0;
    int sentences = 0;
    for (int i = 0, length = strlen(str); i < length; i++) {
        if ( (int) str[i] == 32) {
            words++;
        }
        if ( (int) str[i] == 33 || (int) str[i] == 46 || (int) str[i] == 63) {
            sentences++;
        }
        if ( (int) str[i] > 64 && (int) str[i] < 91) {
            letters++;
        }
        if ( (int) str[i] > 96 && (int) str[i] < 123) {
            letters++;
        }
    }

    float l = (float) letters / words * 100;
    float s = (float) sentences / words * 100;

    int grade = round(0.0588 * l - 0.296 * s - 15.8);

   printf("%i %i %i %i\n", words, letters, sentences, grade);

    return grade;
}

void printGrade(int grade) {
    if (grade >= 16) {
        printf("Grade 16+\n");
    } else if (grade < 1) {
        printf("Before Grade 1\n");
    } else {
        printf("Grade %i\n", grade);
    }
}
