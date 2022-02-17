#include"../include/analyzeui.hpp"
#include<cmath>

Analyze_ui::Analyze_ui()
{
  graph.setPosition(150,150);
  graph.setSize(sf::Vector2f(1020-300,780-300));
  graph.setOutlineThickness(4);
  graph.setOutlineColor(sf::Color(52,73,85));
  graph.setFillColor(sf::Color(0,0,0));

//  chart.create(graph.getSize().x-4,graph.getSize().y-4,sf::Color(0,0,0));
  //texture.create(chart.getSize().x,chart.getSize().y);
  //sprite.setTexture(texture);
  //sprite.setPosition(150+2,150+2);
 // sprite.setOrigin(0,texture.getSize().y);
 // sprite.setPosition(0,0);
}

void Analyze_ui::render(sf::RenderWindow &w)
{
  w.draw(graph);
  float x_pos;
  float y_pos;
  for(int x=0;x<(1020-300);x++)
  {
    x_pos=get_relative_x(x);
    y_pos=get_relative_y(x*log(x));
    if(y_pos<150)
        break;

    w.draw(addPixels(x_pos,y_pos,sf::Color::Red));
  }


}

sf::RectangleShape Analyze_ui::addPixels(float pos_x,float pos_y,sf::Color color)
{
  sf::RectangleShape pixel;
  pixel.setSize(sf::Vector2f(1,1));
  pixel.setPosition(pos_x,pos_y);
  pixel.setFillColor(color);
  return pixel;
}

float Analyze_ui::get_relative_x(float x)
{
  return(150+x);//graph_position_x+ x
}
float Analyze_ui::get_relative_y(float y)
{
  return((780-150)-y);
}
  
