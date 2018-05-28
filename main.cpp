#include "draw.h"
int main()
{
    bool gameRunning = false;
    SHIP ship[SHIP_TYPES];
    ship[0].name = "TAU HO TONG"; ship[0].length = 2;
	ship[1].name = "TAU KHU TRUC"; ship[1].length = 3;
	ship[2].name = "TAU CHIEN"; ship[2].length = 4;
	ship[3].name = "TAU SAN BAY"; ship[3].length = 5;

    // thiet lap kich co diem cho moi tau
   // LoadShips(&ship);

	PLAYER player[3];

    	for (int plyr = 1; plyr <3; ++plyr)
	{
		// doi voi moi diem tren bang, thiet lap vi tri dat bom
		for (int w = 0; w < BOARD_WIDTH; ++w){
			for (int h = 0; h < BOARD_HEIGHT; ++h){
				player[plyr].grid[w][h] = isWATER;
			}
		}
		// lap lai nguoi choi tiep theo
	}

	// các giai đoạn của trò chơi
	// lướt qua từng người chơi
	for (int aplyr = 1; aplyr < 3; ++aplyr)
	{
		// vòng qua từng loại tàu để đặt tàu trên bảng
		for (int thisShip = 0; thisShip < SHIP_TYPES; ++thisShip)
		{
			// hiển thị bàn chơi cho người chơi khi game chưa bắt đầu
			system("cls");
			DrawBoad(player[aplyr], aplyr,gameRunning);
			// hiển thị hướng dẫn
			cout << "\n";
			cout << "HUONG DAN CHOI GAME(Player " << aplyr << ") \n \n ";
			cout << "SAP DAT VI TRI TAU CHIEN \n \n";
			cout << "Ban dat vi tri cho cac tau cua minh theo dinh dang sau:\n";
			cout << "Chieu( 0: ngang, 1: doc), toa do o dau cua tau X(cot) , Y(hang) \n";
			cout << "Vi du: 0 3 7  dat mot con tau bat dau o X=3, Y=7 theo chieu ngang \n";

			cout << endl << " ---------------------------------- " << endl << endl;
			cout << "Ship: '" << ship[thisShip].name << "' voi do dai = " << ship[thisShip].length << "\n";
			cout << "Ban muon dat tau nay o dau? (chieu, toa do x, toa do y) = ";
			// nhan du lieu tu nguoi dung và vong lăp
			PLACESHIPS aship; // vẽ tàu
			aship.shipType.onGrid[0].X = -1;
			while (aship.shipType.onGrid[0].X == -1)
			{
				aship = UserInputShipPlacement();
			}
			// kết hợp dữ liệu người chơi với dữ liệu cac tàu
			aship.shipType.length = ship[thisShip].length;
			aship.shipType.name = ship[thisShip].name;
			// thêm điểm đầu tiên cua tau vào bảng trò chơi của người chơi hiện tại
			player[aplyr].grid[aship.shipType.onGrid[0].X][aship.shipType.onGrid[0].Y] = isSHIP;

			// Xác đinh tất cả các điểm tàu dựa trên chiều dài và hướng đã nhâp;
			for (int i = 1; i < aship.shipType.length; ++i)
			{
				if (aship.direction == HORIZONTAL) {
					aship.shipType.onGrid[i].X = aship.shipType.onGrid[i - 1].X + 1;
					aship.shipType.onGrid[i].Y = aship.shipType.onGrid[i - 1].Y;
				}
				if (aship.direction == VERTICAL){
					aship.shipType.onGrid[i].Y = aship.shipType.onGrid[i - 1].Y + 1;
					aship.shipType.onGrid[i].X = aship.shipType.onGrid[i - 1].X;
				}
				// them cac diem tau con lai vao
				player[aplyr].grid[aship.shipType.onGrid[i].X][aship.shipType.onGrid[i].Y] = isSHIP;

			}
			// vong lap trở lại qua từng loại tàu
		}
		// vong lap tro lai qua moi nguoi choi
	}
	// hoàn thành xong giai đoan chuẩn bị

	// ----------------------------------------------------------
	// bat dau vao tran
	gameRunning = true;
	int thisPlayer = 1;
	do {
		//
		int enemyPlayer;
		if (thisPlayer == 1) enemyPlayer = 2;
		if (thisPlayer == 2) enemyPlayer = 1;
		system("cls");
		// hiển thị bàn chơi trong quá trình chơi
		DrawBoad(player[enemyPlayer],enemyPlayer,gameRunning);
		// nhan tan cong tu ke thu
		bool goodInput = false;
		int x, y;
		while (goodInput == false) {
			goodInput = UserInputAttack(x, y, thisPlayer);// kiểm tra vị trí đặt bom có nằm trong bảng ko
		}
		// kiểm tra bảng, nếu có tàu ở đó, đặt là HIT 'X', nếu không đặt là MISS  'O'
		if (player[enemyPlayer].grid[x][y] == isSHIP) player[enemyPlayer].grid[x][y] = isHIT;
		if (player[enemyPlayer].grid[x][y] == isWATER) player[enemyPlayer].grid[x][y] = isMISS;
		// kiểm tra để kết thúc trò chơi, nếu trả về 0 thì ko ai thắng
		bool aWin = GameOverCheck(player[enemyPlayer]);
		if (aWin == true) {
			gameRunning = false;
			break;
		}
		// thay the giua hai người chơi
		thisPlayer = (thisPlayer == 1) ? 2 : 1;
	}    while (gameRunning);

	system("cls");
	cout << " \n CONGRATULATIONS!!! PLAYER " << thisPlayer << " HAS WON THE GAME! \n \n";
	system("pause");
	return 0;


}
