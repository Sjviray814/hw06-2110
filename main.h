#ifndef MAIN_H
#define MAIN_H

#include "gba.h"

// Main:
#define BACKGROUND_COLOR BLACK

// Title:
void drawTitle(int selection);

// Player:
struct Player {
    int score;
    float xPos;
    float yPos;
    float xVel;
    float yVel;
    int width;
    int height;
    u16 color;
};
#define PLAYER_WIDTH 10
#define PLAYER_HEIGHT 10

void controlPlayer(struct Player *player, u32 buttons);
void movePlayer(struct Player *player, float playerSpeed);



// Food:
struct Food {
    int xPos;
    int yPos;
    u16 color;
};

#define FOOD_WIDTH 10
#define FOOD_HEIGHT 10
void spawnFoods(struct Food foods[], int difficulty, struct Player *player);
void drawFoods(struct Food foods[], int numFoods);
int checkCollision(struct Player *player, struct Food *food);
void undrawFoods(struct Food foods[], int numFoods);


// Instructions/Text:
void drawInstructions(int difficulty);
void drawScore(void);
void handleScore(struct Food *food);

void resetEverything(void);

void drawHow(void);
#endif