//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string startWord, string targetWord, vector<string>& wordList) {
        unordered_set <string> s(wordList.begin(), wordList.end());
        s.erase(startWord);
        queue <pair <string, int>> q;
        q.push({startWord,1});
        
        while(!q.empty()){
            auto it = q.front();
            q.pop();
            string str = it.first;
            int ways = it.second;
            if(str == targetWord) return ways;
            for(int i=0 ; i<str.length() ; i++){
                char original = str[i];
                for(char ch = 'a' ; ch <= 'z' ; ch++){
                    str[i] = ch;
                    if(s.find(str) != s.end()){
                        s.erase(str);
                        q.push({str,ways+1});
                    }
                }
                str[i] = original;
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
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
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends
