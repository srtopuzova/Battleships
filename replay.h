#ifndef REPLAY_H
#define REPLAY_H
#include <stdint.h>

void logMove(const char *player, int row, int col, int hit, uint32_t key);
void replayGame(uint32_t key);

#endif