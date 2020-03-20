#include <iostream>
#include <vector>

/*
Basic structure
1. Make a class called as Graph
2. Make a var named v and a pointer named adj.
3. Make add edge fn and a graph constructor and a bfs function.
*/


/*
 * bfs function:
 * 1. make a queue
 * 2. mark all nodes as false using a boolean array to mark the visited nodes.
 * Loop:
 * 3. Get an element out of the queue and then print it if not visited.
 * 4. Make it visited and add all of its children to the queue.
 * 5. stop when queue is empty.
 */

/*
 * Notes:
 * To access iterator we use *.
 * We can directly refer any element of an array pointer to actually access that element of the array.
 * Eg: int *num = new int[5];
 * num[4]=2;
 */


class graph(){

private:
    int v;
    vector<int> *adj;

public:

    graph(int v);
    void add_edge(int u, int v);
    void bfs(int s);

};

graph::graph(int v){
    this->v=v;
    adj = new vector<int>[v];
}

void graph::add_edge(int u, int v){
    adj[u].push_back(v); // directional graph
}

void graph::bfs(int s){
    bool *visited;
    visited = new bool[v];
    for(int i=0;i<v;i++){
        visited[v]=false;
    }

    queue<int> q;
    q.push_back(s);
    visited[s]=true;

    vector<int>::iterator i;

    while(!q.empty()){
        s=q.front();
        q.pop();
        cout<<s<<" ";
        visited[s]=true;


        for (i = adj[s].begin(); i != adj[s].end(); ++i){
            if(!visited[*i]){
                cout<<*i<<" ";
                visited[*i]=true;
                q.push(*i);
            }
        }

    }

}

using namespace std;

int main() {
    cout << "Hi World!" << endl;
    return 0;
}
