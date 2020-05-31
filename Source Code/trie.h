#ifndef TRIE_H
#define TRIE_H
#include "trie_node.h"
#include <QString>
#include <QPair>

class trie
{
private:
  trie_node *root;
  trie_node *current;
  QString current_word;
public:
  trie();
  ~trie();
  void add_word(QString input);
  QPair <bool , QVector<unsigned int >> check_word(QString input);
  bool check_index(QString word , unsigned int file_id );
  void add_index(QString word , unsigned int file_id );

};

#endif // TRIE_H
