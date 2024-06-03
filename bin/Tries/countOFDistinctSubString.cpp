// https://www.geeksforgeeks.org/problems/count-of-distinct-substrings/1
#include <bits/stdc++.h>
using namespace std;

class TrieNode
{
public:
  TrieNode *childNode[26] = {NULL};
};

class Trie
{
public:
  TrieNode *root = new TrieNode();

  int insert(string s)
  {
    TrieNode *currentNode = this->root;
    int count = 0;
    for (char ch : s)
    {
      if (!currentNode->childNode[ch - 'a'])
      {
        count++;
        currentNode->childNode[ch - 'a'] = new TrieNode();
      }
      currentNode = currentNode->childNode[ch - 'a'];
    }
    return count;
  }
  int countDistinctSubstring(string s)
  {
    int count = 0;
    for (int i = 0; i < s.size(); i++)
    {
      count += insert(s.substr(i, s.size() - i));
    }
    // plus 1 for empty string
    return count + 1;
  }
};

/*You are required to complete this method */
int countDistinctSubstring(string s)
{
  Trie t;
  return t.countDistinctSubstring(s);
}