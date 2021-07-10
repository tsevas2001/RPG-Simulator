#include "grid.h"

int NumberOfPlayers;

Grid::Grid()
{
	//std::cout << "Creating Map...." << endl;
	displayMap();
	//std::cout << "Completed!" << endl;
}

void Grid::displayMap()
{
	int i, j;

	for (i = 0; i < 14; i++)
	{
		for (j = 0; j < 23; j++)
		{
			if (i == position1[0] && j == position1[1])
				std::cout << "" << character1;
			else
				std::cout << "" << grid[i][j] << "";
		}
		std::cout << '\n';
	}
}

void Grid::move(char direction)
{

	if (direction == 'u')
	{
		if (nonAccessible(direction) == true || market(direction) == true || common(direction) == true)
		{
			if (market(direction) == true)
				openMarket();
			else if (common(direction) == true)
			{
				if (rand() % 100 > 50) {
					battle();
				}
			}
			position1[0] -= 1;
		}
		else
			std::cout << "You can't go right there" << endl;
	}
	else if (direction == 'r')
	{
		if (nonAccessible(direction) == true || market(direction) == true || common(direction) == true)
		{
			if (market(direction) == true)
				openMarket();
			else if (common(direction) == true)
			{
				if (rand() % 100 > 50) {
					battle();
				}
			}
			position1[1] += 1;
		}
		else
			std::cout << "You can't go right there" << endl;
	}
	else if (direction == 'd')
	{
		if (nonAccessible(direction) == true || market(direction) == true || common(direction) == true)
		{
			if (market(direction) == true)
				openMarket();
			else if (common(direction) == true)
			{
				if (rand() % 100 > 50) {
					battle();
				}
			}
			position1[0] += 1;
		}
		else
			std::cout << "You can't go right there" << endl;
	}
	else if (direction == 'l')
	{
		if (nonAccessible(direction) == true || market(direction) == true || common(direction) == true)
		{
			if (market(direction) == true)
				openMarket();
			else if (common(direction) == true)
			{
				if (rand() % 100 > 50) {
					battle();
				}
			}
			position1[1] -= 1;
		}
		else
			std::cout << "You can't go right there" << endl;
	}
}

bool Grid::nonAccessible(char direction)
{
	if (direction == 'u')
	{
		if (grid[position1[0] - 1][position1[1]] == '+' || grid[position1[0] - 1][position1[1]] == '=' || grid[position1[0] - 1][position1[1]] == '-' || grid[position1[0] - 1][position1[1]] == '#')
			return false;
		else
			return true;
	}
	else if (direction == 'r')
	{
		if (grid[position1[0]][position1[1] + 1] == '+' || grid[position1[0]][position1[1] + 1] == '=' || grid[position1[0]][position1[1] + 1] == '-' || grid[position1[0]][position1[1] + 1] == '#')
			return false;
		else
			return true;
	}
	else if (direction == 'd')
	{
		if (grid[position1[0] + 1][position1[1]] == '+' || grid[position1[0] + 1][position1[1]] == '=' || grid[position1[0] + 1][position1[1]] == '-' || grid[position1[0] + 1][position1[1]] == '#')
			return false;
		else
			return true;
	}
	else if (direction == 'l')
	{
		if (grid[position1[0]][position1[1] - 1] == '+' || grid[position1[0]][position1[1] - 1] == '=' || grid[position1[0]][position1[1] - 1] == '-' || grid[position1[0]][position1[1] - 1] == '#')
			return false;
		else
			return true;
	}
	return false;
}

bool Grid::common(char direction)
{
	if (direction == 'u')
	{
		if (grid[position1[0] - 1][position1[1]] == 'X')
			return true;
		else
			return false;
	}
	else if (direction == 'r')
	{
		if (grid[position1[0]][position1[1] + 1] == 'X')
			return true;
		else
			return false;
	}
	else if (direction == 'd')
	{
		if (grid[position1[0] + 1][position1[1]] == 'X')
			return true;
		else
			return false;
	}
	else if (direction == 'l')
	{
		if (grid[position1[0]][position1[1] - 1] == 'X')
			return true;
		else
			return false;

	}
	return false;
}

bool Grid::market(char direction)
{
	if (direction == 'u')
	{
		if (grid[position1[0] - 1][position1[1]] == 'M')
			return true;
		else
			return false;
	}
	else if (direction == 'r')
	{
		if (grid[position1[0]][position1[1] + 1] == 'M')
			return true;
		else
			return false;
	}
	else if (direction == 'd')
	{
		if (grid[position1[0] + 1][position1[1]] == 'M')
			return true;
		else
			return false;
	}
	else if (direction == 'l')
	{
		if (grid[position1[0]][position1[1] - 1] == 'M')
			return true;
		else
			return false;

	}
	return false;
}

static int spaceInventory = 0;
static int spaceInventory2 = 0;
static int spaceInventory3 = 0;
static int spaceSpell = 0;
static int spaceSpell2 = 0;
static int spaceSpell3 = 0;

