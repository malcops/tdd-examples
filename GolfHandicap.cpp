#include "GolfHandicap.hpp"
#include "math.h"     // floor
#include <algorithm>  // sort
#include <iostream>
#include <numeric>    // accumulate
#include <vector>

GolfHandicap::GolfHandicap(){
    differentials = {0};
    handicap = 0.0;
    idx = 0;
    enteredScores = 0;
}

void GolfHandicap::addDifferential(float differential){
    differentials[idx] = differential;
    idx = (idx + 1) % DIFFERENTIALS_SIZE;
    enteredScores++;
    handicap = calculateHandicap(enteredScores, differentials);
}

unsigned GolfHandicap::totalScores(){
    return enteredScores;
}

float calculateHandicap(unsigned enteredScores, std::array<float, DIFFERENTIALS_SIZE> differentials){

    unsigned scoresToUse = 0;
    float adjustment = 0.0;

    if (enteredScores < 3){
        return 0.0;
    }
    else if (enteredScores == 3){
        scoresToUse = 1;
        adjustment = -2.0;
    }
    else if(enteredScores == 4){
        scoresToUse = 1;
        adjustment = -1.0;
    }
    else if (enteredScores == 5){
        scoresToUse = 1;
    }
    else if (enteredScores == 6){
        scoresToUse = 2;
        adjustment = -1.0;
    }
    else if (enteredScores == 7 || enteredScores == 8){
        scoresToUse = 2;
    }
    else if (enteredScores >= 9 && enteredScores <= 11){
        scoresToUse = 3;
    }
    else if (enteredScores >= 12 && enteredScores <= 14){
        scoresToUse = 4;
    }
    else if (enteredScores == 15 || enteredScores == 16){
        scoresToUse = 5;
    }
    else if (enteredScores == 17 || enteredScores == 18){
        scoresToUse = 6;
    }
    else if (enteredScores == 19){
        scoresToUse = 7;
    }
    else if (enteredScores >= DIFFERENTIALS_SIZE){
        scoresToUse = 8;
    }

    std::vector<float> sorted;
    unsigned activeDifferentials = enteredScores > DIFFERENTIALS_SIZE? DIFFERENTIALS_SIZE : enteredScores;
    for (auto it=0; it < activeDifferentials; it++){
        sorted.push_back(differentials[it]);
    }
    std::sort(sorted.begin(), sorted.end());

    float average = (std::accumulate(sorted.begin(), sorted.begin() + scoresToUse, 0.0) / scoresToUse) + adjustment;
    float handicap = (float)floor(average*10+0.5)/10;
    return handicap;
}

float GolfHandicap::currentHandicap(){
    return handicap;
}

float calculateScoreDifferential(GolfScore score){
    return (113.0 / score.course.slope) * (score.score - score.course.rating);
}

void GolfHandicap::printDifferentials(){
    for (auto it=0; it < differentials.size(); it++){
        std::cout << differentials[it] << std::endl;
    }
}