#include "header.h"
#include <locale>



node::node(){
    tally = 0;
    left = right = NULL;
    s = 0;
}


node::node(string& tword){
    //strcpy(word, tword);
    word = tword;
    left = right = nullptr;
    s = 0;
    tally = 1;
    //word(tword);
    //word = new string(tword);
}

node::node(const node& to_copy){
    word = to_copy.word;
    tally = to_copy.tally;//could break;
    left = right = nullptr;
    s = 0;

}


void node::display(){
    cout << " said \"" <<  word << "\" " << tally << " time(s).\n\n"  << "______________________" << endl;

}


friends::friends(string tname){
    name = tname;
    totalwords = 0;
    root = orderRoot = NULL;
    size = 0;
}


int friends::insert(node *& to_add){
    string temp;
    temp = to_add->word;
    locale loc;
    for(string::size_type  i = 0; i < temp.length(); ++i){
        temp[i] = tolower(temp[i], loc);
    }
    insert(root, to_add, temp);
    return 1;
}


int friends::search(string key){
    node *temp = nullptr;
    temp = search(root, key);
    if(temp){
        temp->display();
    }
    else{
        cout << " said \"" << key << "\" 0 times.\n\n" << "______________________" << endl << endl;
    }
    return 1;
}

node* friends::search(node *root, string key){
    locale loc1;
    string tempp;
    if(!root){
        return nullptr;
    }
    tempp = root->word;
    for(string::size_type i = 0; i < tempp.length(); ++i){
        tempp[i] = tolower(tempp[i], loc1);
    }
    if(!(tempp.compare(key))){
        return root;
        return 0;
    }
    else if(tempp.compare(key) > 0){
        return search(root->left, key);
    }
    else{
        return search(root->right, key);
    }
    

}

int friends::insert(node*&root, node *& to_add, string temp){
    locale loc1;
    string tempp;
    if(!root){
        root = new node(*to_add);
        delete to_add;
        to_add = nullptr;
        ++size;
        return 0;
    }
    tempp = root->word;
    for(string::size_type i = 0; i < tempp.length(); ++i){
        tempp[i] = tolower(tempp[i], loc1);
        //cout << "root: " << root->word << endl << "tempp: " << tempp << endl;
    }
    if(!(tempp.compare(temp))){
        ++(root->tally);
        delete to_add;
        to_add = NULL;
        return 0;
    }
    else if(tempp.compare(temp) > 0){
        return insert(root->left, to_add, temp);
    }
    else{
        return insert(root->right, to_add, temp);
    }
}


node* friends::orderIt(){
    node *tt = root;
    int i = 0;
    return orderIt(root, tt, i);
}


node* friends::orderIt(node*source, node*&watch, int&num){
    //int maybe = 0;
   if(num == (size-1)){
       return nullptr;
   }
   if(!source){
     return nullptr;
   }
   if(source->tally > watch->tally && source->s == 0){
       //cout << "source: " << source->tally << "watchh " << watch->tally << endl;
        watch = source;
   }
   orderIt(source->left, watch, num);
   orderIt(source->right, watch, num);
    if(watch == source && source->s == 0){
        source->s = 1;
        return watch;
   }
}


int friends::build(){
    int i = 0;
    //int x = 0;
    string tempp;
    node *temp = nullptr;
    node* watch = nullptr;
    //cout << this->size << endl;
    while(i < size-2){
        watch = root;
        temp = orderIt(root, watch, i);
        if(temp){
            temp->display();
        }
        else{
            return 0;
        }
        ++i;
        //watch = nullptr;
    }
    displayWords(orderRoot);
    return 0;
}


int friends::write(){
    ofstream out;
    out.open("wordsfordays.txt");
    write(root, out);
    out.close();
    return 0;
}


int friends::write(node*root, ofstream&out){
    if(!root){
        return 0;
    }
    write(root->left, out);
    out << root->word << '\n';
    write(root->right, out);
}


void friends::displayWords(){
    //build();
    //write();
    cout << name << "'s word usage: " << endl;
    displayWords(root);
}

void friends::displayWords(node* root){
    if(!root){
        return;
    }
    displayWords(root->left);
    if(root->tally > 5){
    root->display();
    }
    displayWords(root->right);
}


void friends::display(){
    cout << "Name: " << name << endl;

}