void Grid::openMarket()
{
	int ch;
	int i;
	int input;
	int categ;
	int character;
	
	clear_screen();
	

	std::cout << "\033[1;93m   ______  ______  ______  ______  ______  ______  ______  ______  ______  ______  \033[0m" << endl;
	std::cout << "\033[1;93m  |______||______||______||______||______||______||______||______||______||______| \033[0m" << endl;

	std::cout << "\033[1;95m                    _    _ _____ _     _____ ________  ___ _____          \033[0m" << endl;
	std::cout << "\033[1;95m                   | |  | |  ___| |   /  __ \\  _  |  \\/  ||  ___|             \033[0m" << endl;
	std::cout << "\033[1;95m                   | |  | | |__ | |   | /  \\/ | | | .  . || |__               \033[0m" << endl;
	std::cout << "\033[1;95m                   | |/\\| |  __|| |   | |   | | | | |\\/| ||  __|             \033[0m" << endl;
	std::cout << "\033[1;95m                   \\  /\\  / |___| |___| \\__/\\ \\_/ / |  | || |___             \033[0m" << endl;
	std::cout << "\033[1;95m                    \\/  \\/\\____/\\_____/\\____/\\___/\\_|  |_/\\____/               \033[0m" << endl;
	std::cout << "\033[1;95m                                                                               \033[0m" << endl;
	std::cout << "\033[1;95m                                   _____ _____									\033[0m" << endl;
	std::cout << "\033[1;95m                                  |_   _|  _  |								 \033[0m" << endl;
	std::cout << "\033[1;95m                                    | | | | | |							   \033[0m" << endl;
	std::cout << "\033[1;95m                                    | | | | | |								  \033[0m" << endl;
	std::cout << "\033[1;95m                                    | | \\ \\_/ /								 \033[0m" << endl;
	std::cout << "\033[1;95m                                    \\_/  \\___/								  \033[0m" << endl;
	std::cout << "\033[1;95m                                                                               \033[0m" << endl;
	std::cout << "\033[1;95m                     ___  ___  ___  ______ _   __ _____ _____          \033[0m" << endl;
	std::cout << "\033[1;95m                     |  \\/  | / _ \\ | ___ \\ | / /|  ___|_   _|             \033[0m" << endl;
	std::cout << "\033[1;95m                     | .  . |/ /_\\ \\| |_/ / |/ / | |__   | |                \033[0m" << endl;
	std::cout << "\033[1;95m                     | |\\/| ||  _  ||    /|    \\ |  __|  | |              \033[0m" << endl;
	std::cout << "\033[1;95m                     | |  | || | | || |\\ \\| |\\  \\| |___  | |             \033[0m" << endl;
	std::cout << "\033[1;95m                     \\_|  |_/\\_| |_/\\_| \\_\\_| \\_/\\____/  \\_/                \033[0m" << endl;

	std::cout << "\033[1;93m   ______  ______  ______  ______  ______  ______  ______  ______  ______  ______  \033[0m" << endl;
	std::cout << "\033[1;93m  |______||______||______||______||______||______||______||______||______||______| \033[0m" << endl << endl;


	for (i = 0; i < NumberOfPlayers; i++)
	{
		std::cout << i + 1 << ") Name: " << Team[i]->getName() << " Level: " << Team[i]->getLevel() << " Money: " << Team[i]->getMoney() << endl;
	}
	std::cout<< NumberOfPlayers + 1 << ") Exit " << endl;
	std::cout << "Choose Character: ";
	std::cin >> character;

	while (character < 1 || character > NumberOfPlayers + 1)
	{
		std::cout << "Wrong Number! Give again from 1 - "<<NumberOfPlayers + 1<<": ";
		std::cin >> character;
	}
	
	if (character == NumberOfPlayers + 1)
	{
		ch = 3;
	}
	else
	{
		std::cout << "\tDo you like to 1) Buy 2) Sell or 3) Cancel: ";
		std::cin >> ch;

		while (ch < 1 || ch > 3)
		{
			std::cout << "Enter number from 1 - 3: ";
			std::cin >> ch;
		}
	}

	while (ch != 3)
	{



		switch (ch)
		{
		case 1:
			int spelloritem;
			std::cout << "What do you like to buy: 1) Item, 2) Spell, 3)Cancel ";
			std::cin >> spelloritem;
			while (spelloritem < 1 || spelloritem > 3)
			{
				std::cout << "Enter number from 1 - 3: ";
				std::cin >> spelloritem;
			}
			switch (spelloritem) {
			case 1:


				std::cout << "What do you like to buy: 1) Weapon, 2) Armor, 3)Potion 4) Cancel: ";
				std::cin >> categ;
				while (categ < 1 || categ > 4) {
					std::cout << "Enter number from 1 - 4: ";
					std::cin >> categ;
				}
				switch (categ) {
				case 1:

					for (i = 0; i < 3; i++)
					{
						std::cout << i + 1 << ")" << "Name: " << weapons[i]->getName() << "||" << "Level: " << weapons[i]->getLevel() << "||" << "Price: " << weapons[i]->getPrice() << endl;
					}
					std::cout << "4) Cancel!" << endl;
					std::cout << "Witch weapon do you like to buy: ";
					std::cin >> input;

					while (input < 1 || input > 4)
					{
						std::cout << "Enter number from 1 - 4: ";
						std::cin >> input;
					}

					if(input==4){
						break;
					}

					if (character==1)
					{
						
						if (Team[0]->getMoney() >= weapons[input - 1]->getPrice() && Team[0]->getLevel() >= weapons[input - 1]->getLevel()){
							Team[0]->removeMoney(weapons[input - 1]->getPrice());
							inventory[spaceInventory] = weapons[input - 1];
							spaceInventory++;
							break;
						}else{
							std::cout << "You dont have the required level or money for this item"<<endl;
							break;
						}
					}else if(character==2){
						if (Team[1]->getMoney() >= weapons[input - 1]->getPrice() && Team[1]->getLevel() >= weapons[input - 1]->getLevel()){
							Team[1]->removeMoney(weapons[input - 1]->getPrice());
							inventory2[spaceInventory2] = weapons[input - 1];
							spaceInventory2++;
							break;
						}else{
							std::cout << "You dont have the required level or money for this item"<<endl;
							break;
						}

					}else if(character==3){
						if (Team[2]->getMoney() >= weapons[input - 1]->getPrice() && Team[2]->getLevel() >= weapons[input - 1]->getLevel()){
							Team[2]->removeMoney(weapons[input - 1]->getPrice());
							inventory3[spaceInventory3] = weapons[input - 1];
							spaceInventory3++;
							break;
						}else{
							std::cout << "You dont have the required level or money for this item"<<endl;
							break;
						}	
					}
					else {
						break;
					}
				case 2:

					for (i = 0; i < 3; i++)
					{
						std::cout << i +1 << ")" << "Name: " << armors[i]->getName() << "||" << "Level: " << armors[i]->getLevel() << "||" << "Price: " << armors[i]->getPrice() << endl;
					}
					std::cout << "4) Cancel!" << endl;

					std::cout << "Witch weapon do you like to buy: ";
					std::cin >> input;

					while (input < 1 || input > 4)
					{
						std::cout << "Enter number from 1 - 4: ";
						std::cin >> input;
					}

					if(input==4){
						break;
					}
					
					if (character==1)
					{
						if (Team[0]->getMoney() >= armors[input - 1]->getPrice() && Team[0]->getLevel() >= armors[input - 1]->getLevel()){
							Team[0]->removeMoney(armors[input - 1]->getPrice());
							inventory[spaceInventory] = armors[input - 1];
							spaceInventory++;
							break;
						}else{
							std::cout << "You dont have the required level or money for this item"<<endl;
							break;
						}	
					}else if(character==2){
						if (Team[1]->getMoney() >= armors[input - 1]->getPrice() && Team[1]->getLevel() >= armors[input - 1]->getLevel()){
							Team[1]->removeMoney(armors[input - 1]->getPrice());
							inventory2[spaceInventory2] = armors[input - 1];
							spaceInventory2++;
							break;
						}else{
							std::cout << "You dont have the required level or money for this item"<<endl;
							break;
						}	
					}else if(character==3){
						if (Team[2]->getMoney() >= armors[input - 1]->getPrice() && Team[2]->getLevel() >= armors[input - 1]->getLevel()){
							Team[2]->removeMoney(armors[input - 1]->getPrice());
							inventory3[spaceInventory3] = armors[input - 1];
							spaceInventory3++;
							break;
						}else{
							std::cout << "You dont have the required level or money for this item"<<endl;
							break;
						}
					}
					else {
						break;
					}
				case 3:

					for (i = 0; i < 3; i++)
					{
						std::cout << i + 1 << ")" << "Name: " << potions[i]->getName() << "||" << "Level: " << potions[i]->getLevel() << "||" << "Price: " << potions[i]->getPrice() << endl;
					}
					std::cout << "4) Cancel!" << endl;
					std::cout << "Witch weapon do you like to buy: ";
					std::cin >> input;

					while (input < 1 || input > 4)
					{
						std::cout << "Enter number from 1 - 4: ";
						std::cin >> input;
					}

					if(input==4){
						break;
					}

					
					if (character==1)
					{
						if (Team[0]->getMoney() >= potions[input - 1]->getPrice() && Team[0]->getLevel() >= potions[input - 1]->getLevel()){
							Team[0]->removeMoney(potions[input - 1]->getPrice());
							inventory[spaceInventory] = potions[input - 1];
							spaceInventory++;
							break;
						}else{
							std::cout << "You dont have the required level or money for this item"<<endl;
							break;
						}	
					}else if(character==2){
						if (Team[1]->getMoney() >= potions[input - 1]->getPrice() && Team[1]->getLevel() >= potions[input - 1]->getLevel()){
							Team[1]->removeMoney(potions[input - 1]->getPrice());
							inventory2[spaceInventory2] = potions[input - 1];
							spaceInventory2++;
							break;
						}else{
							std::cout << "You dont have the required level or money for this item"<<endl;
							break;
						}	
					}else if(character==3){
						if (Team[2]->getMoney() >= potions[input - 1]->getPrice() && Team[2]->getLevel() >= potions[input - 1]->getLevel()){
							Team[2]->removeMoney(potions[input - 1]->getPrice());
							inventory3[spaceInventory3] = potions[input - 1];
							spaceInventory3++;
							break;
						}else{
							std::cout << "You dont have the required level or money for this item"<<endl;
							break;
						}	
					}
					else {
						break;
					}
					
				case 4:
					break;
				}
				break;
			case 2:

				std::cout << "What do you like to buy: 1) IceSpell, 2) FireSpell, 3)LightingSpell 4) Cancel: ";
				std::cin >> categ;
				while (categ < 1 || categ > 4) {
					std::cout << "Enter number from 1 - 4: ";
					std::cin >> categ;
				}
				switch (categ) {
				case 1:
					int i;

					for (i = 0; i < 3; i++)
					{
						std::cout << i + 1 << ")" << "Name: " << iceSpells[i]->getName() << "||" << "Level: " << iceSpells[i]->getLevel() << "||" << "Price: " << iceSpells[i]->getPrice() << endl;
					}
					std::cout << "4) Cancel!" << endl;
					std::cout << "Witch spell do you like to buy: ";
					std::cin >> input;

					while (input < 1 || input > 4)
					{
						std::cout << "Enter number from 1 - 4: ";
						std::cin >> input;
					}

					if (input == 4) {
						break;
					}

					
					if (character == 1)
					{
						if (Team[0]->getMoney() >= iceSpells[input - 1]->getPrice() && Team[0]->getLevel() >= iceSpells[input - 1]->getLevel()){
							Team[0]->removeMoney(iceSpells[input - 1]->getPrice());
							spellInventory[spaceSpell] = iceSpells[input - 1];
							spaceSpell++;
							break;
						}
						else
						{
							std::cout << "You dont have the required level or money for this spell"<<endl;
							break;
						}	
					}
					else if(character == 2)
					{
						if (Team[1]->getMoney() >= iceSpells[input - 1]->getPrice() && Team[1]->getLevel() >= iceSpells[input - 1]->getLevel())
						{
							Team[1]->removeMoney(iceSpells[input - 1]->getPrice());
							spellInventory2[spaceSpell2] = iceSpells[input - 1];
							spaceSpell2++;
							break;
						}
						else 
						{
							std::cout << "You dont have the required level or money for this spell"<<endl;
							break;
						}
					}
					else if(character == 3)
					{
						if (Team[2]->getMoney() >= iceSpells[input - 1]->getPrice() && Team[2]->getLevel() >= iceSpells[input - 1]->getLevel())
						{
							Team[2]->removeMoney(iceSpells[input - 1]->getPrice());
							spellInventory3[spaceSpell3] = iceSpells[input - 1];
							spaceSpell3++;
							break;
						}
						else
						{
							std::cout << "You dont have the required level or money for this spell" << endl;
							break;
						}
					}
					else 
					{
						break;
					}
				case 2:

					for (i = 0; i < 3; i++)
					{
						std::cout << i+1 << ")" << "Name: " << fireSpells[i]->getName() << "||" << "Level: " << fireSpells[i]->getLevel() << "||" << "Price: " << fireSpells[i]->getPrice() << endl;
					}
					std::cout << "4) Cancel!" << endl;
					std::cout << "Witch spell do you like to buy: ";
					std::cin >> input;
					while (input < 1 || input > 4)
					{
						std::cout << "Enter number from 1 - 4: ";
						std::cin >> input;
					}

					if(input==4){
						break;
					}

				
					if (character==1)
					{
						if (Team[0]->getMoney() >= fireSpells[input - 1]->getPrice() && Team[0]->getLevel() >= fireSpells[input - 1]->getLevel()){
							Team[0]->removeMoney(fireSpells[input - 1]->getPrice());
							spellInventory[spaceSpell] = fireSpells[input - 1];
							spaceSpell++;
							break;
						}else
						{
							std::cout << "You dont have the required level or money for this spell"<<endl;
							break;
						}	
					}else if(character==2){
						if (Team[1]->getMoney() >= fireSpells[input - 1]->getPrice() && Team[1]->getLevel() >= fireSpells[input - 1]->getLevel()){
							Team[1]->removeMoney(fireSpells[input - 1]->getPrice());
							spellInventory2[spaceSpell2] = fireSpells[input - 1];
							spaceSpell2++;
							break;
						}else
						{
							std::cout << "You dont have the required level or money for this spell"<<endl;
							break;
						}	
					}else if(character==3){
						if (Team[2]->getMoney() >= fireSpells[input - 1]->getPrice() && Team[2]->getLevel() >= fireSpells[input - 1]->getLevel()){
							Team[2]->removeMoney(fireSpells[input - 1]->getPrice());
							spellInventory3[spaceSpell3] = fireSpells[input - 1];
							spaceSpell3++;
							break;
						}else
						{
							std::cout << "You dont have the required level or money for this spell"<<endl;
							break;
						}		
					}else {
						break;
					}
				case 3:

					for (i = 0; i < 3; i++)
					{
						std::cout << i+1 << ")" << "Name: " << lightingSpells[i]->getName() << "||" << "Level: " << lightingSpells[i]->getLevel() << "||" << "Price: " << lightingSpells[i]->getPrice() << endl;
					}
					std::cout << "4) Cancel!" << endl;
					std::cout << "Witch spell do you like to buy: ";
					std::cin >> input;

					while (input < 1 || input > 4)
					{
						std::cout << "Enter number from 1 - 4: ";
						std::cin >> input;
					}

					if(input==4){
						break;
					}

					
					if (character==1)
					{
						if (Team[0]->getMoney() >= lightingSpells[input - 1]->getPrice() && Team[0]->getLevel() >= lightingSpells[input - 1]->getLevel()){
							Team[0]->removeMoney(lightingSpells[input - 1]->getPrice());
							spellInventory[spaceSpell] = lightingSpells[input - 1];
							spaceSpell++;
							break;
						}else
						{
							std::cout << "You dont have the required level or money for this spell"<<endl;
							break;
						}		
					}else if(character==2){
						if (Team[1]->getMoney() >= lightingSpells[input - 1]->getPrice() && Team[1]->getLevel() >= lightingSpells[input - 1]->getLevel()){
							Team[1]->removeMoney(lightingSpells[input - 1]->getPrice());
							spellInventory2[spaceSpell2] = lightingSpells[input - 1];
							spaceSpell2++;
							break;
						}else
						{
							std::cout << "You dont have the required level or money for this spell"<<endl;
							break;
						}		
					}else if(character==3){
						if (Team[2]->getMoney() >= lightingSpells[input - 1]->getPrice() && Team[2]->getLevel() >= lightingSpells[input - 1]->getLevel()){
							Team[2]->removeMoney(lightingSpells[input - 1]->getPrice());
							spellInventory3[spaceSpell3] = lightingSpells[input - 1];
							spaceSpell3++;
							break;
						}else
						{
							std::cout << "You dont have the required level or money for this spell"<<endl;
							break;
						}		
					}else {
						break;				// Test Remember
					}

					break;
				case 4:
					break;
				}
				break;

			case 3:
				break;


			}
			break;
		case 2:
			if (character==1)
			{
				if (spaceInventory != 0) {
					int sellitem;
					std::cout << "Which item/spell do you want to sell: ";
					for (i = 0; i < spaceInventory; i++)
					{
						std::cout << i + 1 << ")" << inventory[i]->getName() << inventory[i]->getLevel() << inventory[i]->getPrice();
					}
					std::cin >> sellitem;
					while (sellitem < 1 || sellitem > spaceInventory) {
						std::cout << "Wrong Number! Enter number from 1 - " << spaceInventory << " :";
						std::cin >> sellitem;
					}

					while (1)
					{
						int temp;
						temp = inventory[sellitem - 1]->getPrice() / 2;
						Team[0]->addMoney(temp);
						inventory[sellitem - 1] = NULL;
						spaceInventory--;

						std::cout << "Do you want to sell more items 1) Yes 2) No :";
						std::cin >> input;

						while (input < 1 || input > 2)
						{
							std::cout << "Wrong Number! Try again 1) Yes 2) No: ";
							std::cin >> input;
						}
						if (input == 1)
						{
							std::cout << "Give  the number of the Item: ";
							std::cin >> sellitem;
						}
						else
							break;
					}
				}
				else {
					std::cout << "You dont have any item in your invetory" << endl;
					break;
				}
			}
			else if (character == 2)
			{
				if (spaceInventory2 != 0) {
					int sellitem;
					std::cout << "Which item/spell do you want to sell: ";
					for (i = 0; i < spaceInventory2; i++)
					{
						std::cout << i + 1 << ")" << inventory2[i]->getName() << inventory2[i]->getLevel() << inventory2[i]->getPrice();
					}
					std::cin >> sellitem;
					while (sellitem < 1 || sellitem > spaceInventory2) {
						std::cout << "Wrong Number! Enter number from 1 - " << spaceInventory2 << " :";
						std::cin >> sellitem;
					}

					while (1)
					{
						int temp;
						temp = inventory2[sellitem - 1]->getPrice() / 2;
						Team[1]->addMoney(temp);
						inventory2[sellitem - 1] = NULL;
						spaceInventory2--;

						std::cout << "Do you want to sell more items 1) Yes 2) No :";
						std::cin >> input;

						while (input < 1 || input > 2)
						{
							std::cout << "Wrong Number! Try again 1) Yes 2) No: ";
							std::cin >> input;
						}
						if (input == 1)
						{
							std::cout << "Give  the number of the Item: ";
							std::cin >> sellitem;
						}
						else
							break;
					}
				}
				else {
					std::cout << "You dont have any item in your invetory" << endl;
					break;
				}
			}
			else if (character == 3)
			{
				if (spaceInventory3 != 0) {
					int sellitem;
					std::cout << "Which item/spell do you want to sell: ";
					for (i = 0; i < spaceInventory3; i++)
					{
						std::cout << i + 1 << ")" << inventory3[i]->getName() << inventory3[i]->getLevel() << inventory3[i]->getPrice();
					}
					std::cin >> sellitem;
					while (sellitem < 1 || sellitem > spaceInventory3) {
						std::cout << "Wrong Number! Enter number from 1 - " << spaceInventory3 << " :";
						std::cin >> sellitem;
					}

					while (1)
					{
						int temp;
						temp = inventory3[sellitem - 1]->getPrice() / 2;
						Team[2]->addMoney(temp);
						inventory3[sellitem - 1] = NULL;
						spaceInventory3--;

						std::cout << "Do you want to sell more items 1) Yes 2) No :";
						std::cin >> input;

						while (input < 1 || input > 2)
						{
							std::cout << "Wrong Number! Try again 1) Yes 2) No: ";
							std::cin >> input;
						}
						if (input == 1)
						{
							std::cout << "Give  the number of the Item: ";
							std::cin >> sellitem;
						}
						else
							break;
					}
				}
				else {
					std::cout << "You dont have any item in your invetory" << endl;
					break;
				}
			}

		case 3:
			break;
		default:
			break;
		}
		
		std::cout << "Do you want to continue shopping ?"<<endl;
		std::cout << "1) Yes or 2) No :  ";
		std::cin >> ch;
		while (ch < 1 || ch > 2)
		{
			std::cout << "Enter 1 or 2: ";
			std::cin >> ch;
		}

		if(ch==1){
			std::cout << "Do you want to change character?";
			std::cout << "1) Yes or 2) No :  ";
			std::cin >> ch;
			while (ch < 1 || ch > 2)
			{
				std::cout << "Enter 1 or 2: ";
				std::cin >> ch;
			}
			
			if( ch==1){
				for (i = 0; i < NumberOfPlayers; i++)
				{
					std::cout << i + 1 << ") Name: " << Team[i]->getName() << " Level: " << Team[i]->getLevel() << " Money: " << Team[i]->getMoney() << endl;
				}
				std::cout <<NumberOfPlayers + 1<< ") Exit " << endl;
				std::cout << "Choose Character: ";
				std::cin >> character;

				while (character < 1 || character > NumberOfPlayers + 1)
				{
					std::cout << "Wrong Number! Give again from 1 - "<< NumberOfPlayers + 1 <<": ";
					std::cin >> character;
				}
				
				if (character == NumberOfPlayers + 1)
				{
					ch = 3;
				}
				else
				{
					std::cout << "\tDo you like to 1) Buy 2) Sell or 3) Cancel: ";
					std::cin >> ch;

					while (ch < 1 || ch > 3)
					{
						std::cout << "Enter number from 1 - 3: ";
						std::cin >> ch;
					}
				}
			}else{
				std::cout << "\tDo you like to 1) Buy 2) Sell or 3) Cancel: ";
					std::cin >> ch;

					while (ch < 1 || ch > 3)
					{
						std::cout << "Enter number from 1 - 3: ";
						std::cin >> ch;
					}
			}
			
			
		}else{
			ch=3;
		}
				
		
		
	}
}

