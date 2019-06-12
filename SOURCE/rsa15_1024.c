/* gcc rsa15_1024.c -o rsa15_1024 -pthread -lcrypto -ldl -static-libgcc -O2 -I/home/joss/openssl/include/ -L/home/joss/openssl/lib/ */

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/rsa.h>
#include <openssl/crypto.h>
#include <openssl/objects.h>

// Assembler rdtsc Function to Measure Clock Cycles
static inline uint64_t rdtsc(void)
{
    unsigned int eax, edx;
    asm volatile("rdtsc" : "=a" (eax), "=d" (edx));
    return ((uint64_t) edx << 32) | eax;
}

int main()
{
    const int sizek = 1024;
    const EVP_MD *md = EVP_sha1();
    const void *msg = "lasquinceletrasmascuarentaycuatroletrascincuentaynuevebytes"; // 59 Bytes Message like SUPERCOP Project

    EVP_PKEY *key = NULL;
    EVP_PKEY_CTX *ctx = NULL;
    EVP_MD_CTX *mdctxs = NULL;
    EVP_MD_CTX *mdctxv = NULL;
    char *md_value = NULL;
    size_t md_len = 0;
    uint64_t tmp1 = 0, tmp2 = 0, tiempo1 = 0, tiempo2 = 0, tiempo3 = 0, tiempo4 = 0;
    double tiempos = 0, tiempov = 0;
    long long int ciclosign = 0, cicloverify = 0;
    long long int totalsign = 0, totalverify = 0;
    
    // Keypair Block
    key = EVP_PKEY_new();
    ctx = EVP_PKEY_CTX_new(key, NULL);
    ctx = EVP_PKEY_CTX_new_id(EVP_PKEY_RSA, NULL);
    EVP_PKEY_keygen_init(ctx);
    EVP_PKEY_CTX_set_rsa_keygen_bits(ctx, sizek);
    EVP_PKEY_keygen(ctx, &key);

    // CPU Warming Block
    for (int i = 0; i < 1000000000; i++)
    {
        int a = rand(), b = rand(); 
        double c = 0, d = 0, e = 0;
        c = a * b;
        d = c / i;
        e = a ^ b;
    }

    for (int i = 0; i < 10000; i++)
    {
        // Sign Block
        mdctxs = EVP_MD_CTX_create();
        EVP_DigestSignInit(mdctxs, &ctx, md, NULL, key);
        EVP_DigestSignUpdate(mdctxs, &msg, strlen(msg));
        EVP_DigestSignFinal(mdctxs, NULL, &md_len);
        md_value = OPENSSL_malloc(md_len);
        tiempo1 = rdtsc();
        // START MEASURING
        EVP_DigestSignFinal(mdctxs, md_value, &md_len);
        // END MEASURING
        tiempo2 = rdtsc();

        // Verify Block
        mdctxv = EVP_MD_CTX_create();
        EVP_DigestVerifyInit(mdctxv, &ctx, md, NULL, key);
        EVP_DigestVerifyUpdate(mdctxv, &msg, strlen(msg));
        tiempo3 = rdtsc();
        // START MEASURING
        EVP_DigestVerifyFinal(mdctxv, md_value, md_len);
        // END MEASURING
        tiempo4 = rdtsc();

        tmp1 = tiempo2 - tiempo1;
        tmp2 = tiempo4 - tiempo3;
        ciclosign = ciclosign + tmp1;
        cicloverify = cicloverify + tmp2;
    }

    totalsign = ciclosign / 10000;
    totalverify = cicloverify / 10000;
    tiempos = (double) totalsign / 1895000000; // clock cycles of the testing CPU
    tiempov = (double) totalverify / 1895000000; // clock cycles of the testing CPU
    printf("RSA15 1024 bits:\n"); 
    printf("Sign Clock Cycles: %llu\n", totalsign);
    printf("Sign Time Seconds: %f\n", tiempos);
    printf("Verify Clock Cycles: %llu\n", totalverify);
    printf("Verify Time Seconds: %f\n", tiempov);

    free(md_value);
    return 0;
}

