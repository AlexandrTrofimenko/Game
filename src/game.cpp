#include<SFML\Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <chrono>
#include <thread>
#include <iostream>
#include <windows.h>
#include <walls.hpp>
#include <bird.hpp>
#include <menu.hpp>
#include <game.hpp>  

using namespace bird;
using namespace std::chrono_literals;

namespace game
{
    bool game()
    {
        srand(time(NULL));
        int L = 0;
        // Текст
        sf::Font font;
        if (!font.loadFromFile("font/font.ttf"))
        {
            std::cout << "ERROR: font was not loaded." << std::endl;
            return false;
        }
        sf::Text text;
        text.setFont(font);
        text.setCharacterSize(50);
        text.setFillColor(sf::Color::White);

        int height = 600; int width = 900;
        sf::RenderWindow window(sf::VideoMode(width, height), "BirdIn");

        // Фон
        sf::Texture texture;
        if (!texture.loadFromFile("img/background.png"))
        {
            std::cout << "ERROR: not found background.png" << std::endl;
            return false;
        }
        sf::Sprite background(texture);

        mn::menu(window);
        if (!mn::menu(window))
        {
            return false;
        }

        // Создание стенок
        const int N = 5;
        std::vector<rc::Walls*> walls;
        int randznch = 0;
        int randznch1 = 0;


        for (int i = 300; i < 900; i += 900 / N)
        {
            randznch = rand() % 150 + 110;
            randznch1 = rand() % 150 + 110;
            walls.push_back(new rc::Walls(i, 0 + randznch / 2, 60, randznch));
            walls.push_back(new rc::Walls(i, 600 - randznch1 / 2, 60, randznch1));
        }
        // Птичка
        int R = 26;
        Bird* fowl = new Bird(50, 315, R);
        int score = 0;
        // Музыка
        sf::Music sound;
        //     sf::Sound sound;
        sound.setVolume(10);
        if (!sound.openFromFile("audio/music.ogg"))
        {
            return false;
        }
        //   sound.setBuffer(buffer);
        sound.play(); 
        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }
            // Фон в буфере
            window.draw(background);
            for (int i = 0; i < walls.size(); i++)
            {
                int X = fowl->Get_x();
                int Y = fowl->Get_y();
                int x = walls[i]->GetX();
                int y = walls[i]->GetY();
                int d_y = abs(y - Y);
                int d_x = abs(x - X);
                if ((2 * R >= d_x) && ((((walls[i]->m_l) / 2) + R - 4) >= d_y))
                {
                    fowl->Move(fowl->Get_x(), fowl->Get_y());
                    L = 1;
                }
            }
            if (fowl->Get_y() == height - R)
            {
                L = 1;
            }
            // Счётчик
            for (int i = 0; i < walls.size(); i++)
            {
                int X = fowl->Get_x();
                int x = walls[i]->GetX();
                int d = abs(X - x);
                if (2 * R - 49 > d)
                {
                    score++;
                }
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
            {
                fowl->Move(8, -6);
            }
            else
            {
                fowl->Velocity();
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            {
                return false;
            }
            if (fowl->Get_x() >= width - R)
            {
                for (const auto& Walls : walls)
                {
                    delete Walls;
                }
                walls.clear();
                for (int i = 300; i < 900; i += 900 / N)
                {
                    randznch = rand() % 150 + 110;
                    randznch1 = rand() % 160 + 110;
                    walls.push_back(new rc::Walls(i, 0 + randznch / 2, 60, randznch));
                    walls.push_back(new rc::Walls(i, 600 - randznch1 / 2, 60, randznch1));
                }
                fowl->Set_y(fowl->Get_y());
                fowl->Set_x(-R);
            }
            text.setString(std::string("Score ") + std::to_string(score));
            window.draw(text);
            // Перемещение стенок в буфер
            for (const auto& Walls : walls)
            {
                window.draw(*Walls->Get());
            }

            // Птичка в буфере
            window.draw(*fowl->Get());
            // Отображение в окне с буфера.
            window.display();
            window.clear();
            std::this_thread::sleep_for(40ms);

            if (L == 1)
            {
                mn::Remenu(window, score);
                if (mn::Remenu(window, score))

                {
                    L = 0;
                    return true;
                }
                else
                {
                    return false;
                }
            }
        }

        // Удаление стенок
        for (const auto& Walls : walls)
        {
            delete Walls;
        }
        walls.clear();
        delete fowl;
        return false;
    }

    void ReGame()
    {
        if (game())
        {
            ReGame();
        }
    }
}