static int weapon = 0;

void Grid::setShopWeapon(Weapon* p1)
{

	weapons[weapon] = p1;
	
	weapon++;
}

static int armor = 0;

void Grid::setShopArmor(Armor* p1)
{
	armors[armor] = p1;

	armor++;
}

static int potion = 0;

void Grid::setShopPotion(Potion* p1)
{
	potions[potion] = p1;

	potion++;
}

static int iceSpell = 0;

void Grid::setShopIceSpell(IceSpell* p1)
{
	iceSpells[iceSpell] = p1;

	iceSpell++;
}

static int fireSpell = 0;

void Grid::setShopFireSpell(FireSpell* p1)
{
	fireSpells[fireSpell] = p1;

	fireSpell++;
}

static int lightingSpell = 0;

void Grid::setShopLightingSpell(LightingSpell* p1)
{
	lightingSpells[lightingSpell] = p1;

	lightingSpell++;
}

static int team = 0;

void Grid::setTeam(Hero* p1)
{
	Team[team] = p1;

	team++;
}

void Grid::checkInventory()
{
	int i, j;
		std::cout << "\033[1;93m   ______  ______  ______  ______  ______  ______  ______  ______  ______  ______  \033[0m" << endl;
		std::cout << "\033[1;93m  |______||______||______||______||______||______||______||______||______||______| \033[0m" << endl;

		std::cout << "\033[1;95m            _____ _   _ _   _ _____ _   _ _____ _____________   __  _ _ _          \033[0m" << endl;
		std::cout << "\033[1;95m           |_   _| \\ | | | | |  ___| \\ | |_   _|  _  | ___ \\ \\ / / | | | |             \033[0m" << endl;
		std::cout << "\033[1;95m             | | |  \\| | | | | |__ |  \\| | | | | | | | |_/ /\\ V /  | | | |             \033[0m" << endl;
		std::cout << "\033[1;95m             | | | . ` | | | |  __|| . ` | | | | | | |    /  \\ /   | | | |             \033[0m" << endl;
		std::cout << "\033[1;95m            _| |_| |\\  \\ \\_/ / |___| |\\  | | | \\ \\_/ / |\\ \\  | |   |_|_|_|             \033[0m" << endl;
		std::cout << "\033[1;95m            \\___/\\_| \\_/\\___/\\____/\\_| \\_/ \\_/  \\__/\\_| \\_|  \\_/   (_|_|_)             \033[0m" << endl;

		std::cout << "\033[1;93m   ______  ______  ______  ______  ______  ______  ______  ______  ______  ______  \033[0m" << endl;
		std::cout << "\033[1;93m  |______||______||______||______||______||______||______||______||______||______| \033[0m" << endl << endl;
		std::cout << "=================================================================" << endl;
		std::cout<< "HERO 1"<<endl;

		for (i = 0; i < spaceInventory; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (inventory[i] == weapons[j])
				{
					std::cout << "" << i + 1 << ") Weapon:" << weapons[j]->getName() << " Damage: " << weapons[j]->getDamge() << " Hands:" << weapons[j]->getHands() << endl;
				}
				else if (inventory[i] == armors[j])
				{
					std::cout << "" << i + 1 << ") Armor:" << armors[j]->getName() << " Resistance: " << armors[j]->getResistance() << endl;
				}
				else if (inventory[i] == potions[j])
				{
					std::cout << "" << i + 1 << ") Potion:" << potions[j]->getName() << " More Ability: " << potions[j]->getAbility() << endl;
				}
			}

		}

		
		if(NumberOfPlayers>=2)
		{	
			std::cout<< "HERO 2"<<endl;
				for (i = 0; i < spaceInventory2; i++)
				{
					for (j = 0; j < 3; j++)
					{
						if (inventory2[i] == weapons[j])
						{
							std::cout << "" << i + 1 << ") Weapon:" << weapons[j]->getName() << " Damage: " << weapons[j]->getDamge() << " Hands:" << weapons[j]->getHands() << endl;
						}
						else if (inventory2[i] == armors[j])
						{
							std::cout << "" << i + 1 << ") Armor:" << armors[j]->getName() << " Resistance: " << armors[j]->getResistance() << endl;
						}
						else if (inventory2[i] == potions[j])
						{
							std::cout << "" << i + 1 << ") Potion:" << potions[j]->getName() << " More Ability: " << potions[j]->getAbility() << endl;
						}
					}

				}
		}

		if(NumberOfPlayers==3)
		{
			std::cout<< "HERO 3"<<endl;
				for (i = 0; i < spaceInventory3; i++)
				{
					for (j = 0; j < 3; j++)
					{
						if (inventory3[i] == weapons[j])
						{
							std::cout << "" << i + 1 << ") Weapon:" << weapons[j]->getName() << " Damage: " << weapons[j]->getDamge() << " Hands:" << weapons[j]->getHands() << endl;
						}
						else if (inventory3[i] == armors[j])
						{
							std::cout << "" << i + 1 << ") Armor:" << armors[j]->getName() << " Resistance: " << armors[j]->getResistance() << endl;
						}
						else if (inventory3[i] == potions[j])
						{
							std::cout << "" << i + 1 << ") Potion:" << potions[j]->getName() << " More Ability: " << potions[j]->getAbility() << endl;
						}
					}

				}
		}
		std::cout << "=================================================================" << endl;
}


