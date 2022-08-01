#include <SFML/Graphics.hpp>
#include <iostream>
#include <chrono>
#include <thread>
using namespace std;

void Branch(float length, float positionX, float positionY, float angle, sf::RenderWindow& window);
void Draw(sf::RenderWindow& window);


vector <sf::RectangleShape> Lines;

const double Pi = 2 * acos(0.0);
const double Degrees = 60;
const float AngleScale = (Degrees *Pi)/180;
const float LengthScale = 0.62;


int main()
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "Tree Fractal", sf::Style::Fullscreen);

    Branch(450, 960, 1080, -1.5708, window);


    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

    }

    return 0;
}

void Branch(float length, float positionX, float positionY, float angle, sf::RenderWindow& window)
{
    if (length > 90)
    {
        Lines.push_back(sf::RectangleShape(sf::Vector2f(length, 3.5)));
        Lines.back().move(positionX, positionY);
        Lines.back().rotate((angle * 180) / Pi);
        Lines.back().setFillColor(sf::Color::White);
        Draw(window);
        Branch(length * LengthScale, positionX + length * cos(angle), positionY + length * sin(angle), angle - AngleScale, window);
        Branch(length * LengthScale, positionX + length * cos(angle), positionY + length * sin(angle), angle + AngleScale, window);
    }
    else if (length > 50)
    {
        Lines.push_back(sf::RectangleShape(sf::Vector2f(length, 2.5)));
        Lines.back().move(positionX, positionY);
        Lines.back().rotate((angle*180)/Pi);
        Lines.back().setFillColor(sf::Color::White);
        Draw(window);
        Branch(length * LengthScale, positionX + length * cos(angle), positionY + length * sin(angle), angle - AngleScale, window);
        Branch(length * LengthScale, positionX + length * cos(angle), positionY + length * sin(angle), angle + AngleScale, window);
    }
    else if (length > 20)
    {
        Lines.push_back(sf::RectangleShape(sf::Vector2f(length, 1.5)));
        Lines.back().move(positionX, positionY);
        Lines.back().rotate((angle * 180) / Pi);
        Lines.back().setFillColor(sf::Color::White);
        Draw(window);
        Branch(length * LengthScale, positionX + length * cos(angle), positionY + length * sin(angle), angle - AngleScale, window);
        Branch(length * LengthScale, positionX + length * cos(angle), positionY + length * sin(angle), angle + AngleScale, window);
    }
    else if(length > 3)
    {
        Lines.push_back(sf::RectangleShape(sf::Vector2f(length, 1)));
        Lines.back().move(positionX, positionY);
        Lines.back().rotate((angle * 180) / Pi);
        Lines.back().setFillColor(sf::Color::White);
        Draw(window);
        Branch(length * LengthScale, positionX + length * cos(angle), positionY + length * sin(angle), angle - AngleScale, window);
        Branch(length * LengthScale, positionX + length * cos(angle), positionY + length * sin(angle), angle + AngleScale, window);
    }
}

void Draw(sf::RenderWindow& window)
{
    for (int i = 0; i < Lines.size(); i++)
    {
        window.draw(Lines[i]);
    }
    window.display();
}