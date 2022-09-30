#pragma once
#include <string>
#include "Nodo.h"

class Trie{
    private:
        Nodo* HEAD;
    public:
        Trie();

        void addWord(string);

        //void shList();

        //void searchWord(string);
        
};

Trie::Trie(){
    HEAD = new Nodo('*');
}

void Trie::addWord(string word){
    Nodo* curr = HEAD;
    cout << "word is: " << word << endl;

    for(int i = 0; i< word.length(); i++){ // for every element in the input word
            cout << "Miki: " << "word[i] is " << word[i] << endl;
            cout << "PreMaik: " << "Curr is "; 
            curr->shNode();
        if(curr->findEdge(word[i])){ //if the input's current character is among the node's children
            cout << "Miki: ";
            curr = curr->fetchEdge(word[i]); //go to it, 
            cout << "Node " << word[i] << " already in list" << endl;
        } else { //if it's not there yet
            cout << "Miki: ";
            curr->addEdge(word[i]); // add it to the list
            cout << "Node " << word[i] << " added to list" << endl;
            cout << "PostMaik: " << "Curr is "; 
            curr->shNode();
            cout << endl;
            curr = curr->fetchEdge(word[i]); // go to the newly made node            
        }

    }
    cout << endl;
    cout << endl;
}

////void Trie::shList(){

//}