#pragma once

#include<iostream>
#include "Map.h"
#include "PlayerBase.h"

namespace TikTakToe
{
	namespace Players
	{
		class Player : public PlayerBase
		{
		public:
			inline Player(char symbol) : PlayerBase(symbol) {}

			int TakeAction(const Map* const map) override;
		};
	}
}