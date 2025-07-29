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