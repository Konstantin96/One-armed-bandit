#pragma once
#include "Libery.h"

class OneArmedBandit {
    int Chips;
    int **Ring;
    void RandQueue(int);
public:
    OneArmedBandit();
    void setChips(int);
    void Start();
    void ShowRings();
    int getScore();
    ~OneArmedBandit();
};
OneArmedBandit::OneArmedBandit() {
    srand((size_t)time(nullptr));
    this->Ring = new int*[3];
    for (int i = 0;i < 3;i++) {
        this->Ring[i] = new int[10];
        for (int j = 0;j < 10;j++) {
            this->Ring[i][j] = j;
        }
    }
    this->Chips = 0;
}
void OneArmedBandit::setChips(int Value) {
    this->Chips += Value;
}
void OneArmedBandit::Start() {
    for (int i = 0;i < 3;i++) {
        this->RandQueue(i);
    }
}
void OneArmedBandit::RandQueue(int Value) {
    int random = 1+rand() % 8;
    int tmp;
    for (int i = 0;i < random;i++) {
        tmp = this->Ring[Value][0];
        for (int j = 0;j < 9;j++) {
            this->Ring[Value][j] = this->Ring[Value][j + 1];
        }
        this->Ring[Value][9] = tmp;
    }
}
void OneArmedBandit::ShowRings() {
    for (int i = 3;i < 6;i++) {
        printf("\t");
        if (i == 4) {
            printf("- ");
        }
        else {
            printf("  ");
        }
        for (int j = 0;j < 3;j++) {
            switch (this->Ring[j][i]) {
            case 0:printf("%c ", char(2));break;
            case 1:printf("%c ", char(3));break;
            case 2:printf("%c ", char(4));break;
            case 3:printf("%c ", char(5));break;
            case 4:printf("%c ", char(6));break;
            case 5:printf("%c ", char(15));break;
            case 6:printf("%c ", char(19));break;
            case 7:printf("%c ", char(1));break;
            case 8:printf("%c ", char(14));break;
            case 9:printf("%c ", char(11));break;
            };
        }
        if (i == 4) {
            printf("-");
        }
        printf("\n");
    }
}
int OneArmedBandit::getScore() {
    if ((this->Ring[0][4]- this->Ring[1][4])==1&& (this->Ring[1][4] - this->Ring[2][4])==1) {
        return 30;
    }
    else if(this->Ring[0][4]==5&& this->Ring[1][4] == 5&& this->Ring[2][4] == 5) {
        return 50;
    }
    else if(this->Ring[0][4] == this->Ring[1][4] && this->Ring[1][4] ==  this->Ring[2][4]) {
        return 100;
    }
    else {
        return 0;
    }
}
OneArmedBandit::~OneArmedBandit() {
}
void showPanel(char *, int);
void Line(char, int);
void StringToCenter(char *, int);
 
void showMenu();