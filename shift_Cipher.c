#include<stdio.h>
#include<string.h>


int main(){
    char str[100];
    int shift, i;
    // Input string and shift value
    printf("Shift Cipher Encryption and Decryption\n");
    printf("Enter the string to encrypt: \n");
    // Using fgets to read the string to handle spaces
    // and avoid buffer overflow
    // Note: fgets includes the newline character, which we will handle later
    fgets(str,sizeof(str),stdin);
    // key for shift cipher for encryption and decryption
    printf("Enter the shift value: \n");
    scanf("%d",&shift);

    int len = strlen(str);
    for(i = 0; i < len; i++){
        if(str[i] >= 'a' && str[i] <= 'z'){
            str[i] = (str[i] - 'a' + shift) % 26 + 'a';
        }
        else if(str[i] >= 'A' && str[i] <= 'Z'){
            str[i] = (str[i] - 'A' + shift) % 26 + 'A';
        }
    }
    printf("Encrypted string: %s\n", str);
    for(i = 0; i < len; i++){
        if(str[i] >= 'a' && str[i] <= 'z'){
            str[i] = (str[i] - 'a' - shift + 26) % 26 + 'a';
        }
        else if(str[i] >= 'A' && str[i] <= 'Z'){
            str[i] = (str[i] - 'A' - shift + 26) % 26 + 'A';
        }
    }
    printf("Decrypted string: %s\n", str);
    return 0;
}