void Grid::use()
{
	int lista[100];
	int character;
	int input;
	int counter = 1;
	


	for (int i = 0; i < NumberOfPlayers; i++) {
		std::cout << i + 1 << ") " << Team[i]->getName() << endl;
	}

	std::cout << NumberOfPlayers + 1 << ") Exit " << endl;
	std::cout << "Choose Character: ";
	std::cin >> character;

	while (character < 1 || character > NumberOfPlayers + 1)
	{
		std::cout << "Wrong Number! Give again from 1 - "<< NumberOfPlayers + 1 <<": ";
		std::cin >> character;
	}

	if (character != NumberOfPlayers + 1) {


		std::cout << "\033[1;93m   ______  ______  ______  ______  ______  ______  ______  ______  ______  ______  \033[0m" << endl;
		std::cout << "\033[1;93m  |______||______||______||______||______||______||______||______||______||______| \033[0m" << endl;

		std::cout << "\033[1;95m                   ______ _____ _____ _____ _____ _   _  _____           \033[0m" << endl;
		std::cout << "\033[1;95m                   | ___ \\  _  |_   _|_   _|  _  | \\ | |/  ___|             \033[0m" << endl;
		std::cout << "\033[1;95m                   | |_/ / | | | | |   | | | | | |  \\| |\\ `--.              \033[0m" << endl;
		std::cout << "\033[1;95m                   |  __/| | | | | |   | | | | | | . ` | `--. \\             \033[0m" << endl;
		std::cout << "\033[1;95m                   | |   \\ \\_/ / | |  _| |_\\ \\_/ / |\\  |/\\__/ /             \033[0m" << endl;
		std::cout << "\033[1;95m                   \\_|    \\___/  \\_/  \\___/ \\___/\\_| \\_/\\____/              \033[0m" << endl;

		std::cout << "\033[1;93m   ______  ______  ______  ______  ______  ______  ______  ______  ______  ______  \033[0m" << endl;
		std::cout << "\033[1;93m  |______||______||______||______||______||______||______||______||______||______| \033[0m" << endl << endl;

		if (character == 1)
		{

			for (int i = 0; i < spaceInventory; i++)
			{
				
				if (inventory[i] == potions[0])
				{
					std::cout << counter << ") Potion: " << potions[0]->getName() << "		" << "Agility: " << potions[0]->getAbility() << endl;
					lista[counter] = i;
					counter++;
				}else if (inventory[i] == potions[1])
				{
					std::cout << counter << ") Potion: " << potions[1]->getName() << "		" << "Damage: " << potions[1]->getAbility() << endl;
					lista[counter] = i;
					counter++;
				}else if (inventory[i] == potions[2])
				{
					std::cout << counter << ") Potion: " << potions[2]->getName() << "		" << "Defense: " << potions[2]->getAbility() << endl;
					lista[counter] = i;
					counter++;
				}
			}

			std::cout << counter << ") Cancel " << endl;
			std::cout << "Choose Potion you want to use: ";
			std::cin >> input;

			while (input < 1 || input > counter)
			{
				std::cout << "Wrong Number! Give again from 1 - " << counter << ": ";
				std::cin >> input;
			}

			if (input != counter) {
				
				
				if (inventory[lista[input]] == potions[0]) {
					Team[0]->addAgility(potions[0]->getAbility());
				}else if(inventory[lista[input]] == potions[1]){
					Team[0]->addDamage(potions[1]->getAbility());
				}else if(inventory[lista[input]] == potions[2]){
					Team[0]->addDefense(potions[2]->getAbility());
				}

				
			}




		}
		else if (character == 2) {
			for (int i = 0; i < spaceInventory2; i++)
			{
				if (inventory2[i] == potions[0])
				{
					std::cout << counter << ") Potion: " << potions[0]->getName() << "		" << "Agility: " << potions[0]->getAbility() << endl;
					lista[counter] = i;
					counter++;
				}
				else if (inventory2[i] == potions[1])
				{
					std::cout << counter << ") Potion: " << potions[1]->getName() << "		" << "Damage: " << potions[1]->getAbility() << endl;
					lista[counter] = i;
					counter++;
				}
				else if (inventory2[i] == potions[2])
				{
					std::cout << counter << ") Potion: " << potions[2]->getName() << "		" << "Defense: " << potions[2]->getAbility() << endl;
					lista[counter] = i;
					counter++;
				}
			}

			std::cout << counter << ") Cancel " << endl;
			std::cout << "Choose potion you want to equip: ";
			std::cin >> input;

			while (input < 1 || input > counter)
			{
				std::cout << "Wrong Number! Give again from 1 - " << counter << ": ";
				std::cin >> input;
			}

			if (input != counter) {
				if (inventory2[lista[input]] == potions[0]) {
					Team[1]->addAgility(potions[0]->getAbility());
				}
				else if (inventory2[lista[input]] == potions[1]) {
					Team[1]->addDamage(potions[1]->getAbility());
				}
				else if (inventory2[lista[input]] == potions[2]) {
					Team[1]->addDefense(potions[2]->getAbility());
				}
			}
		}
		else if (character == 3) {
			for (int i = 0; i < spaceInventory3; i++)
			{
				if (inventory3[i] == potions[0])
				{
					std::cout << counter << ") Potion: " << potions[0]->getName() << "		" << "Agility: " << potions[0]->getAbility() << endl;
					lista[counter] = i;
					counter++;
				}
				else if (inventory3[i] == potions[1])
				{
					std::cout << counter << ") Potion: " << potions[1]->getName() << "		" << "Damage: " << potions[1]->getAbility() << endl;
					lista[counter] = i;
					counter++;
				}
				else if (inventory3[i] == potions[2])
				{
					std::cout << counter << ") Potion: " << potions[2]->getName() << "		" << "Defense: " << potions[2]->getAbility() << endl;
					lista[counter] = i;
					counter++;
				}
			}

			std::cout << counter << ") Cancel " << endl;
			std::cout << "Choose Potion you want to use: ";
			std::cin >> input;

			while (input < 1 || input > counter)
			{
				std::cout << "Wrong Number! Give again from 1 - " << counter << ": ";
				std::cin >> input;
			}

			if (input != counter) {
				if (inventory3[lista[input]] == potions[0]) {
					Team[2]->addAgility(potions[0]->getAbility());
				}
				else if (inventory3[lista[input]] == potions[1]) {
					Team[2]->addDamage(potions[1]->getAbility());
				}
				else if (inventory3[lista[input]] == potions[2]) {
					Team[2]->addDefense(potions[2]->getAbility());
				}
			}
		}
	}
}


