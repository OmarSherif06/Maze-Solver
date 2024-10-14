#include "Stack.cpp"
#include "Position.cpp"
#include <vector>

class Maze {
public:
    int** maze;
    Stack<Position> path;
    Position start;
    int rows;
    int cols;

    Maze(int rows, int cols) {
        this->rows = rows;
        this->cols = cols;
        maze = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            maze[i] = new int[cols];
        }
    }

    ~Maze() {
        for (int i = 0; i < rows; ++i) {
            delete[] maze[i];
        }
        delete[] maze;
    }
};

