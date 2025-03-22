#include "../inc/bowling.h"

int main(int argc, char *argv[])
{
    Bowling *bowl = new Bowling();

    bowl->processInput();

    std::cout << "Total Score = " << bowl->calculateScore() << std::endl;

    return 0;
}