bool firstTimeWeapon = true;
bool firstTimeArmor = true;

bool firstTimeWeapon2 = true;
bool firstTimeArmor2 = true;

bool firstTimeWeapon3 = true;
bool firstTimeArmor3 = true;

void Grid::equip()
{
	int lista[100];
	int character;
	int input;
	int counter=1;
	Weapon* temp = weapons[0];
	Armor* tempa = armors[0];


	for (int i = 0; i < NumberOfPlayers; i++) {
		std::cout << i + 1 << ") " << Team[i]->getName() << endl;
	}

	std::cout << NumberOfPlayers + 1 << ") Exit " << endl;
	std::cout << "Choose Character: ";
	std::cin >> character;

	while (character < 1 || character > NumberOfPlayers + 1)
	{
		std::cout << "Wrong Number! Give again from 1 - "<<NumberOfPlayers + 1<<": ";
		std::cin >> character;
	}
	
	if(character!= NumberOfPlayers + 1){
	

			std::cout << "\033[1;93m   ______  ______  ______  ______  ______  ______  ______  ______  ______  ______  \033[0m" << endl;
			std::cout << "\033[1;93m  |______||______||______||______||______||______||______||______||______||______| \033[0m" << endl;

			std::cout << "\033[1;95m                     ___  _________  ______________  _____            \033[0m" << endl;
			std::cout << "\033[1;95m                    / _ \\ | ___ \\  \\/  |  _  | ___ \\/  ___|             \033[0m" << endl;
			std::cout << "\033[1;95m                   / /_\\ \\| |_/ / .  . | | | | |_/ /\\ `--.               \033[0m" << endl;
			std::cout << "\033[1;95m                   |  _  ||    /| |\\/| | | | |    /  `--. \\             \033[0m" << endl;
			std::cout << "\033[1;95m                   | | | || |\\ \\| |  | \\ \\_/ / |\\ \\ /\\__/ /             \033[0m" << endl;
			std::cout << "\033[1;95m                   \\_| |_/\\_| \\_\\_|  |_/\\___/\\_| \\_|\\____/               \033[0m" << endl;
			std::cout << "\033[1;95m                                                                         \033[0m" << endl;
			std::cout << "\033[1;95m                    _    _ _____  ___  ______ _____ _   _  _____            \033[0m" << endl;
			std::cout << "\033[1;95m                   | |  | |  ___|/ _ \\ | ___ \\  _  | \\ | |/  ___|             \033[0m" << endl;
			std::cout << "\033[1;95m                   | |  | | |__ / /_\\ \\| |_/ / | | |  \\| |\\ `--.         \033[0m" << endl;
			std::cout << "\033[1;95m                   | |/\\| |  __||  _  ||  __/| | | | . ` | `--. \\        \033[0m" << endl;
			std::cout << "\033[1;95m                   \\  /\\  / |___| | | || |   \\ \\_/ / |\\  |/\\__/ /       \033[0m" << endl;
			std::cout << "\033[1;95m                    \\/  \\/\\____/\\_| |_/\\_|    \\___/\\_| \\_/\\____/         \033[0m" << endl;

			std::cout << "\033[1;93m   ______  ______  ______  ______  ______  ______  ______  ______  ______  ______  \033[0m" << endl;
			std::cout << "\033[1;93m  |______||______||______||______||______||______||______||______||______||______| \033[0m" << endl << endl;
			
		if (character == 1)
		{
			
			for (int i = 0; i < spaceInventory; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					if (inventory[i] == weapons[j])
					{
						std::cout << counter << ") Weapon: " << weapons[j]->getName() << "		" << "Damage: " << weapons[j]->getDamge() << endl;
						lista[counter]=i;
						counter++;
					}
					else if (inventory[i] == armors[j])
					{
						std::cout << counter << ") Armor: " << armors[j]->getName() << "		" << "Defense: " << armors[j]->getResistance() << endl;
						lista[counter]=i;
						counter++;
					}
				}
			}

			std::cout << counter << ") Cancel " << endl;
			std::cout << "Choose Weapon/Armor you want to equip: ";
			std::cin >> input;

			while (input < 1 || input > counter)
			{
				std::cout << "Wrong Number! Give again from 1 - "<< counter << ": ";
				std::cin >> input;
			}
			
			if(input!=counter){
				for (int j = 0; j < 3; j++)
				{
					if(inventory[lista[input]]==weapons[j]){
						if(firstTimeWeapon == false){
							Team[0]->removeDamage(temp->getDamge());
						}
						Team[0]->addDamage(weapons[j]->getDamge());
						temp = weapons[j];
						firstTimeWeapon = false;
					}

					if(inventory[lista[input]]==armors[j]){
						if (firstTimeArmor == false) {
							Team[0]->removeDefense(tempa->getResistance());
						}
						Team[0]->addDefense(armors[j]->getResistance());
						tempa = armors[j];
						firstTimeArmor = false;
					}

				}
			}

			


		}else if(character == 2){
			for (int i = 0; i < spaceInventory2; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					if (inventory2[i] == weapons[j])
					{
						std::cout << counter << ") Weapon: " << weapons[j]->getName() << "		" << "Damage: " << weapons[j]->getDamge() << endl;
						lista[counter] = i;
						counter++;
					}
					else if (inventory2[i] == armors[j])
					{
						std::cout << counter << ") Armor: " << armors[j]->getName() << "		" << "Defense: " << armors[j]->getResistance() << endl;
						lista[counter] = i;
						counter++;
					}

				}


			}

			std::cout << counter << ") Cancel " << endl;
			std::cout << "Choose Weapon/Armor you want to equip: ";
			std::cin >> input;

			while (input < 1 || input > counter)
			{
				std::cout << "Wrong Number! Give again from 1 - " << counter << ": ";
				std::cin >> input;
			}

			if(input!=counter){
				for (int j = 0; j < 3; j++)
				{
					if (inventory2[lista[input]] == weapons[j]) {
						if (firstTimeWeapon2 == false) {
							Team[1]->removeDamage(temp->getDamge());
						}
						Team[1]->addDamage(weapons[j]->getDamge());
						temp = weapons[j];
						firstTimeWeapon2 = false;
					}

					if (inventory2[lista[input]] == armors[j]) {
						if (firstTimeArmor2 == false) {
							Team[1]->removeDefense(tempa->getResistance());
						}
						Team[1]->addDefense(armors[j]->getResistance());
						tempa = armors[j];
						firstTimeArmor2 = false;
					}

				}
			}

			

			


		}else if(character == 3){
			for (int i = 0; i < spaceInventory3; i++)
			{
				for (int j = 0; j < 3; j++)
				{
					if (inventory3[i] == weapons[j])
					{
						std::cout << counter << ") Weapon: " << weapons[j]->getName() << "		" << "Damage: " << weapons[j]->getDamge() << endl;
						lista[counter] = i;
						counter++;
					}
					else if (inventory3[i] == armors[j])
					{
						std::cout << counter << ") Armor: " << armors[j]->getName() << "		" << "Defense: " << armors[j]->getResistance() << endl;
						lista[counter] = i;
						counter++;
					}

				}


			}

			std::cout << counter << ") Cancel " << endl;
			std::cout << "Choose Weapon/Armor you want to equip: ";
			std::cin >> input;

			while (input < 1 || input > counter)
			{
				std::cout << "Wrong Number! Give again from 1 - " << counter << ": ";
				std::cin >> input;
			}

			if(input!=counter){
				for (int j = 0; j < 3; j++)
				{
					if (inventory3[lista[input]] == weapons[j]) {
						if (firstTimeWeapon3 == false) {
							Team[2]->removeDamage(temp->getDamge());
						}
						Team[2]->addDamage(weapons[j]->getDamge());
						temp = weapons[j];
						firstTimeWeapon3 = false;
					}

					if (inventory3[lista[input]] == armors[j]) {
						if (firstTimeArmor3 == false) {
							Team[2]->removeDefense(tempa->getResistance());
						}
						Team[2]->addDefense(armors[j]->getResistance());
						tempa = armors[j];
						firstTimeArmor3 = false;
					}

				}
			}

			
			
		}
		
	}

}

