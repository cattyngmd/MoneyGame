#include "utils.h"

int utils::RandomInt( int min, int max )
{
	std::random_device device;
	std::mt19937 engine( device( ) );
	std::uniform_int_distribution< int > dist( min, max );

	return dist( engine );
}

void utils::Print( const wchar_t* text, ... )
{
	wchar_t buffer[ 1024 ];

	va_list vlist;
	__crt_va_start( vlist, text );
	vswprintf_s( buffer, text, vlist );
	__crt_va_end( vlist );

	wprintf_s( buffer );
}

void utils::PrintColored( int color, const wchar_t* text, ... )
{
	static HANDLE consolehandle = GetStdHandle( STD_OUTPUT_HANDLE );

	wchar_t buffer[ 1024 ];

	va_list vlist;
	__crt_va_start( vlist, text );
	vswprintf_s( buffer, text, vlist );
	__crt_va_end( vlist );

	// set color
	SetConsoleTextAttribute( consolehandle, color );

	// print message
	wprintf_s( buffer );

	// reset color to white
	SetConsoleTextAttribute( consolehandle, 7 );
}

std::string utils::GetUserInput( )
{
	std::string input = "";
	std::cin >> input;
	return input;
}

void utils::Sleep( int seconds )
{
	::Sleep( seconds * 1000 );
}

std::wstring utils::GetRandomDeathReason( )
{
	std::array< std::wstring, 5 > reasons =
	{
		L"Вас укусила пчола и вы все.... гейм овер", L"Тебя зарезал тажик. гейм овер",
		L"Вам на голову упала беременная мать с 1337 этажа. гейм овер",
		L"приве) гейм овер", L"Вас застрелил спецна....з.. гейм овер"
	};

	return reasons[ utils::RandomInt( 0, reasons.size( ) - 1 ) ];
}
