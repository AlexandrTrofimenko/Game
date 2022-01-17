#pragma once
#include<SFML\Graphics.hpp>
#include <bird.hpp>

namespace bird
{	
		Bird::Bird(int x, int y, float R)
		{
			m_texture.loadFromFile("img/bird.png");
			m_bird = new sf::Sprite();
			m_bird->setTexture(m_texture);
			m_R = R;
			m_x = x;
			m_y = y;
			m_bird->setPosition(m_x, m_y);
			m_bird->setOrigin(R, R);
		}
		Bird::~Bird()
		{
			delete m_bird;
		}
		int Bird::Get_x()
		{
			return m_x;
		}
		void Bird::Set_x(int x)
		{
			m_x = x;
			m_bird->setPosition(m_x, m_y);
		}
		int Bird::Get_y()
		{
			return m_y;
		}
		void Bird::Set_y(int y)
		{
			m_y = y;
			m_bird->setPosition(m_x, m_y);
		}
		void Bird::Velocity()
		{
			m_x += 8;
			m_y += 5;
			m_bird->setPosition(m_x, m_y);
		}
		void Bird::Move(int x, int y)
		{
			m_x += x;
			m_y += y;
			m_bird->setPosition(m_x, m_y);
		}
		sf::Sprite* Bird::Get()
		{
			return m_bird;
		}
}