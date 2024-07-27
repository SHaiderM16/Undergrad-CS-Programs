#include <stdio.h>

void main() {
    int totalBatsmen, totalInnings;

    printf("Enter the number of batsmen: ");
    scanf("%d", &totalBatsmen);
    printf("Enter the number of innings played: ");
    scanf("%d", &totalInnings);

    int teamBattingPerformance[totalBatsmen][totalInnings];
    int teamTotalRuns[totalBatsmen];
    float teamAvgRuns[totalBatsmen];
	int teamHighestScore[totalBatsmen];
	int teamCenturies[totalBatsmen];
	int teamHalfCenturies[totalBatsmen];

    printf("\n");
    for (int i = 0; i < totalBatsmen; i++)
    {
        int totalRuns = 0, highestScore = 0, centuries = 0, halfCenturies = 0;

        for (int j = 0; j < totalInnings; j++)
        {
            printf("Enter runs scored by batsman %d in innings %d: ", i + 1, j + 1);
            scanf("%d", &teamBattingPerformance[i][j]);
            totalRuns = totalRuns + teamBattingPerformance[i][j];

            if (teamBattingPerformance[i][j] > highestScore) {
                highestScore = teamBattingPerformance[i][j];
            }

            if (teamBattingPerformance[i][j] >= 50 && teamBattingPerformance[i][j] <= 100) {
                halfCenturies = halfCenturies + 1;
            }
            else if (teamBattingPerformance[i][j] >= 100) {
                centuries = centuries + 1;
            }
        }
    teamTotalRuns[i] = totalRuns;
    teamAvgRuns[i] = (float)totalRuns / totalInnings;
    teamHighestScore[i] = highestScore;
    teamCenturies[i] = centuries;
    teamHalfCenturies[i] = halfCenturies;
	printf("\n");
    }

    printf("\n      Batting Statistics\n\n");
    for (int i = 0; i < totalBatsmen; i++)
    {
        printf("           Batsman %d\n", i + 1);
        printf("Total Runs     |    %d\n\n", teamTotalRuns[i]);
        printf("Average Runs   |    %.2f\n\n", teamAvgRuns[i]);
        printf("Highest Score  |    %d\n\n", teamHighestScore[i]);
        printf("Centuries      |    %d\n\n", teamCenturies[i]);
        printf("Half-Centuries |    %d\n\n", teamHalfCenturies[i]);
    }
}