/* GolfHandicap Calculation:

-> Every golf course has a given par, course rating, and slope
-> A golfer can calculate their score differential for each round, using the calculation:

    score differential = ( 113 / slope ) x (adjusted gross score - course rating - PCC adjustment)

-> After playing a minumum of 3 rounds, a golfer can calculate their handicap index
-> top 8 score differentials out of the most recent 20

-> A golfer's handicap can be calculated for a given course, using the calculation:

    course handicap = ((handicap index x slope) / 113) + (course rating - par)

*/
#include <array>

#define DIFFERENTIALS_SIZE 20

struct GolfCourse {
    float rating;
    unsigned slope;
};

struct GolfScore {
    unsigned score;
    GolfCourse course;
};

float calculateHandicap(unsigned, std::array<float, DIFFERENTIALS_SIZE>);
float calculateScoreDifferential(GolfScore);

class GolfHandicap{

    public:
        GolfHandicap();
        void addDifferential(float differential);
        void printDifferentials();
        unsigned totalScores();
        float currentHandicap();
        unsigned courseHandicap(GolfCourse);

    private:
        std::array<float, DIFFERENTIALS_SIZE> differentials;
        float handicap;
        unsigned idx;
        unsigned enteredScores;
};