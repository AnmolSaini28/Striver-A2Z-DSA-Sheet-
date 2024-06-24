//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
  public:
    int MinimumEffort(int n, int m, vector<vector<int>> &heights) {
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        vector<vector<int>> dis(n, vector<int>(m,1e9));
        dis[0][0] = 0;
        pq.push({0,{0,0}});
        int nRow[] = {-1,0,+1,0};
        int nCol[] = {0,-1,0,+1};
        while(!pq.empty()){
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            int weight = pq.top().first;
            pq.pop();
            if(row == n-1 && col == m-1){
                return weight;
            }
            for(int i=0 ; i<4 ; i++){
                int newRow = row+nRow[i];
                int newCol = col+nCol[i];
                if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m){
                    int newEffort = max(weight, abs(heights[newRow][newCol]-heights[row][col]));
                    if(dis[newRow][newCol] > newEffort){
                        dis[newRow][newCol] = newEffort;
                        pq.push({newEffort, {newRow, newCol}});
                    }
                }
            }
        }
        return 0;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int rows;
        scanf("%d", &rows);

        int columns;
        scanf("%d", &columns);

        vector<vector<int>> heights(rows, vector<int>(columns));
        Matrix::input(heights, rows, columns);

        Solution obj;
        int res = obj.MinimumEffort(rows, columns, heights);

        cout << res << endl;
    }
}

// } Driver Code Ends
