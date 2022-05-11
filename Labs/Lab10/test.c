#ifndef MAZEGRAPH_H
#define MAZEGRAPH_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define UP 1
#define LEFT 2
#define DOWN -1
#define RIGHT -2


typedef struct Node {
   short up; // true or false - i.e. a wall or not a wall
   short left;
   short down;
   short right;
   int flags[4];
} Node;
typedef Node *Tile;


typedef struct Graph {
Tile** tiles;
Tile currentTile;
int currentTileX;
int currentTileY;
int size;
} Graph;
typedef Graph *Maze; // 'Maze' is a pointer to a Graph

// Create a maze with starting position x, y
Maze createMaze(int size, int x, int y);
// Print current maze
void printMaze(Maze maze);

// Get current tile
Tile getCurrentTile(Maze maze);
// Add a possible direction from the current position
Tile add(Maze maze, int direction);
// Move current position to an adjacent tile
Tile move(Maze maze, int direction);
// Update status of current tile (flag ID from 0 to 3)
Tile updateCurrentTile(Maze maze, int flagid, int status);

/* Helper functions */
Tile createTile();


Maze createMaze(int size, int x, int y) {
   // Create space for a Graph
   Maze maze = (Maze)malloc(sizeof(Graph));
   assert(maze != NULL);
   // Create space for the Tiles (pointers) in the Graph
   // No need to actually make space for Nodes - will do when
   // we find them, as there is limited memory.
   maze->tiles = (Tile**)calloc(size, sizeof(Tile*));
   int i;
   for (i = 0; i < size; i++) {
       maze->tiles[i] = (Tile*)calloc(size, sizeof(Tile));
   }
   assert(maze->tiles != NULL);
   // Create starting tile
   maze->tiles[x][y] = createTile();
   maze->currentTile = maze->tiles[x][y];
   maze->currentTileX = x;
   maze->currentTileY = y;
   maze->size = size;
   return maze;
}

/**
* Prints the current state of the maze.
*/
void printMaze(Maze maze) {
   // Fill in this function
   // To do so, you will need to loop through the 2D array,
   // check if a Tile exists (doesn't point to NULL), and
   // print out X or space.
   // If it is a current tile, print O.
   int x, y;
   for (x = 0; x < maze->size; x++) {
       for (y = 0; y < maze->size; y++) {
           Tile tile = maze->tiles[x][y];
           if (tile == NULL) {
               printf(" ");
           } else if (x == maze->currentTileX && y == maze->currentTileY) {
               printf("O");
           } else {
               printf("X");
           }
       }
       printf("\n");
   }
}


Tile getCurrentTile(Maze maze) {
   return maze->currentTile;
}


Tile updateCurrentTile(Maze maze, int flagid, int status) {
   Tile t = maze->currentTile;
   if (t != NULL) {
       t->flags[flagid] = status;
   }
   return t;
}


Tile add(Maze maze, int direction) {
   // Fill in this function
   // To fill in this function, you need to update the
   // currentTile's up, down, left or right depending on what
   // direction was supplied.
   Tile current = maze->currentTile;
   switch(direction){
       case UP:
           current->up = 1;
           break;
       case LEFT:
           current->left = 1;
           break;
       case DOWN:
           current->down = 1;
           break;
       case RIGHT:
           current->right = 1;
           break;
   }
   return current; // remove this line if not needed
}


Tile move(Maze maze, int direction) {
   // 1. Check if the direction is possible (not a wall)
   // - if not possible, return NULL
   // 2. Change the currentTile pointer to point to the Tile
   // above, left, right or down from the current tile.
   Tile current = maze->currentTile;
   switch(direction){
       case UP:
           if (!current->up || maze->currentTileX == 0) return NULL;
           maze->currentTileX--;
           break;
       case LEFT:
           if (!current->left || maze->currentTileY == 0) return NULL;
           maze->currentTileY--;
           break;
       case DOWN:
           if (!current->down || maze->currentTileX == maze->size - 1) return NULL;
           maze->currentTileX++;
           break;
       case RIGHT:
           if (!current->right || maze->currentTileY == maze->size - 1) return NULL;
           maze->currentTileY++;
           break;
   }
   // Create tile if it doesn't exist
   if (maze->tiles[maze->currentTileX][maze->currentTileY] == NULL) {
       maze->tiles[maze->currentTileX][maze->currentTileY] = createTile();
   }
   maze->currentTile = maze->tiles[maze->currentTileX][maze->currentTileY];
   // Update current tile
   add(maze, -direction);
   return maze->currentTile; // remove this line if not needed
}


Tile createTile() {
   Tile t = (Tile)malloc(sizeof(Node));
   assert(t != NULL);
   t->up = 0;
   t->left = 0;
   t->down = 0;
   t->right = 0;
   int i;
   for (i = 0; i < 4; i++) {
       t->flags[i] = 0;
   }
   return t;
}

#endif

int main() {
   // make a maze
   Maze maze = createMaze(5, 0, 0);
   // possible paths: down and left at [0, 0]
   printf("Current location: [%d, %d]\n", maze->currentTileX, maze->currentTileY);
   add(maze, DOWN);
   add(maze, RIGHT);
   Tile curr = getCurrentTile(maze);
   if (curr != NULL) {
       // should print that down and right are available
       printf("Current status (u,d,l,r): %d, %d, %d, %d\n", curr->up, curr->down, curr->left, curr->right);
   }
   // move to [1, 0]
   move(maze, RIGHT);
   printf("Current location: [%d, %d]\n", maze->currentTileX, maze->currentTileY);
   // possible paths: left and right at [1, 0]
   add(maze, LEFT);
   add(maze, RIGHT);
   curr = getCurrentTile(maze);
   if (curr != NULL) {
       // should print that left and right are available
       printf("Current status (u,d,l,r): %d, %d, %d, %d\n", curr->up, curr->down, curr->left, curr->right);
   }
   // print the maze
   printMaze(maze);

   return 0;
}