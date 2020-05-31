#include "trie.h"

trie::trie()
{
  root = new trie_node('\0');
  current = root;
  current_word="";
}
trie::~trie()
{
  delete root;
}
QPair <bool , QVector<unsigned int >>trie::check_word(QString input)//L number of characters
{                                                                   //O(L)
  QPair <bool , QVector<unsigned int >> result;
  result.first=true;
  current = root;
  current_word="";
  QPair <bool , unsigned int > next_index(false,0);
  for(int i=0 ; i<=input.length()-1;i++)
    {
      next_index=current->check_child(input.toStdString()[i]);
      if(next_index.first == false)
        {
          result.first=false;
          next_index.second=i;
          i=input.length();
        }
      else
        {
          current=current->get_child(next_index.second);
          current_word+=current->get_value();
        }
    }
  if(result.first)result.second=current->get_indeces();
  else result.second.push_front(next_index.second);
  return result;
}
void trie::add_word(QString input)//O(L)
{
  QPair <bool , QVector<unsigned int >> check_res = check_word(input);//O(L)
  unsigned int next_index=0;
  if(!check_res.first)
    {
      for(int i = check_res.second[0] ; i < input.length() ; i++)
        {
          next_index=current->add_child(input.toStdString()[i]);
          current = current->get_child(next_index);
          current_word+=current->get_value();
        }
    }
}

//search : naive: O(D*W*L)     bianry tree:O(L*logW)     trie:O(L)
//Building: O(D*W*L)
//search : O(L)
//access : O(L)



bool trie::check_index(QString word , unsigned int file_id )
{
  QPair <bool , QVector<unsigned int >> check_res = check_word(word);
  bool result =false;
  unsigned int file_index=0;
  if(!check_res.first)
    {
      result = false;
    }
  else
    {
      file_index = current->check_index(file_id);
      (file_index==npos)?result=false:result=true;
    }
  return result;
}
void trie::add_index(QString word , unsigned int file_id )
{
  bool check_res = check_index(word , file_id);
  if(!check_res)
    {
      if(current_word != word)
        {
          add_word(word);
        }
        current->add_index(file_id);
    }
}
