#include "main.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int generateTwoDigitNumber(int exclude) {
    if (exclude < 0 || exclude > 2) {
        return -1; // Invalid input
    }

    int digits[2];
    int index = 0;

    // Fill the array with the remaining two digits
    for (int i = 0; i <= 2; i++) {
        if (i != exclude) {
            digits[index++] = i;
        }
    }

    // Shuffle the two digits randomly
    if (rand() % 2) {
        int temp = digits[0];
        digits[0] = digits[1];
        digits[1] = temp;
    }

    // Convert to a two-digit number
    return digits[0] * 10 + digits[1];
}

int generateFourDigitNumber(int exclude) {
    if (exclude < 0 || exclude > 4) {
        return -1; // Invalid input
    }

    int digits[4];
    int index = 0;

    // Fill the array with the remaining four digits
    for (int i = 0; i <= 4; i++) {
        if (i != exclude) {
            digits[index++] = i;
        }
    }

    // Shuffle the four digits randomly
    for (int i = 3; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = digits[i];
        digits[i] = digits[j];
        digits[j] = temp;
    }

    // Convert to a four-digit number
    return digits[0] * 1000 + digits[1] * 100 + digits[2] * 10 + digits[3];
}

long generateEightDigitNumber(int exclude) {
    if (exclude < 0 || exclude > 8) {
        return -1; // Invalid input
    }

    int digits[8];
    int index = 0;

    // Fill the array with digits 0-8, skipping the excluded number
    for (int i = 0; i < 9; i++) {
        if (i != exclude) {
            digits[index++] = i;
        }
    }

    // Shuffle the array (Fisher-Yates Shuffle)
    for (int i = 8; i > 0; i--) {
        int j = rand() % (i + 1);
        int temp = digits[i];
        digits[i] = digits[j];
        digits[j] = temp;
    }

    // Convert the array into a 8-digit number
    long result = 0;
    for (int i = 0; i < 8; i++) {
        result = result * 10 + digits[i];
    }

    return result;
}