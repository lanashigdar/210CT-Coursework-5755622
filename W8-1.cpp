#include <iostream>
#include <limits>

using namespace std;

class Vertex
{
public:
    Vertex(int label){             //constructor
        this->label = label;

        cout << "Vertex " <<  label << " has been created" << endl;
    }
    ~Vertex(){                      //deconstructor
        cout << "Vertex " << label << " has been destroyed" << endl;
    }
    int label;              //value of the vertex
    int tenWeight = 0;      //tentative weight
    Vertex* prevVertex = NULL;  //previous vertex
    int linkPosition = 0;       //how many links added to this vertex so far

    pair<Vertex*,int>links[10] = {};
};

class Graph
{
public:
    Graph(){
    }
    ~Graph(){
    }
    int verticesPosition = 0;   //how many vertices added to this graph so far
    Vertex* vertices[10] = {};  //fixed array of 10

    void addVertex(int label)
    {
        if(!inGraph(label)) //checks to see if a vertex exists with this label in the graph
        {
            vertices[verticesPosition] = new Vertex(label); //adds vertex to graph
            verticesPosition = verticesPosition +1; //avoid overwriting vertices
        }
    }

    void addEdge(int a,int b, int weight)   //a = from vertex, b = to vertex
    {
        if(inGraph(a) && inGraph(b))
        {
            Vertex* vertexA = getVertex(a); //pointers from getVertex
            Vertex* vertexB = getVertex(b);
            vertexA->links[vertexA->linkPosition] = make_pair(vertexB,weight); //each with their own link position
            vertexA->linkPosition = vertexA->linkPosition +1;                   //increments position of links to avoid overwriting
            vertexB->links[vertexB->linkPosition] = make_pair(vertexA, weight);
            vertexB->linkPosition = vertexB->linkPosition +1;

            cout << "A link was created to " << b << " from " << a << ". Weight is: " << weight << endl;
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

void dijkstra(Graph* G, int s, int d)
{
    //declaring variables
    Vertex* sVertex = G->getVertex(s);  //starting vertex
    Vertex* dVertex = G->getVertex(d);  //destination vertex
    Vertex* v = sVertex; //traversing vertex

    //set all vertices in the graph to infinite weight
    for (int i = 0; i < G->verticesPosition; i++)
    {
        Vertex* currentVertex = G->vertices[i];

        if (currentVertex == NULL)
        {
            break;
        }
        currentVertex->tenWeight = numeric_limits<int>::max(); //max number an int can be
    }

    //declaring variables
    sVertex->tenWeight = 0; //start has no weight
    Vertex* visited[10] = {};
    int visitedPosition = 0;

    //while we are not at our destination
    while (v != dVertex)
    {
        //update tentitive weights of v's neighbours and set their previous vertex to v
        for (int i = 0; i < v->linkPosition; i++)
        {
            if (v->tenWeight + v->links[i].second < v->links[i].first->tenWeight)
            {
              v->links[i].first->tenWeight = v->tenWeight + v->links[i].second;
              v->links[i].first->prevVertex = v;
            }
        }

        //set v to visited
        visited[visitedPosition] = v;
        visitedPosition = visitedPosition +1;

        //set v to smallest weighted vertex that has yet to be visited
        int minimum = numeric_limits<int>::max();
        //find all vertices in the graph that have yet to be visited
        for (int i = 0; i < G->verticesPosition; i++)
        {
            Vertex* currentVertex = G->vertices[i];
            bool inVisited = false;
            for(int j = 0; j < visitedPosition; j++)
            {
                Vertex* visitedVertex = visited[j];
                if (currentVertex == visitedVertex)
                {
                    inVisited = true;
                }
            }
            //if this vertex has not been visited, and its weight is smaller than the current minimum
            if (inVisited == false && currentVertex->tenWeight < minimum)
            {
               v = currentVertex;
               minimum = currentVertex->tenWeight;
            }
        }
    }
    //display the shortest route (but in reverse)
    while (v != sVertex)
    {
        cout << v->label << endl;
        v = v->prevVertex;
    }
    cout << v->label << endl;
}

void W8_1()
{
    Graph* graph = new Graph();
    graph->addVertex(1);
    graph->addVertex(2);
    graph->addVertex(3);
    graph->addVertex(4);

    graph->addEdge(1,2,2);
    graph->addEdge(1,4,2);
    graph->addEdge(2,4,2);
    graph->addEdge(3,4,2);

    dijkstra(graph, 1, 3);


    delete graph;

}
