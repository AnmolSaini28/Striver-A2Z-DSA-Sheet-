int n;
int parent[n];
int rank[n];

void initilise(){
  for(int i=0 ; i<n ; i++){
    parent[i] = i;
    rank[i] = 0;
  }
}

int find(int X){
  if(parent[X] == X){
    return X;
  }
  parent[X] = find(parent[X]);
  return parent[X];
}

void union(int X , int Y){
  int x_rep = find(X);
  int y_rep = find(Y);
  if(x_rep == y_rep){
    return;
  }
  else if(rank[x_rep] > rank[y_rep]){
    parent[y_rep] = x_rep;
  }
  else if(rank[y_rep] > rank[x_rep]){
    parent[x_rep] = y_rep;
  }
  else{
    parent[x_rep] = y_rep;
    rank[y_rep]++;
  }
}
