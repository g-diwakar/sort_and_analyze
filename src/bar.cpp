#include "../include/bar.hpp"
#include<cmath>
 
Bar::Bar(unsigned n)
{
  value=n;
  defaultcolor=sf::Color::Blue;
  rectangle.setFillColor(defaultcolor);
}

void Bar::setSize(const float width, const float height)
{
  rectangle.setOrigin(sf::Vector2f(0,height));
  rectangle.setSize(sf::Vector2f(width,height));
}

void Bar::setColor(const sf::Color &color)
{
  rectangle.setFillColor(color);
}

void Bar::setDefaultColor()
{
  rectangle.setFillColor(defaultcolor);
}
void Bar::render(sf::RenderWindow &w, const float position)
{
  rectangle.setPosition(position,w.getSize().y-150); 
  w.draw(rectangle);
}


