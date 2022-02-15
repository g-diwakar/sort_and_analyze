#include "../include/bar.hpp"
#include<cmath>
#include<mutex>
Bar::Bar(int n)
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
  std::mutex m;
  m.lock();
  rectangle.setFillColor(color);
  m.unlock();
}

void Bar::setDefaultColor()
{
  std::mutex m;
  m.lock();
  rectangle.setFillColor(defaultcolor);
  m.unlock();
}
void Bar::render(sf::RenderWindow &w, const float position)
{
  std::mutex m;
  m.lock();
  rectangle.setPosition(position,w.getSize().y-150); 
  w.draw(rectangle);
  m.unlock();
}


