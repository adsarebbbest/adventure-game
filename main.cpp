#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

class Goblin {
  public:
    int damage = 3;
    int health = 6;
    int coins = 4;
    int healingPotion = 1;
};

class Zombie {
  public:
    int damage = 2;
    int health = 8;
    int coins = 3;
};

class Crocodile {
  public:
    int damage = 5;
    int health = 10;
    int coins = 8;
};

class Colors {
  public:
    const string reset = "\033[0m";
    const string black = "\033[30m";
    const string red = "\033[31m";
    const string green = "\033[32m";
    const string yellow = "\033[33m";
    const string blue = "\033[34m";
    const string magenta = "\033[35m";
    const string cyan = "\033[36m";
    const string white = "\033[37m";
};

int main() {
  Colors colors;
  string pause;
  int healingPotions = 0;
  int coins = 0;
  int health = 100;
  int damage = 2;
  string weapon;
  string userName;
  cout << colors.yellow << "Enter a username\n>" << colors.reset;
  cin >> userName;
  while(true) {
    if(health <= 0) {
      cout << colors.red << "You died" << colors.reset << endl;
      exit(0);
    }
    if(weapon == "woodenSword") {
      damage = 3;
    } else if(weapon == "stoneSword") {
      damage = 4;
    } else if(weapon == "ironSword") {
      damage = 5;
    } else if(weapon == "diamondSword") {
      damage = 9;
    }
    string place;
    int enemy;
    int choice;
    system("clear");
    cout << colors.cyan << "Hello " << userName << colors.reset << endl;
    cout << colors.green << "Health: " << health << colors.reset << endl;
    cout << colors.red << "Damage: " << damage << colors.reset << endl;
    cout << colors.yellow << "Coins: " << coins << colors.reset << endl;
    cout << colors.red << "Healing potions: " << healingPotions << colors.reset << endl;
    cout << colors.yellow << "[1] Shop\n[2] Fight\n[3] Use healing potion\n>" << colors.reset << flush;
    cin >> choice;
    system("clear");
    switch(choice) {
      case 1:
        int shopChoice;
        place = "shop";
        cout << colors.yellow << "[1] Wooden sword: FREE\n[2] Stone Sword: 10 Coins\n[3] Iron sword: 50 Coins\n[4] Shield: 20 coins: reduces the amount of damage by 2" << colors.reset << endl;
        cin >> shopChoice;
        if(shopChoice == 1) {
          if(weapon == "woodenSword") {
            cout << colors.red << "You already equipped this" << colors.reset << endl;
            cin >> pause;
          } else {
            weapon = "woodenSword";
            cout << colors.green << "You have equipped a wooden sword" << colors.reset << endl;
            cin >> pause;
          }
        } 
        if(shopChoice == 2 && coins >= 10) {
          if(weapon == "stoneSword") {
            cout << colors.red <<  "You already equipped this" << colors.reset << endl;
            cin >> pause;
          } else {
            weapon = "stoneSword";
            cout << colors.green << "You have equipped a stone sword" << colors.reset << endl;
            cin >> pause;
          }
        } else if(shopChoice == 2 && coins <= 10) {
          cout << colors.yellow << "You don't have enough coins for this" << colors.reset << endl;
          cin >> pause;
        } else if(shopChoice == 3 && coins >= 50) {
          if(weapon == "ironSword") {
            cout << colors.red << "You already equipped this" << colors.reset << endl;
            cin >> pause;
          } else {
            weapon = "ironSword";
            cout << colors.green << "You have equipped an iron sword" << colors.reset << endl;
            cin >> pause;
          }

        } else if(shopChoice == 3 && coins <= 50) {
          cout << colors.yellow << "You don't have enough coins for this" << colors.reset << endl;
          cin >> pause;
        } else if(shopChoice == 4 && coins <= 20) {

        }
    
        break;
      case 2:
        place = "battle";
        cout << colors.cyan << "choose an enemie: [1] Goblin: [2] Zombie: [3] Crocodile\n>" << colors.reset;
        cin >> enemy;
        system("clear");
        if(enemy == 1) {
          bool gameRunning = true;
          int battleChoice;
          Goblin goblin;
          system("clear");
          while(gameRunning) {
            cout << colors.red <<  "You find yourself in a dungeon. You look around and see a goblin" << colors.reset << endl;
            cout << colors.cyan << "[1] Attack\n[2] Run\n>" << colors.reset;
            cin >> battleChoice;
            switch(battleChoice) {
              case 1:
                goblin.health -= damage;
                cout << colors.green <<  "You dealt " << damage << " damage to the goblin, leaving it at " << goblin.health << " health" << colors.reset << endl;
                health -= goblin.damage;
                cout << colors.red << "The goblin dealt " << goblin.damage << " damage to you, leaving you at " << health << " health" << colors.reset << endl;
                if(goblin.health <= 0) {
                  gameRunning = false;
                }
                if(health <= 0) {
                  cout << colors.red << "You died" << colors.reset << endl;
                  exit(0);
                }
                break;
              case 2:
                cout << colors.cyan << "You ran away, causing you to lose 2 health" << colors.reset << endl;
                health -= 2;
                gameRunning = false;
                cin >> pause;
                break;
              default:
                cout << colors.cyan << "You tripped and ran away, causing you to lose 2 health" << colors.reset << endl;
                health -= 2;
                gameRunning = false;
                cin >> pause;
            }
          }
          cout << colors.yellow << "You killed the goblin, giving you " << goblin.coins << " coins AND a healing potion woah" << colors.reset << endl;
          coins += goblin.coins;
          healingPotions += goblin.healingPotion;
          cin >> pause;
        } else if(enemy == 2) {
            int battleChoice;
            bool gameRunning = true;
            Zombie zombie;
            system("clear");
            while(gameRunning) {
              
              cout << colors.green << "You find yourself in a city. You look around and see a zombie" << colors.reset << endl;
              cout << colors.cyan << "[1] Attack\n[2] Run\n>" << colors.reset;
              cin >> battleChoice;
              switch(battleChoice) {
                case 1:
                  zombie.health -= damage;
                  cout << colors.green << "You dealt " << damage << " damage to the zombie, leaving it at " << zombie.health << " health" << colors.reset << endl;
                  health -= zombie.damage;
                  cout << colors.red << "The zombie dealt" << zombie.damage << " damage to you leaving you at " << health << " health" << colors.reset << endl;
                  if(zombie.health <= 0 || health <= 0) {
                    gameRunning = false;
                  }
                  if(health <= 0) {
                    cout << colors.red << "You died" << colors.reset << endl;
                    exit(0);
                  }
                  break;
                case 2:
                  cout << colors.cyan << "You ran away, causing you to lose 2 health" << colors.reset << endl;
                  health -= 2;
                  break;
                default:
                  cout << colors.cyan << "You tripped and ran away, causing you to lose 2 health" << colors.reset << endl;
                  health -= 2;
                  gameRunning = false;
                  cin >> pause;
                  break;
            }
          }
          coins += zombie.coins;
          cout << colors.yellow << "You killed the zombie, giving you " << zombie.coins << "coins" << colors.reset << endl;
          cin >> pause;
        } else if(enemy == 3) {
          int battleChoice;
          bool gameRunning = true;
          
          Crocodile crocodile;
          system("clear");
          while(gameRunning) {
            
            cout << colors.green << "You find yourself in a swamp. You look around and see a crocodile" << colors.reset << endl;
            cout << colors.cyan << "[1] Attack\n[2] Run\n>" << colors.reset;
            cin >> battleChoice;
            switch(battleChoice) {
              case 1:
                  crocodile.health -= damage;
                  cout << colors.green << "You dealt " << damage << " damage to the crocodile, leaving it at " << crocodile.health << " health" << colors.reset << endl;
                  health -= crocodile.damage;
                  cout << colors.red << "The crocodile dealt " << crocodile.damage << " damage to you leaving you at " << health << " health" << colors.reset << endl;
                  if(crocodile.health <= 0) {
                    gameRunning = false;
                  }
                  if(health <= 0) {
                    cout << colors.red << "You died" << colors.reset << endl;
                    exit(0);
                  }
                  break;
              case 2:
                cout << colors.cyan << "You ran away, costing you to lose 2 health" << colors.reset << endl;
                health -= 2;
                gameRunning = false;
                break;
              default:
                cout << colors.cyan << "You tripped and ran away, costing you to lose 2 health" << colors.reset << endl;
                health -= 2;
                gameRunning = false;
                cin >> pause;
                break;
            }
          }
          cout << colors.yellow << "You killed the crocodile, giving you " << crocodile.coins << " coins" << colors.reset << endl;
          coins += crocodile.coins;
          cin >> pause;
        } else {
          cout << colors.cyan << "That is not a valid choice" << colors.reset << endl;
          cout << colors.cyan << "You tripped and ran away, which costed you 2 health" << colors.reset << endl;
          health -= 2;
        }
        break;
      case 3:
        if(healingPotions >= 1) {
          cout << colors.blue << "You used your healing potion and you gained 8 health" << colors.reset << endl;
          health += 8;
          healingPotions -= 1;
          cin >> pause; 
        } else {
          cout << colors.red << "You don't have a healing potion" << colors.reset << endl;
          cin >> pause;
        }
        break;
      default:
        cout << colors.red << "Make a choice" << colors.reset << endl;
        cin >> pause;
        break;
    }
    system("clear");
  }
  return 0;
}