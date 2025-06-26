#include <iostream>
#include <random>

int getRandomNumber(int min, int max) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(min, max);
    return distrib(gen);
}
int main() 
{
    PlayAgain:

    int myNumber { getRandomNumber(0, 100) };
    std::cout << "lets play a game. I thinking of a number. You have 7 attempt to guess what it is \n";
    bool FlagForAttempt{ true };

    for (int i{ 1 }; i < 8; ++i) 
    {
        std::cout << "attempt #" << i << std::endl;
        int number;
        std::cin >> number;
        if (number > myNumber)
        {
            std::cout << "Your guest is too high" << std::endl;
            continue;
        }
        if (number < myNumber) {
            std::cout << "Your guest is too low" << std::endl;
            continue;
        }
        if (number == myNumber) {
            std::cout << "Correct! You win!" << std::endl;
            FlagForAttempt = false;
            break;
        }
    }
    if (FlagForAttempt)
        std::cout << "Sorry. You lose (" << std::endl;

    char choos;
    while (true)
    {
        std::cout << "Do you wont play again (y/n)?" << std::endl;
        std::cin >> choos;

        if (std::cin.fail()) 
        {
            std::cin.clear();
            int MaxValueInCin{ 32767 };
            std::cin.ignore(MaxValueInCin, '\n');
            continue;
        }
        else if (choos == 'y' || choos == 'n')
        {
            if (choos == 'y')
                goto PlayAgain;
            else
                std::cout << "OK, good luck )" << std::endl;
            break;
        }
        else
            continue;
    }
}