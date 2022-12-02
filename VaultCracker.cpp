/*Author: Gideon Tladi
Date: 14/01/2022
Title: Vault Cracker game
Description: This is a modified version of the TripleX game created by the GameDev.tv Team. 
             You can find the original game in their Unreal Engine C++ Developer course on Udemy*/

#include <iostream>
#include <ctime> //This allows you to use the computer's time

void PrintIntroduction()
{
     // Print welcome message to the terminal.
    std::cout << "\n--------------V4ULT CR4CK3R--------------";
    std::cout << "\nDo you have what it takes to crack open a randomly-coded vault? Test your skills with this math-based game!\n";
    
    std::cout << "\n~~~~~STORY: ~~~~~\n";
    std::cout << "You are a mathematician on a field trip with an archaeologist. While excavating, your shovel hits the door of a large vault.\n";
    std::cout << "Your friend decodes the enscriptions on it, some of which translate as follows: \n";
    std::cout << "\n=====WE HID THE EVIDENCE WHERE NO ONE CAN FIND IT...=====\n\n"; 
    std::cout << "She also decoded that the vault contains a few scrolls.";
    std::cout << "Wondering what the riddle means, your curiosity gets the better of you.";
    std::cout << "Using your math skills, you decide to crack open the vault...\n"; 
    
    std::cout << "\n~~~~~RULES OF THE GAME: ~~~~~\n";
    std::cout << "--> The vault has 5 locks, which are represented by 5 levels in the game. \n";
    std::cout << "--> Guess the correct codes to unlock each level until you win the game. \n"; 
    std::cout << "--> If you fail to get the correct answer, you can use a hint. If you don't use the hint, the game will restart!\n";
    std::cout << "--> You are only allowed to enter the single digits 1 up to 9. Negative numbers, 0, and numbers greater than 10 are NOT allowed.\n";
    std::cout << "Good luck...\n";
}

void PrintGameDifficulty(int Difficulty)
{
    std::cout << "\n--$--$--LEVEL " << Difficulty << " --$--$--";
}

bool PlayGame(int Difficulty)
{
    PrintGameDifficulty(Difficulty);

    // Declare random 3-number code
    const int CodeA = rand() % Difficulty + Difficulty;
    const int CodeB = rand() % Difficulty + Difficulty;
    const int CodeC = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    // Print sum & product to the terminal
    std::cout << "\nThere are 3 digits in the code.";
    std::cout << "\n(+) The digits add up to: " << CodeSum;
    std::cout << "\n(*) The digits multiply to give: " << CodeProduct;
   
   // Declare 3-number guess
    int GuessA, GuessB, GuessC;

    // Player enters 3-number guess
    std::cout << "\n\nUse the format (1ST DIGIT -space- 2ND DIGIT -space- 3RD DIGIT) to enter your code.\n";

    std::cout << "Enter the code here: ";
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;
    
    // Check if the player's 1st guess is correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\n*** Correct! Move on to the next lock. ***\n";
        return true;
    }
    else
    {
        std::cout << "\n*** Wrong! The lock makes an awful sound. *** \n";
        
        // Give player 2nd chance to answer the question
        std::cout << "\n-------DO YOU WANT A HINT?-------";
        std::cout << "\nEnter 'y' for Yes or 'n' for No: ";

        char Hint;
        const char Yes = 'y';
        const char No = 'n';

        std::cin >> Hint;

        if (Hint == Yes)
        {
            std::cout << "\n\nOkay, here's a hint. One of the digits is: " << CodeA << "\n";
            std::cout << "\n-------LAST CHANCE! TRY AGAIN!-------\n";

            PrintGameDifficulty(Difficulty);

            // Print sum & product to the terminal
            std::cout << "\nThere are 3 digits in the code.";
            std::cout << "\n(+) The digits add up to: " << CodeSum;
            std::cout << "\n(*) The digits multiply to give: " << CodeProduct;

            // Player enters 3-number guess
            std::cout << "\n\nUse the format (1ST DIGIT -space- 2ND DIGIT -space- 3RD DIGIT) to enter your code.\n";

            std::cout << "Enter the code here: ";
            std::cin >> GuessA >> GuessB >> GuessC;

            // Check if the player's guess is correct
            if (GuessSum == CodeSum && GuessProduct == CodeProduct)
            {
                std::cout << "\n*** Correct! Move on to the next lock. ***\n";
                return true;
            }
            else
            {
                std::cout << "\nYou failed to unlock the vault.";
                std::cout << "\n-------GAME OVER! YOU LOSE!-------\n";
                return false;
            }
        }
        else if(Hint == No)
        {
            std::cout << "\nYou failed to unlock the vault.";
            std::cout << "\n-------GAME OVER! YOU LOSE!-------\n";
        }
        return false;
    }
}

int main() 
{
    PrintIntroduction();

    //I want a "PRESS ENTER TO START PLAYING THE GAME" sequence after the intro, before I start playing the game...

    srand(time(NULL)); //Creates new random sequence based on the time of the day

    int LevelDifficulty = 1;
    int const MaxDifficulty = 5;

    while (LevelDifficulty <= MaxDifficulty) //Loop the game until all levels have been completed.
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear(); //Clears any errors
        std::cin.ignore(); //Discards the buffer

        if (bLevelComplete) 
        {
            ++LevelDifficulty; // Increase the level difficulty
        }
        else 
        {
            LevelDifficulty = 1;
        }
    }

    std::cout << "\n-------CONGRATULATIONS! YOU WON THE GAME!-------\n";

    std::cout << "\n~~~~~ENDING: ~~~~~\n";
    std::cout << "After carefully calculating and entering each code, you finally unlocked the vault!\n";
    std::cout << "Your archaeologist friend carefully picks up and unwraps each scroll. All the scrolls but one are blank.\n";
    std::cout << "She decodes the single line on the scroll. It reads:\n";
    std::cout << "=====...INSIDE OUR STOMACHS!=====\n";
    
    return 0;
}