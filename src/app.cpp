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
  a_menu=true;
  a_visualize=false;
  a_analyze=false;
  set_algorithm=false;
  reset_array=false;
  
  ui = new Appui(set_algorithm,reset_array);
  M_ui=new MainMenu(a_menu,a_visualize,a_analyze);
  A_ui=new(Analyze_ui);
 // sortingAlgorithm=std::make_unique<BubbleSort>();
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

  if(!a_menu && a_visualize)
  {
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) || set_algorithm) 
	  {
//      std::thread(&App::startSort,this).detach();
 //     sortingAlgorithm=std::make_unique<InsertionSort>();
       // sortingAlgorithm=std::make_unique<SelectionSort>();
       // sortingAlgorithm=std::make_unique<HeapSort>();
//      std::thread(&App::startSort,this).detach();
        set_algorithm=true;  
		}
    if(reset_array)
    {
      std::random_shuffle(array.begin(),array.end());
      for(int i=0;i<array.size();i++)
        {
          array[i].setDefaultColor();
        }
      reset_array=false;
    }
  }
}

void App::update()
{
  if(!a_menu && a_visualize)
  {    
    ui->monitor(window);
    if(set_algorithm)
      {
       //  sortingAlgorithm=std::make_unique<InsertionSort>();
   //    sortingAlgorithm=std::make_unique<SelectionSort>();
    // sortingAlgorithm=std::make_unique<HeapSort>();
     sortingAlgorithm=std::make_unique<QuickSort>();
    //sortingAlgorithm=std::make_unique<BubbleSort>();

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
    for(int i=1;i<array.size();i++)
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
