# OpenSSL CBOM Test Repository

This repository is used to verify cryptographic source-code discovery
and line-level traceability in CeQureX Wave-Key.

## Included cryptographic usages

- SHA-256 using OpenSSL SHA256 API
- AES-256-CBC using OpenSSL EVP API
- RSA-2048 key generation using OpenSSL EVP API

## Test objectives

The scanner should identify:

- OpenSSL cryptographic library references
- SHA-256 usage
- AES-256-CBC usage
- RSA-2048 usage
- Repository, file path, and source code line number
- CycloneDX 1.6 CBOM export