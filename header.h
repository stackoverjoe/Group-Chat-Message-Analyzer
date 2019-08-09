#ifndef __HEADER__
#define __HEADER__

#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include <string>
using namespace std;

struct node{
    node();
    node(string& string);
    node(const node&);
    string word;
    void display();
    int tally;
    int s;
    node *left;
    node *right;
};

class friends{
    public:
        //friends1
        friends(string);
        string name;
        int parse(string);
        int totalwords;
        void display();
        void displayWords();
        void displayWords(node*root);
        int insert(node*&);
        int insert(node *&, node*&, string);
        node* orderIt();
        node* orderIt(node*, node*&, int&);
        int build();
        int size;
        int write();
        int write(node*root, ofstream&);
        int search(string);
        node * search(node*root, string);
    private:
        node *root;
        node *orderRoot;
};





#endif
