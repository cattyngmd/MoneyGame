#pragma once
#include <Windows.h>
#include <iostream>
#include <random>
#include <string>
#include <array>

// custom
#include "utils.h"
#include "data.h"
#include "difficulty.h"

// defines
#define GAMENAME "Money Mod game (in C++)"
#define GAMEVERSION "beta 0.2.4"

#define PRINT( ... ) utils::Print( L##__VA_ARGS__## )
#define PRINTCOLORED( color, ... ) utils::PrintColored( color, L##__VA_ARGS__## )
#define CLEAR( ) system( "cls" )