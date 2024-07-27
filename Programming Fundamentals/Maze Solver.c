#include <stdio.h>

void main() {
    char maze[5][5] = { {'S', 'O', 'O', 'W', 'W'},
                        {'O', 'W', 'O', 'W', 'W'},
                        {'W', 'O', 'O', 'W', 'O'},
                        {'W', 'W', 'O', 'W', 'O'},
                        {'W', 'W', 'O', 'E', 'W'}
                      };
    
    int pathX = 0, pathY = 0;

    while (maze[pathX][pathY] != 'E') {
        while (maze[pathX][pathY] != 'W') {
            printf("%d,%d  ", pathX, pathY);
            pathY = pathY + 1;
        }
        pathX = pathX + 1;

        while (maze[pathX][pathY] != 'O') {
            if (maze[pathX][pathY] == 'E') {
                printf("%d,%d  ", pathX, pathY - 1);
                printf("%d,%d  ", pathX, pathY);
                break;
            } 
			else {
                printf("%d,%d  ", pathX, pathY - 1);
                pathX = pathX + 1;
            }
        }
    }
}