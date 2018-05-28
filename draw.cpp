#include "draw.h"



// ham nhap vi tri dat tau
PLACESHIPS UserInputShipPlacement()
{
	int d, x, y;
	// kiem tra neu nguoi dung nhap sai, yeu cau nhap lai
	PLACESHIPS tmp;
	// bien gan
	tmp.shipType.onGrid[0].X = -1;
	// nhan 3 gia tri tu nguoi dung
	cin >> d >> x >> y;
	if (d != 0 && d != 1) return tmp;
	if (x < 0 || x >= BOARD_WIDTH) return tmp;
	if (y <0 || y >= BOARD_HEIGHT) return tmp;
	// if 3 so do thoai man, gan chung vao bang
	tmp.direction = (DIRECTION)d;
	tmp.shipType.onGrid[0].X = x;
	tmp.shipType.onGrid[0].Y = y;
	return tmp;
}

//void LoadShips(SHIP *ship)

	// thiet lap kich co diem cho moi tau


// // hiển thị bàn chơi cho người chơi
void DrawBoad(PLAYER thisPlayer,int indexThisPlayer ,bool gameRunning)
{
	// ve bang cho tung nguoi choi
	cout << "PLAYER " << indexThisPlayer << " 's GAME BOARD \n";
	cout << "---------------------\n";
	// lặp qua hàng đầu và các cột số
	cout << "   ";
	for (int w = 0; w < BOARD_WIDTH; ++w){ // chiều ngang
		if (w < 10)
			// nếu chỉ số có một chữ số thêm 2 khoảng trắng
			cout << w << " ";
		else if (w >= 10)
			cout << w << " ";
	}
	cout << "\n";
	// vòng lặp qua mỗi ô và hiển thị hình
	for (int h = 0; h< BOARD_HEIGHT; ++h){
		for (int w = 0; w < BOARD_WIDTH; ++w){
			// neu đây là điểm đầu tiên bên trái, đánh dấu số lưới đầu tiên
			if (w == 0 && h < 10) cout << h << " ";
			if( w == 0 && h>= 10) cout << h ;

			// if h dài một kí tự, thêm một khoảng trống để khoảng cách các ô bằng nhau
			if (w < 10 && w == 0) cout << " ";
			if(w >= 10) cout << " ";
			// hiển thị lưới, nếu trò chơi chưa chạy, đang đặt vị trí tàu , thì hiển trị các tàu
			if (gameRunning == false) cout << thisPlayer.grid[w][h] << " ";
			// nếu game đang chơi, thì ko hiển thị các tàu, chỉ  hiển thị các điểm tàu bị bắn trúng
			if (gameRunning == true && thisPlayer.grid[w][h] != isSHIP){
				cout << thisPlayer.grid[w][h] << " ";
			}
			else if (gameRunning == true && thisPlayer.grid[w][h] == isSHIP)
			{
				cout << isWATER << " ";
			}
			// if toi diem cuoi cua chieu ngang
			if (w == BOARD_WIDTH - 1) cout << "\n";
		}

	}
}

// ham kiểm tra vị tri đặt boom có nằm trong bảng ko
bool UserInputAttack(int &x, int &y, int theplayer)
{
	cout << "\nPLAYER " << theplayer << ", nhap vi tri tha boom: ";
	bool goodInput = false;
	cin >> x >> y;
	if (x < 0 || x >= BOARD_WIDTH) return goodInput;
	if (y < 0 || y >= BOARD_HEIGHT) return goodInput;
	goodInput = true;
	return goodInput;
}


// ham check xem con hinh tau ko
bool GameOverCheck(PLAYER enemyPlayer)
{
	bool winner = true;
	// vòng lặp kiem tra tau cua tung ng choi
	for (int w = 0; w < BOARD_WIDTH; ++w){
		for (int h = 0; h < BOARD_HEIGHT; ++h){
			// if van con tau thi doi thu ko qua
			if (enemyPlayer.grid[w][h] == isSHIP)
			{
				winner = false;
				return winner;
			}
		}
	}
	// if mà hết hình tàu rồi thì người chơi thắng, end game
	return winner;

}

