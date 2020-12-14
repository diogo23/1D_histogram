//
// Created by diogo on 09/12/20.
//

#ifndef HISTOGRAM_UTILS_H
#define HISTOGRAM_UTILS_H

#include <vector>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <zconf.h>
#include <random>


struct ConfigProbabilities{
    float moveOneProbability{0.9};
    float moveTwoProbability{0.05};
    float moveZeroProbability{0.05};
    float correctColorProbability{0.9};
    float wrongColorProbability{0.1};
};

struct HistogramInitValues{
    std::vector<std::string> colorVector{"B","O","B","B","O"};
    std::vector<std::string> colorSensedVector{"O","B","O"};
    ConfigProbabilities configProbabilities{ConfigProbabilities()};
};

static std::vector<std::string> randomVector(int size, int ratioOfBlueCells){
    std::vector<std::string> outputVector(size);
    int randomValue;
    srand(time(NULL));

    for(int i=0; i<size; i++){
        randomValue = random() % 100;

        if(randomValue > ratioOfBlueCells){
            outputVector[i] = 'O';
        } else{
            outputVector[i] = 'B';
        }

        if(i%5 == 0){
            std::cout << std::endl;
        }

        std::cout << outputVector[i] << " ; ";
    }
    std::cout << std::endl << std::endl;
    return outputVector;
}

static ConfigProbabilities obtainConfigValues(){
    ConfigProbabilities configProbabilities;
    float i;
    std::string mystr;

    std::cout << "Please enter the probability of Moving One bin: ";
    getline (std::cin,mystr);
    std::stringstream(mystr) >> i;
    configProbabilities.moveOneProbability = i;
    std::cout << i << std::endl;

    std::cout << "Please enter the probability of Moving Two bin: ";
    getline (std::cin,mystr);
    std::stringstream(mystr) >> i;
    configProbabilities.moveTwoProbability = i;
    std::cout << i << std::endl;

    std::cout << "Please enter the probability of Moving Zero bin: ";
    getline (std::cin,mystr);
    std::stringstream(mystr) >> i;
    configProbabilities.moveZeroProbability = i;
    std::cout << i << std::endl;

    std::cout << "Please enter the probability of having the Correct sensed Color: ";
    getline (std::cin,mystr);
    std::stringstream(mystr) >> i;
    configProbabilities.correctColorProbability = i;
    std::cout << i << std::endl;

    std::cout << "Please enter the probability of having the Wrong sensed Color: ";
    getline (std::cin,mystr);
    std::stringstream(mystr) >> i;
    configProbabilities.wrongColorProbability = i;
    std::cout << i << std::endl;

    return configProbabilities;
}

static std::vector<std::string> choseColorPath(int numberOfSteps){
    std::vector<std::string> colorVector(numberOfSteps);
    std::string i;
    std::string mystr;

    for(int j = 0; j < numberOfSteps ; j++){
        std::cout << "(orange O or Blue B) Please enter the sensed color: ";
        std::getline(std::cin, i);
        colorVector[j] = i;
        std::cout << i << std::endl;
    }
    return colorVector;
}

static HistogramInitValues getHistogramInitValues(){
    std::string i;
    std::string mystr;

    std::cout << "Do you want to run the default example? [Y/N] ";
    getline (std::cin,mystr);
    std::stringstream(mystr) >> i;

    if(i == "y" || i == "Y"){
        HistogramInitValues histogramInitValues = HistogramInitValues();
        return histogramInitValues;

    } else if(i== "n" || i == "N"){
        int j, k;
        HistogramInitValues histogramInitValues = HistogramInitValues();
        std::cout << "Number of bin elements? ";
        getline (std::cin,mystr);
        std::stringstream(mystr) >> j;

        std::cout << "Percantage number of Blue cells? ";
        getline (std::cin,mystr);
        std::stringstream(mystr) >> k;

        histogramInitValues.colorVector = randomVector(j, k);

        std::cout << "Number of sensed color elements? ";
        getline (std::cin,mystr);
        std::stringstream(mystr) >> j;

        histogramInitValues.colorSensedVector = choseColorPath(j);
        histogramInitValues.configProbabilities = obtainConfigValues();

        return histogramInitValues;
    }
}

static void diplayValues(std::vector<float> values){

    for(int i = 0; i < values.size(); i++){

        if(i%5 == 0){
            std::cout << std::endl;
        }

        printf("%f ; ", values[i]);
    }
    std::cout << std::endl << std::endl;
}
#endif //HISTOGRAM_UTILS_H
