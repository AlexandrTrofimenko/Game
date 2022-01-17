#pragma once
#include<SFML\Graphics.hpp>

namespace rc   // rc - rectangle 
{
	class Walls
	{
	public:
		Walls(int x, int y, float h, float l);

		~Walls();
		
		sf::Sprite* Get();

		int GetX();

		int GetY();

	float m_h, m_l;
	private:
		int m_x, m_y;
		sf::Texture m_texture;
		sf::Sprite* m_walls;
	};
}