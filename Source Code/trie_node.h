#ifndef TRIE_NODE_H
#define TRIE_NODE_H
#include <QVector>
#include <QPair>

#define NUM_chars 36
#define npos ~0U

class trie_node
{
private:
  char value;
  trie_node *children[NUM_chars];
  QVector <unsigned int>indeces;
public:
  trie_node();
  trie_node(char in_value);
  ~trie_node();
  char get_value();
  QPair <bool , unsigned int> check_child(char &input);
  unsigned int add_child(char input);
  void add_index(unsigned int input);
  unsigned int check_index(unsigned int input);
  QVector <unsigned int> get_indeces();
  trie_node * get_child(unsigned int index);
};

#endif // TRIE_NODE_H
