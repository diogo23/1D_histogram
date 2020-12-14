#include <iostream>
#include "include/utils/utils.h"
#include "include/Histrogram.h"

int main() {
    std::cout << "Starting Algorithm!" << std::endl;

    HistogramInitValues histogramInitValues = getHistogramInitValues();
    Histrogram Histogram(histogramInitValues.configProbabilities, histogramInitValues.colorVector);

    for(const auto& robotSensedColor : histogramInitValues.colorSensedVector){
        std::cout << "Going to move robot";
        Histogram.moveRobot();

        std::cout << "Color sensed: \"" + robotSensedColor << "\" ; Going to calculate probabilities:";
        Histogram.robotSenseColor(robotSensedColor);
        std::cout << std::endl;
    }
    return 0;
}