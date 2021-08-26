#include "GolfHandicap.hpp"
#include "gtest/gtest.h"

GolfScore score =  {85, GolfCourse{70.3, 126}};
GolfScore score2 = {78, GolfCourse{72.1, 115}};
GolfScore score3 = {82, GolfCourse{66.8, 120}};
GolfScore score4 = {85, GolfCourse{65.9, 118}};
GolfScore score5 = {88, GolfCourse{74.3, 137}};
GolfScore score6 = {90, GolfCourse{71.1, 126}};

TEST(TestScoreDifferential, basicCalculation){

    EXPECT_NEAR(calculateScoreDifferential(score), 13.2, 0.1);
    EXPECT_NEAR(calculateScoreDifferential(score2), 5.8, 0.1);
    EXPECT_NEAR(calculateScoreDifferential(score3), 14.3, 0.1);
    EXPECT_NEAR(calculateScoreDifferential(score4), 18.3, 0.1);
    EXPECT_NEAR(calculateScoreDifferential(score5), 11.3, 0.1);
    EXPECT_NEAR(calculateScoreDifferential(score6), 17.0, 0.1);
}

TEST(TestGolfHandicap, initialize){
    GolfHandicap gh = GolfHandicap();
    ASSERT_FLOAT_EQ(gh.currentHandicap(), 0.0);
    ASSERT_EQ(gh.totalScores(), 0);
}

TEST(TestGolfHandicap, add1Score){
    GolfHandicap gh = GolfHandicap();
    gh.addDifferential(13.2);
    ASSERT_EQ(gh.totalScores(), 1);
    ASSERT_FLOAT_EQ(gh.currentHandicap(), 0.0);
}

TEST(TestGolfHandicap, calculateHandicap){

    GolfHandicap gh = GolfHandicap();
    gh.addDifferential(1.0);
    gh.addDifferential(2.0);
    gh.addDifferential(3.0);
    ASSERT_EQ(gh.totalScores(), 3);
    ASSERT_FLOAT_EQ(gh.currentHandicap(), -1.0);
}

TEST(TestGolfHandicap, calculateHandicap6Scores){
    GolfHandicap gh = GolfHandicap();
    gh.addDifferential(13.2);
    gh.addDifferential(5.8);
    gh.addDifferential(14.3);
    gh.addDifferential(18.3);
    gh.addDifferential(11.3);
    ASSERT_FLOAT_EQ(gh.currentHandicap(), 5.8);
    gh.addDifferential(17.0);
    ASSERT_EQ(gh.totalScores(), 6);
    ASSERT_FLOAT_EQ(gh.currentHandicap(), 7.6);
}

TEST(TestGolfHandicap, calculateHandicap21Scores){
    GolfHandicap gh = GolfHandicap();
    for (auto it=0; it < 8; it++){
        gh.addDifferential(5.0);
    }
    for (auto it=0; it < 12; it++){
        gh.addDifferential(6.0);
    }
    ASSERT_FLOAT_EQ(gh.currentHandicap(), 5.0);
    gh.addDifferential(7.0);
    ASSERT_EQ(gh.totalScores(), 21);
    ASSERT_FLOAT_EQ(gh.currentHandicap(), 5.1);
}

TEST(TestGolfHandicap, calculateHandicap40Scores){
    GolfHandicap gh = GolfHandicap();
    for (auto it=0; it < 20; it++){
        gh.addDifferential(5.0);
    }
    ASSERT_FLOAT_EQ(gh.currentHandicap(), 5.0);
    for (auto it=0; it < 20; it++){
        gh.addDifferential(6.0);
    }
    ASSERT_FLOAT_EQ(gh.currentHandicap(), 6.0);
    ASSERT_EQ(gh.totalScores(), 40);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
