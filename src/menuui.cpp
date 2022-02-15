#include"../include/menuui.hpp"
#include<iostream>

MainMenu::MainMenu(bool& a_m,bool& a_v,bool& a_a):a_menu(a_m),a_visualize(a_v),a_analyze(a_a)
{
  visualization =new(Button);
  analyzation=new(Button);

  visualization->setPosition(1020.00/2-400,780.00/2);
  analyzation->setPosition(1020.00/2+200,780.00/2);

  visualization->setSize(200,100);
  analyzation->setSize(200,100);

  visualization->setFont("../fonts/lato.ttf");
  analyzation->setFont("../fonts/lato.ttf");

  visualization->setCharacterSize(35);
  analyzation->setCharacterSize(35);

  nh_setcolor();

  visualization->setString("VISUALIZE");
  analyzation->setString("ANALYZE");
  
}

void MainMenu::render(sf::RenderWindow& w)
{
  w.draw(*visualization);
  w.draw(*analyzation);
}

void MainMenu::nh_setcolor()
{
  visualization->setBackgroundColor(sf::Color(52,73,85));
  analyzation->setBackgroundColor(sf::Color(52,73,85));

  visualization->setTextColor(sf::Color(249,170,51));
  analyzation->setTextColor(sf::Color(249,170,51));

  visualization->setBorderColor(sf::Color(143,188,143));
  analyzation->setBorderColor(sf::Color(143,188,143));

}

void MainMenu::h_setcolor()
{
  if(visualization->hovered)
  {
    visualization->setBackgroundColor(sf::Color(249,170,51));
    visualization->setTextColor(sf::Color(52,73,85));
    h_coloredset=true;
  }
  if(analyzation->hovered)
  {
    analyzation->setBackgroundColor(sf::Color(249,170,51));
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
    std::cout<<"visualization clicked"<<std::endl;
  }
  if(analyzation->clicked)
  {
    a_menu=false;
    a_analyze=true;
    a_visualize=false;

    std::cout<<"Analyzation clicked"<<std::endl;
  }
}

MainMenu::~MainMenu()
{
  delete visualization;
  delete analyzation;
}
