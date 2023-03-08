#include "Player.h"

namespace TikTakToe
{
	int Players::Player::TakeAction(const Map* const map)
	{
		std::cout << std::endl;

		std::cout << "Select position: ";
		int pos;
		std::cin >> pos;
		if (pos == 7) return 0;
		if (pos == 8) return 1;
		if (pos == 9) return 2;
		if (pos == 4) return 3;
		if (pos == 5) return 4;
		if (pos == 6) return 5;
		if (pos == 1) return 6;
		if (pos == 2) return 7;
		if (pos == 3) return 8;
		return -1;
	}
}