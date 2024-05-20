#include <GL/gl.h>
#include <GL/glut.h>
#include <iostream>
#include <math.h>
#include <cmath>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <sstream>
#define M_PI 3.14159265358979323846

// Window dimensions
const int width = 800;
const int height = 700;

//hearts
struct Health {
    float x;
    float y;
    float radius;
    bool active;
};
std::vector<Health> healths;

void initializeHealths() {
    healths.clear();
    Health health1 = {250.0f, 80.0f,  1.0f, true};
    Health health2 = {120.0f, 370.0f, 1.0f, true};
    Health health3 = {630.0f, 680.0f, 1.0f, true};
    healths.push_back(health1);
    healths.push_back(health2);
    healths.push_back(health3);
}

//Coin
struct Coin {
    float x;
    float y;
    float radius;
    bool active; // Whether the coin is active or not
};

std::vector<Coin> coins;
int score = 0;
int lives=3;

void initializeCoins() {
    coins.clear();
    // Set specific coordinates for the coins
    Coin coin1 = {125.0f, 400.0f, 10.0f, true}; // Example coin
    Coin coin2 = {495.0f, 400.0f, 10.0f, true}; // Example coin
    Coin coin3 = {665.0f, 268.0f, 10.0f, true}; // Example coin
    Coin coin4 = {522.0f, 200.0f, 10.0f, true}; // Example coin
    Coin coin5 = {175.0f, 660.0f, 10.0f, true}; // Example coin
    Coin coin6 = {500.0f, 640.0f, 10.0f, true}; // Example coin
    Coin coin7 = {345.0f, 610.0f, 10.0f, true}; // Example coin
    Coin coin8 = {380.0f, 320.0f, 10.0f, true}; // Example coin
    coins.push_back(coin1);
    coins.push_back(coin2);
     coins.push_back(coin3);
      coins.push_back(coin4);
       coins.push_back(coin5);
        coins.push_back(coin6);
         coins.push_back(coin7);
          coins.push_back(coin8);
}

// Player ball position
float ballX = 30;
float ballY = 30;
float ballRadius = 20.0f;
float speed = 5.0f;
float jumpHeight = 0.0f;//the value used for translation
float jumpAnimationHeight = 0.0f;//standby animation location tracking
float jumpHeightOnSpace=0.0f;//jump location tracking
float jumpSpeed = 0.05f;
bool jumpeStatus =false;//ball in a jump state
bool jumpAnimationStatus=false;//jump position tracking
bool jumpDefaltAnimationStatus =false;//standby animation ball position tracking
//refresh
int refreshMills = 30;
// goal ball position
float ballX1 = 750;
float ballY1 = 500;
float ballRadius1 = 20.0f;
bool gameOver = false;
bool gameGoal_Reach_Status=false;
// Wall coordinates (multiple walls can be added here)
// Wall coordinates (multiple walls can be added here)
float wallX1 = 50.0f;
float wallY1 = 0.0f;
float wallWidth =50.0f;
float wallHeight =50.0f;

float wallX2 =100.0f;
float wallY2 = 0.0f;
float wallWidth2 =50.0f;
float wallHeight2 =150.0f;

float wallX3 =150.0f;
float wallY3 = 100.0f;
float wallWidth3 =150.0f;
float wallHeight3 =50.0f;

float wallX4 =300.0f;
float wallY4 = 0.0f;
float wallWidth4 =50.0f;
float wallHeight4 =150.0f;

float wallX5 =350.0f;
float wallY5 = 0.0f;
float wallWidth5 =450.0f;
float wallHeight5 =50.0f;

float wallX6 =400.0f;
float wallY6 = 100.0f;
float wallWidth6 =100.0f;
float wallHeight6 =100.0f;

float wallX7 =650.0f;
float wallY7 = 100.0f;
float wallWidth7 =100.0f;
float wallHeight7 =100.0f;

float wallX8 =550.0f;
float wallY8 = 100.0f;
float wallWidth8 =50.0f;
float wallHeight8 =120.0f;

float wallX9 =350.0f;
float wallY9 = 250.0f;
float wallWidth9 =170.0f;
float wallHeight9 =50.0f;

float wallX10 =300.0f;
float wallY10 = 200.0f;
float wallWidth10 =50.0f;
float wallHeight10 =100.0f;

float wallX11 =100.0f;
float wallY11 = 200.0f;
float wallWidth11 =150.0f;
float wallHeight11 =50.0f;

float wallX12 =420.0f;
float wallY12 = 300.0f;
float wallWidth12 =50.0f;
float wallHeight12 =200.0f;

float wallX13 =650.0f;
float wallY13 = 300.0f;
float wallWidth13 =100.0f;
float wallHeight13 =50.0f;

float wallX14 =700.0f;
float wallY14 = 250.0f;
float wallWidth14 =50.0f;
float wallHeight14 =50.0f;

float wallX15 =690.0f;
float wallY15 = 400.0f;
float wallWidth15 =150.0f;
float wallHeight15 =50.0f;

float wallX16 =650.0f;
float wallY16 = 550.0f;
float wallWidth16 =50.0f;
float wallHeight16 =200.0f;

float wallX17 =520.0f;
float wallY17 = 350.0f;
float wallWidth17 =50.0f;
float wallHeight17 =250.0f;

float wallX18 =320.0f;
float wallY18 =350.0f;
float wallWidth18 =50.0f;
float wallHeight18 =250.0f;

float wallX19 =50.0f;
float wallY19 = 350.0f;
float wallWidth19 =50.0f;
float wallHeight19 =150.0f;

float wallX20 =100.0f;
float wallY20 = 300.0f;
float wallWidth20 =100.0f;
float wallHeight20 =50.0f;

float wallX21 =150.0f;
float wallY21 = 350.0f;
float wallWidth21 =50.0f;
float wallHeight21 =100.0f;

float wallX22 =50.0f;
float wallY22 = 600.0f;
float wallWidth22 =50.0f;
float wallHeight22 =100.0f;

float wallX23 =150.0f;
float wallY23 = 550.0f;
float wallWidth23 =50.0f;
float wallHeight23 =100.0f;

float wallX24 =300.0f;
float wallY24 = 650.0f;
float wallWidth24 =300.0f;
float wallHeight24 =50.0f;

float wallX25 =0.0f;
float wallY25 = 0.0f;
float wallWidth25 =50.0f;
float wallHeight25 =10.0f;

float wallX26 =250.0f;
float wallY26 = 480.0f;
float wallWidth26 =70.0f;
float wallHeight26 =50.0f;

//Block
float blockX = 0.0f;
float blockY = 500.0f;
float blockWidth = 20.0f;
float blockHeight = 20.0f;
float deltaX = 2.0f; // Speed in x-direction
float leftBound = 0.0f; // Define left boundary
float rightBound = 250.0f; // Define right boundary

float blockX2 = 380.0f;
float blockY2 = 540.0f;
float blockWidth2 = 20.0f;
float blockHeight2 = 20.0f;
float deltaX2 = 2.0f; // Speed in x-direction
float leftBound2= 368.0f; // Define left boundary
float rightBound2 = 520.0f; // Define right boundary

