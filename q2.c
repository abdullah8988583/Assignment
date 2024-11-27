#include <stdio.h>
#include <string.h>

typedef struct {
    int ballScores[12];
    char playerName[50];
    int totalScore;
} Player;

void playGame(Player *player) {
    player->totalScore = 0;
    printf("Enter scores for %s:\n", player->playerName);
    for (int i = 0; i < 12; i++) {
        int score;
        printf("Ball %d: ", i + 1);
        scanf("%d", &score);
        if (score < 0 || score > 6) {
            printf("Invalid score, marking ball.\n");
            player->ballScores[i] = 0;
        } else {
            player->ballScores[i] = score;
            player->totalScore += score;
        }
    }
}

void findWinner(Player player1, Player player2) {
    if (player1.totalScore > player2.totalScore)
        printf("%s wins with %d runs!\n", player1.playerName, player1.totalScore);
    else if (player1.totalScore < player2.totalScore)
        printf("%s wins with %d runs!\n", player2.playerName, player2.totalScore);
    else
        printf("It's a tie!\n");
}

void displayMatchScoreboard(Player player1, Player player2) {
    printf("\nScoreboard:\n");
    printf("%s - Total Score: %d\n", player1.playerName, player1.totalScore);
    printf("Ball Scores: ");
    for (int i = 0; i < 12; i++) printf("%d ", player1.ballScores[i]);
    printf("\n\n%s - Total Score: %d\n", player2.playerName, player2.totalScore);
    printf("Ball Scores: ");
    for (int i = 0; i < 12; i++) printf("%d ", player2.ballScores[i]);
    printf("\n");
}

int main() {
    Player player1, player2;
    printf("Enter Player 1 Name: ");
    scanf(" %[^\n]", player1.playerName);
    printf("Enter Player 2 Name: ");
    scanf(" %[^\n]", player2.playerName);

    playGame(&player1);
    playGame(&player2);

    displayMatchScoreboard(player1, player2);
    findWinner(player1, player2);
    return 0;
}
