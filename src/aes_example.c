#include <openssl/evp.h>
#include <stdio.h>
#include <string.h>

int main(void){
    unsigned char key[32] = {0};
    unsigned char iv[16]= {0};

    const unsigned char plaintext[]="Wave Key OpenSSl AES-256-CBC test";

    unsigned char ciphertext[128];

    int output_length = 0;
    int final_length = 0;
    EVP_CIPHER_CTX *context = EVP_CIPHER_CTX_new();

    if (EVP_EncryptInit_ex(
            context,
            EVP_aes_256_cbc(),
            NULL,
            key,
            iv
        )!=1){
        fprintf(stderr,"Failed to initialize AES encryption\n");
        EVP_CIPHER_CTX_free(context);
        return 1;

    }

    if(EVP_EncrptUpdate(
        context,
        ciphertext,
        &output_length,
        plaintext,
        (int)strlen((const char *)plaintext)  
    )!= 1){
        fprintf(stderr,"Failed to encrypt data\n");
        EVP_CIPHER_CTX_free(context);
        return 1;
    }

    if (EVP_EncryptFinal_ex(
        context,
        ciphertext + output_length,
        &final_length
    )!=1){
       fprintf(stderr,"Failed to finalize encryption\n");
       EVP_CIPHER_CTX_free(context);
       return 1;
    }
    EVP_CIPHER_CTX_free(context);

    printf("AES-256-CBC encryption complete, ciphertext length : %d\n",output_length + final_length);
    
    return 0;
}