#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Test values: HI, key = 3, output: KL

string addKey(int key, string plaintext);

int main (int argc, string argv[]) {
    // Handling too many command-line arguments and if the argument is empty
    bool execute = true;
    if (argc == 1) {
        execute = false;
    } else if (argc != 2) {
        execute = false;
    }
    if (execute == false) {
        return 1;
    }

    bool isDigit = false;
    for (int i = 0, length = strlen(argv[1]); i < length; i++) {
        if (isdigit(argv[1][i]) != 0) {
            isDigit = true;
        } else {
            isDigit = false;
        }
    }
    if (isDigit == false) {
        printf("Usage: ./caesar key\n");
        return 1;
    }
        int key = atoi(argv[1]);

        string plaintext = get_string("Plaintext:  ");
        addKey(key, plaintext);
}

string addKey(int key, string plaintext) {
    string ciphertext = plaintext;
    for (int i = 0, length = strlen(plaintext); i < length; i++) {
        while (key > 25) {
        key -= 26;
    }
        printf("%i", key);
        if (isupper(plaintext[i])) {
            if (plaintext[i] + key > 90) {
                ciphertext[i] = plaintext[i] + key - 26;
            } else {
                ciphertext[i] = plaintext[i] + key;
            }
        }
        if (islower(plaintext[i])) {
            if (plaintext[i] + key > 122) {
                ciphertext[i] = plaintext[i] + key - 26;
            } else {
                ciphertext[i] = plaintext[i] + key;
            }
        }
    }

    printf("ciphertext: %s\n", ciphertext);
    return ciphertext;
}