void Grid::attack(Monster** MonsterTeam, int numberofenemies, int character)
{
	int input;

	int Monstershealth = 0;

	for (int i = 0; i < numberofenemies; i++) {
		if (MonsterTeam[i]->getHealth() > 0){
			std::cout << i + 1 << ") " << MonsterTeam[i]->getName() << " Health: " << MonsterTeam[i]->getHealth() << endl;
		}else{
			std::cout << i + 1 << ") " << MonsterTeam[i]->getName() << " is Dead!" << endl;
		}
		if(MonsterTeam[i]->getHealth()>0){
			Monstershealth = Monstershealth + MonsterTeam[i]->getHealth();
		}
	}
	
	if (Monstershealth > 0) {
		std::cout << "which monster are you going to attack :";
		std::cin >> input;

		while (input < 1 || input > numberofenemies)
		{
			std::cout << "Enter number from 1 - " << numberofenemies << ": ";
			std::cin >> input;
		}

		while (MonsterTeam[input - 1]->getHealth() < 0) {
			std::cout << "This monster is dead choose another one " << endl;
			std::cout << "Enter number from 1 - " << numberofenemies << ": ";
			std::cin >> input;
		}

		if (rand() % 100 > MonsterTeam[input - 1]->getMiss())
		{
			MonsterTeam[input - 1]->removeHealth(Team[character]->getDamage());
		}
		else
		{
			std::cout << Team[character]->getName() << " missed the attack!" << endl;
		}

	}
}

void Grid::castSpell(Monster** MonsterTeam, int numberofenemies, int character)
{
	int input;

	int Monstershealth = 0;

	for (int i = 0; i < numberofenemies; i++) {
		if (MonsterTeam[i]->getHealth() > 0){
			std::cout << i + 1 << ") " << MonsterTeam[i]->getName() << " Health: " << MonsterTeam[i]->getHealth() << endl;
		}else{
			std::cout << i + 1 << ") " << MonsterTeam[i]->getName() << " is Dead!" << endl;
		}
		
		if(MonsterTeam[i]->getHealth() > 0){
			Monstershealth = Monstershealth + MonsterTeam[i]->getHealth();
		}
	}
	
	if (Monstershealth > 0) {
		std::cout << "which monster are you going to attack :";
		std::cin >> input;

		while (input < 1 || input > numberofenemies)
		{
			std::cout << "Enter number from 1 - " << numberofenemies << ": ";
			std::cin >> input;
		}

		while (MonsterTeam[input - 1]->getHealth() < 0) {
			std::cout << "This monster is dead choose another one " << endl;
			std::cout << "Enter number from 1 - " << numberofenemies << ": ";
			std::cin >> input;
		}

		if (character == 0)
		{
			if(spaceSpell != 0){
				for(int i = 0; i < spaceSpell; i++){
					std::cout << i + 1 << ") " <<spellInventory[i]->getName()<<endl;
				}

				std::cout << "which spell are you going to use :";
				std::cin >> input;

				while (input < 1 || input > spaceSpell)
				{
					std::cout << "Enter number from 1 - " << spaceSpell << ": ";
					std::cin >> input;
				}

				if (Team[0]->getMagicPower() > 0)
				{
					if (rand() % 100 > MonsterTeam[input - 1]->getMiss())
					{
						for (int i = 0; i < 3; i++)
						{
							if (spellInventory[input - 1] == fireSpells[i])
							{
								MonsterTeam[input - 1]->removeHealth(spellInventory[input - 1]->getMagicDamage() * Team[0]->getDexterity());
								Team[character]->removeMagicPower(spellInventory[input - 1]->getMagicPower());
								MonsterTeam[input - 1]->removeDefense(5);
							}
							else if (spellInventory[input - 1] == iceSpells[i])
							{
								MonsterTeam[input - 1]->removeHealth(spellInventory[input - 1]->getMagicDamage() * Team[0]->getDexterity());
								Team[character]->removeMagicPower(spellInventory[input - 1]->getMagicPower());
								MonsterTeam[input - 1]->removeDamage(10);
							}
							else if (spellInventory[input - 1] == lightingSpells[i])
							{
								MonsterTeam[input - 1]->removeHealth(spellInventory[input - 1]->getMagicDamage() * Team[0]->getDexterity());
								Team[character]->removeMagicPower(spellInventory[input - 1]->getMagicPower());
								MonsterTeam[input - 1]->removeMiss(5);
							}
						}
					}
					else
					{
						std::cout << Team[character]->getName() << " missed the attack!" << endl;
					}
				}
				else {
					std::cout << "You dont have Magic Power" << endl;
					std::cout << "The Hero will do normal attack!" << endl;
					if (rand() % 100 > MonsterTeam[input - 1]->getMiss())
					{
						MonsterTeam[input - 1]->removeHealth(Team[character]->getDamage());
					}
					else
					{
						std::cout << Team[character]->getName() << " missed the attack!" << endl;
					}
				}

			}else{
				std::cout<<"You dont have any spell"<<endl;
				std::cout << "The Hero will do normal attack!"<<endl;
				if (rand() % 100 > MonsterTeam[input - 1]->getMiss())
				{
					MonsterTeam[input - 1]->removeHealth(Team[character]->getDamage());
				}
				else
				{
					std::cout << Team[character]->getName() << " missed the attack!" << endl;
				}
			}
		}
		else if (character == 1)
		{
			if(spaceSpell2 != 0){
				for(int i = 0; i < spaceSpell2; i++){
					std::cout << i + 1 << ") " <<spellInventory2[i]->getName()<<endl;
				}

				std::cout << "which spell are you going to use :";
				std::cin >> input;

				while (input < 1 || input > spaceSpell2)
				{
					std::cout << "Enter number from 1 - " << spaceSpell2 << ": ";
					std::cin >> input;
				}

				if (Team[1]->getMagicPower() > 0)
				{
					if (rand() % 100 > MonsterTeam[input - 1]->getMiss())
					{
						for (int i = 0; i < 3; i++)
						{
							if (spellInventory2[input - 1] == fireSpells[i])
							{
								MonsterTeam[input - 1]->removeHealth(spellInventory2[input - 1]->getMagicDamage() * Team[1]->getDexterity());
								Team[character]->removeMagicPower(spellInventory2[input - 1]->getMagicPower());
								MonsterTeam[input - 1]->removeDefense(5);
							}
							else if (spellInventory2[input - 1] == iceSpells[i])
							{
								MonsterTeam[input - 1]->removeHealth(spellInventory2[input - 1]->getMagicDamage() * Team[1]->getDexterity());
								Team[character]->removeMagicPower(spellInventory2[input - 1]->getMagicPower());
								MonsterTeam[input - 1]->removeDamage(10);
							}
							else if (spellInventory2[input - 1] == lightingSpells[i])
							{
								MonsterTeam[input - 1]->removeHealth(spellInventory2[input - 1]->getMagicDamage() * Team[1]->getDexterity());
								Team[character]->removeMagicPower(spellInventory2[input - 1]->getMagicPower());
								MonsterTeam[input - 1]->removeMiss(5);
							}
						}
					}
					else
					{
						std::cout << Team[character]->getName() << " missed the attack!" << endl;
					}
				}
				else {
					std::cout << "You dont have Magic Power" << endl;
					std::cout << "The Hero will do normal attack!" << endl;
					if (rand() % 100 > MonsterTeam[input - 1]->getMiss())
					{
						MonsterTeam[input - 1]->removeHealth(Team[character]->getDamage());
					}
					else
					{
						std::cout << Team[character]->getName() << " missed the attack!" << endl;
					}
				}

			}else{
				std::cout << "You dont have any spell" << endl;
				std::cout << "The Hero will do normal attack!"<<endl;
				if (rand() % 100 > MonsterTeam[input - 1]->getMiss())
				{
					MonsterTeam[input - 1]->removeHealth(Team[character]->getDamage());
				}
				else
				{
					std::cout << Team[character]->getName() << " missed the attack!" << endl;
				}
			}
		}
		else if (character == 2)
		{
			if(spaceSpell3 != 0){
				for(int i = 0; i < spaceSpell3; i++){
					std::cout << i + 1 << ") " <<spellInventory3[i]->getName()<<endl;
				}

				std::cout << "which spell are you going to use :";
				std::cin >> input;

				while (input < 1 || input > spaceSpell3)
				{
					std::cout << "Enter number from 1 - " << spaceSpell3 << ": ";
					std::cin >> input;
				}

				if (Team[2]->getMagicPower() > 0)
				{
					if (rand() % 100 > MonsterTeam[input - 1]->getMiss())
					{
						for (int i = 0; i < 3; i++)
						{
							if (spellInventory3[input - 1] == fireSpells[i])
							{
								MonsterTeam[input - 1]->removeHealth(spellInventory3[input - 1]->getMagicDamage() * Team[2]->getDexterity());
								Team[character]->removeMagicPower(spellInventory3[input - 1]->getMagicPower());
								MonsterTeam[input - 1]->removeDefense(5);
							}
							else if (spellInventory3[input - 1] == iceSpells[i])
							{
								MonsterTeam[input - 1]->removeHealth(spellInventory3[input - 1]->getMagicDamage() * Team[2]->getDexterity());
								Team[character]->removeMagicPower(spellInventory3[input - 1]->getMagicPower());
								MonsterTeam[input - 1]->removeDamage(10);
							}
							else if (spellInventory3[input - 1] == lightingSpells[i])
							{
								MonsterTeam[input - 1]->removeHealth(spellInventory3[input - 1]->getMagicDamage() * Team[2]->getDexterity());
								Team[character]->removeMagicPower(spellInventory3[input - 1]->getMagicPower());
								MonsterTeam[input - 1]->removeMiss(5);
							}
						}
						MonsterTeam[input - 1]->removeHealth(spellInventory3[input - 1]->getMagicDamage());
						Team[character]->removeMagicPower(spellInventory3[input - 1]->getMagicPower());
					}
					else
					{
						std::cout << Team[character]->getName() << " missed the attack!" << endl;
					}
				}else{
					std::cout << "You dont have Magic Power" << endl;
					std::cout << "The Hero will do normal attack!"<<endl;
					if (rand() % 100 > MonsterTeam[input - 1]->getMiss())
					{
						MonsterTeam[input - 1]->removeHealth(Team[character]->getDamage());
					}
					else
					{
						std::cout << Team[character]->getName() << " missed the attack!" << endl;
					}

				}

			}else{
				std::cout << "You dont have any spell" << endl;
				std::cout << "The Hero will do normal attack!"<<endl;
				if (rand() % 100 > MonsterTeam[input - 1]->getMiss())
				{
					MonsterTeam[input - 1]->removeHealth(Team[character]->getDamage());
				}
				else
				{
					std::cout << Team[character]->getName() << " missed the attack!" << endl;
				}
			}
		}
	}
}


