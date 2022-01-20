#include <menu.hpp>
#include <SFML/Graphics.hpp>

namespace mn  // mn - menu 
{
    bool menu(sf::RenderWindow& window)
    {
        sf::Texture backgroundmenu, start, faq, exit, FAQ;
        backgroundmenu.loadFromFile("img/menu.jpg");
        start.loadFromFile("img/start.png");
        faq.loadFromFile("img/FAQ.png");
        exit.loadFromFile("img/exit.png");
        FAQ.loadFromFile("img/afaq.png");

        sf::Sprite menu_back(backgroundmenu), menu_start(start), menu_faq(faq), menu_exit(exit), FaQ(FAQ);

        bool isMenu = true;
        int menuNum = 0;
        menu_start.setPosition(150, 50);
        menu_faq.setPosition(600, 200);
        menu_faq.rotate(5);
        menu_exit.setPosition(100, 320);
        menu_exit.rotate(-5);
        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            if (!isMenu)
                break;

            menu_start.setColor(sf::Color::White);
            menu_exit.setColor(sf::Color::White);
            menu_faq.setColor(sf::Color::White);
            menuNum = 0;
            window.clear(sf::Color::White);
            if (sf::IntRect(190, 50, 220, 120).contains(sf::Mouse::getPosition(window)))
            {
                menu_start.setColor(sf::Color::Blue);
                menuNum = 1;
            }
            if (sf::IntRect(580, 200, 220, 70).contains(sf::Mouse::getPosition(window)))
            {
                menu_faq.setColor(sf::Color::Blue);
                menuNum = 2;
            }
            if (sf::IntRect(80, 320, 220, 70).contains(sf::Mouse::getPosition(window)))
            {
                menu_exit.setColor(sf::Color::Blue);
                menuNum = 3;
            }
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {

                if (menuNum == 1)
                {
                    isMenu = false;
                    return true;
                }
                if (menuNum == 2)
                {
                    window.draw(FaQ);
                    window.display();
                    while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Escape));
                }
                if (menuNum == 3)
                {
                    isMenu = false;
                    window.close();
                    return false;
                }
            }
            window.draw(menu_back);
            window.draw(menu_start);
            window.draw(menu_faq);
            window.draw(menu_exit);
            window.display();
        }
    }


    bool Remenu(sf::RenderWindow& window, int score)
    {
        sf::Texture backgroundmenu, restart, exit, gameov;
        backgroundmenu.loadFromFile("img/menu.jpg");
        restart.loadFromFile("img/restart.png");
        exit.loadFromFile("img/exit.png");
        gameov.loadFromFile("img/gameover.png");
        sf::Sprite menu_back(backgroundmenu), menu_restart(restart), menu_exit(exit), gameover(gameov);

        sf::Text text;
        sf::Font font;
        font.loadFromFile("font/font.ttf");
        text.setFont(font);
        text.setCharacterSize(56);
        text.setFillColor(sf::Color::Cyan);
        text.setStyle(sf::Text::Bold | sf::Text::Underlined);
        text.setPosition(100, 160);
        text.setString(std::string("Score: ") + std::to_string(score));

        bool isMenu = true;
        int menuNum = 0;
        gameover.setPosition(450, 250);
        gameover.rotate(8);
        menu_restart.setPosition(150, 50);
        menu_exit.setPosition(100, 320);
        menu_exit.rotate(-5);
        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            if (!isMenu)
                break;

            menu_restart.setColor(sf::Color::White);
            menu_exit.setColor(sf::Color::White);
            menuNum = 0;
            window.clear(sf::Color::White);
            if (sf::IntRect(190, 50, 220, 120).contains(sf::Mouse::getPosition(window)))
            {
                menu_restart.setColor(sf::Color::Blue);
                menuNum = 1;
            }

            if (sf::IntRect(80, 320, 220, 70).contains(sf::Mouse::getPosition(window)))
            {
                menu_exit.setColor(sf::Color::Blue);
                menuNum = 2;
            }
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {

                if (menuNum == 1)
                {
                    return true;
                    isMenu = false;
                }
                if (menuNum == 2)
                {
                    window.close();
                    isMenu = false;
                    return false;
                }

            }
            window.draw(menu_back);
            window.draw(menu_restart);
            window.draw(menu_exit);
            window.draw(text);
            window.draw(gameover);
            window.display();
        }
    }
}