#include <iostream>
#include <set>

#include "Map.h"
#include "PlayerBase.h"
#include "Player.h"
#include "RandomPlayer.h"
#include "Game.h"

using namespace std;

int main()
{
	srand(time(NULL));
	//TikTakToe::Players::Player player1('A');
	//TikTakToe::Players::Player player2('0');
	TikTakToe::Players::RandomPlayer player1('A', true);
	TikTakToe::Players::RandomPlayer player2('B', true);
	TikTakToe::Game game(&player1, &player2, '-');

	char winner;
	while (!game.IsGameEnded(winner))
	{
		game.PrintMap();
		game.NextStep();
	}
	game.PrintMap();
	if (game.IsDraw())
		cout << "Draw" << endl;
	else
		cout << "Winner: " << winner << endl;
}