#pragma once

#include "PlayerBase.h"

namespace TikTakToe
{
	namespace Players
	{
		class RandomPlayer : public PlayerBase
		{
		private:
			bool vaitAfterStep;

		public:
			inline RandomPlayer(char symbol, bool vaitAfterStep) : PlayerBase(symbol)
			{
				this->vaitAfterStep = vaitAfterStep;
			}

			int TakeAction(const Map* const map) override;
		};
	}
}