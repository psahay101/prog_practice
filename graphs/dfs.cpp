

/*
Depth first search:

1. go to s
2. go to each of s's children in a stack and proceed from there.

breadth first search:

1. go to s
2. add all the s's children to the queue and proceed from the queue.

*/

/*
 * stacks vs queue in dfs vs bfs:
 * in bfs we have to add all the children of a node in a queue and then take each of the children
 * and further add their children in the queue.
 * But the turn of children of children will come only ones all the children of the first node have
 * been processed.
 *
 * In DFS we want all the lineage of one node to get covered first.
 * We will have to put them in a stack which actually works opposite of the queue.
 * s->s1->s2->s3->s31->s32->s321->s322->s323
 */

/*
 * the other way of implementing a dfs would through a recursive call where a child's first child's first child can
 * be called until there is no first child then look for second child.
 * the other method is shown below and the recur function is the crux of it.
 */

void recur(int s, bool *visited){
    cout<<s<<" ";
    visited[s]=true;
    vector<int>::iterator i;
    for(i=adj[s].begin();i!=adj[s].end();++i){
        if(!visited[*i]){
            recur(s,*visited);
        }
    }
}

void graph::dfs(int s){
    bool *visited = new bool[v];
    for(int i=0;i<v;i++){
        visited[i]=false;
    }

    cout<<s<<" ";
    visited[s]= true;

    recur(s,*visited);


}