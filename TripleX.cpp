#include <iostream>
#include <ctime>

void PrintIntroduction (int Difficulty)
{
    std::cout << "\n\nYou are on board of the Death Star! You are breaking into a level "<< Difficulty << " security server \n";
    std::cout << "You need to enter the correct codes so you can free Princes Leia.\n";
}

bool PlayGame (int Difficulty)
{
    PrintIntroduction (Difficulty);
    
    //Declare three number code.
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    //Print sum and product.
    std::cout << std::endl;
    std::cout << "There are three digits in the code\n" ;
    std::cout << "The codes add up to: " << CodeSum << "\n";
    std::cout << "The codes multiply to give: " << CodeProduct << "\n";
    
    //Store the value that user enters.
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;
    
    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    //Check if the players guess is correct.
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        if (Difficulty < 5)
        {
        std::cout << "You entered a correct code you now proceed onto a next level!\n";
        }
        return true;
    }
    else
    {
        std::cout << "The code is wrong, try again.\n";
        return false;
    }
}

int main () 
{
    srand(time(NULL));
    const int MaxLevel = 5;
    int LevelDifficulty = 1;
    while (LevelDifficulty <= MaxLevel) //Loop the game until all levels are complete
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); //Clears any errors
        std::cin.ignore(); //Discards the buffer

        if (bLevelComplete)    
        {
            ++LevelDifficulty;
        }
    }
    
    std::cout << "\n ***Congratulations you saved Princess Leia!!***";
    return 0;
}