void Grid::displayTeam(){

	std::cout << "\033[1;93m   ______  ______  ______  ______  ______  ______  ______  ______  ______  ______  \033[0m" << endl;
	std::cout << "\033[1;93m  |______||______||______||______||______||______||______||______||______||______| \033[0m" << endl;

	std::cout << "\033[1;95m                            _____ _____ ___ _____ _____      \033[0m" << endl;
	std::cout << "\033[1;95m                           /  ___|_   _/ _ \\_   _/  ___|             \033[0m" << endl;
	std::cout << "\033[1;95m                           \\ `--.  | |/ /_\\ \\| | \\ `--.              \033[0m" << endl;
	std::cout << "\033[1;95m                            `--. \\ | ||  _  || |  `--. \\             \033[0m" << endl;
	std::cout << "\033[1;95m                           /\\__/ / | || | | || | /\\__/ /             \033[0m" << endl;
	std::cout << "\033[1;95m                           \\____/  \\_/\\_| |_/\\_/ \\____/              \033[0m" << endl;

	std::cout << "\033[1;93m   ______  ______  ______  ______  ______  ______  ______  ______  ______  ______  \033[0m" << endl;
	std::cout << "\033[1;93m  |______||______||______||______||______||______||______||______||______||______| \033[0m" << endl << endl;

	for (int i = 0; i < NumberOfPlayers; i++)
	{
		std::cout << Team[i]->getName() << endl;
		std::cout << "=============================" << endl;
		std::cout << "Health: " << Team[i]->getHealth() << endl;
		std::cout << "Damage: " <<Team[i]->getDamage() <<  endl;
		std::cout << "Dexterity: " << Team[i]->getDexterity() << endl;
		std::cout << "Agility: " << Team[i]->getAgility() << endl;
		std::cout << "Level: " << Team[i]->getLevel() <<  endl;
		std::cout << "Magic Power: " << Team[i]->getMagicPower() << endl;
		std::cout << "=============================" << endl;

	}
}

void Grid::displayStats(Monster** p1)
{
	std::cout << "\033[1;93m   ______  ______  ______  ______  ______  ______  ______  ______  ______  ______  \033[0m" << endl;
	std::cout << "\033[1;93m  |______||______||______||______||______||______||______||______||______||______| \033[0m" << endl;

	std::cout << "\033[1;95m                            _____ _____ ___ _____ _____      \033[0m" << endl;
	std::cout << "\033[1;95m                           /  ___|_   _/ _ \\_   _/  ___|             \033[0m" << endl;
	std::cout << "\033[1;95m                           \\ `--.  | |/ /_\\ \\| | \\ `--.              \033[0m" << endl;
	std::cout << "\033[1;95m                            `--. \\ | ||  _  || |  `--. \\             \033[0m" << endl;
	std::cout << "\033[1;95m                           /\\__/ / | || | | || | /\\__/ /             \033[0m" << endl;
	std::cout << "\033[1;95m                           \\____/  \\_/\\_| |_/\\_/ \\____/              \033[0m" << endl;

	std::cout << "\033[1;93m   ______  ______  ______  ______  ______  ______  ______  ______  ______  ______  \033[0m" << endl;
	std::cout << "\033[1;93m  |______||______||______||______||______||______||______||______||______||______| \033[0m" << endl << endl;

	for (int i = 0; i < NumberOfPlayers; i++)
	{
		std::cout << Team[i]->getName() << "   ||   " << p1[i]->getName() << endl;
		std::cout << "=============================" << endl;
		std::cout << "Health: " << Team[i]->getHealth() << "       " << " Health: " << p1[i]->getHealth() << endl;
		std::cout << "Damage: " <<Team[i]->getDamage() << "       " << " Damage: " << p1[i]->getDamage() << endl;
		std::cout << "Dexterity: " << Team[i]->getDexterity() << "       " << " Defense: " << p1[i]->getDefense() << endl;
		std::cout << "Agility: " << Team[i]->getAgility() << "       " << " Agility: " << p1[i]->getMiss() << endl;
		std::cout << "Level: " << Team[i]->getLevel() << "         " << " Level: " << p1[i]->getLevel() << endl;
		std::cout << "Magic Power: " << Team[i]->getMagicPower() << endl;
		std::cout << "=============================" << endl;

	}
}

