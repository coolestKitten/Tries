#pragma once
#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Nodo{
    public:
        Nodo(char);

        char getLetter();
        bool getComplete();

        void setLetter(char);
        void setComplete(bool);

        Nodo* fetchEdge(char);
        bool findEdge(char);
        
        void addEdge(char);
        void shNode();


    private:
        char letter;
        bool isComplete;
        vector<Nodo*> children;
};

Nodo::Nodo(char _letter){
    letter = _letter;
    isComplete = false;
}

char Nodo::getLetter(){
    return letter;
}
bool Nodo::getComplete(){
    return isComplete;
}

void Nodo::setLetter(char _letter){
    letter = _letter;
}
void Nodo::setComplete(bool complete){
    isComplete = complete;
}

Nodo* Nodo::fetchEdge(char dat){
    Nodo *target = new Nodo(dat);
    for (int i = 0; i < children.size(); i++){
        if (target->getLetter() == children[i]->getLetter()){
            return target;
        }
    }
    return NULL;
}

bool Nodo::findEdge(char targChild){
    Nodo *target = new Nodo(targChild);
    for (int i = 0; i < children.size(); i++){
        if (target->getLetter() == children[i]->getLetter()){
            return true;
        }
    }
    return false;
}
        
void Nodo::addEdge(char newChild){
    Nodo *addChild = new Nodo(newChild);
    

    children.push_back(addChild);
    //cout << addChild->getLetter() << endl;
    
}

void Nodo::shNode(){
    cout << letter << endl;
    cout << "children: ";

    for (int i = 0; i < children.size(); i++){
        cout << children[i]->getLetter() << " ";
    }
    cout << endl;
}
