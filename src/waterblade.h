#ifndef WATERB_H_
#define WATERB_H_

#include "SDL2/SDL.h"

#define WATERB_FRAMES 1
#define MAX_WATERBS 100
#define WATERB_SPEED 2


typedef struct waterb waterb_t;
struct waterb {
    int x;
    int y;
    int direction;
    long int startTime;
    SDL_Texture *texture;
    SDL_Rect spriteClips[WATERB_FRAMES];
    void (*update)(waterb_t *);
};

waterb_t *init_waterb();
void free_waterb(void *data);

#endif
