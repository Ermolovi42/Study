#include <iostream>
#include <string>
#include <cstdint>
#include <algorithm>
#include <vector>
#include <array>  
#include <ctime>
#include <cstdlib>

enum ADVANTAGES
{
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACKS,
    LADY,
    KING,
    ACE,
    MAX_ADV,
};

enum SUIT
{
    TREFU,
    BYBNU,
    CHERVU,
    PIKI,
    SUIT_MAX,
};

struct Cart
{
    ADVANTAGES rank;
    SUIT       suit;
};

void PrintCart(const Cart& card)
{
    switch (card.rank)
    {
    case ADVANTAGES::TWO:     std::cout << "2"; break;
    case ADVANTAGES::THREE:   std::cout << "3"; break;
    case ADVANTAGES::FOUR:    std::cout << "4"; break;
    case ADVANTAGES::FIVE:    std::cout << "5"; break;
    case ADVANTAGES::SIX:     std::cout << "6"; break;
    case ADVANTAGES::SEVEN:   std::cout << "7"; break;
    case ADVANTAGES::EIGHT:   std::cout << "8"; break;
    case ADVANTAGES::NINE:    std::cout << "9"; break;
    case ADVANTAGES::TEN:     std::cout << "T"; break;
    case ADVANTAGES::JACKS:   std::cout << "J"; break;  
    case ADVANTAGES::LADY:    std::cout << "Q"; break;  
    case ADVANTAGES::KING:    std::cout << "K"; break;
    case ADVANTAGES::ACE:     std::cout << "A"; break;  
    }

    switch (card.suit)
    {
    case SUIT::TREFU:  std::cout << "T ";
        break;
    case SUIT::BYBNU:  std::cout << "B ";
        break;
    case SUIT::PIKI:   std::cout << "P ";
        break;
    case SUIT::CHERVU: std::cout << "C ";  
    }
}

void printDeck(const std::array<Cart, 52>& deck)
{
    for (Cart value : deck)
    {
        PrintCart(value);
        std::cout << " ";
    }
    std::cout << '\n';
}

void SwapCart(Cart &cart1, Cart &cart2)
{
    Cart popa = cart1;
    cart1 = cart2;
    cart2 = popa;
}

int getRandomNum(int min, int max)
{
    int randomNum = std::rand() % (max - min + 1) + min;
    return randomNum;
}

void ShuffDeck(std::array<Cart, 52> &deck)
{
    
    for (int value{ 0 }; value < 52; value++)
    {
        SwapCart(deck[value], deck[getRandomNum(0, 51)]);
    }
}

int getCardValue(const Cart& card)
{
    switch (card.rank)
    {
    case ADVANTAGES::TWO:     return 2;
    case ADVANTAGES::THREE:   return 3;
    case ADVANTAGES::FOUR:    return 4;
    case ADVANTAGES::FIVE:    return 5;
    case ADVANTAGES::SIX:     return 6;
    case ADVANTAGES::SEVEN:   return 7;
    case ADVANTAGES::EIGHT:   return 8;
    case ADVANTAGES::NINE:    return 9;
    case ADVANTAGES::TEN:     return 10;
    case ADVANTAGES::JACKS:   return 10;
    case ADVANTAGES::LADY:    return 10;
    case ADVANTAGES::KING:    return 10;
    case ADVANTAGES::ACE:     return 11;
    }

    return 0;
}

bool playBlackjack(std::array<Cart, 52> deck)
{

    ShuffDeck(deck);

    int diller{ 0 };
    int player{ 0 };

    const Cart* cartPtr = &deck[0];

    for (int count{ 0 }; count < 52; count++)
    {
        std::cout << "round #" << count + 1 << std::endl; 

        if (diller < 17)
        {
            diller += getCardValue(*cartPtr);
            cartPtr++;
        }

        if (diller > 21)
        {
            return true;
        }
        if (diller == 21)
        {
            return false;
        }


        std::cout << "diller :" << diller << std::endl;

        std::cout << "player :" << player << '\n' << std::endl;

        std::cout << "the card :" << getCardValue(*cartPtr) << std::endl;

        std::string choos{};
        std::cout << "do you want hit or stand ?(h/s) :";
        std::cin >> choos;

        if (player > 21)
        {
            return false;
        }
        if (player == 21)
        {
            return true;
        }

        
       
        if (choos == "h")
        {
            player += getCardValue(*cartPtr);
            cartPtr++;
        }

        if (choos == "s" && player > diller)
            return true;

        if (choos == "s" && player < diller)
            return false;
            
           
    }
}

int main()
{
    std::srand(static_cast<int>(std::time(NULL)));
    std::rand();

    std::array<Cart, 52> Deck;

    int cart{ 0 };
    for (int mast = 0; mast < SUIT_MAX; mast++)
    {
        for (int adv = 0; adv < MAX_ADV; adv++)
        {
            Deck[cart].suit = static_cast<SUIT>(mast);
            Deck[cart].rank = static_cast<ADVANTAGES>(adv);
            cart++;
        }
    }
    int  game = playBlackjack(Deck);
    
    if (game)
    {
        std::cout << "you win";
    }
    else
        std::cout << "you lose";

    return 0;
}





