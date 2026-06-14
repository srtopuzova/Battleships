#include "utils.h"
#include <stdint.h>
#include <stdlib.h>

#define ROUNDS 4

static uint32_t rnd(uint32_t half, uint32_t key, int round) {
    return (half ^ key) + round;
}

uint32_t randomUI32T() {
    return (uint32_t)rand() ^ ((uint32_t)rand() << 16);
}

uint64_t feistelEncrypt(uint64_t input, uint32_t key) {
    uint32_t l = (uint32_t)(input >> 32), r = (uint32_t)(input & 0xFFFFFFFF);
    for (int i = 0; i < ROUNDS; i++) {
        uint32_t tmp = r;
        r = l ^ rnd(r, key, i);
        l = tmp;
    }
    return ((uint64_t)l << 32) | r;
}

uint64_t feistelDecrypt(uint64_t input, uint32_t key) {
    uint32_t l = (uint32_t)(input >> 32), r = (uint32_t)(input & 0xFFFFFFFF);
    for (int i = ROUNDS - 1; i >= 0; i--) {
        uint32_t tmp = l;
        l = r ^ rnd(l, key, i);
        r = tmp;
    }
    return ((uint64_t)l << 32) | r;
}

uint64_t packMove(int row, int col, int hit) {
    uint64_t res = 0;
    res |= (uint64_t)(uint16_t)row << 32;
    res |= (uint64_t)(uint16_t)col << 16;
    res |= (uint64_t)(uint16_t)hit;
    return res;
}

void unpackMove(uint64_t packed, int *row, int *col, int *hit) {
    *row = (int)(uint16_t)((packed >> 32) & 0xFFFF);
    *col = (int)(uint16_t)((packed >> 16) & 0xFFFF);
    *hit = (int)(uint16_t)(packed & 0xFFFF);
}

uint64_t encryptMove(int row, int col, int hit, uint32_t key) {
    uint64_t packed = packMove(row, col, hit);
    return feistelEncrypt(packed, key);
}

uint64_t decryptMove(uint64_t packed, uint32_t key, int *row, int *col, int *hit) {
    uint64_t decrypted = feistelDecrypt(packed, key);
    unpackMove(decrypted, row, col, hit);
    return decrypted;
}
