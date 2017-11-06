#ifndef MAP_H
#define MAP_H#include <iostream>
#include <stdio.h>
#include <list>
#include <fstream>
#include "AStar.h"

#define DEBUG_LISTS 0
#define DEBUG_LIST_LENGTHS_ONLY 0


struct position{
public:
    int x,y;
};

class Map {
public:
    inline position start(int startX, int startY,std::list<position> data);
};




// Global data

// The world map

const int MAP_WIDTH = 1200;
const int MAP_HEIGHT = 700;



// map helper functions

inline void printMap(int* map){
    std::ofstream myfile;
    myfile.open ("map.csv");
    int contador=0;
    for(int i = 0;i < 700;i++){
        for(int j = 0;j < 1200;j++){
            myfile <<map[contador]<<", ";
            contador++;
        }
        myfile <<"\n";
    }
    cout <<"Contador: "<< contador<<endl;
    myfile.close();
}
inline int* generateMap(std::list<position> data) {
    int result[1200*700];
    int i;
    for (i = 0; i < (1200*700); ++i){
        result[i] = 1;
        //cout<<"Posicion: "<< i<<endl;
    }
    cout <<"Counter: "<< i<<endl;
    int counter = 0;
    for(position n : data){
        std::cout<< n.x<<", "<<n.y<<"\n";
        for(int i = n.y-15; i <= n.y+20;i++){
            for(int j = n.x-15; j <= n.x+15;j++){
                counter++;
                result[j+i*1200]=9;
                //std::cout<<"Coordenadas: "<<j<<", "<<i<<"\n";
            }
        }

    }
    //printMap(result);
    return result;
}



inline std::list<position> data;

inline int* map1;


inline int GetMap( int x, int y )
{

    if( x < 0 ||
        x >= MAP_WIDTH ||
        y < 0 ||
        y >= MAP_HEIGHT
            )
    {
        return 9;
    }

    return map1[(y*MAP_WIDTH)+x];
}



// Definitions

class MapSearchNode
{
public:
    unsigned int x;	 // the (x,y) positions of the node
    unsigned int y;

    MapSearchNode() { x = y = 0; }
    MapSearchNode( unsigned int px, unsigned int py ) { x=px; y=py; }

    inline float GoalDistanceEstimate( MapSearchNode &nodeGoal );
    inline bool IsGoal( MapSearchNode &nodeGoal );
    inline bool GetSuccessors( AStarSearch<MapSearchNode> *astarsearch, MapSearchNode *parent_node );
    inline float GetCost( MapSearchNode &successor );
    inline bool IsSameState( MapSearchNode &rhs );

    inline void PrintNodeInfo();


};

inline bool MapSearchNode::IsSameState( MapSearchNode &rhs )
{

    // same state in a maze search is simply when (x,y) are the same
    if( (x == rhs.x) &&
        (y == rhs.y) )
    {
        return true;
    }
    else
    {
        return false;
    }

}

inline void MapSearchNode::PrintNodeInfo()
{
    char str[100];
    sprintf( str, "Node position : (%d,%d)\n", x,y );

    cout << str;
}

// Here's the heuristic function that estimates the distance from a Node
// to the Goal.

inline float MapSearchNode::GoalDistanceEstimate( MapSearchNode &nodeGoal )
{
    float xd = float( ( (float)x - (float)nodeGoal.x ) );
    float yd = float( ( (float)y - (float)nodeGoal.y) );

    return ((xd*xd) + (yd*yd));

}

inline bool MapSearchNode::IsGoal( MapSearchNode &nodeGoal )
{

    if( (x == nodeGoal.x) &&
        (y == nodeGoal.y) )
    {
        return true;
    }

    return false;
}

// This generates the successors to the given Node. It uses a helper function called
// AddSuccessor to give the successors to the AStar class. The A* specific initialisation
// is done for each node internally, so here you just set the state information that
// is specific to the application
inline bool MapSearchNode::GetSuccessors( AStarSearch<MapSearchNode> *astarsearch, MapSearchNode *parent_node )
{

    int parent_x = -1;
    int parent_y = -1;

    if( parent_node )
    {
        parent_x = parent_node->x;
        parent_y = parent_node->y;
    }


    MapSearchNode NewNode;

    // push each possible move except allowing the search to go backwards

    if( (GetMap( x-1, y ) < 9)
        && !((parent_x == x-1) && (parent_y == y))
            )
    {
        NewNode = MapSearchNode( x-1, y );
        astarsearch->AddSuccessor( NewNode );
    }

    if( (GetMap( x, y-1 ) < 9)
        && !((parent_x == x) && (parent_y == y-1))
            )
    {
        NewNode = MapSearchNode( x, y-1 );
        astarsearch->AddSuccessor( NewNode );
    }

    if( (GetMap( x+1, y ) < 9)
        && !((parent_x == x+1) && (parent_y == y))
            )
    {
        NewNode = MapSearchNode( x+1, y );
        astarsearch->AddSuccessor( NewNode );
    }


    if( (GetMap( x, y+1 ) < 9)
        && !((parent_x == x) && (parent_y == y+1))
            )
    {
        NewNode = MapSearchNode( x, y+1 );
        astarsearch->AddSuccessor( NewNode );
    }

    return true;
}

// given this node, what does it cost to move to successor. In the case
// of our map the answer is the map terrain value at this node since that is
// conceptually where we're moving

inline float MapSearchNode::GetCost( MapSearchNode &successor )
{
    return (float) GetMap( x, y );

}


// Main

inline position Map::start(int startX, int startY,std::list<position> data)
{
    map1 = generateMap(data);

    //printMap(map1);


    AStarSearch<MapSearchNode> astarsearch;

    // Create a start state
    MapSearchNode nodeStart;
    nodeStart.x = startX;
    nodeStart.y = startY;

    // Define the goal state
    MapSearchNode nodeEnd;
    nodeEnd.x = 1199;
    nodeEnd.y = 350;

    // Set Start and goal states

    astarsearch.SetStartAndGoalStates( nodeStart, nodeEnd );


    unsigned int SearchState;
    unsigned int SearchSteps = 0;
    position temp;

    do
    {
        SearchState = astarsearch.SearchStep();

        SearchSteps++;


    }
    while( SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_SEARCHING );
    if( SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_SUCCEEDED )
    {
        cout << "Search found goal state\n";

        MapSearchNode *node = astarsearch.GetSolutionStart();

        int steps = 0;

        node->PrintNodeInfo();

            node = astarsearch.GetSolutionNext();
            //cout << "Current node X: " << node->x << endl;
            if( !node )
            {
            }

            node->PrintNodeInfo();
            steps ++;
        temp.x = node->x;
        temp.y = node->y;


        cout << "Solution steps " << steps << endl;

        // Once you're done with the solution you can free the nodes up
        astarsearch.FreeSolutionNodes();

    }
    else if( SearchState == AStarSearch<MapSearchNode>::SEARCH_STATE_FAILED )
    {
        cout << "Search terminated. Did not find goal state\n";

    }

    // Display the number of loops the search went through
    cout << "SearchSteps : " << SearchSteps << "\n";
    *map1 = 0;
    return temp;
}
#endif // MAP_H
