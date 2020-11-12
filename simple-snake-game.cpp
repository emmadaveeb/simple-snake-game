#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

const int width = 30;
const int height = 40;
int X;
int Y;
int fruitX;
int fruitY;
bool gameOver;

enum direction {LEFT, RIGHT, UP, DOWN};
direction dir;

void start(){

    gameOver = false;
    X = width/2;
    Y = height/2;
    fruitX = rand() % 30 + 1;
    fruitY = rand() % 40 + 1;
}


void draw(){


    system("cls");
    for(int i = 0; i < width; i++)
        cout << '#';
    
    cout << endl;

    for(int i = 0; i < height; i++){

        for(int j = 0; j < width; j++){
           
            if(j == 0 || j == (width - 1))
                cout << '#';
            else if(j == X && i == Y) {
                cout << 'O';
            }
            else if(i == fruitY && j == fruitX){
                cout << 'F';
            }
            else{
                cout << ' ';
            }
        }

        cout << endl;  
    }


    
    for(int i = 0; i < width; i++)
        cout << '#';

    cout << endl;
        
}

void logic(){

    switch(dir){

        case LEFT:
            X--;
            break;
        case RIGHT:
            X++;
            break;
        case UP:
            Y--;
            break;
        case DOWN:
            Y++;
            break;
        default:
            break;

    }

    if((X >= width) || (X < 0) || (Y > height) || (Y <= 0))
        gameOver = true;



}

void input(){

    if(_kbhit()){

        switch(_getch()){

            case 'w':
                dir = UP;
                break;
            case 'd':
                dir = RIGHT;
                break;
            case 's':
                dir = DOWN;
                break;
            case 'a':
                dir = LEFT;
                break;
        }


        }
    }


int main(){
    
    start();
    while(!gameOver){
        draw();
        input();
        logic();
    }

    
    //system("pause");

}