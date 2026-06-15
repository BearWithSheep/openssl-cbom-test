#include <openssl/sha.h>
#include <stdio.h>
#include <string.h>

int main(void){
    const char *message = "Wave Key OpenSSL SHA-256 test";
    unsigned char digest[SHA256_DIGEST_LENGTH];

    SHA256(
        (const unsigned char *)message,
        strlen(message),
        digest
    );

    printf("SHA-256 digest: ");

    for(int i = 0;i < SHA256_DIGEST_LENGTH;i++){
        printf("%02x",digest[i]);
    }
    
    printf("\n");

    return 0;
}