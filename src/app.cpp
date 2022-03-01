#include"../include/app.hpp"

#include <SFML/Window/Keyboard.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/Window/WindowStyle.hpp>
#include <algorithm>
#include<iostream>
#include<cmath>
#include <memory>

int i = 0;
App::App()
{
  a_menu=true;
  a_visualize=false;
  a_analyze=false;
  set_algorithm=false;
  reset_array=false;
  
  for(int i=0;i<6;i++)
  {
      current_algorithm.push_back(false);
  }
  current_algorithm[0]=true;

  ui = new Appui(set_algorithm,reset_array,current_algorithm);
  M_ui=new MainMenu(a_menu,a_visualize,a_analyze);
  A_ui=new(Analyze_ui);
  

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

  array_width=((window.getSize().x-150)-t_data*x_barmargin)/float(t_data);

  for(int i=1;i<=t_data;i++)
  {
    Bar bar(i);
    array_height=((i-1)/float((t_data-1)))*(window.getSize().y-150);//(total_available_height)/largest_value * current_value)-margin_top
    bar.setSize(array_width,array_height);

    array.push_back(bar);
  }
  std::random_shuffle(array.begin(),array.end());
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
  if(!a_menu && a_analyze)
  {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
      a_analyze=false;
      a_menu=true;
    }
  }
  if(!a_menu && a_visualize)
  {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || set_algorithm) 
	  {
        set_algorithm=true;  
  	}
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
    {
      a_visualize=false;
      a_menu=true;
    }
    if(reset_array)
    {
      initialize();
      reset_array=false;
    }
  }
}

void App::update()
{
  if(!a_menu && a_analyze)
  {
    A_ui->monitor(window);
  }
  if(!a_menu && a_visualize)
  {    
    ui->monitor(window);
      if(current_algorithm[0])
      {
        sortingAlgorithm=std::make_unique<BubbleSort>();
      }
      else if(current_algorithm[1])
      {
        sortingAlgorithm=std::make_unique<HeapSort>();
      }
      else if(current_algorithm[2])
      {
        sortingAlgorithm=std::make_unique<InsertionSort>();
      }
      else if(current_algorithm[3])
      {
        sortingAlgorithm=std::make_unique<QuickSort>();
      }
      else if(current_algorithm[4])
      {
        sortingAlgorithm=std::make_unique<SelectionSort>();
      }
      else if(current_algorithm[5])
      {
        sortingAlgorithm=std::make_unique<ShellSort>();
      }
      else 
      {
      sortingAlgorithm=std::make_unique<BubbleSort>();
      }
      if (set_algorithm)
      {
       sortingAlgorithm->sort(window,array,ui,array_width+x_barmargin,set_algorithm);
      }
  }
  if(a_menu)
  {
    M_ui->monitor(window);
  }
}

void App::render()
{
  window.clear(sf::Color(35,47,52));

  if(a_menu)
  {
   M_ui->render(window); 
  }

  if(!a_menu && a_visualize)
  {  
    ui->render(window);
    for(int i=0;i<array.size();i++)
    {
      array[i].render(window,(array_width+x_barmargin)*(i)); 
    }
  }

  if(!a_menu && a_analyze)
  {
    A_ui->render(window); 
  }
  window.display();
  
}


App::~App(){
  delete ui;
  delete M_ui;
  delete A_ui;

}
