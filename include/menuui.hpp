#ifndef MENUUI_HPP
#define MENUUI_HPP

#include"button.hpp"

class MainMenu
{
private:
    Button *visualization;
    Button *analyzation;

    bool& a_menu;
    bool& a_visualize;
    bool& a_analyze;

    bool h_coloredset;
    void nh_setcolor();
    void h_setcolor();
public:
    MainMenu(bool& a_m,bool& a_v,bool& a_a);
    void render(sf::RenderWindow& w);
    void monitor(sf::RenderWindow& w);
    ~MainMenu();
  };

#endif
