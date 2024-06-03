#include <iostream>
using namespace std;

const char TRIE_NODE_START_CH = 'a';
const char TRIE_NODE_END_CH = 'z';
const int TRIE_NODE_SIZE = TRIE_NODE_END_CH - TRIE_NODE_START_CH + 1;

class TrieNode
{

private:
  bool isWordEnd;

  // array of pointers to child nodes
  TrieNode **childNodeArr;

public:
  TrieNode()
  {
    this->isWordEnd = false;
    this->childNodeArr = new TrieNode *[TRIE_NODE_SIZE];
    for (int i = 0; i < TRIE_NODE_SIZE; i++)
    {
      this->childNodeArr[i] = NULL;
    }
  }

  bool getWordEnd()
  {
    return this->isWordEnd;
  }

  void setWordEnd(bool isWordEnd)
  {
    this->isWordEnd = isWordEnd;
  }

  TrieNode *getChildNode(char ch)
  {
    return this->childNodeArr[ch - TRIE_NODE_START_CH];
  }

  void setChildNode(char ch, TrieNode *newNode)
  {
    this->childNodeArr[ch - TRIE_NODE_START_CH] = newNode;
  }

  void setNewChildNode(char ch)
  {
    this->childNodeArr[ch - TRIE_NODE_START_CH] = new TrieNode();
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

  void insert(string s)
  {
    TrieNode *currentTriNode = root;

    for (char ch : s)
    {
      if (currentTriNode->getChildNode(ch) == NULL)
      {
        currentTriNode->setNewChildNode(ch);
      }
      currentTriNode = currentTriNode->getChildNode(ch);
    }
    currentTriNode->setWordEnd(true);
  }

  bool search(string s)
  {
    TrieNode *currentTrieNode = root;

    for (char ch : s)
    {
      if (currentTrieNode->getChildNode(ch) == NULL)
      {
        return false;
      }
      currentTrieNode = currentTrieNode->getChildNode(ch);
    }
    return currentTrieNode->getWordEnd();
  }
};