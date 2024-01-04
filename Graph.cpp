#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<list>


using namespace std;

void AdjMatrix(int n,int m){
    int arr[n+1][n+1]={0};
    int i,j;
    for(i=0;i<m;i++){
        int u,v;
        cout<<"values 1 & 2 = ";
        cin>>u>>v;
        arr[u][v]=1;
        arr[v][u]=1;
    }

    for(i=1;i<=m;i++){
        cout<<i<<" -> ";
        for(j=0;j<m;j++){
            cout<<arr[i][j]<<" ";
        }
        cout<<"\n";
    }

}

void AdjList(int n,int m){
    vector<int> arr[n+1];
    int i,j;
    for(i=0;i<m;i++){
        int u,v;
        cout<<"values 1 & 2 : ";
        cin>>u>>v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    vector<int>::iterator it;
    for(i=1;i<=n;i++){
        cout<<i<<" -> ";
        for(it=arr[i].begin();it!=arr[i].end();it++){
            cout<<*it<<" ";
        }
        cout<<"\n";
    }
}

void AdjMap(int n,int m){
    map<int,list<int> > Map;
    int i,j;
    for(i=0;i<m;i++){
        int u,v;
        cout<<"values 1 & 2 = ";
        cin>>u>>v;
        Map[u].push_back(v);
        Map[v].push_back(u);
    }

    map<int,list<int> > :: iterator mit;
    list<int> :: iterator lit;
    for(mit=Map.begin();mit!=Map.end();mit++){
        cout<<mit->first<<" -> ";
        for(lit=mit->second.begin();lit!=mit->second.end();lit++){
             cout<<*lit<<" " ;
        }
        cout<<endl;
    }
}

void bfs(int n,int m){
    int i;
    vector<int> arr[n+1];
    for(i=0;i<m;i++){
        int u,v;
        cout<<"values 1 & 2 = ";
        cin>>u>>v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }

    vector<int>::iterator it;
    for(i=1;i<=m;i++){
        cout<<i<<" -> ";
        for(it=arr[i].begin();it!=arr[i].end();it++){
            cout<<*it<<" ";
        }
        cout<<"\n";
    }

    queue<int> q;
    int vis[n+1]={0};
    int rootNode;
    cout<<"enter node from where u wanna start implementing bfs algorithm : ";
    cin>>rootNode;
    q.push(rootNode);
    vis[rootNode]=1;
    while (!q.empty()){
        int node = q.front();
        q.pop();
        cout<<node<<" ";
        vector<int>::iterator it;
        for(it=arr[node].begin();it!=arr[node].end();it++){
            if(!vis[*it]){
                vis[*it]=1;
                q.push(*it);
            }
        }
    }
}   

void dfs(int rootNode,int vis[],vector<int> arr[]){
    vis[rootNode]=1;
    cout<<rootNode<<" ";
    vector<int> :: iterator it;
    for(it=arr[rootNode].begin();it!=arr[rootNode].end();it++){
        if(!vis[*it]){
            int start=*it;
            dfs(start,vis,arr);
        }
    }
}

int main(){
    int n,m;
    cout<<"nodes & edges = ";
    cin>>n>>m;
    vector<int> arr[n+1];
    cout<<"1 FOR GRAPH WITH ADJACENCY MATRIX\n";
    cout<<"2 FOR GRAPH WITH ADJACENCY LIST\n";
    cout<<"3 FOR GRAPH WITH ADJACENCY MAP\n";
    cout<<"4 FOR BFS -> BREADTH FIRST SEARCH\n";
    cout<<"5 FOR DFS -> DEPTH FIRST SEARCH\n";
    int num;
    cout<<"enter choice : ";
    cin>>num;   
    switch(num){
        case 1:{
            AdjMatrix(n,m);
            break;
        }
        case 2:{
            AdjList(n,m);
            break;
        }
        case 3:{
            AdjMap(n,m);
            break;
        }
        case 4:{
            bfs(n,m);
            break;
        }
        case 5:{
            int i;
            int n,m;
            cout<<"nodes & edges = ";
            cin>>n>>m;
            vector<int> arr[n+1];
            for(i=0;i<m;i++){
                int u,v;
                cout<<"values 1 & 2 = ";
                cin>>u>>v;
                arr[u].push_back(v);
                arr[v].push_back(u);
            }

            vector<int>::iterator it;
            for(i=1;i<=m;i++){
                cout<<i<<" -> ";
                for(it=arr[i].begin();it!=arr[i].end();it++){
                    cout<<*it<<" ";
                }
                cout<<"\n";
            }
            int rootNode;
            cout<<"enter node from where u wanna start implementing dfs algorithm : ";
            cin>>rootNode;
            int vis[n+1]={0};
            dfs(rootNode,vis,arr);
            break;
        }
        default : {
            cout<<"wrong number\n";
            break;
        }
    }
}