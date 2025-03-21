#include <iostream>
#include <vector>
#include <algorithm>

class Bowling
{
    std::vector<std::vector<int>> scores;

public:
    Bowling();
    Bowling(Bowling &obj) = delete;
    Bowling &operator=(const Bowling &obj) = delete;

    void processInput();
    int calculateScore();
};