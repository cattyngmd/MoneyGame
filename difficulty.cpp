#include "difficulty.h"

int difficulty::Portal( int difficulty )
{
	switch( difficulty )
	{
		case 1: return 6666;
		case 2: return 7777;
		case 3: return 8888;
		default: return 0;
	}
}

int difficulty::Hunger( int difficulty )
{
	switch( difficulty )
	{
		case 1: return 4;
		default: return 9;
	}
}

int difficulty::Weakness( int difficulty )
{
	switch( difficulty )
	{
		case 3: return 5;
		default: return 4;
	}
}

int difficulty::MoneySpent( int difficulty )
{
	switch( difficulty )
	{
		case 1: return 200;
		case 2: return 250;
		case 3: return 350;
		default: return -1;
	}
}

int difficulty::DeathChance( int difficulty )
{
	switch( difficulty )
	{
		case 1: return 35;
		case 2: return 22;
		case 3: return 17;
		default: return 1337;
	}
}

int difficulty::MinWorkTime( int difficulty )
{
	switch( difficulty )
	{
		case 3: return 6;
		default: return 4;
	}
}

int difficulty::MaxWorkTime( int difficulty )
{
	switch( difficulty )
	{
		case 3: return 15;
		default: return 13;
	}
}

int difficulty::MinWorkSalary( int difficulty )
{
	switch( difficulty )
	{
		case 1: return 150;
		default: return 50;
	}
}

int difficulty::MaxWorkSalary( int difficulty )
{
	switch( difficulty )
	{
		case 1: return 435;
		case 2: return 666;
		case 3: return 777;
		default: return 1337;
	}
}

int difficulty::WorkHunger( int difficulty )
{
	switch( difficulty )
	{
		case 3: return 4;
		default: return 3;
	}
}

int difficulty::MinWorkWeakness( int difficulty )
{
	switch( difficulty )
	{
		case 3: return 4;
		default: return 3;
	}
}

int difficulty::MaxWorkWeakness( int difficulty )
{
	switch( difficulty )
	{
		case 1: return 5;
		default: return 6;
	}
}

int difficulty::WorkHealth( int difficulty )
{
	switch( difficulty )
	{
		case 3: return 4;
		default: return 3;
	}
}

int difficulty::SleepWeakness( int difficulty )
{
	switch( difficulty )
	{
		case 3: return 8;
		default: return 10;
	}
}

int difficulty::SleepHunger( int difficulty )
{
	switch( difficulty )
	{
		case 3: return 4;
		default: return 3;
	}
}

/*extern int PharmacyHealth( int difficulty );
	extern int PharmacyWeakness( int difficulty );
	extern int MinPharmacyMoneySpending( int difficulty );
	extern int MaxPharmacyMoneySpending( int difficulty );*/
int difficulty::PharmacyHealth( int difficulty )
{
	switch( difficulty )
	{
		case 3: return 8;
		default: return 9;
	}
}

int difficulty::PharmacyWeakness( int difficulty )
{
	switch( difficulty )
	{
		case 1: return 3;
		case 2: return 4;
		case 3: return 5;
		default: return 4;
	}
}

int difficulty::MinPharmacyMoneySpending( int difficulty )
{
	switch( difficulty )
	{
		case 3: return 100;
		default: return 40;
	}
}

int difficulty::MaxPharmacyMoneySpending( int difficulty )
{
	switch( difficulty )
	{
		case 1: return 200;
		case 2: return 250;
		case 3: return 350;
		default: return 1337;
	}
}