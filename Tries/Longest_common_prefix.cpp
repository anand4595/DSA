// https://leetcode.com/problems/longest-common-prefix/description/
/*

    PENDING

*/
#include <bits/stdc++.h>
using namespace std;

const string dash = "---------------------------------";

class Logger
{
public:
  static const bool isDebuging = false;
  static void debug(string s)
  {
    if (isDebuging)
    {
      cout << s << endl;
      cout.flush();
    }
  }

  static void debug(vector<string> strLs)
  {
    if (isDebuging)
    {
      for (string s : strLs)
      {
        cout << s << " ";
      }
      cout << endl;
      cout.flush();
    }
  }
};

struct TrieNode
{
  static const int ALPHABET_SIZE = 26;
  bool isWordEnd;
  TrieNode *childNode[TrieNode::ALPHABET_SIZE];
  TrieNode()
  {
    for (int i = 0; i < TrieNode::ALPHABET_SIZE; i++)
    {
      this->childNode[i] = NULL;
    }
    this->isWordEnd = false;
  }
};

class Trie
{
public:
  TrieNode *root = new TrieNode();

  void insert(string str)
  {
    TrieNode *currentNode = this->root;
    for (char ch : str)
    {
      Logger::debug("insert - " + string(1, ch));
      if (currentNode->childNode[ch - 'a'] == NULL)
      {
        Logger::debug("insert - " + string(1, ch) + " new node inserted");
        currentNode->childNode[ch - 'a'] = new TrieNode();
      }
      currentNode = currentNode->childNode[ch - 'a'];
    }
    Logger::debug("insert - " + string(1, str[str.size() - 1]) + " marked as end");
    currentNode->isWordEnd = true;
  }

  void insert(vector<string> stringLs)
  {
    for (string s : stringLs)
    {
      Logger::debug(dash);
      Logger::debug("insert - " + s + " inserted");
      insert(s);
    }
  }

  vector<pair<int, TrieNode *>> getNonNullElements(TrieNode *node)
  {
    vector<pair<int, TrieNode *>> ls;
    for (int i = 0; i < TrieNode::ALPHABET_SIZE; i++)
    {
      if (node->childNode[i])
      {
        Logger::debug("getNonNullElements - found non element " + string(1, char('a' + i)));
        ls.push_back({i, node->childNode[i]});
      }
    }
    return ls;
  }

  string getLongestCommonPrefix(TrieNode *node, string &prefix)
  {
    vector<pair<int, TrieNode *>> nonNullElements = getNonNullElements(node);
    if (nonNullElements.size() == 1)
    {
      prefix.push_back(char('a' + nonNullElements[0].first));
      if (!nonNullElements[0].second->isWordEnd)
      {
        getLongestCommonPrefix(nonNullElements[0].second, prefix);
      }
      else
      {
        return prefix;
      }
    }
    return prefix;
  }

  string getLongestCommonPrefix()
  {
    string prefix = "";
    getLongestCommonPrefix(this->root, prefix);
    Logger::debug("getLongestCommonPrefix - found longest preifx " + prefix);
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
    return t.getLongestCommonPrefix();
  }
};

// int main()
// {
//   Solution solution;
//   vector<string> strLs = {"anand", "anan", "a"};
//   solution.longestCommonPrefix(strLs);
// }