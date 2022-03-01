#include"../include/menuui.hpp"
#include <SFML/Graphics/Rect.hpp>
#include<iostream>

MainMenu::MainMenu(bool& a_m,bool& a_v,bool& a_a):a_menu(a_m),a_visualize(a_v),a_analyze(a_a)
{
  visualization =new(Button);
  analyzation=new(Button);

  visualization->setPosition(1020.00/2-400,780.00/2-50);
  analyzation->setPosition(1020.00/2+200,780.00/2-50);

  visualization->setSize(180,80);
  analyzation->setSize(180,80);

  visualization->setFont("../fonts/lato.ttf");
  analyzation->setFont("../fonts/lato.ttf");

  visualization->setCharacterSize(35);
  analyzation->setCharacterSize(35);

  nh_setcolor();

  visualization->setString("VISUALIZE");
  analyzation->setString("ANALYZE");

  t_bg.loadFromFile("../bg.png");
  t_bg.setRepeated(true);
  s_bg.setTexture(t_bg);

  font.loadFromFile("../fonts/QuickSand.ttf");
  u_text.setFont(font);
  u_text.setString("BUTTERFLY! BUTTERFLY!");
  u_text.setPosition(350,50);
  u_text.setStyle(sf::Text::Bold);
  u_text.setFillColor(sf::Color(223, 252, 3));

  font.loadFromFile("../fonts/QuickSand.ttf");
  d_text.setFont(font);
  d_text.setString("Which sort do you like?");
  d_text.setPosition(350,700);
  d_text.setStyle(sf::Text::Bold);
  d_text.setFillColor(sf::Color(223, 252, 3));


}

void MainMenu::render(sf::RenderWindow& w)
{
  w.draw(s_bg);
  w.draw(*visualization);
  w.draw(*analyzation);
  w.draw(u_text);
  w.draw(d_text);
}

void MainMenu::nh_setcolor()
{
  visualization->setBackgroundColor(sf::Color(52,73,85));
  analyzation->setBackgroundColor(sf::Color(52,73,85));

  visualization->setTextColor(sf::Color(3, 252, 57));
  analyzation->setTextColor(sf::Color(3, 252, 57));

  visualization->setBorderColor(sf::Color(143,188,143));
  analyzation->setBorderColor(sf::Color(143,188,143));

}

void MainMenu::h_setcolor()
{
  if(visualization->hovered)
  {
    visualization->setBackgroundColor(sf::Color(141, 171, 65));
    visualization->setTextColor(sf::Color(52,73,85));
    h_coloredset=true;
  }
  if(analyzation->hovered)
  {
    analyzation->setBackgroundColor(sf::Color(141, 171, 65));
    analyzation->setTextColor(sf::Color(52,73,85));
    h_coloredset=true;
  }
}

void MainMenu::monitor(sf::RenderWindow& w)
{
  visualization->listen(w);
  analyzation->listen(w);

  h_coloredset=false;
  h_setcolor();

  if(!h_coloredset)
    nh_setcolor();
  
  if(visualization->clicked)
  {
     a_menu=false;
     a_visualize=true;
     a_analyze=false;
  }
  if(analyzation->clicked)
  {
    a_menu=false;
    a_analyze=true;
    a_visualize=false;

  }
}

MainMenu::~MainMenu()
{
  delete visualization;
  delete analyzation;
}
