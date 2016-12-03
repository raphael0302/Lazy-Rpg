#include "bigfireball.h"
#include "util.h"
#include <stdlib.h>



static void _loadMedia(bigfireball_t *bigfireball)
{

    bigfireball->texture = game_loadTexture("img/bigfireball.png", 0, 64, 128);

    bigfireball->spriteClips[0].x = 2;
    bigfireball->spriteClips[0].y = 1;
    bigfireball->spriteClips[0].w = 93;
    bigfireball->spriteClips[0].h = 100;

    bigfireball->spriteClips[1].x = 95;
    bigfireball->spriteClips[1].y = 1;
    bigfireball->spriteClips[1].w = 93;
    bigfireball->spriteClips[1].h = 100;

    bigfireball->spriteClips[2].x = 186;
    bigfireball->spriteClips[2].y = 1;
    bigfireball->spriteClips[2].w = 93;
    bigfireball->spriteClips[2].h = 100;

    bigfireball->spriteClips[3].x = 274;
    bigfireball->spriteClips[3].y = 1;
    bigfireball->spriteClips[3].w = 93;
    bigfireball->spriteClips[3].h = 100;
    
    bigfireball->spriteClips[4].x = 369;
    bigfireball->spriteClips[4].y = 1;
    bigfireball->spriteClips[4].w = 92;
    bigfireball->spriteClips[4].h = 100;


}

static void _update(bigfireball_t *bigfireball)
{
    int frame = game_animation_frame(bigfireball->startTime, 4, 500, BIGFIREBALL_FRAMES);
    SDL_Rect *current = &bigfireball->spriteClips[frame];

    if (bigfireball->direction == 1) {
     bigfireball->x += BIGFIREBALL_SPEED;
    } else {
     bigfireball->x -= BIGFIREBALL_SPEED;
    }
    
    game_renderTexture(bigfireball->x,
                       bigfireball->y,
                       93,
                       100,
                       current,
                       360,
                       NULL,
                       (bigfireball->direction == 1) ? SDL_FLIP_NONE : SDL_FLIP_HORIZONTAL,
                       bigfireball->texture);

}

void free_bigfireball(void *data)
{

}



bigfireball_t *init_bigfireball()
{
    bigfireball_t *bigfireball = malloc(sizeof(bigfireball_t));
    bigfireball->x = 0;
    bigfireball->y = 0;
    bigfireball->direction = 1;
    bigfireball->startTime = SDL_GetTicks();
    _loadMedia(bigfireball);
    bigfireball->update = _update;

    return bigfireball;
}
