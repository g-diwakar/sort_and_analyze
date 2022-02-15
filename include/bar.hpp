#ifndef BAR_HPP
#define BAR_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Color.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

class Bar{
private:
  sf::RectangleShape rectangle;
  sf::Color defaultcolor;
  sf::Color color;
  int  value;
public:
  Bar(){};
  Bar(int n);
  void setSize(const float width, const float height);
  void setColor(const sf::Color& color);
  void setDefaultColor();
void render(sf::RenderWindow& w, const float position);
  
  bool operator >(Bar any)
  {
    return value>any.value;
  }

  bool operator <(Bar any)
  {
    return value<any.value;
  }
  int getValue()
  {
    return value;
  }
};


#endif
