//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    vector<vector<string>> findSequences(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>>ans;
        unordered_set<string>dict(wordList.begin(),wordList.end());
        if (dict.find(endWord) == dict.end()) return ans;
        
        queue<vector<string>>q;
        q.push({beginWord});
        dict.erase(beginWord);
        
        while (q.empty() == false){
            
            int s = q.size();
            vector<string>wordsUsed;
            
            for (int i = 0; i < s; i++){
                vector<string>path = q.front();
                string word = q.front().back();
                q.pop();
                
                if (word == endWord){
                    ans.push_back(path);
                    continue;
                }
                for (int i = 0; i < word.size(); i++){
                    char original = word[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        word[i] = c;
                        if ( dict.find(word) != dict.end() ) { 
                            path.push_back(word);
                            q.push(path);
                            wordsUsed.push_back(word);
                            path.pop_back();
                        }
                    }
                    word[i] = original;
                }
            }
            for(auto it : wordsUsed) dict.erase(it);
        
        } return ans;
    }
};

//{ Driver Code Starts.

bool comp(vector<string> a, vector<string> b)
{
    string x = "", y = "";
    for(string i: a)
        x += i;
    for(string i: b)
        y += i;
    
    return x<y;
}

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		vector<vector<string>> ans = obj.findSequences(startWord, targetWord, wordList);
		if(ans.size()==0)
		    cout<<-1<<endl;
		else
		{
		    sort(ans.begin(), ans.end(), comp);
            for(int i=0; i<ans.size(); i++)
            {
                for(int j=0; j<ans[i].size(); j++)
                {
                    cout<<ans[i][j]<<" ";
                }
                cout<<endl;
            }
		}
	}
	return 0;
}
// } Driver Code Ends
