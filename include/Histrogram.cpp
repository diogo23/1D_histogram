//
// Created by diogo on 08/12/20.
//

#include "Histrogram.h"
#include <vector>
#include <iostream>
#include <string>
#include "utils/utils.h"

using namespace std;

Histrogram::Histrogram(ConfigProbabilities configProbabilities, std::vector<std::string> colorGrid) {

    this->moveOneProbability_m = configProbabilities.moveOneProbability;
    this->moveTwoProbability_m = configProbabilities.moveTwoProbability;
    this->moveZeroProbability_m = configProbabilities.moveZeroProbability;
    this->correctColorProbability_m = configProbabilities.correctColorProbability;
    this->wrongColorProbability_m = configProbabilities.wrongColorProbability;
    this->colorVector_m = colorGrid;

    int numberOfCells = colorGrid.size();
    float initialProbability = ((float) 1.0) / numberOfCells;
    constructGrid(numberOfCells, initialProbability);
}

void Histrogram::constructGrid(int numberOfElements, float probability) {
    cout << endl;
    cout << "Starting probability grid: ";

    for(int i = 0; i<numberOfElements; i++){
        this->probabilityGrid_m.push_back(probability);
    }
    diplayValues(this->probabilityGrid_m);
}

void Histrogram::moveRobot() {

    std::vector<std::vector<float>> allProbabilityGrids;
    std::vector<float> finalProbabilityGrid(this->probabilityGrid_m.size());

    for(int i=0; i<this->probabilityGrid_m.size(); i++){

        std::vector<float> clonedProbabilityicGrid(this->probabilityGrid_m.size());

        if(i + 2 == this->probabilityGrid_m.size()){
            clonedProbabilityicGrid[i] = this->probabilityGrid_m[i] * this->moveZeroProbability_m;
            clonedProbabilityicGrid[i+1] = this->probabilityGrid_m[i] * this->moveOneProbability_m;
            clonedProbabilityicGrid[0] = this->probabilityGrid_m[i] * this->moveTwoProbability_m;

        }else if(i + 1 == this->probabilityGrid_m.size()){
            clonedProbabilityicGrid[i] = this->probabilityGrid_m[i] * this->moveZeroProbability_m;
            clonedProbabilityicGrid[0] = this->probabilityGrid_m[i] * this->moveOneProbability_m;
            clonedProbabilityicGrid[1] = this->probabilityGrid_m[i] * this->moveTwoProbability_m;

        }else{
            clonedProbabilityicGrid[i] = this->probabilityGrid_m[i] * this->moveZeroProbability_m;
            clonedProbabilityicGrid[i+1] = this->probabilityGrid_m[i] * this->moveOneProbability_m;
            clonedProbabilityicGrid[i+2] = this->probabilityGrid_m[i] * this->moveTwoProbability_m;
        }

        allProbabilityGrids.push_back(clonedProbabilityicGrid);
    }

    for(const auto& probabilityGrid : allProbabilityGrids){
        for(int i = 0; i<this->probabilityGrid_m.size(); i++)
        {
            finalProbabilityGrid[i] += probabilityGrid[i];
        }
    }
    diplayValues(finalProbabilityGrid);
    this->probabilityGrid_m = finalProbabilityGrid;
}

void Histrogram::robotSenseColor(std::string color) {

    for(int i = 0; i < this->probabilityGrid_m.size(); i++){

        if(color == this->colorVector_m[i]){
            this->probabilityGrid_m[i] = this->probabilityGrid_m[i] * this->correctColorProbability_m;
        } else{
            this->probabilityGrid_m[i] = this->probabilityGrid_m[i] * this->wrongColorProbability_m;
        }
    }
    this->normalizeGrid();
}

void Histrogram::normalizeGrid() {

    float total = 0.0;
    for(const auto& probability : this->probabilityGrid_m){
        total = total + probability;
    }

    for(float& probability : this->probabilityGrid_m){
        probability = probability / total;
    }

    diplayValues(this->probabilityGrid_m);
}
