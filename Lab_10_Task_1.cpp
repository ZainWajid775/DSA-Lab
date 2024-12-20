#include <iostream>
#include <list>

using namespace std;

class Graph
{
    public:
        int vertices;
        list<int> *adjacency_list;

        Graph(int v)
        {
            vertices = v;
            adjacency_list = new list<int>[vertices];
        }

        void add_edge(int v1 , int v2)
        {
            adjacency_list[v1].push_back(v2);
            adjacency_list[v1].push_back(v2);
        }

        void print(int source)
        {
            cout << "Adjacency List of " << source << " is: ";
            for(auto x : adjacency_list[source])
            {
                cout << x << " ";
            }
            cout << endl;

        }

        void bfs(int source)
        {
            // Mark all as unvisited
            bool *visited = new bool[vertices];
            for(int i = 0 ; i < vertices ; i++)
            {
                visited[i] = false;
            }

            list<int> queue;

            // Source node visited
            visited[source] = true;
            queue.push_back(source);

            // Iterator to get adjacent nodes
            list<int>::iterator i;

            while (!queue.empty())
            {
                // Remove front and print
                source = queue.front();
                cout << source << " ";
                queue.pop_front();

                // Check all stored nodes in adjacent list if they have been visisted already
                // If not add to queue
                for(i = adjacency_list[source].begin() ; i != adjacency_list[source].end() ; i++)
                {
                    if(!visited[*i])
                    {
                        visited[*i] = true;
                        queue.push_back(*i);
                    }
                }
            }
            
        }



};

int main()
{
    Graph temp(5);

    temp.add_edge(0, 1);
    temp.add_edge(0, 2);
    temp.add_edge(0, 3);
    temp.add_edge(0, 4);
    temp.add_edge(1, 2);
    temp.add_edge(2, 0);

    temp.print(0);
    temp.print(1);

    cout << endl;

    cout << "BFS Traversal: ";
    temp.bfs(2);
}