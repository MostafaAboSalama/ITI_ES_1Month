#include <stdio.h>
#include <string.h>
char str[] = "Hello World";

void Encrypt(char *msg);
void Decrypt(char *msg);

int main() {
    printf("Message: %s\n", str);
    Encrypt(str);
    printf("Encrypted Message: %s\n", str);
    Decrypt(str);
    printf("Decrypted Message: %s\n", str);
}

void Encrypt(char *msg)
{
    for(int i=0; i< strlen(msg); i++)
        msg[i] = msg[i] + 45;
}

void Decrypt(char *msg)
{
    for(int i=0; i< strlen(msg); i++)
        msg[i] = msg[i] - 45;
}
