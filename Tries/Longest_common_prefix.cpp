// https://leetcode.com/problems/longest-common-prefix/description/

#include <bits/stdc++.h>
using namespace std;

const unsigned int ALPHABET_SIZE = 26;
const char CHILD_NODE_START = 'a';

class TrieNode
{
public:
  vector<TrieNode *> childNode;
  bool wordEnd;

  TrieNode()
  {
    this->childNode = vector<TrieNode *>(ALPHABET_SIZE, NULL);
    this->wordEnd = false;
  }

  vector<pair<int, TrieNode *>> getNonNullChildNode()
  {
    vector<pair<int, TrieNode *>> ls;
    for (int i = 0; i < childNode.size(); i++)
    {
      if (childNode[i])
      {
        ls.push_back({i, childNode[i]});
      }
    }
    return ls;
  }
};

class Trie
{
private:
  TrieNode *root;

public:
  Trie()
  {
    this->root = new TrieNode();
  }

  void insert(string str)
  {
    TrieNode *currentNode = this->root;
    for (char ch : str)
    {
      TrieNode *childNode = currentNode->childNode[ch - CHILD_NODE_START] ? currentNode->childNode[ch - CHILD_NODE_START] : new TrieNode();
      currentNode->childNode[ch - CHILD_NODE_START] = childNode;
      currentNode = childNode;
    }
    currentNode->wordEnd = true;
  }

  void insert(vector<string> &strs)
  {
    for (string str : strs)
    {
      insert(str);
    }
  }

  void longestCommonPrefix(TrieNode *trieNode, string &prefix)
  {
    // if a word end then prefix ends there
    if (trieNode->wordEnd)
    {
      return;
    }
    auto nonNullChildNode = trieNode->getNonNullChildNode();
    // only single node must be condidered
    // Zero or Greater than one means no node and more than one path respectively
    if (nonNullChildNode.size() == 1)
    {
      prefix.append(string(1, char(CHILD_NODE_START + nonNullChildNode[0].first)));
      longestCommonPrefix(nonNullChildNode[0].second, prefix);
    }
  }

  string longestCommonPrefix()
  {
    string prefix = "";
    longestCommonPrefix(this->root, prefix);
    return prefix;
  }
};

class Solution
{
public:
  string longestCommonPrefix(vector<string> &strs)
  {
    Trie t;
    t.insert(strs);
    return t.longestCommonPrefix();
  }
};