#include <iostream>
#include <stack> //for DFS
#include <queue> //for BFS
#include <fstream> //allow for print to file

using namespace std;

//Task 1

class Vertex
{
public:
    Vertex(int label){      //constructor
        this->label = label;
        cout << "Vertex " <<  label << " has been created" << endl;
    }
    ~Vertex(){              //deconstructor
        cout << "Vertex " << label << " has been destroyed" << endl;
    }
    int label;              //value of the vertex
    int linkPosition = 0;   //how many links added to this vertex so far
    Vertex* links[10] = {}; //fixed array at 10
};

class Graph
{
public:
    Graph(){
    }
    ~Graph(){
    }
    int verticesPosition = 0;   //how many vertices added to this graph so far
    Vertex* vertices[10] = {};

    void addVertex(int label)
    {
        if(!inGraph(label))     //checks to see if a vertex exists with this label in the graph
        {
            vertices[verticesPosition] = new Vertex(label); //adds vertex to graph
            verticesPosition = verticesPosition +1;         //avoid overwriting vertices
        }
    }

    void addEdge(int a,int b)   //a = from vertex, b = to vertex
    {
        if(inGraph(a) && inGraph(b))
        {
            Vertex* vertexA = getVertex(a);                 //pointers from getVertex
            Vertex* vertexB = getVertex(b);
            vertexA->links[vertexA->linkPosition] = vertexB; //each with their own link position
            vertexA->linkPosition = vertexA->linkPosition +1; //increments position of links to avoid overwriting
            vertexB->links[vertexB->linkPosition] = vertexA;
            vertexB->linkPosition = vertexB->linkPosition +1;

            cout << "A link was created to " << b << " from " << a << endl;
        }

    }

    bool inGraph(int label)
    {
        for(int i = 0; i < 10; i++)   //10, as it is length of vertices array
        {
            Vertex* currentVertex = vertices[i];

            if (currentVertex == NULL) //cannot compare label if null
            {
                break;
            }

            if (label == currentVertex->label)
            {
                return true;
            }
        }
        return false;       //cannot find vertex with the label
    }

    Vertex* getVertex(int label)
    {
        for(int i = 0; i < 10; i++)   //10, as it is length of vertices array
        {
            Vertex* currentVertex = vertices[i];

            if (currentVertex == NULL) //cannot compare label if null
            {
                break;
            }

            if (label == currentVertex->label)
            {
                return currentVertex;
            }
        }
        return NULL;
    }
};

//Task 2

void depthFirstSearch (Graph* G,int v)
{
    //creating variables
    stack<Vertex*> stackDFS;
    int visitedPosition = 0;
    Vertex* visited[10] = {};
    Vertex* vVertex = G->getVertex(v);

    stackDFS.push(vVertex);

    while (!stackDFS.empty())       //while the stack is not empty
    {
        Vertex* u = stackDFS.top(); //places vertex into stack
        stackDFS.pop();             //remove vertex from stack

        //find out if u has already been visited
        bool inVisited = false;
        for (int i = 0; i < sizeof(visited)/sizeof(visited[0]); i++)  //iterate for length of visited
        {
            Vertex* currentVertex = visited[i];
            if (currentVertex == NULL)          //cannot compare if vertex is null
            {
                break;
            }
            if (currentVertex->label == u->label)   //if vertex with label is found, is in visited
            {
                inVisited = true;
            }
        }

        //if u has not been visited, update visited so it has been
        //add all of u's neighbours to the stack
        if (inVisited == false)
        {
            visited[visitedPosition] = u;
            visitedPosition = visitedPosition +1;

            for (int i = 0; i < u->linkPosition; i++)
            {
                stackDFS.push(u->links[i]);
            }
        }
    }

    //output the results to a file
    ofstream myFile("Week7Search.txt"); //file for result
    if (myFile.is_open())
    {
        myFile << "DFS results " << endl;

        for (int i = 0; i < sizeof(visited)/sizeof(visited[0]); i++)
        {
            Vertex* currentVertex = visited[i];
            if (currentVertex == NULL)
            {
                break;
            }
            myFile << currentVertex->label;
        }
        myFile << endl;
        myFile.close();
    }
    else
    {
        cout << "File failed to open " << endl; //fail conditon
    }
}

//same as DFS algorithm, but with a queue data structure
void breadthFirstSearch (Graph* G,int v)
{
    queue<Vertex*> queueBFS;
    int visitedPosition = 0;
    Vertex* visited[10] = {};
    Vertex* vVertex = G->getVertex(v);
    queueBFS.push(vVertex);


    while (!queueBFS.empty())         //while queue is not empty
    {
        Vertex* u = queueBFS.front(); //places vertex into queue
        queueBFS.pop();               //removes vertex from queue

        bool inVisited = false;
        for (int i = 0; i < sizeof(visited)/sizeof(visited[0]); i++)
        {
            Vertex* currentVertex = visited[i];
            if (currentVertex == NULL)
            {
                break;
            }
            if (currentVertex->label == u->label)
            {
                inVisited = true;
            }
        }
        if (inVisited == false)
        {
            visited[visitedPosition] = u;
            visitedPosition = visitedPosition +1;

            for (int i = 0; i < u->linkPosition; i++)
            {
                queueBFS.push(u->links[i]);
            }
        }
    }

    ofstream myFile("Week7Search.txt",ios::out|ios::app);
    if (myFile.is_open())
    {
        myFile << "BFS results " << endl;

        for (int i = 0; i < sizeof(visited)/sizeof(visited[0]); i++)
        {
            Vertex* currentVertex = visited[i];
            if (currentVertex == NULL)
            {
                break;
            }
            myFile << currentVertex->label;
        }
        myFile << endl;
        myFile.close();
    }
    else
    {
        cout << "File failed to open " << endl;
    }
}

void W7_1()
{
    Graph* graph = new Graph();
    graph->addVertex(1);
    graph->addVertex(2);
    graph->addVertex(3);
    graph->addVertex(4);

    graph->addEdge(1,2);
    graph->addEdge(1,4);
    graph->addEdge(2,4);
    graph->addEdge(3,4);

    depthFirstSearch(graph, 1);
    breadthFirstSearch(graph, 1);

    delete graph;

}
