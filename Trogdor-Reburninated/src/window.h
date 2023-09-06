#include "include.h"
#include "general.h"

#ifndef WINDOW_H
#define WINDOW_H

constexpr auto gameWidth = 250;
constexpr auto gameHeight = 180;
constexpr auto TWIPS_PER_PIXEL = 20;

extern Uint16 gameHiResWidth;
extern Uint16 gameHiResHeight;
extern Uint16 appWidth;
extern Uint16 appHeight;
extern double gameWidthMult; // game scaling relative to app
extern double gameHeightMult; // game scaling relative to app
extern double gameHiResMult; // hi-res screen scaling
extern Uint16 windowWidth;
extern Uint16 windowHeight;
extern double appWidthMult; // app scaling relative to window
extern double appHeightMult; // app scaling relative to window
extern Uint32 ticksPerFrame;

#if !defined(SDL1)
extern SDL_Window *window;
extern SDL_Renderer *renderer;
#else
extern SDL_Surface *windowScreen;
extern SDL_Surface *transparentScreen;
#endif
extern SDL_Rect gameSrcRect;
const SDL_Rect gameSrcRect_unscaled = { 0, 0, gameWidth, gameHeight };
//extern SDL_Rect gameToAppDstRect; // game screen mapping to app
extern SDL_Rect gameHiResSrcRect;
extern SDL_Rect appSrcRect;
extern SDL_Rect appToWindowDstRect; // app mapping to window
extern SDL_Rect gameToWindowDstRect; // game screen mapping to window
extern SDL_Rect menuToWindowDstRect; // menu mapping to window

extern bool isWindowed;
extern float screenScale; // the multiplier by which graphics should be scaled via SDL_gfx; caps out at 2
extern int trueScreenScaleInt; // the multiplier by which the screen should be scaled via renderer
extern float trueScreenScaleFull; // the multiplier by which the screen should be scaled via renderer
extern float screenScale_menu;
extern bool allowHiRes;
extern Sint8 scalingType;

extern float getScreenScale_app();
extern void scaleGameByApp();
extern float getScreenScale_game();
extern void scaleAppByGame();
extern void scaleGameAndApp();
extern void repositionOverlay();
extern void setWidthHeightMults();
extern void setScaling();
extern void snapWindow_x(double, Uint16);
extern void snapWindow_y(double, Uint16);
extern void SDL_toggleFullscreen();
extern void InitializeMenus(); // this is in menu.cpp

#endif