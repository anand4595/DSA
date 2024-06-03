// https://www.geeksforgeeks.org/problems/trie-delete/1
#define ALPHABET_SIZE 26

struct trie_node
{
  int value; // non zero if leaf
  trie_node *children[ALPHABET_SIZE];
};

class Solution
{
public:
  void deleteKey(trie_node *root, char key[])
  {
    // Code here
  }
};