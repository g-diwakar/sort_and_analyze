#include<SFML/Graphics.hpp>

class Analyze_ui
{
private:
  sf::RectangleShape graph;
  sf::RectangleShape addPixels(float x_pos,float y_pos,sf::Color color);
  std::vector<sf::Image> points;
public:
  Analyze_ui();
  void render(sf::RenderWindow& w );
  float get_relative_x(float x);
  float get_relative_y(float y);
  };
