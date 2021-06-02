#include <SFML/Graphics.hpp>

#include <iostream>
#include <stack>
#include <time.h>
#include <stdlib.h> 
#include <windows.h> 
#include <vector>
#include <fstream>

#include "RandomSolver.h"


const int size = 10;


int main() {

    //rand...
    srand(time(NULL));

    //shape to draw it
    sf::RectangleShape shape{ (sf::Vector2f(size, size)) };
   // window to draw on it
    sf::RenderWindow window(sf::VideoMode((size * width), (size * height)), "Maze Solver!", sf::Style::Titlebar | sf::Style::Close);

    
    bool matrix[height][width];
    int x = 0, y = 0;
    char ch;

    std::fstream fin("maze01.txt", std::fstream::in);
    if (!fin) std::cout << "Canot open file!!!!";

    while (fin >> std::noskipws >> ch) {
        if (ch == '\n') {
            x = 0;
            y++;
            continue;
        }
        if (ch=='1') matrix[y][x]=1;
        if (ch=='0') matrix[y][x]=0;
        //matrix[y][x] << ch; //not not not
        x++;
    }

    /*
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            std::cout << matrix[i][j];
        }
        std::cout << std::endl;
    }
    /////////*/
    auto draw = [&] () {
        window.clear(sf::Color::Yellow);
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                shape.setPosition(j * size, i * size);
                if (matrix[i][j] == 1)shape.setFillColor(sf::Color::Black);
                if (matrix[i][j] == 0)shape.setFillColor(sf::Color::White);
                window.draw(shape);
            }
        }
    };
    ////////////////////////////////draw();

    RandomSolver solver(matrix);

    //draw  solver
    auto draw_solver = [&]() {

        for (auto i = solver.visited.begin(); i != solver.visited.end(); ++i) {
            shape.setPosition(i->second * size, i->first * size);
            shape.setFillColor(sf::Color::Yellow);
            window.draw(shape);
        }

        shape.setPosition(solver.pos('x') * size, solver.pos('y') * size);
        shape.setFillColor(sf::Color::Red);
        window.draw(shape);
        
        
    };
    //-------------------------------------------------------------------------
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        //Random solver///////////////////////////////////////////
        if (!solver.end()) solver.step();
        if (solver.end()) std::cout << "END, solution find!!!";
        ///////////////////////////////////////////////////////////
        
        draw();
        draw_solver();
        window.display();

    }//While window is open


    return 0;
}
