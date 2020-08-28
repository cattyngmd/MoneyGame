import colorama
import os
import random
import time
from colorama import init, Fore, Back, Style
colorama.init()

name = "Money Mod game"
ver = "beta 0.2.2"

bal = 0

selectmain = 0
select = 0

health = 10
hunger = 10
weak = 0

deathMsgs = ["| Вас укусила пчола и вы все.... гейм овер", "| Тебя зарезал тажик. гейм овер", "| Вам на голову упала беременная мать с 1337 этажа. гейм овер", "| приве) гейм овер", "| Вас застрелил спецна....з.. гейм овер"]

def portal():
	result = (bal*420+weak-hunger*2)*health
	return result

def smert(x):
	if x == 5:
		randomDeath = random.randint(0, 4)
		print(Fore.RED + deathMsgs[randomDeath])
		time.sleep(10)
		exit()

os.system('cls' if os.name == 'nt' else 'clear')

print("| Welcome to the " + name + " [" + ver + "]")

print("| 1. Начать новую игру\n| 2. Настройки графики\n| 3. Выйти")
selmain = int(input("> "))

if selmain == 1:
	while 1:
		try:
			os.system('cls' if os.name == 'nt' else 'clear')
			if health <= 0:
				print(Fore.RED + "| ты умер от балезни....")
				time.sleep(3)
				exit()
			elif hunger <= 0:
				print(Fore.RED + "| ты умер от голада....")
				time.sleep(3)
				exit()
			elif weak >= 10:
				print(Fore.RED + "| ты умер от таго что не смог держать груз на работе....")
				time.sleep(3)
				exit()

			if health >= 10:
				health = 10
			if hunger >= 10:
				hunger = 10
			if weak <= 0:
				weak = 0
			print("| Ваша статистика:\n| " + Fore.RED + str(health) + " Здоровья " + Fore.WHITE + "| " + Fore.GREEN + str(hunger) +" Сытости " + Fore.WHITE + "| " + Fore.CYAN + str(weak) + " Усталости " + Fore.WHITE + "| Баланс " + str(bal) + "$" + "\n| ---------------------------")
			print("| Выбери один из вариантов: ")
			print("| 1. Пойти в магаз\n| 2. Пойти на работа\n| 3. Пойти на сон\n| 4. Выйти в окно\n| 5. Пойти в аптека\n| 6. Открыть портал в мир заработка (7777$)")

			select = 0
			select = int(input("| > "))
		except ValueError:
			print("")
		
		if select == 1:
			if bal > 0:
				os.system('cls' if os.name == 'nt' else 'clear')
				randHunger = random.randint(2, 9)
				randWeak = random.randint(2, 9)
				trata = random.randint(0, 250)
				randLLIaHc = random.randint(1,22)
				smert(randLLIaHc)

				if trata > bal:
					trata = bal
				bal -= trata
				
				hunger += randHunger
				weak += randWeak

				print("| Вы пошли в магаз и потратили " + str(trata) + "$\n| Ваш баланс теперь: " + str(bal) + "$")
				time.sleep(5)
			else:
				print("| У тебя нет денег ИДИОТ")
				time.sleep(5)

		elif select == 2:
			os.system('cls' if os.name == 'nt' else 'clear')
			randtime = random.randint(4, 13)
			randIIpu6blLb = random.randint(50, 666)
			randHunger = random.randint(2, 3)
			randWeak = random.randint(3, 7)
			randHealth = random.randint(2, 3)

			randLLIaHc = random.randint(1,22)
			smert(randLLIaHc)

			print("| Вы работаете...")
			time.sleep(randtime)
			bal += randIIpu6blLb
			health -= randHealth
			hunger -= randHunger
			weak += randWeak

			print("| Вы поработали " + str(randtime) + " часов, вы заработали " + str(randIIpu6blLb) + "$\n| Ваш баланс: " + str(bal) + "$")
				
			time.sleep(5)

		elif select == 3:
			os.system('cls' if os.name == 'nt' else 'clear')
			randtime = random.randint(5, 9)
			randWeak = random.randint(3, 10)

			randLLIaHc = random.randint(1,22)
			smert(randLLIaHc)

			randHunger = random.randint(2, 3)
			hunger -= randHunger
			weak -= randWeak

			print("| Вы спите... ZZZzzzzzzzz...")
			time.sleep(randtime)
			print("| Вы поспали " + str(randtime) + " часов! Теперь ваша усталость уменьшилась на - " + str(randWeak))
			time.sleep(5)

		elif select == 4:
			os.system('cls' if os.name == 'nt' else 'clear')

			print(Fore.RED + "| гейм овер..")
			time.sleep(5)
			exit()

		elif select == 5:
			os.system('cls' if os.name == 'nt' else 'clear')

			randHealth = random.randint(2, 9)
			randWeak = random.randint(2, 9)
			trata = random.randint(40, 250)

			randLLIaHc = random.randint(1,22)
			smert(randLLIaHc)

			if trata > bal:
				trata = bal
			bal -= trata
				
			health += randHealth
			weak += randWeak
			print("| Вы идете в аптеку")
			time.sleep(2)
			print("| Вы сходили в аптеку и потратили " + str(trata) + "$, и вылечили себя.")
			time.sleep(4)

		elif select == 6:
			os.system('cls' if os.name == 'nt' else 'clear')
			if bal < 7777:
				print("| Недостаточно денег чтобы войти в портал мира денег.")
				time.sleep(5)
			else:
				if portal() <= 0:
					print("| Ваш баланс ушел в минус. ГЕЙМ ОВЕР")
					time.sleep(5)
				else:
					print("| " + str(portal()) + "$ вы заработали в портале.\n| Игра пройдена!!!\n| Credits:\n| Cattyn\n")
					time.sleep(10)
					exit()

elif selmain == 2:
	os.system('cls' if os.name == 'nt' else 'clear')
	print("| No!!!")
	time.sleep(3)
	exit()
else:
	exit()

input("")
