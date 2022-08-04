#include "config.h"

#ifndef SPRITE_OBJECTS_H
#define SPRITE_OBJECTS_H

struct SpriteObject {
    SDL_Surface *surface;
    SDL_Rect srcrect, dstrect;
};

extern void prepareSprite(SpriteObject *, const char [], int, int, float);
extern void setSpritePos(SpriteObject *, int, int);
extern void renderSprite(SpriteObject);
extern void renderSpriteAtRect(SpriteObject, SDL_Rect);
extern void renderSpriteUsingRects(SpriteObject, SDL_Rect, SDL_Rect);
extern void renderSpriteScaled(SpriteObject);
extern void setSpriteScale(SpriteObject *, float);
extern void drawRect(SDL_Rect, Uint8, Uint8, Uint8);
extern void DRAW_RECT_WITH_ALPHA(SDL_Rect, Uint8, Uint8, Uint8, Uint8);

#define PREPARE_SPRITE(spriteObj, path, rect_x, rect_y, numSprites_x, numSprites_y, scale) \
    prepareSprite(&spriteObj, path, numSprites_x, numSprites_y, scale);                    \
    setSpritePos(&spriteObj, rect_x, rect_y);

#define OBJ_TO_MID_SCREEN_X(obj) \
    ((GAME_WIDTH - obj.dstrect.w) / 2)

#define OBJ_TO_SCREEN_AT_FRACTION_X(obj, val) \
    ((GAME_WIDTH * val) - (obj.dstrect.w / 2))

#define OBJ_TO_MID_SCREEN_Y(obj) \
    ((GAME_HEIGHT - obj.dstrect.h) / 2)

#define OBJ_TO_SCREEN_AT_FRACTION_Y(obj, val) \
    ((GAME_HEIGHT * val) - (obj.dstrect.h / 2))

#endif