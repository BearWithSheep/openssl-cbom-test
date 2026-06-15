#include <openssl/bn.h>
#include <openssl/evp.h>
#include <openssl/rsa.h>
#include <stdio.h>

int main(void) {
    EVP_PKEY_CTX *context = EVP_PKEY_CTX_new_id(
        EVP_PKEY_RSA,
        NULL
    );

    if (context == NULL) {
        fprintf(stderr, "Failed to create RSA context\n");
        return 1;
    }

    if (EVP_PKEY_keygen_init(context) <= 0) {
        fprintf(stderr, "Failed to initialize RSA key generation\n");
        EVP_PKEY_CTX_free(context);
        return 1;
    }

    if (EVP_PKEY_CTX_set_rsa_keygen_bits(context, 2048) <= 0) {
        fprintf(stderr, "Failed to set RSA key size\n");
        EVP_PKEY_CTX_free(context);
        return 1;
    }

    EVP_PKEY *key_pair = NULL;

    if (EVP_PKEY_keygen(context, &key_pair) <= 0) {
        fprintf(stderr, "Failed to generate RSA key pair\n");
        EVP_PKEY_CTX_free(context);
        return 1;
    }

    printf("RSA-2048 key pair generated successfully\n");

    EVP_PKEY_free(key_pair);
    EVP_PKEY_CTX_free(context);

    return 0;
}