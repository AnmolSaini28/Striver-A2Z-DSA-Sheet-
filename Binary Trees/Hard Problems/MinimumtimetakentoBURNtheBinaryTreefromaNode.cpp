//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    Node * nodetoParentMapping(Node *root, int target, map<Node*, Node*> &m){
        Node *res = NULL;
        queue <Node*> q;
        q.push(root);
        m[root] = NULL;
        while(!q.empty()){
            Node *curr = q.front();
            q.pop();
            if(curr->data == target){
                res = curr;
            }
            if(curr->left != NULL){
                q.push(curr->left);
                m[curr->left] = curr;
            }
            if(curr->right != NULL){
                q.push(curr->right);
                m[curr->right] = curr;
            }
        }
        return res;
    }
    int burnTree(Node *root, map <Node*, Node*> &m){
        map <Node*,bool> vis;
        queue <Node*> q;
        q.push(root);
        vis[root] = 1;
        int res = 0;
        while(!q.empty()){
            bool flag = 0;
            int count = q.size();
            for(int i=0 ; i<count ; i++){
                Node *curr = q.front();
                q.pop();
                if(curr->left && !vis[curr->left]){
                    q.push(curr->left);
                    vis[curr->left] = 1;
                    flag = 1;
                }
                if(curr->right && !vis[curr->right]){
                    q.push(curr->right);
                    vis[curr->right] = 1;
                    flag = 1;
                }
                if(m[curr] && !vis[m[curr]]){
                    q.push(m[curr]);
                    vis[m[curr]] = 1;
                    flag = 1;
                }
            }
            if(flag == 1){
                res++;
            }
        }
        return res;
    }
    int minTime(Node* root, int target) 
    {
        // Create a Node to Parent Mapping and find TargetNode
        map <Node*, Node*> m;
        Node *targetNode = nodetoParentMapping(root,target,m);
        
        // Burn Tree
        int ans = burnTree(targetNode,m);
        return ans;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends
