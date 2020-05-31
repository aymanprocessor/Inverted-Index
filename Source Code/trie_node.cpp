#include "trie_node.h"

trie_node::trie_node()
{
  value = '\0';
  for(int i =0 ; i <NUM_chars ; i++)
    {
      children[i] = nullptr;
    }
}
trie_node::trie_node(char in_val)
{
  value = in_val;
  for(int i =0 ; i <NUM_chars ; i++)
    {
      children[i] = nullptr;
    }
}
trie_node::~trie_node()
{
  for(int i =0 ; i <NUM_chars ; i++)
    {
      delete children[i] ;
    }
}
//children[] = "a b c d e f g h.... x y z 0 1 2 3 4 5 6 7 8 9
QPair <bool , unsigned int> trie_node::check_child(char &input)
{
  unsigned int index=npos;
  bool result = false;
  if(input >='A' && input <='Z')
    {
      index=input-'A';
      (children[index] != nullptr)?result=true:result=false;
    }
  else if (input >='a' && input <='z')
    {
      index=input-'a';
      (children[index] != nullptr)?result=true:result=false;
      input=input-'a'+'A';
    }
  else if (input >='0' && input <='9')
  {
    index=input-'0'+26;
    (children[index] != nullptr)?result=true:result=false;
  }
  QPair <bool , unsigned int> res(result , index);
  return res;
}
unsigned int trie_node:: add_child(char input)
{
  QPair <bool , unsigned int> ind=check_child(input);
  if (ind.first == false)
    {
      children[ind.second]= new trie_node(input);
    }
  return ind.second;
}
unsigned int trie_node::check_index(unsigned int input)
{
  return indeces.indexOf(input);
}
void trie_node::add_index(unsigned int input)
{
  unsigned int index = indeces.indexOf(input);
  if(index == npos)indeces.push_back(input);
}
QVector <unsigned int> trie_node:: get_indeces()
{
  return indeces;
}

trie_node* trie_node:: get_child(unsigned int index)
{
  return children[index];
}
char trie_node::get_value()
{
  return value;
}
