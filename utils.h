#pragma once
#include <stdint.h>

uint32_t randomUI32T();

uint64_t feistelEncrypt(uint64_t input, uint32_t key);
uint64_t feistelDecrypt(uint64_t input, uint32_t key);

uint64_t packMove(int row, int col, int hit);
void unpackMove(uint64_t packed, int *row, int *col, int *hit);

uint64_t encryptMove(int row, int col, int hit, uint32_t key);
uint64_t decryptMove(uint64_t packed, uint32_t key, int *row, int *col, int *hit);
