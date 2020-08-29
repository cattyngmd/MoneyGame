#pragma once

namespace difficulty
{
	extern int Portal( int difficulty );
	extern int Hunger( int difficulty );
	extern int Weakness( int difficulty );
	extern int MoneySpent( int difficulty );
	extern int DeathChance( int difficulty );
	extern int MinWorkTime( int difficulty );
	extern int MaxWorkTime( int difficulty );
	extern int MinWorkSalary( int difficulty );
	extern int MaxWorkSalary( int difficulty );
	extern int WorkHunger( int difficulty );
	extern int MinWorkWeakness( int difficulty );
	extern int MaxWorkWeakness( int difficulty );
	extern int WorkHealth( int difficulty );
	extern int SleepWeakness( int difficulty );
	extern int SleepHunger( int difficulty );
	extern int PharmacyHealth( int difficulty );
	extern int PharmacyWeakness( int difficulty );
	extern int MinPharmacyMoneySpending( int difficulty );
	extern int MaxPharmacyMoneySpending( int difficulty );
}