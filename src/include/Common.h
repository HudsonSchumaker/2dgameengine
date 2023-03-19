/*
    SchumakerLab
    SchumakerTeam
    Hudson Schumaker
*/

#pragma once
#include <set>
#include <map>
#include <array>
#include <limits>
#include <vector>
#include <random>
#include <chrono>
#include <future>
#include <string>
#include <thread>
#include <utility>
#include <fstream>
#include <iostream>
#include <typeindex>
#include <algorithm>
#include <functional>
#include <unordered_map>
#include <SDL2/SDL.h>
#include <math.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_gamecontroller.h>

#define QUIT -1
#define TITLE 0
#define MENU 1
#define SCREEN_WIDTH 640
#define SCREEN_H_WIDTH 320
#define SCREEN_HEIGHT 480
#define SCREEN_H_HEIGHT 240

class Common final {
public:
    inline static const char NAME[] = "- -";

    constexpr static float FPS = 60.0f;
    constexpr static float FRAME_TIME_LENGTH = 1000.0f / FPS;
    constexpr static float PI = 3.141592f;
};