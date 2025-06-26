#include <iostream>
#include <string>
#include <limits>
#include <random>
#include <cctype>

int getRandomNumber(int min, int max)
{
    if (min > max)
    {
        int temp = min;
        min = max;
        max = temp;
    }
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(min, max);
    return distrib(gen);
}

class Creature
{
protected:
    std::string m_name;
    char m_symbol;
    int  m_health;
    int  m_damage;
    int  m_gold;

public:
    Creature(std::string name, char symbol, int health, int damage, int gold)
        : m_name(name), m_symbol(symbol), m_health(health), m_damage(damage), m_gold(gold)
    {
    }

    std::string getName() const { return m_name; }
    char getSymbol() const { return m_symbol; }
    int  getHealth() const { return m_health; }
    int  getDamage() const { return m_damage; }
    int  getGold() const { return m_gold; }

    void reduceHealth(int quantity) { m_health -= quantity; }
    bool isDead() const { return m_health <= 0; }
    void addGold(int quantity) { m_gold += quantity; }
};

class Player : public Creature
{
private:
    int m_level = 1;

public:
    Player(std::string name)
        : Creature(name, '@', 10, 1, 0)
    {
    }

    int getLevel() const { return m_level; }
    void levelUp() { ++m_level; ++m_damage; }
    bool hasWon() const { return m_level >= 20; }
};

class Monster : public Creature
{
public:
    enum Type
    {
        DRAGON,
        ORC,
        SLIME,
        MAX_TYPES
    };

    struct MonsterData
    {
        std::string name;
        char symbol;
        int health;
        int damage;
        int gold;
    };

    static MonsterData monsterData[MAX_TYPES];

    Monster(Type type)
        : Creature(monsterData[type].name, monsterData[type].symbol,
            monsterData[type].health, monsterData[type].damage,
            monsterData[type].gold)
    {
    }

    static Monster getRandomMonster()
    {
        return Monster(static_cast<Type>(getRandomNumber(0, MAX_TYPES - 1)));
    }
};

Monster::MonsterData Monster::monsterData[Monster::MAX_TYPES] =
{
    { "dragon", 'D', 20, 4, 100 },
    { "orc", 'o', 4, 2, 25 },
    { "slime", 's', 1, 1, 10 }
};

bool attackMonster(Player& p, Monster& m)
{
    m.reduceHealth(p.getDamage());
    std::cout << "You hit the " << m.getName() << " for " << p.getDamage() << " damage.\n";

    if (m.isDead())
    {
        std::cout << "You killed the " << m.getName() << ".\n";
        p.addGold(m.getGold());
        p.levelUp();
        return true;
    }
    return false;
}

bool attackPlayer(Player& p, Monster& m)
{
    p.reduceHealth(m.getDamage());
    std::cout << "The " << m.getName() << " hit you for " << m.getDamage() << " damage.\n";
    return p.isDead();
}

char fightMonster()
{
    char choice;
    do
    {
        std::cout << "(R)un or (F)ight: ";
        std::cin >> choice;
        choice = tolower(choice);

        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    } while (choice != 'r' && choice != 'f');

    return choice;
}

void playGame()
{
    std::cout << "Enter your name: ";
    std::string playerName;
    std::cin >> playerName;

    Player p(playerName);
    std::cout << "Welcome, " << p.getName() << ".\n";

    Monster m = Monster::getRandomMonster();

    while (true)
    {
        std::cout << "\nYou have encountered a " << m.getName() << " (" << m.getSymbol() << ").\n";
        std::cout << "HP: " << p.getHealth() << " | Level: " << p.getLevel()
            << " | Gold: " << p.getGold() << "\n";

        char choice = fightMonster();

        if (choice == 'f')
        {
            if (attackMonster(p, m))
            {
                if (p.hasWon())
                {
                    std::cout << "\nYou win the game!\n";
                    return;
                }
                m = Monster::getRandomMonster();
            }
            else if (attackPlayer(p, m))
            {
                std::cout << "\nYou died at level " << p.getLevel()
                    << " and with " << p.getGold() << " gold.\n";
                return;
            }
        }
        else
        {
            if (getRandomNumber(0, 1))
            {
                std::cout << "You successfully fled.\n";
                m = Monster::getRandomMonster();
            }
            else
            {
                std::cout << "You failed to flee!\n";
                if (attackPlayer(p, m))
                {
                    std::cout << "\nYou died at level " << p.getLevel()
                        << " and with " << p.getGold() << " gold.\n";
                    return;
                }
            }
        }
    }
}

int main()
{
    std::cout << "=== MONSTER BATTLE GAME ===\n";

    while (true)
    {
        playGame();

        char choice;
        do
        {
            std::cout << "\nPlay again? (y/n): ";
            std::cin >> choice;
            choice = tolower(choice);

            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        } while (choice != 'y' && choice != 'n');

        if (choice == 'n')
            break;
    }

    std::cout << "\nThanks for playing!\n";
    return 0;
}