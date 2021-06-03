#include "DepthFirstSearch.h"
#include <iostream>

DepthFirstSearch::DepthFirstSearch(const bool matrixcome[height][width]) {
    
    memset(crossroads, 0, 4);
    in = 1;
    out = 0;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {

            matrix[i][j] = matrixcome[i][j];
        }
    }

    for (int i = 0; i < width; i++) {
        if (matrix[0][i] == 0) in = i;
    }//enough???
    if (!(in > 0 and in < width)) {
        std::cout << "Dont have entre in maze!!!\n";
    }// now ok??

    for (int i = 0; i < width; i++) {
        if (matrix[height - 1][i] == 0) out = i;
    }//enough???
    x = in;
    y = 0;

}
void DepthFirstSearch::step() {
    if (y == 0) {//first
        visited.push_back(std::make_pair(y, x));
        y = y + 1;
        //std::cout << "FIRST MOVE!\n";
        abort;///////////////////////////////
    }

    //if no path, go back
    memset(crossroads, 0, 4);
    if (x > 0) if (matrix[y][x - 1] == 0) {
        for (auto i = visited.end(); i != visited.begin(); --i) {
            if (visited.back().first == y and visited.back().second == x - 1) {
                crossroads[0] = 0;
                break;
            }
            crossroads[0] = 1;
        }
    }//left
    if (y > 0) if (matrix[y - 1][x] == 0) {
        for (auto i = visited.end(); i != visited.begin(); --i) {
            if (visited.back().first == y - 1 and visited.back().second == x) {
                crossroads[1] = 0;
                break;
            }
            crossroads[1] = 1;
        }
    }//up

    if (x < width - 1) if (matrix[y][x + 1] == 0 ){
        for (auto i = visited.end(); i != visited.begin(); --i) {
            if (visited.back().first == y and visited.back().second == x + 1) {
                crossroads[2] = 0;
                break;
            }
            crossroads[2] = 1;
        }
    }//right
    if (y < height - 1) if (matrix[y + 1][x] == 0){
        for (auto i = visited.end(); i != visited.begin(); --i) {
            if (visited.back().first == y + 1 and visited.back().second == x) {
                crossroads[3] = 0;
                break;
            }
            crossroads[3] = 1;
        }
    }//down

    //std::cout << (crossroads[0])<< (crossroads[1])<< (crossroads[2])<< ( crossroads[3]) << "\n";

    
    
   
    auto add_visited = [&](int way) {
        visited.push_back(std::make_pair(y, x));
        if (way==0) x = x - 1;
        else if (way == 1) y = y - 1;
        else if (way == 2) x = x + 1;
        else if (way == 3) y = y + 1;
        else {
            if (crossroads_paths.size()==0) {
                std::cout << "ERROR, ERROR, ERROR!!!\n";
                abort;
            }
            y = crossroads_paths.back().first;
            x = crossroads_paths.back().second;
            crossroads_paths.pop_back();
        }
    };
   
    /////////////////////////////// ONE PATH ////////////////////////////
    if ((crossroads[0] + crossroads[1] + crossroads[2] + crossroads[3]) == 1) {
        if (crossroads[0] == 1) add_visited(0);
        else if (crossroads[1] == 1) add_visited(1);
        else if (crossroads[2] == 1) add_visited(2);
        else if (crossroads[3] == 1) add_visited(3);
        //std::cout << "only one road\n";
        abort;
    }
    ////////////////// MORE PATH //////////////////////////////////////////////////////
    else if ((crossroads[0] + crossroads[1] + crossroads[2] + crossroads[3]) > 1) {

        int* wsk = new int;

        while (true) {
            *wsk = rand() % 4;

            if (*wsk == 0 and crossroads[0] == 1) {
                add_visited(0); 
                crossroads[0] = 0;
                break;
            }
            else if (*wsk == 1 and crossroads[1] == 1) {
                add_visited(1);
                crossroads[1] = 0;
                break;
            }
            else if (*wsk == 2 and crossroads[2] == 1) {
                add_visited(2);
                crossroads[2] = 0;
                break;
            }
            else if (*wsk == 3 and crossroads[3] == 1) {
                add_visited(3);
                crossroads[3] = 0;
                break;
            }
            else continue;
        }
        delete wsk;
        if ((crossroads[0] + crossroads[1] + crossroads[2] + crossroads[3]) > 0) {
            if (crossroads[0]==1) crossroads_paths.push_back(std::make_pair(y, x-1));
            if (crossroads[1] == 1) crossroads_paths.push_back(std::make_pair(y-1, x ));
            if (crossroads[2] == 1) crossroads_paths.push_back(std::make_pair(y, x + 1));
            if (crossroads[3] == 1) crossroads_paths.push_back(std::make_pair(y+1, x));
        }
    }
    /// ////////////// NO PATH /////////////////////////////////////////
    else //no way to go so go to crossroads
    {
        add_visited(404);//no way so 404
    }
}
bool DepthFirstSearch::end() {
    if (y == height - 1 and x == out) return true;
    else return false;
}
int DepthFirstSearch::pos(char a) {
    if (a == 'x') return x;
    else if (a == 'y') return y;
    else {
        std::cout << "ERROR!!!\n";
        return 404;
    }
}
