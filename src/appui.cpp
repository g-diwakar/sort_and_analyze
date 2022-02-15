#include"../include/appui.hpp"
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

Appui::Appui(bool& s_a,bool& r_a):start_algorithm(s_a),reset_array(r_a)
{
  start = new(Button);
  reset = new(Button);
  stop = new(Button);
  separator =new(sf::RectangleShape);

  start->setPosition(sf::Vector2f(100,780-100));
  reset->setPosition(sf::Vector2f(500,780-100));
  stop->setPosition(sf::Vector2f(800,780-100));
  separator->setPosition(sf::Vector2f(0,780-150));

  start->setSize(sf::Vector2f(100,50));
  reset->setSize(sf::Vector2f(100,50));
  stop->setSize(sf::Vector2f(100,50));
  separator->setSize(sf::Vector2f(1020,5));

  start->setFont("../fonts/lato.ttf");
  reset->setFont("../fonts/lato.ttf");
  stop->setFont("../fonts/lato.ttf");

  start->setCharacterSize(30);
  reset->setCharacterSize(30);
  stop->setCharacterSize(30);

  nh_setcolor();
  separator->setFillColor(sf::Color(52,73,85));

start->setString("START");
  reset->setString("RESET");
  stop->setString("STOP");

}

void Appui::render(sf::RenderWindow &w)
{
 w.draw(*start);
 w.draw(*reset);
 w.draw(*stop);
 w.draw(*separator);
}

bool Appui::isResetClicked()
{
  return reset->clicked;
}

bool Appui::isStartClicked()
{
  return start->clicked;
}

bool Appui::isStopClicked()
{
  return stop->clicked;
}

void Appui::monitor(sf::RenderWindow &w)
{

  start->listen(w);
  reset->listen(w);
  stop->listen(w);

  h_coloredset=false;
  h_setcolor();
  if(!h_coloredset)
    nh_setcolor();
  
  if(start->clicked)
  {
    start_algorithm=true;
  }
  if(stop->clicked)
  {
    start_algorithm=false;
  }

  if(reset->clicked)
  {
    start_algorithm=false;
    reset_array=true;
  }

}

void Appui::nh_setcolor()
{
  start->setBackgroundColor(sf::Color(52,73,85));
  reset->setBackgroundColor(sf::Color(52,73,85));
  stop->setBackgroundColor(sf::Color(52,73,85));

  start->setTextColor(sf::Color(249,170,51));
  reset->setTextColor(sf::Color(249,170,51));
  stop->setTextColor(sf::Color(249,170,51));

  start->setBorderColor(sf::Color(143,188,143));
  reset->setBorderColor(sf::Color(143,188,143));
  stop->setBorderColor(sf::Color(143,188,143));
}

void Appui::h_setcolor()
{
  if(start->hovered)
  {
   start->setBackgroundColor(sf::Color(249,170,51));
   start->setTextColor(sf::Color(52,73,85));
   h_coloredset=true; 
  }
  if(stop->hovered)
  {
    stop->setBackgroundColor(sf::Color(249,170,51));
    stop->setTextColor(sf::Color(52,73,85));
    h_coloredset=true;
  }
  if(reset->hovered)
  {
    reset->setBackgroundColor(sf::Color(249,170,51));
    reset->setTextColor(sf::Color(52,73,85));
    h_coloredset=true;
  }

}

Appui::~Appui(){
   delete start;
  delete reset;
  delete stop;
  delete separator;
}


