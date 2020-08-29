#pragma once
#include "main.h"

namespace utils
{
	extern int RandomInt( int min, int max );
	extern void Print( const wchar_t* text, ... );
	extern void PrintColored( int color, const wchar_t* text, ... );
	extern std::string GetUserInput( );
	extern void Sleep( int seconds );
	extern std::wstring GetRandomDeathReason( );
}