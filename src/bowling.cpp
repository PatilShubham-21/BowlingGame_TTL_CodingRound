#include "inc/bowling.h"

Bowling::Bowling()
{
    scores.resize(1);
}

bool Bowling::processInput()
{
    std::cout << "\n *** WELCOME TO BOWLING GAME ***" << std::endl;
    std::cout << " A. You have to Enter scores for total 10 round, Each Round has";
    std::cout << " 2 balls to throw." << std::endl;
    std::cout << " B. Max you can score 10 points in 2 throws." << std::endl;
    std::cout << " C. If in one of round's first throw itself if you score 10"; 
    std::cout << " points, application will skip input for 2nd throw, and goes";
    std::cout << " to next round" << std::endl;
    std::cout << " D. Consecutive 3 wrong input will exits from application,";
    std::cout << " you have to start from beigining." << std::endl;

    std::cout << "\n\n **** Let's start to Play ***" << std::endl;

    int input = 0;
    for(int i = 0; i < 10; i++)
    {
        for(int j = 0; j < 2; j++)
        {
            if(j == 1 && input == 10)
            {
                scores[i][j] = 0;
                break;
            }

            std::cout << "Round " << i+1 << "Throw " << j+1 << " : ";
            cin >> input;

            if(input > 10)
            {
                cout << "Wrong Input...! Value must be below 10" << std::endl;
                return false;
            }
            else if(j == 1 && (scores[i][j-1] + input > 10))
            {
                cout << "Wrong Input...! Value must be below OR equal to " << (10 - scores[i][j-1]) << std::endl;
                return false;
            }
            else
            {
                scores[i][j] = input;
            }
        }
    }
    
    return true;
}

int Bowling::calculateScore()
{
    int total = 0;

    for(int i = 0; i < 10; i++)
    {
        if(scores[i][0] == 10)
        {
            total += 10 + 
        }
    }
}