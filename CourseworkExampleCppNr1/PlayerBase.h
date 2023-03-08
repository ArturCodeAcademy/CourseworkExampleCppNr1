#pragma once

#include "Map.h"

namespace TikTakToe
{
	namespace Players
	{
		class PlayerBase
		{
		private:
			char symbol;

		public:
			inline PlayerBase(char symbol)
			{
				this->symbol = symbol;
			}

			virtual int TakeAction(const Map* const map) = 0;
			inline char GetSymbol()
			{
				return symbol;
			}
		};
	}
}