// https://www.geeksforgeeks.org/problems/search-query-auto-complete/1
#include <bits/stdc++.h>
using namespace std;
#define MAX_LEN 256
#define HASH '#'
#define EMPTY_STRING ""
#define EMPTY_CHAR '\0'

struct TrieNode
{
  vector<TrieNode *> childNode;
  int frequency;
  char ch;
  // constructor
  TrieNode(char ch = EMPTY_CHAR, int frequency = 0)
  {
    childNode = vector<TrieNode *>(MAX_LEN, NULL);
    this->ch = ch;
    this->frequency = frequency;
  }
  // methods

  vector<TrieNode *> getNonNullChildNodes()
  {
    vector<TrieNode *> ls;
    for (auto t : childNode)
    {
      if (t)
      {
        ls.push_back(t);
      }
    }
    return ls;
  }
};

class Trie
{
private:
  TrieNode *root = new TrieNode();

public:
  // if no frequnecy is provided it should be take as one
  void insert(string &str, int frequency = 1)
  {
    TrieNode *currentNode = this->root;

    for (char ch : str)
    {
      TrieNode *childNode = currentNode->childNode[ch];
      if (childNode == NULL)
      {
        childNode = new TrieNode(ch);
      }
      currentNode->childNode[ch] = childNode;
      currentNode = childNode;
    }
    currentNode->frequency = frequency;
  }

  TrieNode *getPrefixNode(string &str)
  {
    TrieNode *currentNode = this->root;
    for (char ch : str)
    {
      if (!currentNode->childNode[ch])
      {
        return NULL;
      }
      currentNode = currentNode->childNode[ch];
    }
    return currentNode;
  }

  void getAutoCompleteRecommendation(TrieNode *trieNode, vector<pair<int, string>> &allRecommendations, string &str)
  {
    if (trieNode == NULL)
    {
      return;
    }
    if (trieNode->frequency != 0)
    {
      allRecommendations.push_back({trieNode->frequency, str});
    }
    vector<TrieNode *> nonNullChildNode = trieNode->getNonNullChildNodes();
    for (auto node : nonNullChildNode)
    {
      str.push_back(trieNode->ch);
      getAutoCompleteRecommendation(node, allRecommendations, str);
      str.pop_back();
    }
  }

  vector<string> getAutoCompleteRecommendation(string &str)
  {
    vector<pair<int, string>> allRecommendations;
    TrieNode *prefixNode = getPrefixNode(str);
    getAutoCompleteRecommendation(prefixNode, allRecommendations, str);
  }
};

class AutoCompleteSystem
{
public:
  AutoCompleteSystem(vector<string> &sentences, vector<int> &times)
  {
    // write code for constructor
  }
  vector<string> input(char c)
  {
    // write code to return the top 3 suggestions when the current character in the stream is c
    // c == '#' means , the current query is complete and you may save the entire query into
    // historical data
  }
};
