//
// Created by diogo on 08/12/20.
//

#ifndef UNTITLED1_HISTROGRAM_H
#define UNTITLED1_HISTROGRAM_H

#include <iostream>
#include <vector>
#include "utils/utils.h"


class Histrogram {
private:
    float moveOneProbability_m;
    float moveTwoProbability_m;
    float moveZeroProbability_m;
    float correctColorProbability_m;
    float wrongColorProbability_m;
    std::vector<float> probabilityGrid_m;
    std::vector<std::string> colorVector_m;

public:
    Histrogram(ConfigProbabilities configProbabilities, std::vector<std::string> colorGrid);

    void moveRobot();
    void robotSenseColor(std::string color);

private:

    void constructGrid(int numberOfElements, float probability);
    void normalizeGrid();
};


#endif //UNTITLED1_HISTROGRAM_H
