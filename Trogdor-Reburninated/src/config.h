#include "include.h"

#ifndef CONFIG_H
#define CONFIG_H

constexpr auto DEFAULT_VOLUME_GAME = 100;
constexpr auto DEFAULT_VOLUME_MUSIC = 35;
#if !(defined(WII_U) || defined(VITA) || defined(SWITCH) || defined(WII) || defined(GAMECUBE) || defined(ANDROID) || defined(PSP) || defined(THREEDS) || defined(XBOX))
#define MAX_PAGE_NUM_LOWRES 5
#define MAX_PAGE_NUM_HIRES 4
#else
#define MAX_PAGE_NUM_LOWRES 4
#define MAX_PAGE_NUM_HIRES 3
#endif

struct SoundSettings {
	Sint8 bgmVolume;
	Sint8 sfxVolume;
};

struct VideoSettings {
	Uint16 widthSetting;
	Uint16 heightSetting;
};

/* Save File */
extern SDL_RWops *saveFile;
extern SoundSettings soundSettings;
extern VideoSettings videoSettings;

/* System-Specific Variables */
#if defined(VITA)
const string rootDir = "ux0:data/Trogdor-RB/";
#elif defined(WII)
const string rootDir = "sd:/apps/Trogdor-RB/";
#elif defined(GAMECUBE)
const string rootDir = "cardb:/Trogdor-RB/";
#elif defined(THREEDS)
const string rootDir = "sdmc:/3ds/Trogdor-RB/";
#elif defined(WINAPI_FAMILY) && (WINAPI_FAMILY == WINAPI_FAMILY_APP)
const string rootDir = "";
#else
const string rootDir = "";
#endif

#define SAVE_FILE (rootDir+"save.bin").c_str()

#define CREATE_DEBUG_FILE(str) \
	saveFile = SDL_RWFromFile((rootDir + str).c_str(), "w+b"); \
	SDL_RWclose(saveFile);

#if !defined(SDL1)
extern SDL_DisplayMode DM;
#endif

#if defined(WII_U)
constexpr auto DEFAULT_WIDTH = 1280;
constexpr auto DEFAULT_HEIGHT = 720;
#elif defined(VITA)
constexpr auto DEFAULT_WIDTH = 960;
constexpr auto DEFAULT_HEIGHT = 544;
#elif defined(SWITCH)
constexpr auto DEFAULT_WIDTH = 1920;
constexpr auto DEFAULT_HEIGHT = 1080;
#elif defined(PSP)
constexpr auto DEFAULT_WIDTH = 480;
constexpr auto DEFAULT_HEIGHT = 272;
#elif defined(WII) || defined(GAMECUBE) || defined(XBOX)
constexpr auto DEFAULT_WIDTH = 640;
constexpr auto DEFAULT_HEIGHT = 480;
#elif defined(THREEDS)
constexpr auto DEFAULT_WIDTH = 400;
constexpr auto DEFAULT_HEIGHT = 240;
#elif defined(ANDROID)
#define DEFAULT_WIDTH  max(DM.w, DM.h)
#define DEFAULT_HEIGHT min(DM.w, DM.h)
#elif defined(SDL1)
constexpr auto DEFAULT_WIDTH = 320;
constexpr auto DEFAULT_HEIGHT = 240;
#elif defined(WINAPI_FAMILY) && (WINAPI_FAMILY == WINAPI_FAMILY_APP)
constexpr auto DEFAULT_WIDTH = 1920;
constexpr auto DEFAULT_HEIGHT = 1080;
#else
constexpr auto DEFAULT_WIDTH = 640;
constexpr auto DEFAULT_HEIGHT = 480;
#endif

extern void loadSaveFile();
extern void initializeSaveFileNew();
//extern void SAVE_CURRENT_SAVE();

#endif