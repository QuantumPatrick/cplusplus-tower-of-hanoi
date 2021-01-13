//
//  graph_class.cpp
//  graph_class
//
//  Created by Patrick Procter on 12/15/20.
//

#ifndef graph_h
#define graph_h

#include <iostream>
#include <vector>



class graph {
public:
    std::vector<int> adjacencyList; // holds values for adjacent vertices, necessary for all graph search problems
    
};

template<class T>
class vertex : public graph { // derived class with Towers of Hanoi metadata
public:
    
    // metadata elements
    int numID, done; // numeric vertex ID for use in adjacency list, signifier for when program reaches a solution state
    T configuration; // arbitrary data type for disc configuration; could be a string, int, etc. 

    vertex(); // default constructor
    
    vertex(int,T,std::vector<int>); // contructor with metadata
    
};

template<class T>
vertex<T>::vertex() { // specialized default constructor for head node of Towers of Hanoi (3 discs)
    numID = 0;
    configuration = "aaa"; // initial state, with all discs on peg 'a'
    graph::adjacencyList = {1 , 2}; // node IDs for connected nodes
    done = 0; // this is not an end state
    
}

template<class T>
vertex<T>::vertex(int ID, T conf, std::vector<int> list) {
    numID = ID; 
    conf = configuration;
    list = graph::adjacencyList;
    done = 0;
}

#endif
