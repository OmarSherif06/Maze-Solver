#include <iostream>
#include "Maze.cpp"

using std::cout;
using std::endl;

int rows = 6;
int cols = 6;

Maze m = Maze(rows, cols);

bool isValid(int x, int y) {
    // Check bounds and if the cell is not a wall or already visited
    if (y < 0 || y >= m.rows || x < 0 || x >= m.cols || m.maze[y][x] == 0) {
        return false;
    }
    
    return true;
}

bool SolveMaze(Position position) {
    m.path.push(position);

    while (!m.path.isEmpty()) {
        int x = m.path.peek().x;
        int y = m.path.peek().y;

        // Check for destination
        if (m.maze[y][x] == 2) {
            cout << "Reached the destination!" << endl;
            return true;
        }

        // Mark current position as visited
        m.maze[y][x] = 0; // 0 means visited
        

        // Try moving down
        if (isValid(x, y + 1)) {
            m.path.push(Position(x, y + 1));
            cout << "Moved down to (" << x << ", " << (y + 1) << ")" << endl;
            continue;
        }

        // Try moving up
        if (isValid(x, y - 1)) {
            m.path.push(Position(x, y - 1));
            cout << "Moved up to (" << x << ", " << (y - 1) << ")" << endl;
            continue;
        }

        // Try moving left
        if (isValid(x - 1, y)) {
            m.path.push(Position(x - 1, y));
            cout << "Moved left to (" << (x - 1) << ", " << y << ")" << endl;
            continue;
        }

        // Try moving right
        if (isValid(x + 1, y)) {
            m.path.push(Position(x + 1, y));
            cout << "Moved right to (" << (x + 1) << ", " << y << ")" << endl;
            continue;
        }

        // No valid moves, backtrack
        m.path.pop();
        cout << "Moved back from (" << x << ", " << y << ")" << endl;
    }

    return false; // No path found
}

int main() {
    int maze[rows][cols] = {
        {2, 1, 1, 0, 0, 0}, // Start (0,0) - destination
        {0, 1, 0, 1, 1, 0},
        {0, 1, 0, 0, 1, 1},
        {0, 1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0, 1},
        {1, 1, 1, 0, 1, 1}
    };

    // Initialize the maze
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            m.maze[i][j] = maze[i][j];
        }
    }

    // Set starting position
    m.start = Position(5, 5); // Start just below the destination
    m.path = Stack<Position>();

    if (SolveMaze(m.start)) {
        cout << "Completed!" << endl;
    } else {
        cout << "No path" << endl;
    }

    return 0;
}
