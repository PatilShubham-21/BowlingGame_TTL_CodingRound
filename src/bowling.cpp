#include "../inc/bowling.h"
#include <limits>

Bowling::Bowling()
{
}

void Bowling::processInput()
{
    std::cout << "\n *** WELCOME TO BOWLING GAME ***" << std::endl;
    std::cout << " A. You have to Enter scores for total 10 round, Each Round";
    std::cout << " has 2 balls to throw." << std::endl;
    std::cout << " B. Max you can score 10 points in 2 throws." << std::endl;
    std::cout << " C. If in one of round's first throw itself if you score 10";
    std::cout << " points, application will skip input for 2nd throw, and goes";
    std::cout << " to next round" << std::endl;

    std::cout << "\n\n **** Let's start to Play ***" << std::endl;

    // Inputs for 1 to 9 round
    for (int i = 0; i < 9; i++)
    {
        std::vector<int> throws;
        int input = 0;
        bool valid = false;

        for (int j = 0; j < 2; j++)
        {
            valid = false;
            if (j == 1 && throws[j - 1] == 10)
            {
                throws.push_back(0);
                break;
            }

            while (!valid)
            {
                std::cout << "Round " << i + 1 << " Throw " << j + 1 << " : ";
                std::cout << std::flush;
                std::cin >> input;

                if (!std::cin.good())
                {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                                    '\n');
                    std::cout << "Wrong Input...! Value must be between 0 to ";
                    std::cout << "10. Please Enter Again...!" << std::endl;
                }
                else if (input > 10)
                {
                    std::cout << "Wrong Input...! Value must be between 0 to ";
                    std::cout << "10. Please Enter Again...!" << std::endl;
                }
                else if (j == 1 && (throws[j - 1] + input > 10))
                {
                    std::cout << "Wrong Input...! Value must be between 0 to ";
                    std::cout << (10 - throws[j - 1]) << ".";
                    std::cout << " Please Enter Again...!" << std::endl;
                }
                else
                {
                    valid = true;
                    throws.push_back(input);
                }
            }
        }
        scores.push_back({throws[0], throws[1]});
    }

    // Inputes for 10th Round

    std::vector<int> throws;
    int input = 0;
    bool spark = false;

    for (int j = 0; j < 3; j++)
    {
        bool valid = false;
        while (!valid)
        {
            std::cout << "Round 10 Throw " << j + 1 << " : " << std::flush;
            std::cin >> input;

            if (!std::cin.good())
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(),
                                '\n');
                std::cout << "Wrong Input...! Value must be between 0 to ";
                std::cout << "10. Please Enter Again...!" << std::endl;
            }
            else if (input > 10)
            {
                std::cout << "Wrong Input...! Value must be between 0 to ";
                std::cout << "10. Please Enter Again...!" << std::endl;
            }
            else if (j > 0 && !spark &&
                     throws[j - 1] != 10 && (throws[j - 1] + input > 10))
            {
                std::cout << "Wrong Input. vc..! Value must be between 0 to ";
                std::cout << (10 - throws[j - 1]) << ".";
                std::cout << " Please Enter Again...!" << std::endl;
            }
            else
            {
                throws.push_back(input);
                valid = true;
            }
        }

        if (j == 1 && throws[j - 1] != 10)
        {
            if (j == 1 && throws[j - 1] != 10 &&
                (throws[j - 1] + input < 10))
                break;
            else if (j == 1 && throws[j - 1] != 10 &&
                     (throws[j - 1] + input == 10))
                spark = true;
        }
    }
    scores.push_back(throws);
}

int Bowling::calculateScore()
{
    int final_total = 0;

    bool strike = false;
    bool spark = false;

    for (auto vec : scores)
    {
        int round_total = 0;

        for (int ele : vec)
        {
            final_total += ele;
        }

        if (strike)
        {
            final_total += vec.at(0) + vec.at(1);
            strike = false;
        }
        else if (spark)
        {
            final_total += vec.at(0);
            spark = false;
        }

        if (vec.at(0) == 10)
            strike = true;
        else if (vec.at(0) + vec.at(1) == 10)
            spark = true;
    }

    return final_total;
}