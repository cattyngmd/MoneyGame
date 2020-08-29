#include "main.h"

std::shared_ptr< Data > player;
std::string choice;
std::string strdifficulty;
int intdifficulty;

int main( )
{
	// initialize
	SetConsoleTitleA( GAMENAME " [" GAMEVERSION "]" );

	player = std::make_shared< Data >( );
	choice = "";
	strdifficulty = "";
	intdifficulty = 0;

	// needed for russian characters to work
	setlocale( LC_ALL, "" );

JUMP_RESET:
	choice = "";
	strdifficulty = "";
	intdifficulty = 0;
	CLEAR( );

	PRINT( "| Welcome to the " GAMENAME " [" GAMEVERSION "]\n" );
	PRINT( "| 1. Начать новую игру\n" );
	PRINT( "| 2. Настройки графики\n" );
	PRINT( "| 3. Выйти\n" );

	PRINT( "| > " );
	choice = utils::GetUserInput( );

	if( choice == "1" )
		goto JUMP_NEWGAMEOPTION;
	else if( choice == "2" )
		goto JUMP_GRAPHICSOPTION;
	else if( choice == "3" )
		goto JUMP_EXIT;
	else
		goto JUMP_RESET;

JUMP_NEWGAMEOPTION:
	PRINT( "| Выбери сложность\n" );
	PRINT( "| 1. Легкая\n" );
	PRINT( "| 2. Средняя\n" );
	PRINT( "| 3. Сложная\n" );

	PRINT( "| > " );

	choice = "";
	strdifficulty = utils::GetUserInput( );

	if( strdifficulty != "1" && strdifficulty != "2" && strdifficulty != "3" )
	{
		CLEAR( );
		goto JUMP_NEWGAMEOPTION;
	}

	intdifficulty = std::stoi( strdifficulty );

	// le game
JUMP_GAME:
	CLEAR( );
	if( player->health <= 0 )
	{
		PRINTCOLORED( 12, "| ты умер от балезни....\n" );
		utils::Sleep( 3 );
		goto JUMP_EXIT;
	}
	else if( player->hunger <= 0 )
	{
		PRINTCOLORED( 12, "| ты умер от голада....\n" );
		utils::Sleep( 3 );
		goto JUMP_EXIT;
	}
	else if( player->weakness >= 10 )
	{
		PRINTCOLORED( 12, "| ты умер от таго что пупок порвался....\n" );
		utils::Sleep( 3 );
		goto JUMP_EXIT;
	}

	// clamp
	if( player->health > 10 )
		player->health = 10;

	if( player->hunger > 10 )
		player->hunger = 10;

	if( player->weakness < 0 )
		player->weakness = 0;

	// what the FUCK
	PRINT( "| Ваша статистика:\n" );
	PRINT( "| " );
	PRINTCOLORED( 12, "%d Здоровья ", player->health );
	PRINT( "| " );
	PRINTCOLORED( 10, "%d Сытости ", player->hunger );
	PRINT( "| " );
	PRINTCOLORED( 11, "%d Усталости ", player->weakness );
	PRINT( "| Баланс %d$\n", player->balance );
	PRINT( "| ---------------------------\n" );

	PRINT( "| Выбери один из вариантов:\n" );
	PRINT( "| 1. Пойти в магаз\n" );
	PRINT( "| 2. Пойти на работа\n" );
	PRINT( "| 3. Пойти на сон\n" );
	PRINT( "| 4. Выйти в окно\n" );
	PRINT( "| 5. Пойти в аптека\n" );
	PRINT( "| 6. Открыть портал в мир заработка (%d$)\n", difficulty::Portal( intdifficulty ) );

	choice = utils::GetUserInput( );

	CLEAR( );
	if( choice == "1" )
	{
		if( player->balance > 0 )
		{
			int deathchance = utils::RandomInt( 1, difficulty::DeathChance( intdifficulty ) );
			if( deathchance == 5 )
				goto JUMP_FORCEDDEATH;

			int hunger = utils::RandomInt( 2, difficulty::Hunger( intdifficulty ) );
			int weakness = utils::RandomInt( 2, difficulty::Weakness( intdifficulty ) );
			int moneyspent = utils::RandomInt( 0, difficulty::MoneySpent( intdifficulty ) );

			if( moneyspent > player->balance )
				moneyspent = player->balance;

			player->balance -= moneyspent;
			player->hunger += hunger;
			player->weakness += weakness;

			PRINT( "| Вы пошли в магаз и потратили %d$\n", moneyspent );
			PRINT( "| Ваш баланс теперь: %d$\n", player->balance );
		}
		else
			PRINT( "| У тебя нет денег ИДИОТ" );
	}
	else if( choice == "2" )
	{
		int deathchance = utils::RandomInt( 1, difficulty::DeathChance( intdifficulty ) );
		if( deathchance == 5 )
			goto JUMP_FORCEDDEATH;

		int time = utils::RandomInt( difficulty::MinWorkTime( intdifficulty ), difficulty::MaxWorkTime( intdifficulty ) );
		int salary = utils::RandomInt( difficulty::MinWorkSalary( intdifficulty ), difficulty::MaxWorkSalary( intdifficulty ) );
		int hunger = utils::RandomInt( 2, difficulty::WorkHunger( intdifficulty ) );
		int weakness = utils::RandomInt( difficulty::MinWorkWeakness( intdifficulty ), difficulty::MaxWorkWeakness( intdifficulty ) );
		int health = utils::RandomInt( 2, difficulty::WorkHealth( intdifficulty ) );

		PRINT( "| Вы работаете...\n" );
		utils::Sleep( time );

		player->balance += salary;
		player->health -= health;
		player->hunger -= hunger;
		player->weakness += weakness;

		PRINT( "| Вы поработали %d часов, вы заработали %d$\n", time, salary );
		PRINT( "| Ваш баланс: %d$\n", player->balance );
	}
	else if( choice == "3" )
	{
		int deathchance = utils::RandomInt( 1, difficulty::DeathChance( intdifficulty ) );
		if( deathchance == 5 )
			goto JUMP_FORCEDDEATH;

		int time = utils::RandomInt( 5, 9 );
		int weakness = utils::RandomInt( 3, difficulty::SleepWeakness( intdifficulty ) );
		int hunger =
			( intdifficulty == 1 )
			? 3
			: utils::RandomInt( 2, difficulty::SleepHunger( intdifficulty ) );

		PRINT( "| Вы спите... ZZZzzzzzzzz...\n" );
		utils::Sleep( time );

		player->weakness -= weakness;
		player->hunger -= hunger;

		PRINT( "| Вы поспали %d часов! Теперь ваша усталость уменьшена на - %d\n", time, weakness );
	}
	else if( choice == "4" )
	{
		if( intdifficulty == 1 )
		{
			PRINTCOLORED( 13, "| Вы точно хотите выйти в окно?\n" );
			PRINT( "| Да ---------------------- Нет\n" );

			choice = utils::GetUserInput( );
			if( choice == "Да" )
				PRINTCOLORED( 10, "GET STICK BUGGED LOL\n" );
			else
				PRINTCOLORED( 13, "| гейм овер..\n" );
		}
		else
			PRINTCOLORED( 13, "| гейм овер..\n" );

		utils::Sleep( 5 );
		goto JUMP_EXIT;
	}
	else if( choice == "5" )
	{
		// bug - if your money is 0 then you can still heal yourself
		int deathchance = utils::RandomInt( 1, difficulty::DeathChance( intdifficulty ) );
		if( deathchance == 5 )
			goto JUMP_FORCEDDEATH;

		int health = utils::RandomInt( 2, difficulty::PharmacyHealth( intdifficulty ) );
		int weakness = utils::RandomInt( 2, difficulty::PharmacyWeakness( intdifficulty ) );
		int moneyspent = utils::RandomInt( difficulty::MinPharmacyMoneySpending( intdifficulty ), difficulty::MaxPharmacyMoneySpending( intdifficulty ) );

		if( moneyspent > player->balance )
			moneyspent = player->balance;

		player->balance -= moneyspent;
		player->health += health;
		player->weakness += weakness;

		PRINT( "| Вы идете в аптеку\n" );
		utils::Sleep( 2 );
		PRINT( "| Вы сходили в аптеку и потратили %d$, и вылечили себя.\n", moneyspent );
	}
	else if( choice == "6" )
	{
		if( player->balance < difficulty::Portal( intdifficulty ) )
			PRINT( "| Недостаточно денег чтобы войти в портал мира денег." );
		else
		{
			// i just took a big shit
			int portal = ( player->balance * 420 + player->weakness - player->hunger * 2 ) * player->health;
			if( portal < 0 )
			{
				PRINT( "| Ваш баланс ушел в минус. ГЕЙМ ОВЕР\n" );
				utils::Sleep( 5 );
				goto JUMP_EXIT;
			}
			else
			{
				PRINT( "| %d$ вы заработали в портале.\n", portal );
				PRINT( "| Credits:\n" );
				PRINT( "| Cattyn\n" );
				PRINT( "| myrh\n" );
				utils::Sleep( 10 );
				goto JUMP_EXIT;
			}
		}
	}
	else
		goto JUMP_GAME;

	utils::Sleep( 5 );
	goto JUMP_GAME;

JUMP_FORCEDDEATH:
	PRINT( "| %WS", utils::GetRandomDeathReason( ).c_str( ) );
	utils::Sleep( 10 );
	goto JUMP_EXIT;
JUMP_GRAPHICSOPTION:
	CLEAR( );
	PRINT( "| No!!!\n" );
	utils::Sleep( 3 );
JUMP_EXIT:
	system( "pause" );
	return EXIT_SUCCESS;
}
