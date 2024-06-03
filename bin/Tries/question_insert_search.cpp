// https://leetcode.com/problems/implement-trie-prefix-tree/description/
#include <iostream>
using namespace std;

class TrieNode
{
public:
  static const int ALPHABET_SIZE = 'z' - 'a' + 1;
  TrieNode *childeNodes[TrieNode::ALPHABET_SIZE];
  bool isWordEnd;

  TrieNode()
  {
    for (int i = 0; i < ALPHABET_SIZE; i++)
    {
      this->childeNodes[i] = NULL;
    }
    this->isWordEnd = false;
  }

  TrieNode *getChildNode(char ch)
  {
    return this->childeNodes[ch - 'a'];
  }

  void setChildNode(char ch, TrieNode *newNode = NULL)
  {
    this->childeNodes[ch - 'a'] = newNode;
  }

  bool getWordEnd()
  {
    return this->isWordEnd;
  }

  void setWordEnd(bool wordEnd = true)
  {
    this->isWordEnd = wordEnd;
  }
};

class Trie
{
  TrieNode *root;

public:
  Trie()
  {
    this->root = new TrieNode();
  }

  void insert(string word)
  {
    TrieNode *currentNode = root;

    for (char ch : word)
    {
      currentNode->setChildNode(
          ch,
          currentNode->getChildNode(ch) == NULL ? new TrieNode() : currentNode->getChildNode(ch));
      currentNode = currentNode->getChildNode(ch);
    }
    currentNode->setWordEnd();
  }

  bool search(string word)
  {
    TrieNode *currentNode = this->root;
    for (char ch : word)
    {
      if (!currentNode->getChildNode(ch))
      {
        return false;
      }
      currentNode = currentNode->getChildNode(ch);
    }
    return currentNode->getWordEnd();
  }

  bool startsWith(string prefix)
  {
    TrieNode *currentNode = this->root;
    for (char ch : prefix)
    {
      if (!currentNode->getChildNode(ch))
      {
        return false;
      }
      currentNode = currentNode->getChildNode(ch);
    }
    return true;
  }
};