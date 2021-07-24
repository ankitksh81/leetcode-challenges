/* Day 24
    Problem link: https://leetcode.com/explore/challenge/card/july-leetcoding-challenge-2021/611/week-4-july-22nd-july-28th/3825/
*/


// Solution:

class Solution {
public:
    unordered_map<string, vector<string>> adjList;
    vector<string> currPath;
    vector<vector<string>> shortestPaths;

    vector<string> findNeighbors(string &word, unordered_set<string>& wordList) {
        vector<string> neighbors;

        for (int i = 0; i < word.size(); i++) {
            char oldChar = word[i];

            // replace the i-th character with all letters from a to z except the original character
            for (char c = 'a'; c <= 'z'; c++) {
                word[i] = c;

                // skip if the character is same as original or if the word is not present in the wordList
                if (c == oldChar || !wordList.count(word)) {
                    continue;
                }
                neighbors.push_back(word);
            }
            word[i] = oldChar;
        }
        return neighbors;
    }

    void backtrack(string &source, string &destination) {
        // store the path if we reached the endWord
        if (source == destination) {
            shortestPaths.push_back(currPath);
        }
        for (int i = 0; i < adjList[source].size(); i++) {
            currPath.push_back(adjList[source][i]);
            backtrack(adjList[source][i], destination);
            currPath.pop_back();
        }
    }

    void addEdge(string &word1, string &word2, int direction) {
        if(direction == 1) {
            adjList[word1].push_back(word2);
        } else {
            adjList[word2].push_back(word1);
        }
    }

    bool bfs(string beginWord, string endWord, unordered_set<string> wordList) {
        if (wordList.count(endWord) == 0) {
            return false;
        }

        // remove the root word which is the first layer
        if (wordList.find(beginWord) != wordList.end()) {
            wordList.erase(wordList.find(beginWord));
        }

        unordered_set<string> forwardQueue, backwardQueue;
        forwardQueue.insert(beginWord);
        backwardQueue.insert(endWord);

        bool found = false;
        int direction = 1;

        while (forwardQueue.size() != 0)  {
            // visited will store the words of current layer
            unordered_set<string> visited;

            // swap the queues because we are always extending the forwardQueue
            if (forwardQueue.size() > backwardQueue.size()) {
                swap(forwardQueue, backwardQueue);
                direction ^= 1;
            }

            for (auto currWord : forwardQueue) {
                vector<string> neighbors = findNeighbors(currWord, wordList);

                 for (auto word : neighbors) {

                     // if the backwardQueue already contains it we can stop after completing this level
                     if (backwardQueue.find(word) != backwardQueue.end()) {
                         found = true;
                         addEdge(currWord, word, direction);

                     /* the word shouldn't be presnt in forwardQueue because if it is then the edge will
                        be between two words at the same level which we don't want */
                     } else if (!found && wordList.count(word) != 0 && forwardQueue.count(word) == 0) {
                         visited.insert(word);
                         addEdge(currWord, word, direction);
                     }
                 }
            }

            // removing the words of the previous layer
            for (auto currWord : forwardQueue) {
                if (wordList.find(currWord) != wordList.end()) {
                    wordList.erase(wordList.find(currWord));
                }
            }
            if (found) {
                break;
            }

            forwardQueue = visited;
        }
        return found;
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        // copying the words into the set for efficient deletion in BFS
        unordered_set<string> copiedWordList(wordList.begin(), wordList.end());
        // build the DAG using BFS
        bool sequence_found = bfs(beginWord, endWord, copiedWordList);

        // There is no valid sequence that connects `beginWord` to `endWord`
        if (sequence_found == false) {
            return shortestPaths;
        }
        // every path will start from the beginWord
        currPath = {beginWord};
        // traverse the DAG to find all the paths between beginWord and endWord
        backtrack(beginWord, endWord);

        return shortestPaths;
    }
};

class Solution {
public:
    //visited and level
    unordered_map<string,int> visited;
    unordered_set<string> dict;
    unordered_map<string,vector<string>> adjlist;

    vector<vector<string>> ans;
    vector<string> path;

    void dfs(string beginWord, string endWord){
        path.push_back(beginWord);
        if(beginWord == endWord) {
            ans.push_back(path);
            path.pop_back();
            return ;
        }
        for(auto word: adjlist[beginWord])
            //path.push_back(word);
            dfs(word,endWord);
            path.pop_back();
        }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        for(int i = 0; i < wordList.size(); i++)
            dict.insert(wordList[i]);

        if(dict.find(endWord) == dict.end())
            return {};
        queue<string> q;
        q.push(beginWord);
        visited[beginWord] = 1;
        while(!q.empty()) {
            string current = q.front();
            q.pop();
            for(int i = 0; i < current.length(); i++){
                string temp = current;
                for(char j = 'a'; j <= 'z'; j++){
                    temp[i] = j;
                    if(dict.find(temp) != dict.end()){
                        if(visited.find(temp) == visited.end()){
                        visited[temp] = visited[current]+1;
                        q.push(temp);
                        adjlist[current].push_back(temp);
                        }
                        else if(visited[temp] == visited[current]+1)
                            adjlist[current].push_back(temp);
                    }
                }
            }
        }

        dfs(beginWord,endWord);
        return ans;
    }
};
