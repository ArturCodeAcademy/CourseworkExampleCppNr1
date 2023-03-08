#pragma once

#include<iostream>
#include "PlayerBase.h"

namespace TikTakToe
{
	class Game
	{
	private:
		Players::PlayerBase* player1;
		Players::PlayerBase* player2;
		Map* map;
		bool player1Turn;
		char defaultMapSymbol;

	public:
		Game(Players::PlayerBase* player1, Players::PlayerBase* player2, char defaultMapSymbol);
		~Game();

		void NextStep();
		bool IsGameEnded(char& winner);
		inline bool IsDraw()
		{
			char winner;
			return IsGameEnded(winner) && winner == defaultMapSymbol;
		}
		void PrintMap();
	};
}