float blockX3 = 550.0f;
float blockY3 = 400.0f;
float blockWidth3 = 20.0f;
float blockHeight3 = 20.0f;
float deltaX3 = 2.0f; // Speed in x-direction
float leftBound3= 570.0f; // Define left boundary
float rightBound3 = 688.0f; // Define right boundary

//Obstacle
float obstacleX = 440.0f;
float obstacleY = 50.0f;
float obstacleWidth = 10.0f;
float obstacleHeight = 20.0f;

float obstacleX2 = 440.0f;
float obstacleY2 = 630.0f;
float obstacleWidth2 = 10.0f;
float obstacleHeight2 = 20.0f;

float obstacleX3 = 630.0f;
float obstacleY3 = 140.0f;
float obstacleWidth3 = 20.0f;
float obstacleHeight3 = 10.0f;

float obstacleX4 = 300.0f;
float obstacleY4 = 590.0f;
float obstacleWidth4 = 20.0f;
float obstacleHeight4 = 10.0f;

float obstacleX5 = 300.0f;
float obstacleY5 = 350.0f;
float obstacleWidth5 = 20.0f;
float obstacleHeight5 = 10.0f;

float obstacleX6 = 630.0f;
float obstacleY6 = 550.0f;
float obstacleWidth6 = 20.0f;
float obstacleHeight6 = 10.0f;

float obstacleX7 = 570.0f;
float obstacleY7 = 480.0f;
float obstacleWidth7 = 20.0f;
float obstacleHeight7 = 10.0f;

float obstacleX8 = 700.0f;
float obstacleY8 = 380.0f;
float obstacleWidth8 = 10.0f;
float obstacleHeight8 = 20.0f;

 // draw  teleporter 1
float teleporterx1 = 160;
float teleportery1 = 0;
// draw  teleporter 2
float teleporterx2 = 10;
float teleportery2 = 650;

float teleporterx1width = 15;
float teleporterx1Height = 30;

// End goal ball position
float endBallX =700;
float endBallY = 550;


void Timer(int value) {
   glutPostRedisplay();
   glutTimerFunc(refreshMills, Timer, 0);
}

void checkEnd() {
  float distance = sqrt(pow(ballX - endBallX, 2) + pow(ballY - endBallY, 2));
  if (distance < ballRadius * 2) {
    gameOver = false;
    gameGoal_Reach_Status=true;
    std::cout << "Congratulations! You reached the goal!" << std::endl;
  }
}

void drawFilledCircle(float cx, float cy, float radius, int numSegments) {
    glBegin(GL_TRIANGLE_FAN);
    for (int i = 0; i <= numSegments; i++) {
        float angle = 2.0f * M_PI * i / numSegments;
        float x = radius * cosf(angle);
        float y = radius * sinf(angle);
        glVertex2f(cx + x, cy + y);
    }
    glEnd();
}

void jumpLogic(){
    //on jump animation
    if(jumpeStatus){
            //logic status of the ball position top/bottom
            if(jumpHeightOnSpace>2){
                jumpAnimationStatus=true;
            }
            if(jumpHeightOnSpace<0){
                jumpAnimationStatus=false;
                jumpeStatus=false;
            }
        //ball position updating respect to the logic state
        if(!jumpAnimationStatus){
            jumpHeightOnSpace +=0.2f;
            jumpHeight +=5.0f;

        }
         if(jumpAnimationStatus){
            jumpHeightOnSpace -=0.2f;
            jumpHeight -=5.0f;

        }
    }
    //normal standby jump animation
    if(!jumpeStatus){
            //logic status of the ball position top/bottom
            if(jumpAnimationHeight>0.5){
                jumpDefaltAnimationStatus=true;
            }
            if(jumpAnimationHeight<0){
                jumpDefaltAnimationStatus=false;
            }
        //ball position updating respect to the logic state
        if(!jumpDefaltAnimationStatus){
            jumpAnimationHeight +=0.1f;
            jumpHeight +=2.1f;
        }
         if(jumpDefaltAnimationStatus){
            jumpAnimationHeight -=0.1f;
            jumpHeight -=2.1f;
        }
    }
}

void drawText(const char* text, float x, float y) {
    glRasterPos2f(x, y);
    for (const char* c = text; *c != '\0'; ++c) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, *c);
    }
}

void drawHeart(float x, float y, float radius) {
    glBegin(GL_POLYGON);
    for (float t = 0; t < 2 * M_PI; t += 0.01) {
        float heartX = radius * 16 * sin(t) * sin(t) * sin(t);
        float heartY = radius * (13 * cos(t) - 5 * cos(2 * t) - 2 * cos(3 * t) - cos(4 * t));
        glVertex2f(x + heartX, y + heartY);
    }
    glEnd();
}

