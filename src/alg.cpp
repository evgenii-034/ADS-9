// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"
#include <string>

using namespace std;

BST<std::string> makeTree(const char* filename) {
  // поместите сюда свой код
ifstream file(filename);
BST<string> tree;
string word = "";
int count = 0;
// читаем содержимое файла посимвольно
while (!file.eof()) {
char ch = file.get();
if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
if (ch >= 'A' && ch <= 'Z') ch += 32;
word += ch;
count++;
} else if (count > 0) { tree.add(word); word = "";  count = 0;}
}
file.close();
return tree;
}
