#include <iostream>
#include <vector>

class BowlingGame {
private:
    std::vector<int> rolls;

    bool isStrike(int index) {
        return rolls[index] == 10;
    }

  
    bool isSpare(int index) {
        return rolls[index] + rolls[index + 1] == 10;
    }
    int frameScore(int index) {
        return rolls[index] + rolls[index + 1];
    }
    int strikeBonus(int index) {
        return rolls[index + 1] + rolls[index + 2];
    }

    int spareBonus(int index) {
        return rolls[index + 2];
    }
public:
    void roll(int pins) {
        rolls.push_back(pins);
    }

    int score() {
        int totalScore = 0;
        int frameIndex = 0;

        for (int frame = 0; frame < 10; ++frame) {
            if (isStrike(frameIndex)) {
                totalScore += 10 + strikeBonus(frameIndex);
                frameIndex += 1;
            } else if (isSpare(frameIndex)) {
                totalScore += 10 + spareBonus(frameIndex);
                frameIndex += 2;
            } else {
                totalScore += frameScore(frameIndex);
                frameIndex += 2;
            }
        }

        return totalScore;
    }
};
int main() {
    BowlingGame game;
    int inputRolls[] = {5, 4, 1, 5, 4, 6, 10, 10, 10, 9, 0, 1, 9, 4, 6, 2};
    int numRolls = sizeof(inputRolls) / sizeof(inputRolls[0]);

    for (int i = 0; i < numRolls; ++i) {
        game.roll(inputRolls[i]);
    }

    std::cout << "Total score: " << game.score() << std::endl;

    return 0;
}

  
