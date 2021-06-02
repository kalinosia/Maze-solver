#include "RandomSolver.h"
#include <iostream>


RandomSolver::RandomSolver(const bool matrixcome[height][width]) {

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {

            matrix[i][j] = matrixcome[i][j];
        }
    }

    for (int i = 0; i < width; i++) {
        if (matrix[0][i] == 0) in = i;
    }
    for (int i = 0; i < width; i++) {
        if (matrix[height-1][i] == 0) out = i;
    }
    x = in;
    y = 0;
    
    last[0] = y;
    last[1] = x;
    /*
    std::string line;
    std::ifstream myfile("example.txt");
    if (myfile.is_open())
    {
        while (getline(myfile, line))
        {
            std::cout << line << '\n';
        }
        myfile.close();
    }

    else std::cout << "Unable to open file";
    */
}
void RandomSolver::step() {
    if (y == 0) {//first
        visited.push_back(std::make_pair(y, x));
        y = y + 1;
        std::cout << "FIRST MOVE!\n";
        abort;///////////////////////////////
    }

    int* wsk = new int;
    //*wsk = rand()%4;
    /*
    crossroads = 0;

    if (x > 0) if (matrix[y][x - 1] == 0) crossroads += 1; //left
    if (matrix[y - 1][x] == 0) crossroads += 1;//up
    if (matrix[y][x + 1] == 0) crossroads += 1;//right
    if (matrix[y + 1][x] == 0) crossroads += 1; //down
    std::cout << crossroads << "\n"<<"x, y: "<<x<<" "<<y<<"\n";
    if (crossroads > 2) {
    */
        while (true) {
            find = false;
            *wsk = rand() % 4;
            if (*wsk == 0 and x > 0 and matrix[y][x - 1] == 0  and (last[1]!=x-1)) {
                visited.push_back(std::make_pair(y, x));
                last[0] = y;
                last[1] = x;
                x = x - 1;
                break;
            }
            else if (*wsk == 1 and y > 0 and matrix[y - 1][x] == 0 and (last[0] != y-1)) {
                visited.push_back(std::make_pair(y, x));
                last[0] = y;
                last[1] = x;
                y = y - 1;
                break;
            }
            else if (*wsk == 2 and x < width - 1 and matrix[y][x + 1] == 0 and (last[1] != x + 1)) {
                visited.push_back(std::make_pair(y, x));
                last[0] = y;
                last[1] = x;
                x = x + 1;
                break;
            }
            else if (*wsk == 3 and y < height - 1 and matrix[y + 1][x] == 0 and (last[0] != y+1)) {
                visited.push_back(std::make_pair(y, x));
                last[0] = y;
                last[1] = x;
                y = y + 1;
                break;
            }
            else {

                memset(crossroads, 0, 4);//!!
                if (x>0) if (matrix[y][x - 1] == 0) crossroads[0] = 1; //left
                if (y>0) if (matrix[y - 1][x] == 0) crossroads[1] = 1;//up
                if (x<width-1) if (matrix[y][x + 1] == 0) crossroads[2] = 1;//right
                if (y<height-1) if (matrix[y + 1][x] == 0) crossroads[3] = 1;//down

                std::cout << (crossroads[0])<< (crossroads[1])<< (crossroads[2])<< ( crossroads[3]) << "\n";
                // here not working
                if ((crossroads[0] + crossroads[1] + crossroads[2] + crossroads[3]) == 1) {
                    std::cout << "only one road\n";
                    visited.push_back(std::make_pair(y, x));
                    last[0] = y;
                    last[1] = x;
                    y = visited.back().first;
                    x = visited.back().second;
                    find = true;
                }
                //std::cout << "NOT ESCAPE NOT ESCAPE!!!!!!!!!!!!!!!!!!!!!!!!\n";
                //last[0] = y;
                //last[1] = x;
            }//std::cout << "NOT ESCAPE NOT ESCAPE!!!!!!!!!!!!!!!!!!!!!!!!\n";
            if (find) break;
           
        }//while(true)
    /*
    //if (crossroads == 1 )
    else {
        std::cout << "ELSE!!!\n";
        if (y == 0) {//first
            visited.push_back(std::make_pair(y, x));
            y = y + 1;
            std::cout << "FIRST MOVE!\n";
        }
        if (x > 0) {
            if (matrix[y][x - 1] == 0 and !(visited.back().second == x - 1)) {
                visited.push_back(std::make_pair(y, x));
                x = x - 1; //left
                std::cout << "LEFT\n";
            }
        }
        if (y > 0) {
            if (matrix[y - 1][x] == 0 and !(visited.back().first == y - 1) ) {
                visited.push_back(std::make_pair(y, x));
                y = y - 1; //up
                std::cout << "UP\n";
            }
        }
        if (x < width - 1) {
            if (matrix[y][x + 1] == 0 and !(visited.back().second == x + 1)) {
                visited.push_back(std::make_pair(y, x));
                x = x + 1; //right
                std::cout << "RIGHT\n";
            }
        }
        if (y < height - 1) {
            if (matrix[y + 1][x] == 0 and !(visited.back().first == y + 1)) {
                visited.push_back(std::make_pair(y, x));
                y = y + 1; //down
                std::cout << "DOWN\n";
            }
        }
        else std::cout << "Withou solution\n";
        std::cout << "ELSE END\n";
    }
    /*
    int crossroads = 0;
    if (x>0) if (matrix[y][x - 1] == 0) crossroads+=1; //left
    if (matrix[y - 1][x] == 0) crossroads += 1;//up
    if (matrix[y][x + 1] == 0) crossroads += 1;//right
    if (matrix[y + 1][x] == 0) crossroads += 1; //down

    if (crossroads > 2) {
        
    }
    */
    delete wsk;
}
bool RandomSolver::end() {
    if (y == height - 1 and x == out) return true;
    else return false;
}
int RandomSolver::pos(char a) {
    if (a == 'x') return x;
    else if (a == 'y') return y;
    else {
        std::cout << "ERROR!!!\n";
        return 404;
    }
}
