#include <stdio.h>

void printScoringCombinations(int score) {
    int touchdown8pts, touchdown7pts, touchdown6pts, fieldGoal, safety;

    for (touchdown8pts = 0; touchdown8pts * 8 <= score; touchdown8pts++) {
        for (touchdown7pts = 0; touchdown7pts * 7 <= score - touchdown8pts * 8; touchdown7pts++) {
            for (touchdown6pts = 0; touchdown6pts * 6 <= score - touchdown8pts * 8 - touchdown7pts * 7; touchdown6pts++) {
                for (fieldGoal = 0; fieldGoal * 3 <= score - touchdown8pts * 8 - touchdown7pts * 7 - touchdown6pts * 6; fieldGoal++)  {
                    for (safety = 0; safety * 2 <= score - touchdown8pts * 8 - touchdown7pts * 7 - touchdown6pts * 6 - fieldGoal * 3; safety++) {
                        int remainingScore = score - touchdown8pts * 8 - touchdown7pts * 7 - touchdown6pts * 6 - fieldGoal * 3 - safety * 2;
                        if (remainingScore == 0) {
                            printf("%d TD + 2PT, %d TD + 1PT, %d TD + 0PT, %d FG, %d Safety\n", touchdown8pts, touchdown7pts, touchdown6pts, fieldGoal, safety);
                        }

                    }
                }
            }
        }
    }
}

int main() {
    int score;

    printf("Enter 0 or 1 to STOP\n");
    
    while (1) {
        printf("Enter the NFL score: ");
        scanf("%d", &score);

        if (score <= 1)
            break;

        printf("Possible combinations of scoring plays:\n");
        printScoringCombinations(score);
    }

    return 0;
}