void Grid::clear_screen()
{
if (system("CLS")) system("clear");
}

	
void Grid::battle()
{
	Monster** MonsterTeam;
	MonsterTeam = new Monster *[3];
	int TeamHealth = 0;
	int Monstershealth = 0;
	int temp;
	int randmonster;
	int roundcounter = 0;
	int selection;
	int numberofenemies = NumberOfPlayers;
	int numberOfHeros= NumberOfPlayers;
	int input;

	srand(time(NULL));

	temp = Team[0]->getLevel();

	for(int i = 0; i < 3; i++){
		randmonster=rand()%3;
		if(randmonster==0){
			MonsterTeam[i]= new Dragon("Dragon", temp, 500, 150 + temp, 40 + temp, 20 + temp);
		}else if(randmonster==1){
			MonsterTeam[i]= new Exoskeleton("Exoskeleton", temp, 500, 80 + temp, 100 + temp, 20 + temp);
		}else{
			MonsterTeam[i]= new Spirit("Spirit", temp, 500, 100 + temp, 30 + temp, 60 + temp);
		}
	}


	clear_screen();
	
	std::cout << "\t\t\t!!!! LET THE BATTLE BEGIN !!!! " << endl;
	std::cout << "\033[1;34m   ______  ______  ______  ______  ______  ______  ______  ______  ______  ______  \033[0m" << endl; 
    std::cout << "\033[1;34m  |______||______||______||______||______||______||______||______||______||______| \033[0m" << endl; 

    std::cout << "\033[1;91m                   ______  ___ _____ _____ _      _____   _ _ _            \033[0m" << endl; 
    std::cout << "\033[1;91m                   | ___ \\/ _ \\_   _|_   _| |    |  ___| | | | |             \033[0m" << endl; 
    std::cout << "\033[1;91m                   | |_/ / /_\\ \\| |   | | | |    | |__   | | | |             \033[0m" << endl; 
    std::cout << "\033[1;91m                   | ___ \\  _  || |   | | | |    |  __|  | | | |             \033[0m" << endl; 
    std::cout << "\033[1;91m                   | |_/ / | | || |   | | | |____| |___  |_|_|_|             \033[0m" << endl; 
    std::cout << "\033[1;91m                   \\____/\\_| |_/\\_/   \\_/ \\_____/\\____/  (_|_|_)             \033[0m" << endl; 

    std::cout << "\033[1;34m   ______  ______  ______  ______  ______  ______  ______  ______  ______  ______  \033[0m" << endl; 
    std::cout << "\033[1;34m  |______||______||______||______||______||______||______||______||______||______| \033[0m" << endl << endl; 
	


	for (int i = 0; i < numberofenemies; i++) {
		if (MonsterTeam[i]->getHealth() > 0) {
			Monstershealth = Monstershealth + MonsterTeam[i]->getHealth();
		}
	}


	for (int i = 0; i < numberOfHeros; i++) {
		if (Team[i]->getHealth() > 0) {
			TeamHealth = TeamHealth + Team[i]->getHealth();
		}
	}


	while (TeamHealth > 0 && Monstershealth > 0) {

		roundcounter++;
		
		//clear_screen();
		std::cout << "\t\t\t=============================" << endl;
		std::cout << "\t\t\t|        ||ROUND "<< roundcounter <<"||        |" << endl;
		std::cout << "\t\t\t=============================" << endl;


		for(int i = 0; i < numberOfHeros; i++){
			
			if(Team[i]->getHealth()>0){

				Monstershealth = 0;

				for (int j = 0; j < numberofenemies; j++) {
					if(MonsterTeam[j]->getHealth()>0){
						Monstershealth = Monstershealth + MonsterTeam[j]->getHealth();
					}
				}

				if(Monstershealth>0){

					std::cout << "What will be your next move with the hero " << Team[i]->getName() <<":"<<endl;
					std::cout << "1) Attack 2) Cast Spell 3) Use Potion 4) Equip Armor/Weapon 5) Display Stats : ";
					std::cin >> selection;

					while (selection < 1 || selection > 5)
					{
						std::cout << "Enter number from 1 - 5 : ";
						std::cin >> selection;
					}

					if(selection==5){
						displayStats(MonsterTeam);
						while (selection < 1 || selection > 4)
						{
							std::cout << "1) Attack 2) Cast Spell 3) Use Potion 4) Equip Armor/Weapon : ";
							std::cout << "Enter number from 1 - 4 : ";
							std::cin >> selection;
						}
					}


					switch (selection)
					{
					case 1:
						attack(MonsterTeam, numberofenemies, i);	
						break;
					case 2:			
						castSpell(MonsterTeam, numberofenemies, i);
						
						break;
					case 3:							
						use();
						break;
					case 4:
						equip();
						break;
					}
				}
			}else{
				std::cout << Team[i]->getName() << " Is Dead!" << endl;
			}

		}

		for (int i = 0; i < numberofenemies; i++) {
			//clear_screen()
			if (MonsterTeam[i]->getHealth() > 0) {

				TeamHealth = 0;

				for (int i = 0; i < numberOfHeros; i++) {
					if (Team[i]->getHealth() > 0) {
						TeamHealth = TeamHealth + Team[i]->getHealth();
					}
				}

				if (TeamHealth > 0) {


					if (Team[0]->getHealth() > 0)
					{
						if (rand() % 100 > Team[0]->getAgility())
						{
							Team[0]->removeHealth(MonsterTeam[i]->getDamage() - Team[0]->getDefense());
							std::cout << "Hero: " << Team[0]->getName() << " Got attacked  -" << MonsterTeam[i]->getDamage() - Team[0]->getDefense() << " by " << MonsterTeam[i]->getName() << endl;
						}else{
							std::cout << MonsterTeam[i]->getName() << "missed the attack!" << endl;
						}
					}
					else if (Team[1]->getHealth() > 0)
					{
						if (rand() % 100 > Team[1]->getAgility())
						{
							Team[1]->removeHealth(MonsterTeam[i]->getDamage() - Team[1]->getDefense());
							std::cout << "Hero: " << Team[1]->getName() << " Got attacked  -" << MonsterTeam[i]->getDamage() - Team[1]->getDefense() << " by " << MonsterTeam[i]->getName() << endl;
						}else{
							std::cout << MonsterTeam[i]->getName() << "missed the attack!" << endl;
						}
					}
					else if (Team[2]->getHealth() > 0)
					{
						if (rand() % 100 > Team[2]->getAgility())
						{
							Team[2]->removeHealth(MonsterTeam[i]->getDamage() - Team[2]->getDefense());
							std::cout << "Hero: " << Team[2]->getName() << " Got attacked  -" << MonsterTeam[i]->getDamage() - Team[2]->getDefense() << " by " << MonsterTeam[i]->getName() << endl;
						}else{
							std::cout << MonsterTeam[i]->getName() << "missed the attack!" << endl;
						}
					}
				}
			}
		}



		Monstershealth = 0;

		for (int i = 0; i < numberofenemies; i++) {
			if(MonsterTeam[i]->getHealth()>0){
				Monstershealth = Monstershealth + MonsterTeam[i]->getHealth();
			}
		}

		TeamHealth = 0;

		for (int i = 0; i < numberOfHeros; i++) {
			if (Team[i]->getHealth() > 0) {
				TeamHealth = TeamHealth + Team[i]->getHealth();
			}
		}

		for (int i = 0; i < NumberOfPlayers; i++)
		{
			if (Team[i]->getHealth() > 0)
			{
				if(Team[i]->getHealth()+100 >= 1000){
					Team[i]->recoverHealth();
				}else{
					Team[i]->addHealth(100);
				}
					
				if (Team[i]->getMagicPower() + 10 >= 100)
				{
					Team[i]->recoverMagicPower();
				}
				else
				{
					Team[i]->addMagicPower(10);
				}
			}

		}
	}


	if (TeamHealth > 0)
	{

		std::cout << "\033[1;93m   ______  ______  ______  ______  ______  ______  ______  ______  ______  ______  \033[0m" << endl;
		std::cout << "\033[1;93m  |______||______||______||______||______||______||______||______||______||______| \033[0m" << endl;

		std::cout << "\033[1;92m                   _   _ _____ _____ _____ _____________   __  _ _ _     \033[0m" << endl;
		std::cout << "\033[1;92m                  | | | |_   _/  __ \\_   _|  _  | ___ \\ \\ / / | | | |             \033[0m" << endl;
		std::cout << "\033[1;92m                  | | | | | | | /  \\/ | | | | | | |_/ /\\ V /  | | | |             \033[0m" << endl;
		std::cout << "\033[1;92m                  | | | | | | | |     | | | | | |    /  \\ /   | | | |           \033[0m" << endl;
		std::cout << "\033[1;92m                  \\ \\_/ /_| |_| \\__/\\ | | \\ \\_/ / |\\ \\  | |   |_|_|_|         \033[0m" << endl;
		std::cout << "\033[1;92m                   \\___/ \\___/ \\____/ \\_/  \\___/\\_| \\_| \\_/   (_|_|_)            \033[0m" << endl;

		std::cout << "\033[1;93m   ______  ______  ______  ______  ______  ______  ______  ______  ______  ______  \033[0m" << endl;
		std::cout << "\033[1;93m  |______||______||______||______||______||______||______||______||______||______| \033[0m" << endl << endl;
		for (int i = 0; i < NumberOfPlayers; i++)
		{
			Team[i]->recoverHealth();
			Team[i]->addMoney(100 * NumberOfPlayers * Team[i]->getLevel());
			Team[i]->checkXP(50 * NumberOfPlayers * Team[i]->getLevel());
		}
	}
	else
	{
		std::cout << "\033[1;93m   ______  ______  ______  ______  ______  ______  ______  ______  ______  ______  \033[0m" << endl;
		std::cout << "\033[1;93m  |______||______||______||______||______||______||______||______||______||______| \033[0m" << endl;

		std::cout << "\033[1;91m                    ______ ___________ _____  ___ _____      \033[0m" << endl;
		std::cout << "\033[1;91m                    |  _  \\  ___|  ___|  ___|/ _ \\_   _|             \033[0m" << endl;
		std::cout << "\033[1;91m                    | | | | |__ | |_  | |__ / /_\\ \\| |              \033[0m" << endl;
		std::cout << "\033[1;91m                    | | | |  __||  _| |  __||  _  || |             \033[0m" << endl;
		std::cout << "\033[1;91m                    | |/ /| |___| |   | |___| | | || |           \033[0m" << endl;
		std::cout << "\033[1;91m                    |___/ \\____/\\_|   \\____/\\_| |_/\\_/              \033[0m" << endl;

		std::cout << "\033[1;93m   ______  ______  ______  ______  ______  ______  ______  ______  ______  ______  \033[0m" << endl;
		std::cout << "\033[1;93m  |______||______||______||______||______||______||______||______||______||______| \033[0m" << endl << endl;
		for (int i = 0; i < NumberOfPlayers; i++)
		{
			Team[i]->recoverHealth();
			Team[i]->removeMoney(Team[i]->getMoney() / 2);
		}
	}
		


	
	for(int i = 0; i < 3; i++){
		delete MonsterTeam[i];
	}
	delete[] MonsterTeam;
}

void Grid::StartGame()
{
	clear_screen();
	std::cout << "\033[1;91m   ______  ______  ______  ______  ______  ______  ______  ______  ______  ______  \033[0m" << endl; 
    std::cout << "\033[1;91m  |______||______||______||______||______||______||______||______||______||______| \033[0m" << endl; 

    std::cout << "\033[1;94m		 _____ _             _     _____                       \033[0m" << endl; 
    std::cout << "\033[1;94m		/  ___| |           | |   |  __ \\                      \033[0m" << endl; 
    std::cout << "\033[1;94m		\\ `--.| |_ __ _ _ __| |_  | |  \\/ __ _ _ __ ___   ___  \033[0m" << endl; 
    std::cout << "\033[1;94m		 `--. \\ __/ _` | '__| __| | | __ / _` | '_ ` _ \\ / _ \\  \033[0m" << endl; 
	std::cout << "\033[1;94m		/\\__/ / || (_| | |  | |_  | |_\\ \\ (_| | | | | | |  __/ \033[0m" << endl; 
    std::cout << "\033[1;94m		\\____/ \\__\\__,_|_|   \\__|  \\____/\\__,_|_| |_| |_|\\___| \033[0m" << endl;  

    std::cout << "\033[1;91m   ______  ______  ______  ______  ______  ______  ______  ______  ______  ______  \033[0m" << endl; 
    std::cout << "\033[1;91m  |______||______||______||______||______||______||______||______||______||______| \033[0m" << endl << endl; 
	std::cout << "Press Enter to Continue: ";
	std::cin.get();
	clear_screen();

	
	std::cout<<"Choose number of team players 1-3 : "<<endl;
	std::cin >> NumberOfPlayers;

	while (NumberOfPlayers < 1 || NumberOfPlayers > 3)
	{
		std::cout << "Choose number of team players 1-3 : " << endl;
		std::cin >> NumberOfPlayers;
	}

	clear_screen();

	displayMap();
	char input=0;
	while (input!='7')
	{
		std::cout << "1) Move 2) Check Inventory 3) Equip 4) Use 5) Display Stats 6) Display Map 7) Quit Game: " << endl;
		std::cin >> input;

		
		clear_screen();
		

		switch(input){
			case '1':

				char ch;
				std::cout << "u) up d) down l) left r) right c) cancel:  "<<endl;
				std::cin >> ch;
				while (ch != 'c'&& ch != 'u'&& ch != 'd'&& ch != 'l'&& ch != 'r')
				{	
					clear_screen();
					std::cout << "Wrong input! Try again"<<endl;
					std::cout << "u) up d) down l) left r) right c) cancel:  " << endl;
					std::cin >> ch;
				}
				move(ch);
			break;
			case '2':
				checkInventory();
			break;
			case '3':
				equip();
			break;
			case '4':
				use();
			break;
			case '5':
				displayTeam();
			break;
			case '6':
				displayMap();
			break;
			case '7':
				int vag;
				std::cout << "Are you sure you want to quit game 1) Yes 2) No: " << endl;
				std::cin >> vag;
				while (vag!=1 && vag!=2)
				{
					std::cout << "Wrong input! Try again"<<endl;
					std::cout << "Are you sure you want to quit game 1) Yes 2) No: " << endl;
					std::cin >> vag;
				}

				if (vag == 1)
				{
					break;
				}else{
					input=0;
				}
			break;
		}
	}
}

Grid::~Grid()
{
	//std::cout << "Deleting Grid....." << endl;
}
