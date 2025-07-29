/*
 * Shift Cipher Encryption and Decryption
 *
 * This program implements a simple shift cipher (Caesar cipher) for encrypting and decrypting strings.
 * It supports both uppercase and lowercase English letters, preserving non-alphabetic characters.
 */

/**
 * Encrypts the input string using a shift cipher (Caesar cipher).
 *
 * @param input   The original string to encrypt.
 * @param output  The buffer to store the encrypted string (should be large enough).
 * @param shift   The number of positions to shift each alphabetic character represent as key.
 *
 * Summary:
 *   Iterates through each character of the input string. If the character is an uppercase or lowercase
 *   letter, it shifts it by the specified amount, wrapping around the alphabet if necessary.
 *   Non-alphabetic characters are copied unchanged.
 */
void encrypt(char *input, char *output, int shift);

/**
 * Decrypts the input string that was encrypted using a shift cipher.
 *
 * @param input   The encrypted string to decrypt.
 * @param output  The buffer to store the decrypted string (should be large enough).
 * @param shift   The number of positions the original string was shifted.
 *
 * Summary:
 *   Iterates through each character of the input string. If the character is an uppercase or lowercase
 *   letter, it shifts it backwards by the specified amount, wrapping around the alphabet if necessary.
 *   Non-alphabetic characters are copied unchanged.
 */
void decrypt(char *input, char *output, int shift);

/**
 * Main function to demonstrate shift cipher encryption and decryption.
 *
 * Summary:
 *   - Prompts the user to enter a string and a shift value.
 *   - Encrypts the string using the shift cipher and displays the result.
 *   - Decrypts the encrypted string and displays the original string.
 */
int main();
#include <stdio.h>
#include <string.h>

void encrypt(char *input, char *output, int shift) {
    int i;
    for (i = 0; input[i] != '\0'; i++) {
        if (input[i] >= 'a' && input[i] <= 'z') {
            output[i] = (input[i] - 'a' + shift) % 26 + 'a';
        } else if (input[i] >= 'A' && input[i] <= 'Z') {
            output[i] = (input[i] - 'A' + shift) % 26 + 'A';
        } else {
            output[i] = input[i];
        }
    }
    output[i] = '\0';
}

void decrypt(char *input, char *output, int shift) {
    int i;
    for (i = 0; input[i] != '\0'; i++) {
        if (input[i] >= 'a' && input[i] <= 'z') {
            output[i] = (input[i] - 'a' - shift + 26) % 26 + 'a';
        } else if (input[i] >= 'A' && input[i] <= 'Z') {
            output[i] = (input[i] - 'A' - shift + 26) % 26 + 'A';
        } else {
            output[i] = input[i];
        }
    }
    output[i] = '\0';
}

int main() {
    char str[100], encrypted[100], decrypted[100];
    int shift;
    printf("Shift Cipher Encryption and Decryption\n");
    printf("Enter the string to encrypt: \n");
    fgets(str, sizeof(str), stdin);
    // Remove newline if present
    str[strcspn(str, "\n")] = '\0';
    printf("Enter the shift value: \n");
    scanf("%d", &shift);

    encrypt(str, encrypted, shift);
    printf("Encrypted string: %s\n", encrypted);

    decrypt(encrypted, decrypted, shift);
    printf("Decrypted string: %s\n", decrypted);

    return 0;
}