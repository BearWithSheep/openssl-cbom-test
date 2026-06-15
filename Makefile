CC = gcc
CFLAGS = -Wall -Wextra
LIBS = -lcrypto

all: sha256_example aes_example rsa_example

sha256_example:
	$(CC) $(CFLAGS) src/sha256_example.c -o sha256_example $(LIBS)

aes_example:
	$(CC) $(CFLAGS) src/aes_example.c -o aes_example $(LIBS)

rsa_example:
	$(CC) $(CFLAGS) src/rsa_example.c -o rsa_example $(LIBS)

clean:
	rm -f sha256_example aes_example rsa_example