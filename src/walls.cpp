#include <walls.hpp>

namespace rc   // rc - rectangle 
{

	Walls::Walls(int x, int y, float h, float l)
	{
		m_texture.loadFromFile("img/walls.png");
		m_walls = new sf::Sprite();
		m_walls->setTexture(m_texture);
		m_x = x;
		m_y = y;
		m_h = h;
		m_l = l;
		m_walls->setPosition(m_x, m_y);
		m_walls->setOrigin(m_h / 2, m_l / 2);
		m_walls->setTextureRect(sf::IntRect(0, 0, m_h, m_l));
	}
	Walls::~Walls()
	{
		delete m_walls;
	}
	sf::Sprite* Walls::Get()
	{
		return m_walls;
	}
	int Walls::GetX()
	{
		return m_x;
	}
	int Walls::GetY()
	{
		return m_y;
	}
}