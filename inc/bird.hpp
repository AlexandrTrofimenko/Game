#pragma once
#include<SFML\Graphics.hpp>

namespace bird
{
	class Bird
	{
	public:
		Bird(int x, int y, float R);

		~Bird();

		int Get_x();

		void Set_x(int x);

		int Get_y();

		void Set_y(int y);

		void Velocity();

		void Move(int x, int y);

		sf::Sprite* Get();

		float m_R;
	private:
		
		int m_x, m_y;
		sf::Texture m_texture;
		sf::Sprite* m_bird;
	};
}