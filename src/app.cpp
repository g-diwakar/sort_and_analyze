#include"../include/app.hpp"

#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include <algorithm>
#include<iostream>
#include<cmath>
#include <memory>

int i = 0;
App::App()
{
  //sf::VideoMode screen= sf::VideoMode::getDesktopMode();
  ui = new(Appui);
  sortingAlgorithm=nullptr;
  window.create(sf::VideoMode(window_width,window_height),"Butterfly Butterfly",sf::Style::Close);
  window.setFramerateLimit(60);
}

void App::run()
{
 initialize();
 mainloop();
}

void App::initialize()
{
  array.clear();

  array_width=(window.getSize().x-t_data*x_barmargin)/float(t_data);

  for(int i=1;i<=t_data;i++)
  {
    Bar bar(i);
    array_height=((i-1)/float((t_data-1)))*(window.getSize().y-150);//(total_available_height)/largest_value * current_value)-margin_top
    bar.setSize(array_width,array_height);

    array.push_back(bar);
  }
  std::random_shuffle(array.begin(),array.end());
  sortingAlgorithm = std::make_unique<BubbleSort>();
// std::thread t(&BubbleSort::sort,b,array);
//std::thread t(&App::startSort,this);
 // t.detach();
}

void App::mainloop()
{
  while(window.isOpen())
  {
     handleEvents();
     update(); 
     render(); 
    } 
}
void App::handleEvents()
{
  sf::Event event;
  while(window.pollEvent(event))
  {
      if(event.type==sf::Event::Closed)
        window.close();
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) 
			{
    std::thread(&App::startSort,this).detach();
			}
}

void App::update()
{
  ui->monitor(window);
 //std::thread t(&App::startSort,this);
}

void App::render()
{
  //  std::sort(array.begin(), array.end());    
  
  window.clear(sf::Color(35,47,52));
  ui->render(window);
//b->sort(array); 
 for(int i=0;i<array.size();i++)
  {
    array[i].render(window,(array_width+x_barmargin)*(i+1)); 
  }
  window.display();
  
}

void App::startSort()
{
  sortingAlgorithm->sort(array);
}

App::~App(){
  delete ui;

}
