#ifndef STUDENTDB_STUDENT_H
#define STUDENTDB_STUDENT_H

#include<iostream>
#include<string>
using namespace std;
// khai báo biến
// biến hằng số nguyên, giá trị không thay đổi được
const int BOARD_WIDTH = 15; // chiều ngang bảng
const int BOARD_HEIGHT = 15; // chiều cao bảng
const int SHIP_TYPES = 4; // số loại tàu

const char isWATER = 45; // vẽ '-' lên ô trên bảng
const char isHIT = 'X';   // hình đạn bắn trúng tàu
const char isSHIP = 'S';   // hình tàu
const char isMISS = '0';  // hình đạn bắn trượt

// định nghĩa kiểu dữ liệu 1 điểm trên bảng
struct POINT {
    // thành phần dữ liệu của cấu trúc "diem"
    // vi tri tren bang = mot diem
    int X; // ngang
    int Y; // doc
};

 // định nghĩa kiểu dữ liệu 1 tàu
struct SHIP {
    string name; // ten tau
    int length; // tong so diem tren bang
    POINT onGrid[5]; // so diem lon nhat cua tau to nhat
};



// kiểu dữ liệu người chơi
struct PLAYER {
    char grid[BOARD_WIDTH][BOARD_HEIGHT];
}; // bỏ qua người chơi 0, đặt là người chơi số 1 và số 2
// kiểu liệt kê phương hướng
enum DIRECTION{HORIZONTAL,VERTICAL}; // kê khai phương hướng

// ve tau
struct PLACESHIPS {
    DIRECTION direction;
    SHIP shipType;
};

// khai báo các hàm
//void LoadShips(SHIP ); // hàm khai bao cac loai tau
//void ResetBoard(PLAYER); // vẽ  bảng ban đầu
void DrawBoad(PLAYER, int, bool); // vẽ lai bảng khi nhập tàu và onl game
PLACESHIPS UserInputShipPlacement(); // nhap vị trí của các loại tàu
bool UserInputAttack(int&, int&, int); // nhập vị trí đặt tên lửa
bool GameOverCheck(PLAYER enemyPlayer); // kiểm tra thắng thua

#endif // STUDENTDB_STUDENT_H