void display() {
  glClear(GL_COLOR_BUFFER_BIT);
   glMatrixMode(GL_MODELVIEW);     // To operate on Model-View matrix
   glLoadIdentity();

  glPushMatrix();
  glTranslatef(0.0f, jumpHeight, 0.0f);
  // Draw player ball (white circle)
  glColor3f(1.0f, 1.0f, 1.0f);
  drawFilledCircle(ballX, ballY, ballRadius, 360);

  glPopMatrix();// restore translations
 // Draw walls (brown rectangles)
  glColor3f(0.6f, 0.4f, 0.2f);
  glBegin(GL_QUADS);
  glVertex2f(wallX1, wallY1);
  glVertex2f(wallX1 + wallWidth, wallY1);
  glVertex2f(wallX1 + wallWidth, wallY1 + wallHeight);
  glVertex2f(wallX1, wallY1 + wallHeight);
  glEnd();

  glColor3f(0.6f, 0.4f, 0.2f);
  glBegin(GL_QUADS);
  glVertex2f(wallX2, wallY2);
  glVertex2f(wallX2 + wallWidth2, wallY2);
  glVertex2f(wallX2 + wallWidth2, wallY2 + wallHeight2);
  glVertex2f(wallX2, wallY2 + wallHeight2);
  glEnd();

   glColor3f(0.6f, 0.4f, 0.2f);
  glBegin(GL_QUADS);
  glVertex2f(wallX3, wallY3);
  glVertex2f(wallX3 + wallWidth3, wallY3);
  glVertex2f(wallX3 + wallWidth3, wallY3 + wallHeight3);
  glVertex2f(wallX3, wallY3 + wallHeight3);
  glEnd();

  glColor3f(0.6f, 0.4f, 0.2f);
  glBegin(GL_QUADS);
  glVertex2f(wallX4 ,wallY4);
  glVertex2f(wallX4 + wallWidth4, wallY4);
  glVertex2f(wallX4 + wallWidth4, wallY4 + wallHeight4);
  glVertex2f(wallX4, wallY4 + wallHeight4);
  glEnd();

  glColor3f(0.6f, 0.4f, 0.2f);
  glBegin(GL_QUADS);
  glVertex2f(wallX5, wallY5);
  glVertex2f(wallX5 + wallWidth5, wallY5);
  glVertex2f(wallX5 + wallWidth5, wallY5 + wallHeight5);
  glVertex2f(wallX5, wallY5 + wallHeight5);
  glEnd();

  glColor3f(0.6f, 0.4f, 0.2f);
  glBegin(GL_QUADS);
  glVertex2f(wallX6, wallY6);
  glVertex2f(wallX6 + wallWidth6, wallY6);
  glVertex2f(wallX6 + wallWidth6, wallY6 + wallHeight6);
  glVertex2f(wallX6, wallY6 + wallHeight6);
  glEnd();

  glColor3f(0.6f, 0.4f, 0.2f);
  glBegin(GL_QUADS);
  glVertex2f(wallX7, wallY7);
  glVertex2f(wallX7 + wallWidth7, wallY7);
  glVertex2f(wallX7 + wallWidth6, wallY7 + wallHeight7);
  glVertex2f(wallX7, wallY7 + wallHeight7);
  glEnd();

  glColor3f(0.6f, 0.4f, 0.2f);
  glBegin(GL_QUADS);
  glVertex2f(wallX8, wallY8);
  glVertex2f(wallX8 + wallWidth8, wallY8);
  glVertex2f(wallX8 + wallWidth8, wallY8 + wallHeight8);
  glVertex2f(wallX8, wallY8 + wallHeight8);
  glEnd();

  glColor3f(0.6f, 0.4f, 0.2f);
  glBegin(GL_QUADS);
  glVertex2f(wallX9, wallY9);
  glVertex2f(wallX9 + wallWidth9, wallY9);
  glVertex2f(wallX9 + wallWidth9, wallY9 + wallHeight9);
  glVertex2f(wallX9, wallY9 + wallHeight9);
  glEnd();

  glColor3f(0.6f, 0.4f, 0.2f);
  glBegin(GL_QUADS);
  glVertex2f(wallX10, wallY10);
  glVertex2f(wallX10 + wallWidth10, wallY10);
  glVertex2f(wallX10 + wallWidth10, wallY10 + wallHeight10);
  glVertex2f(wallX10, wallY10 + wallHeight10);
  glEnd();

  glColor3f(0.6f, 0.4f, 0.2f);
  glBegin(GL_QUADS);
  glVertex2f(wallX11, wallY11);
  glVertex2f(wallX11 + wallWidth11, wallY11);
  glVertex2f(wallX11 + wallWidth11, wallY11 + wallHeight11);
  glVertex2f(wallX11, wallY11 + wallHeight11);
  glEnd();

  glColor3f(0.6f, 0.4f, 0.2f);
  glBegin(GL_QUADS);
  glVertex2f(wallX12, wallY12);
  glVertex2f(wallX12 + wallWidth12, wallY12);
  glVertex2f(wallX12 + wallWidth12, wallY12 + wallHeight12);
  glVertex2f(wallX12, wallY12 + wallHeight12);
  glEnd();

  glColor3f(0.6f, 0.4f, 0.2f);
  glBegin(GL_QUADS);
  glVertex2f(wallX13, wallY13);
  glVertex2f(wallX13 + wallWidth13, wallY13);
  glVertex2f(wallX13 + wallWidth13, wallY13 + wallHeight13);
  glVertex2f(wallX13, wallY13 + wallHeight13);
  glEnd();

  glColor3f(0.6f, 0.4f, 0.2f);
  glBegin(GL_QUADS);
  glVertex2f(wallX14, wallY14);
  glVertex2f(wallX14 + wallWidth14, wallY14);
  glVertex2f(wallX14 + wallWidth14, wallY14 + wallHeight14);
  glVertex2f(wallX14, wallY14 + wallHeight14);
  glEnd();

  glColor3f(0.6f, 0.4f, 0.2f);
  glBegin(GL_QUADS);
  glVertex2f(wallX15, wallY15);
  glVertex2f(wallX15 + wallWidth15, wallY15);
  glVertex2f(wallX15 + wallWidth15, wallY15 + wallHeight15);
  glVertex2f(wallX15, wallY15 + wallHeight15);
  glEnd();

  glColor3f(0.6f, 0.4f, 0.2f);
  glBegin(GL_QUADS);
  glVertex2f(wallX16, wallY16);
  glVertex2f(wallX16 + wallWidth16, wallY16);
  glVertex2f(wallX16 + wallWidth16, wallY16 + wallHeight16);
  glVertex2f(wallX16, wallY16 + wallHeight16);
  glEnd();

  glColor3f(0.6f, 0.4f, 0.2f);
  glBegin(GL_QUADS);
  glVertex2f(wallX16, wallY16);
  glVertex2f(wallX16 + wallWidth16, wallY16);
  glVertex2f(wallX16 + wallWidth16, wallY16 + wallHeight16);
  glVertex2f(wallX16, wallY16 + wallHeight16);
  glEnd();

  glColor3f(0.6f, 0.4f, 0.2f);
  glBegin(GL_QUADS);
  glVertex2f(wallX17, wallY17);
  glVertex2f(wallX17 + wallWidth17, wallY17);
  glVertex2f(wallX17 + wallWidth17, wallY17 + wallHeight17);
  glVertex2f(wallX17, wallY17 + wallHeight17);
  glEnd();

  glColor3f(0.6f, 0.4f, 0.2f);
  glBegin(GL_QUADS);
  glVertex2f(wallX18, wallY18);
  glVertex2f(wallX18 + wallWidth18, wallY18);
  glVertex2f(wallX18 + wallWidth18, wallY18 + wallHeight18);
  glVertex2f(wallX18, wallY18 + wallHeight18);
  glEnd();

  glColor3f(0.6f, 0.4f, 0.2f);
  glBegin(GL_QUADS);
  glVertex2f(wallX19, wallY19);
  glVertex2f(wallX19 + wallWidth19, wallY19);
  glVertex2f(wallX19 + wallWidth19, wallY19 + wallHeight19);
  glVertex2f(wallX19, wallY19 + wallHeight19);
  glEnd();

  glColor3f(0.6f, 0.4f, 0.2f);
  glBegin(GL_QUADS);
  glVertex2f(wallX20, wallY20);
  glVertex2f(wallX20 + wallWidth20, wallY20);
  glVertex2f(wallX20 + wallWidth20, wallY20 + wallHeight20);
  glVertex2f(wallX20, wallY20 + wallHeight20);
  glEnd();

  glColor3f(0.6f, 0.4f, 0.2f);
  glBegin(GL_QUADS);
  glVertex2f(wallX21, wallY21);
  glVertex2f(wallX21 + wallWidth21, wallY21);
  glVertex2f(wallX21 + wallWidth21, wallY21 + wallHeight21);
  glVertex2f(wallX21, wallY21 + wallHeight21);
  glEnd();

  glColor3f(0.6f, 0.4f, 0.2f);
  glBegin(GL_QUADS);
  glVertex2f(wallX22, wallY22);
  glVertex2f(wallX22 + wallWidth22, wallY22);
  glVertex2f(wallX22 + wallWidth22, wallY22 + wallHeight22);
  glVertex2f(wallX22, wallY22 + wallHeight22);
  glEnd();

  glColor3f(0.6f, 0.4f, 0.2f);
  glBegin(GL_QUADS);
  glVertex2f(wallX23, wallY23);
  glVertex2f(wallX23 + wallWidth23, wallY23);
  glVertex2f(wallX23 + wallWidth23, wallY23 + wallHeight23);
  glVertex2f(wallX23, wallY23 + wallHeight23);
  glEnd();

  glColor3f(0.6f, 0.4f, 0.2f);
  glBegin(GL_QUADS);
  glVertex2f(wallX24, wallY24);
  glVertex2f(wallX24 + wallWidth24, wallY24);
  glVertex2f(wallX24 + wallWidth24, wallY24 + wallHeight24);
  glVertex2f(wallX24, wallY24 + wallHeight24);
  glEnd();

  glColor3f(1.0f, .0f, 1.0f);
  glBegin(GL_QUADS);
  glVertex2f(wallX25, wallY25);
  glVertex2f(wallX25 + wallWidth25, wallY25);
  glVertex2f(wallX25 + wallWidth25, wallY25 + wallHeight25);
  glVertex2f(wallX25, wallY25 + wallHeight25);
  glEnd();

  glColor3f(0.6f, 0.4f, 0.2f);
  glBegin(GL_QUADS);
  glVertex2f(wallX26, wallY26);
  glVertex2f(wallX26 + wallWidth26, wallY26);
  glVertex2f(wallX26 + wallWidth26, wallY26 + wallHeight26);
  glVertex2f(wallX26, wallY26 + wallHeight26);
  glEnd();

//Moving Block
    glColor3f(0.3f, 0.5f, 0.7f);
    glBegin(GL_QUADS);
    glVertex2f(blockX, blockY);
    glVertex2f(blockX + blockWidth, blockY);
    glVertex2f(blockX + blockWidth, blockY + blockHeight);
    glVertex2f(blockX, blockY + blockHeight);
    glEnd();

    glColor3f(0.3f, 0.5f, 0.7f);
    glBegin(GL_QUADS);
    glVertex2f(blockX2, blockY2);
    glVertex2f(blockX2 + blockWidth2, blockY2);
    glVertex2f(blockX2 + blockWidth2, blockY2 + blockHeight2);
    glVertex2f(blockX2, blockY2 + blockHeight2);
    glEnd();

    glColor3f(0.3f, 0.5f, 0.7f);
    glBegin(GL_QUADS);
    glVertex2f(blockX3, blockY3);
    glVertex2f(blockX3 + blockWidth3, blockY3);
    glVertex2f(blockX3 + blockWidth3, blockY3 + blockHeight3);
    glVertex2f(blockX3, blockY3 + blockHeight3);
    glEnd();

    // Draw the obstacle
    glColor3f(1.0f, 0.5f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(obstacleX, obstacleY);
    glVertex2f(obstacleX + obstacleWidth, obstacleY);
    glVertex2f(obstacleX + obstacleWidth, obstacleY + obstacleHeight);
    glVertex2f(obstacleX, obstacleY + obstacleHeight);
    glEnd();

    glColor3f(1.0f, 0.5f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(obstacleX2, obstacleY2);
    glVertex2f(obstacleX2 + obstacleWidth2, obstacleY2);
    glVertex2f(obstacleX2 + obstacleWidth2, obstacleY2 + obstacleHeight2);
    glVertex2f(obstacleX2, obstacleY2 + obstacleHeight2);
    glEnd();

    glColor3f(1.0f, 0.5f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(obstacleX3, obstacleY3);
    glVertex2f(obstacleX3 + obstacleWidth3, obstacleY3);
    glVertex2f(obstacleX3 + obstacleWidth3, obstacleY3 + obstacleHeight3);
    glVertex2f(obstacleX3, obstacleY3 + obstacleHeight3);
    glEnd();

    glColor3f(1.0f, 0.5f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(obstacleX4, obstacleY4);
    glVertex2f(obstacleX4 + obstacleWidth4, obstacleY4);
    glVertex2f(obstacleX4 + obstacleWidth4, obstacleY4 + obstacleHeight4);
    glVertex2f(obstacleX4, obstacleY4 + obstacleHeight4);
    glEnd();

    glColor3f(1.0f, 0.5f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(obstacleX5, obstacleY5);
    glVertex2f(obstacleX5 + obstacleWidth5, obstacleY5);
    glVertex2f(obstacleX5 + obstacleWidth5, obstacleY5 + obstacleHeight5);
    glVertex2f(obstacleX5, obstacleY5 + obstacleHeight5);
    glEnd();

    glColor3f(1.0f, 0.5f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(obstacleX6, obstacleY6);
    glVertex2f(obstacleX6 + obstacleWidth6, obstacleY6);
    glVertex2f(obstacleX6 + obstacleWidth6, obstacleY6 + obstacleHeight6);
    glVertex2f(obstacleX6, obstacleY6 + obstacleHeight6);
    glEnd();

    glColor3f(1.0f, 0.5f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(obstacleX7, obstacleY7);
    glVertex2f(obstacleX7 + obstacleWidth7, obstacleY7);
    glVertex2f(obstacleX7 + obstacleWidth7, obstacleY7 + obstacleHeight7);
    glVertex2f(obstacleX7, obstacleY7 + obstacleHeight7);
    glEnd();

    glColor3f(1.0f, 0.5f, 0.0f);
    glBegin(GL_QUADS);
    glVertex2f(obstacleX8, obstacleY8);
    glVertex2f(obstacleX8 + obstacleWidth8, obstacleY8);
    glVertex2f(obstacleX8 + obstacleWidth8, obstacleY8 + obstacleHeight8);
    glVertex2f(obstacleX8, obstacleY8 + obstacleHeight8);
    glEnd();

    // draw  teleporter 1
    glColor3f(0.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(teleporterx1, teleportery1);
    glVertex2f(teleporterx1 + teleporterx1width , teleportery1 );
    glVertex2f(teleporterx1 + teleporterx1width, teleportery1 + teleporterx1Height);
    glVertex2f(teleporterx1, teleportery1 + teleporterx1Height);
    glEnd();

    // draw  teleporter 2
    glColor3f(0.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
    glVertex2f(teleporterx2, teleportery2);
    glVertex2f(teleporterx2 + teleporterx1width , teleportery2 );
    glVertex2f(teleporterx2 + teleporterx1width, teleportery2 + teleporterx1Height);
    glVertex2f(teleporterx2, teleportery2 + teleporterx1Height);
    glEnd();

// Draw the coins
    glColor3f(1.0f, 0.4f, 0.4f); // Orange color for coins
    for (const auto& coin : coins) {
        if (coin.active) { // Draw only active coins
            glBegin(GL_TRIANGLE_FAN);
            for (int i = 0; i < 360; i++) {
                float angle = i * 3.1415926 / 180;
                glVertex2f(coin.x + coin.radius * cos(angle), coin.y + coin.radius * sin(angle));
            }
            glEnd();
        }
    }
    //call draw heart
    for (const auto& health : healths) {
    if (health.active) { // Draw only active health objects
        glColor3f(0.0f, 1.0f, 0.0f); // Set color to red
        drawHeart(health.x, health.y, health.radius);
    }
   }
  // Draw end goal ball
  if (!gameOver) {
     glColor3f(1.0f, 1.0f, 0.0f); // Set color to yellow
    drawFilledCircle(ballX1, ballY1, ballRadius1, 360);
    glVertex2f(endBallX, endBallY);
  }

  if (lives==0) {
        glColor3f(1.0f, 0.0f, 0.0f); // Red color
        drawText("Game Over!", 340, 380); // Position of the text
         std::string text2 = "Score: " + std::to_string(score);
         drawText(text2.c_str(),340, 350);
    }
    //For showing lives and Score at the top corner of the screen
    if (lives > 0) {
        glColor3f(0.0f, 1.0f, 0.0f); // Red color
        // Draw text with the integer variable
        std::string text1 = "Lives: " + std::to_string(lives);
        drawText(text1.c_str(), 650, 680);

        std::string text2 = "Score: " + std::to_string(score);
        drawText(text2.c_str(), 650, 650);

         if(gameGoal_Reach_Status==true){

            glColor3f(0.0f, 1.0f, 0.0f); // Green color for text
       drawText("Congratulations! You reached the goal!", 280, 350); // Position of the text
         std::string text2 = "Score: " + std::to_string(score);
         drawText(text2.c_str(),280, 320);
    }
    }
  jumpLogic();// jump logic
  glutSwapBuffers();

}

void collision(){

   // Check for collision with wall
  if (ballX + ballRadius > wallX1 && ballX - ballRadius < wallX1 + wallWidth &&
      ballY + ballRadius > wallY1 && ballY - ballRadius < wallY1 + wallHeight) {
    // Bounce back from the wall
    if (ballX + ballRadius > wallX1 && ballX - ballRadius < wallX1 + wallWidth / 2.0f) {
      ballX -= speed;
    } else {
      ballX += speed;
    }
    //back from top bottom
    if (ballY + ballRadius > wallY1 && ballY - ballRadius < wallY1 + wallHeight/ 2.0f) {
      ballY -= speed;
    } else {
      ballY += speed;
    }
  }
   if (ballX + ballRadius > wallX2 && ballX - ballRadius < wallX2 + wallWidth2 &&
      ballY + ballRadius > wallY2 && ballY - ballRadius < wallY2 + wallHeight2) {
    // Bounce back from the wall
    if (ballX + ballRadius > wallX2 && ballX - ballRadius < wallX2 + wallWidth2 / 2.0f) {
      ballX -= speed;
    } else {
      ballX += speed;
    }
     //back from top bottom
    if (ballY + ballRadius > wallY2 && ballY - ballRadius < wallY2 + wallHeight2/ 2.0f) {
      ballY -= speed;
    } else {
      ballY += speed;
    }
  }
 if (ballX + ballRadius > wallX3 && ballX - ballRadius < wallX3 + wallWidth3 &&
      ballY + ballRadius > wallY3 && ballY - ballRadius < wallY3 + wallHeight3) {
    // Bounce back from the wall
    if (ballX + ballRadius > wallX3 && ballX - ballRadius < wallX3 + wallWidth3 / 2.0f) {
      ballX -= speed;
    } else {
      ballX += speed;
    }
                     //back from top bottom
    if (ballY + ballRadius > wallY3 && ballY - ballRadius < wallY3 + wallHeight3/ 2.0f) {
      ballY -= speed;
    } else {
      ballY += speed;
    }
  }

  if (ballX + ballRadius > wallX4 && ballX - ballRadius < wallX4 + wallWidth4 &&
      ballY + ballRadius > wallY4 && ballY - ballRadius < wallY4 + wallHeight4) {
    // Bounce back from the wall
    if (ballX + ballRadius > wallX4 && ballX - ballRadius < wallX4 + wallWidth4 / 2.0f) {
      ballX -= speed;
    } else {
      ballX += speed;
    }
                 //back from top bottom
    if ( ballY + ballRadius > wallY4 && ballY - ballRadius < wallY4 + wallHeight4/ 2.0f) {
      ballY -= speed;
    } else {
      ballY += speed;
    }
  }
  if (ballX + ballRadius > wallX5 && ballX - ballRadius < wallX5 + wallWidth5 &&
      ballY + ballRadius > wallY5 && ballY - ballRadius < wallY5 + wallHeight5) {
    // Bounce back from the wall
    if (ballX + ballRadius > wallX5 && ballX - ballRadius < wallX5 + wallWidth5 / 2.0f) {
      ballX -= speed;
    } else {
      ballX += speed;
    }
    //back from top bottom
    if ( ballY + ballRadius > wallY5 && ballY - ballRadius < wallY5 + wallHeight5/ 2.0f) {
      ballY -= speed;
    } else {
      ballY += speed;
    }
  }
  if (ballX + ballRadius > wallX6 && ballX - ballRadius < wallX6 + wallWidth6 &&
      ballY + ballRadius > wallY6 && ballY - ballRadius < wallY6 + wallHeight6) {
    // Bounce back from the wall
    if (ballX + ballRadius > wallX6 && ballX - ballRadius < wallX6 + wallWidth6 / 2.0f) {
      ballX -= speed;
    } else {
      ballX += speed;
    }
    //back from top bottom
    if (ballY + ballRadius > wallY6 && ballY - ballRadius < wallY6 + wallHeight6/ 2.0f) {
      ballY -= speed;
    } else {
      ballY += speed;
    }
  }
    if (ballX + ballRadius > wallX7 && ballX - ballRadius < wallX7 + wallWidth7 &&
      ballY + ballRadius > wallY7 && ballY - ballRadius < wallY7 + wallHeight7) {
    // Bounce back from the wall
    if (ballX + ballRadius > wallX7 && ballX - ballRadius < wallX7 + wallWidth7 / 2.0f) {
      ballX -= speed;
    } else {
      ballX += speed;
    }
    //back from top bottom
    if (ballY + ballRadius > wallY7 && ballY - ballRadius < wallY7 + wallHeight7/ 2.0f) {
      ballY -= speed;
    } else {
      ballY += speed;
    }
  }
    if (ballX + ballRadius > wallX8 && ballX - ballRadius < wallX8 + wallWidth8 &&
      ballY + ballRadius > wallY8 && ballY - ballRadius < wallY8 + wallHeight8) {
    // Bounce back from the wall
    if (ballX + ballRadius > wallX8 && ballX - ballRadius < wallX8 + wallWidth8 / 2.0f) {
      ballX -= speed;
    } else {
      ballX += speed;

    }
    //back from top bottom
    if (ballY + ballRadius > wallY8 && ballY - ballRadius < wallY8 + wallHeight8/ 2.0f) {
      ballY -= speed;
    } else {
      ballY += speed;
    }
  }
    if (ballX + ballRadius > wallX9 && ballX - ballRadius < wallX9 + wallWidth9 &&
      ballY + ballRadius > wallY9 && ballY - ballRadius < wallY9 + wallHeight9) {
    // Bounce back from the wall
    if (ballX + ballRadius > wallX9 && ballX - ballRadius < wallX9 + wallWidth9 / 2.0f) {
      ballX -= speed;
      //std::cout << "wall9 ballX- !"<< std::endl;
    } else {
      ballX += speed;
      //std::cout << "wall9 ballX+ !" <<std::endl;
    }
             //back from top bottom
    if ( ballY + ballRadius > wallY9 && ballY - ballRadius < wallY9 + wallHeight9/ 2.0f) {
      ballY -= speed;
      //std::cout << "wall9 bally- !"<< std::endl;
    } else {
      ballY += speed;
     // std::cout << "wall9 ballY+ !"<< std::endl;
    }
    //std::cout << "wall9 x !" <<ballX<< "  y"<<ballY << std::endl;
  }
    if (ballX + ballRadius > wallX10 && ballX - ballRadius < wallX10 + wallWidth10 &&
      ballY + ballRadius > wallY10 && ballY - ballRadius < wallY10 + wallHeight10) {
    // Bounce back from the wall
    if (ballX + ballRadius > wallX10 && ballX - ballRadius < wallX10 + wallWidth10 / 2.0f) {
      ballX -= speed;
    } else {
      ballX += speed;
    }
         //back from top bottom
    if ( ballY + ballRadius > wallY10 && ballY - ballRadius < wallY10 + wallHeight10/ 2.0f) {
      ballY -= speed;
    } else {
      ballY += speed;
    }
  }
    if (ballX + ballRadius > wallX11 && ballX - ballRadius < wallX11 + wallWidth11 &&
      ballY + ballRadius > wallY11 && ballY - ballRadius < wallY11 + wallHeight11) {
    // Bounce back from the wall
    if (ballX + ballRadius > wallX11 && ballX - ballRadius < wallX11 + wallWidth11 / 2.0f) {
      ballX -= speed;
    } else {
      ballX += speed;
    }
     //back from top bottom
    if ( ballY + ballRadius > wallY11 && ballY - ballRadius < wallY11 + wallHeight11/ 2.0f) {
      ballY -= speed;
    } else {
      ballY += speed;
    }
  }
    if (ballX + ballRadius > wallX12 && ballX - ballRadius < wallX12 + wallWidth12 &&
      ballY + ballRadius > wallY12 && ballY - ballRadius < wallY12 + wallHeight12) {
    // Bounce back from the wall
    if (ballX + ballRadius > wallX12 && ballX - ballRadius < wallX12 + wallWidth12 / 2.0f) {
      ballX -= speed;
    } else {
      ballX += speed;
    }
 //back from top bottom
    if ( ballY + ballRadius > wallY12 && ballY - ballRadius < wallY12 + wallHeight12/ 2.0f) {
      ballY -= speed;
    } else {
      ballY += speed;
    }
  }
    if (ballX + ballRadius > wallX13 && ballX - ballRadius < wallX13 + wallWidth13 &&
      ballY + ballRadius > wallY13 && ballY - ballRadius < wallY13 + wallHeight13) {
    // Bounce back from the wall
    if (ballX + ballRadius > wallX13 && ballX - ballRadius < wallX13 + wallWidth13 / 2.0f) {
      ballX -= speed;
    } else {
      ballX += speed;
    }
                //back from top bottom
    if (  ballY + ballRadius > wallY13 && ballY - ballRadius < wallY13 + wallHeight13/ 2.0f) {
      ballY -= speed;
    } else {
      ballY += speed;
    }
  }
    if (ballX + ballRadius > wallX14 && ballX - ballRadius < wallX14 + wallWidth14 &&
      ballY + ballRadius > wallY14 && ballY - ballRadius < wallY14 + wallHeight14) {
    // Bounce back from the wall
    if (ballX + ballRadius > wallX14 && ballX - ballRadius < wallX14 + wallWidth14/ 2.0f) {
      ballX -= speed;
    } else {
      ballX += speed;
    }
            //back from top bottom
    if ( ballY + ballRadius > wallY14 && ballY - ballRadius < wallY14 + wallHeight14/ 2.0f) {
      ballY -= speed;
    } else {
      ballY += speed;
    }
  }
    if (ballX + ballRadius > wallX15 && ballX - ballRadius < wallX15 + wallWidth15 &&
      ballY + ballRadius > wallY15 && ballY - ballRadius < wallY15 + wallHeight15) {
    // Bounce back from the wall
    if (ballX + ballRadius > wallX15 && ballX - ballRadius < wallX15 + wallWidth15 / 2.0f) {
      ballX -= speed;
    } else {
      ballX += speed;
    }
        //back from top bottom
    if ( ballY + ballRadius > wallY15 && ballY - ballRadius < wallY15 + wallHeight15/ 2.0f) {
      ballY -= speed;
    } else {
      ballY += speed;
    }
  }
    if (ballX + ballRadius > wallX16 && ballX - ballRadius < wallX16 + wallWidth16 &&
      ballY + ballRadius > wallY16 && ballY - ballRadius < wallY16 + wallHeight16) {
    // Bounce back from the wall
    if (ballX + ballRadius > wallX16 && ballX - ballRadius < wallX16 + wallWidth16 / 2.0f) {
      ballX -= speed;
    } else {
      ballX += speed;
    }
    //back from top bottom
    if (ballY + ballRadius > wallY16 && ballY - ballRadius < wallY16 + wallHeight16/ 2.0f) {
      ballY -= speed;
    } else {
      ballY += speed;
    }
      }
    if (ballX + ballRadius > wallX17 && ballX - ballRadius < wallX17 + wallWidth17 &&
      ballY + ballRadius > wallY17 && ballY - ballRadius < wallY17 + wallHeight17) {
    // Bounce back from the wall
    if (ballX + ballRadius > wallX17 && ballX - ballRadius < wallX17 + wallWidth17 / 2.0f) {
      ballX -= speed;
    } else {
      ballX += speed;
    }
    //back from top bottom
    if ( ballY + ballRadius > wallY17 && ballY - ballRadius < wallY17 + wallHeight17/ 2.0f) {
      ballY -= speed;
    } else {
      ballY += speed;
    }
  }
    if (ballX + ballRadius > wallX18 && ballX - ballRadius < wallX18 + wallWidth18 &&
      ballY + ballRadius > wallY18 && ballY - ballRadius < wallY18 + wallHeight18) {
    // Bounce back from the wall
    if (ballX + ballRadius > wallX18 && ballX - ballRadius < wallX18 + wallWidth18 / 2.0f) {
      ballX -= speed;
    } else {
      ballX += speed;
    }
                    //back from top bottom
    if ( ballY + ballRadius > wallY18 && ballY - ballRadius < wallY18 + wallHeight18/ 2.0f) {
      ballY -= speed;
    } else {
      ballY += speed;
    }
  }
    if (ballX + ballRadius > wallX19 && ballX - ballRadius < wallX19 + wallWidth19 &&
      ballY + ballRadius > wallY19 && ballY - ballRadius < wallY19 + wallHeight19) {
    // Bounce back from the wall
    if (ballX + ballRadius > wallX19 && ballX - ballRadius < wallX19 + wallWidth19 / 2.0f) {
      ballX -= speed;
    } else {
      ballX += speed;
    }
    //back from top bottom
    if (ballY + ballRadius > wallY19 && ballY - ballRadius < wallY19 + wallHeight19/ 2.0f) {
      ballY -= speed;
    } else {
      ballY += speed;
    }
  }
    if (ballX + ballRadius > wallX20 && ballX - ballRadius < wallX20 + wallWidth20 &&
      ballY + ballRadius > wallY20 && ballY - ballRadius < wallY20 + wallHeight20) {
    // Bounce back from the wall
    if (ballX + ballRadius > wallX20 && ballX - ballRadius < wallX20 + wallWidth20/ 2.0f) {
      ballX -= speed;
    } else {
      ballX += speed;
    }
    //back from top bottom
    if ( ballY + ballRadius > wallY20 && ballY - ballRadius < wallY20 + wallHeight20/ 2.0f) {
      ballY -= speed;
    } else {
      ballY += speed;
    }
  }
    if (ballX + ballRadius > wallX21 && ballX - ballRadius < wallX21 + wallWidth21 &&
      ballY + ballRadius > wallY21 && ballY - ballRadius < wallY21 + wallHeight21) {
    // Bounce back from the wall
    if (ballX + ballRadius > wallX21 && ballX - ballRadius < wallX21 + wallWidth21 / 2.0f) {
      ballX -= speed;
    } else {
      ballX += speed;
    }
    //back from top bottom
    if ( ballY + ballRadius > wallY21 && ballY - ballRadius < wallY21 + wallHeight21/ 2.0f) {
      ballY -= speed;
    } else {
      ballY += speed;
    }
  }
    if (ballX + ballRadius > wallX22 && ballX - ballRadius < wallX22 + wallWidth22 &&
      ballY + ballRadius > wallY22 && ballY - ballRadius < wallY22 + wallHeight22) {
    // Bounce back from the wall left right
    if (ballX + ballRadius > wallX22 && ballX - ballRadius < wallX22 + wallWidth22 / 2.0f) {
      ballX -= speed;
    } else {
      ballX += speed;
    }
    //back from top bottom
        if ( ballY + ballRadius > wallY22 && ballY - ballRadius < wallY22 + wallHeight22/ 2.0f) {
      ballY -= speed;
    } else {
      ballY += speed;
    }
  }
   if (ballX + ballRadius > wallX23 && ballX - ballRadius < wallX23 + wallWidth23 &&
      ballY + ballRadius > wallY23 && ballY - ballRadius < wallY23 + wallHeight23) {
    // Bounce back from the wall
    if (ballX + ballRadius > wallX23 && ballX - ballRadius < wallX23 + wallWidth23 / 2.0f) {
      ballX -= speed;
    } else {
      ballX += speed;
    }
    //back from top bottom
    if ( ballY + ballRadius > wallY23 && ballY - ballRadius < wallY23 + wallHeight23/ 2.0f) {
      ballY -= speed;
    } else {
      ballY += speed;
    }
  }
 if (ballX + ballRadius > wallX24 && ballX - ballRadius < wallX24 + wallWidth24 &&
      ballY + ballRadius > wallY24 && ballY - ballRadius < wallY24 + wallHeight24) {
    // Bounce back from the wall
    if (ballX + ballRadius > wallX24 && ballX - ballRadius < wallX24 + wallWidth24 / 2.0f) {
      ballX -= speed;
    } else {
      ballX += speed;
    }
    //back from top bottom
    if (ballY + ballRadius > wallY24 && ballY - ballRadius < wallY24 + wallHeight24/ 2.0f) {
      ballY -= speed;
    } else {
      ballY += speed;
    }
  }
 /*if (ballX + ballRadius > wallX25 && ballX - ballRadius < wallX25 + wallWidth25 &&
      ballY + ballRadius > wallY25 && ballY - ballRadius < wallY25 + wallHeight25) {
    // Bounce back from the wall
    if (ballX + ballRadius > wallX25 && ballX - ballRadius < wallX25 + wallWidth25 / 2.0f) {
     // ballX -= speed;
    } else {
     // ballX += speed;
    }
//back from top bottom
    if (ballY + ballRadius > wallY25 && ballY - ballRadius < wallY25 + wallHeight25/ 2.0f) {
     // ballY -= speed;
    } else {
     // ballY += speed;
    }
  }*/
   if (ballX + ballRadius > wallX26 && ballX - ballRadius < wallX26 + wallWidth26 &&
      ballY + ballRadius > wallY26 && ballY - ballRadius < wallY26 + wallHeight26) {
    // Bounce back from the wall
    if (ballX + ballRadius > wallX26 && ballX - ballRadius < wallX26 + wallWidth26 / 2.0f) {
      ballX -= speed;
    } else {
      ballX += speed;
    }
    //back from top bottom
    if (ballY + ballRadius > wallY26 && ballY - ballRadius < wallY26 + wallHeight26/ 2.0f) {
      ballY -= speed;
    } else {
      ballY += speed;
    }
  }
}

//Static Block collision check
void S_Block_Enemy_Colli_check(){
    if (ballX + ballRadius > obstacleX && ballX - ballRadius < obstacleX + obstacleWidth &&
        ballY + ballRadius > obstacleY && ballY - ballRadius < obstacleY + obstacleHeight) {
        gameOver = true;
    }
if (ballX + ballRadius > obstacleX2 && ballX - ballRadius < obstacleX2 + obstacleWidth2 &&
        ballY + ballRadius > obstacleY2 && ballY - ballRadius < obstacleY2 + obstacleHeight2) {
        gameOver = true;
    }
if (ballX + ballRadius > obstacleX3 && ballX - ballRadius < obstacleX3 + obstacleWidth3 &&
        ballY + ballRadius > obstacleY3 && ballY - ballRadius < obstacleY3 + obstacleHeight3) {
        gameOver = true;
    }
if (ballX + ballRadius > obstacleX4 && ballX - ballRadius < obstacleX4 + obstacleWidth4 &&
        ballY + ballRadius > obstacleY4 && ballY - ballRadius < obstacleY4 + obstacleHeight4) {
        gameOver = true;
    }
if (ballX + ballRadius > obstacleX5 && ballX - ballRadius < obstacleX5 + obstacleWidth5 &&
        ballY + ballRadius > obstacleY5 && ballY - ballRadius < obstacleY5 + obstacleHeight5) {
        gameOver = true;
    }
if (ballX + ballRadius > obstacleX6 && ballX - ballRadius < obstacleX6 + obstacleWidth6 &&
        ballY + ballRadius > obstacleY6 && ballY - ballRadius < obstacleY6 + obstacleHeight6) {
        gameOver = true;
        //std::cout << "Game Over!" << std::endl;
    }
if (ballX + ballRadius > obstacleX7 && ballX - ballRadius < obstacleX7 + obstacleWidth7 &&
        ballY + ballRadius > obstacleY7 && ballY - ballRadius < obstacleY7 + obstacleHeight7) {
        gameOver = true;
    }
if (ballX + ballRadius > obstacleX8 && ballX - ballRadius < obstacleX8 + obstacleWidth8 &&
        ballY + ballRadius > obstacleY8 && ballY - ballRadius < obstacleY8 + obstacleHeight8) {
        gameOver = true;
    }

}
 void checkTeleport(){
    //teleporter 1
    if (ballX + ballRadius > teleporterx1  && ballX - ballRadius < teleporterx1  + teleporterx1width  &&
        ballY + ballRadius > teleportery1  && ballY - ballRadius < teleportery1  + teleporterx1Height ) {
        ballX=20;
        ballY=610;
    }
    //teleporter 2
    if (ballX + ballRadius > teleporterx2  && ballX - ballRadius < teleporterx2  + teleporterx1width  &&
        ballY + ballRadius > teleportery2  && ballY - ballRadius < teleportery2  + teleporterx1Height ) {
        ballX=200;
        ballY=20;
    }

 }

//Block collision
void update(int value) {

     if (gameOver) {
        lives--; // Decrease lives
        std::cout << "Lives left: " << lives << std::endl;
        // Reset ball position - here is where the ball reset logic applies
        ballX = 30.0f;
        ballY = 10.0f;
        // Reset game over flag
        gameOver = false;

        if (lives==-1) {
            std::cout << "Game Over" << std::endl;
            exit(0); // Exit the game
        }
    }
    // Update block position
    blockX += deltaX;
    blockX2 += deltaX2;
    blockX3 += deltaX3;
 checkTeleport();//Teleport check
S_Block_Enemy_Colli_check();

// Check for collision with screen boundaries
if (blockX > rightBound - blockWidth) {
        blockX = rightBound - blockWidth; // Reset block position when it reaches the right bound
        deltaX = -deltaX; // Reverse direction in x-axis
    }
if (blockX < leftBound) {
        blockX = leftBound; // Reset block position when it reaches the left bound
        deltaX = -deltaX; // Reverse direction in x-axis
    }
if (ballX + ballRadius > blockX && ballX - ballRadius < blockX + blockWidth &&
        ballY + ballRadius > blockY && ballY - ballRadius < blockY + blockHeight) {
        gameOver = true; // Set game over flag
    }
if (blockX2 > rightBound2 - blockWidth2) {
        blockX2 = rightBound2 - blockWidth2; // Reset block position when it reaches the right bound
        deltaX2 = -deltaX2; // Reverse direction in x-axis
    }
if (blockX2 < leftBound2) {
        blockX2 = leftBound2; // Reset block position when it reaches the left bound
        deltaX2 = -deltaX2; // Reverse direction in x-axis
    }
if (ballX + ballRadius > blockX2 && ballX - ballRadius < blockX2 + blockWidth &&
        ballY + ballRadius > blockY2 && ballY - ballRadius < blockY2+ blockHeight) {
        gameOver = true; // Set game over flag
    }

if (blockX3 > rightBound3 - blockWidth3) {
        blockX3 = rightBound3 - blockWidth3; // Reset block position when it reaches the right bound
        deltaX3 = -deltaX3; // Reverse direction in x-axis
    }
if (blockX3 < leftBound3) {
        blockX3 = leftBound3; // Reset block position when it reaches the left bound
        deltaX3 = -deltaX3; // Reverse direction in x-axis
    }
if (ballX + ballRadius > blockX3 && ballX - ballRadius < blockX3 + blockWidth3 &&
        ballY + ballRadius > blockY3 && ballY - ballRadius < blockY3 + blockHeight3) {
        gameOver = true; // Set game over flag
    }

//Collision of obstacles
if (ballX + ballRadius > obstacleX && ballX - ballRadius < obstacleX + obstacleWidth &&
        ballY + ballRadius > obstacleY && ballY - ballRadius < obstacleY + obstacleHeight) {
        gameOver = true;
    }
if (ballX + ballRadius > obstacleX2 && ballX - ballRadius < obstacleX2 + obstacleWidth2 &&
        ballY + ballRadius > obstacleY2 && ballY - ballRadius < obstacleY2 + obstacleHeight2) {
        gameOver = true;
    }
if (ballX + ballRadius > obstacleX3 && ballX - ballRadius < obstacleX3 + obstacleWidth3 &&
        ballY + ballRadius > obstacleY3 && ballY - ballRadius < obstacleY3 + obstacleHeight3) {
        gameOver = true;

    }
if (ballX + ballRadius > obstacleX4 && ballX - ballRadius < obstacleX4 + obstacleWidth4 &&
        ballY + ballRadius > obstacleY4 && ballY - ballRadius < obstacleY4 + obstacleHeight4) {
        gameOver = true;
    }
if (ballX + ballRadius > obstacleX5 && ballX - ballRadius < obstacleX5 + obstacleWidth5 &&
        ballY + ballRadius > obstacleY5 && ballY - ballRadius < obstacleY5 + obstacleHeight5) {
        gameOver = true;

    }
if (ballX + ballRadius > obstacleX6 && ballX - ballRadius < obstacleX6 + obstacleWidth6 &&
        ballY + ballRadius > obstacleY6 && ballY - ballRadius < obstacleY6 + obstacleHeight6) {
        gameOver = true;

    }
if (ballX + ballRadius > obstacleX7 && ballX - ballRadius < obstacleX7 + obstacleWidth7 &&
        ballY + ballRadius > obstacleY7 && ballY - ballRadius < obstacleY7 + obstacleHeight7) {
        gameOver = true;
    }
if (ballX + ballRadius > obstacleX8 && ballX - ballRadius < obstacleX8 + obstacleWidth8 &&
        ballY + ballRadius > obstacleY8 && ballY - ballRadius < obstacleY8 + obstacleHeight8) {
        gameOver = true;
    }

// Check for collision with coins
    for (auto& coin : coins) {
        if (coin.active) { // Check only active coins
            float dist = sqrt(pow(coin.x - ballX, 2) + pow(coin.y - ballY, 2));

            if (dist < ballRadius + coin.radius) {
                score++; // Increase score
                std::cout << "Score: " << score << std::endl;
                coin.active = false; // Deactivate the coin
            }}}

// Check for collision with health objects
    for (auto& health : healths) {
        if (health.active) { // Check only active health objects
            float dist = sqrt(pow(health.x - ballX, 2) + pow(health.y - ballY, 2));
            if (dist < ballRadius + health.radius) {
            // Perform actions upon collision with a health object
            // For example, increase the player's health
            lives += 1;
            std::cout << "Player Health: " << lives << std::endl;
            health.active = false; // Deactivate the health object
            }
        }
    }
    // Redraw the scene
    glutPostRedisplay();
    //Call update function again after 16 milliseconds
glutTimerFunc(8, update, 0);
}

void moveBall(int key, int x, int y) {
  switch (key){
    case GLUT_KEY_LEFT:
      if (ballX - ballRadius > 0) {
        ballX -= speed;
        glutPostRedisplay();
      }
      break;
    case GLUT_KEY_RIGHT:
      if (ballX + ballRadius < width) {
        ballX += speed;
        glutPostRedisplay();
      }
      break;
    case GLUT_KEY_UP:
      if (ballY + ballRadius < height) {
        ballY += speed;
        glutPostRedisplay();
      }
      break;
    case GLUT_KEY_DOWN:
      if (ballY - ballRadius > 0) {
        ballY -= speed;
        glutPostRedisplay();
      }
      break;
  }

    //check for collision
    collision();
  // Check if player reached end goal
   checkEnd();
  glutPostRedisplay();
}

void jump(unsigned char key, int, int) {
    if (key == ' ') {
        // Jump action
        jumpeStatus=true;
        glutPostRedisplay();
    }
}

void initialize() {
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(width, height);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Treasure Collector");

  glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0.0f, width, 0.0f, height);
}

int main(int argc, char** argv) {
  glutInit(&argc, argv);
  initialize();
  glutDisplayFunc(display);
  glutSpecialFunc(moveBall);
  glutKeyboardFunc(jump);
  initializeCoins();
  initializeHealths();
  glutTimerFunc(8, update, 0);

  glutMainLoop();

  return 0;
}
