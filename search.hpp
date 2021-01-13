//
//  search.hpp
//  graph_class
//
//  Created by Patrick Procter on 12/16/20.
//

#ifndef search_h
#define search_h

//#include "graph_class.cpp"

#include <list>
#include <string>
#include <iostream>

namespace search {
    std::vector<int> runningList; // running vector list of nodes left to check
    std::vector<int> newList; // placeholder list for transferring data to next iteration of loop
    std::vector<int> checkedNodes; // vector list of nodes already checked to avoid repeats (my graph is funky)
    bool repeatNode; // boolean to check if a node has already been visited FIXME: (time permitting) change vertex class to have this as metadata
    
    template<class T>
    void searchDepth(vertex<std::string> start, std::vector<vertex<std::string>> all) {
        int i = start.numID;
        runningList.clear();
        runningList.insert(runningList.end(), start.adjacencyList.begin(), start.adjacencyList.end()); // initializes runningList to start node's adjacency list
        
        while (all.at(i).done != 1) {
            repeatNode = false; // assumes no nodes were repeated
            i = runningList.at(0); // i is the first ID in the adjacency list
            
            
            for (int j = 0; j < checkedNodes.size(); j++) { // for loop checks if a nodeID has been checked already
                if (checkedNodes.at(j) == runningList.at(0)) {
                    repeatNode = true;
                }
                
            }
            checkedNodes.push_back(runningList.at(0)); // adds the most recent node to the checkedNodes vector
            
            if (repeatNode == false) { // if the node isn't a repeat, check the node for a solution
                newList.clear();
                newList.insert(newList.begin(), all.at(i).adjacencyList.begin(), all.at(i).adjacencyList.end());
                
                newList.insert(newList.end(), runningList.begin() + 1, runningList.end()); // stops the checked node from being replaced on the list
                
                // sets running list for new items
                runningList.clear(); // clears the running list to prevent unnecessary repetition
                runningList.insert(runningList.end(), newList.begin(), newList.end()); // converts runningList to the newList (with the prepended values from the current node)
                std::cout << "Checking node n" << all.at(i).numID << ". Disc Config: " << all.at(i).configuration << std::endl; // outputs node name and its disc configuration to the console
            }
            else { // drops the node that was already checked from the list and moves on
                newList.clear();
                
                newList.insert(newList.end(), runningList.begin() + 1, runningList.end());
                
                // sets running list for new items
                runningList.clear();
                runningList.insert(runningList.end(), newList.begin(), newList.end());
            }
            
        }
        checkedNodes.clear(); // clears the checkedNodes list so another search can be performed
        std::cout << "Solution found!" << std::endl << std::endl;
    }
    
    template<class T>
    void searchBreadth(vertex<std::string> start, std::vector<vertex<std::string>> all) {
        int i = start.numID;
        runningList.clear();
        runningList.insert(runningList.end(), start.adjacencyList.begin(), start.adjacencyList.end());
        
        while (all.at(i).done != 1) {
            repeatNode = false;
            i = runningList.at(0);
            
            for (int j = 0; j < checkedNodes.size(); j++) {
                if (checkedNodes.at(j) == runningList.at(0)) {
                    repeatNode = true;
                }
                
            }
            checkedNodes.push_back(runningList.at(0));
            
            if (repeatNode == false) {
                newList.clear();
                newList.insert(newList.begin(), all.at(i).adjacencyList.begin(), all.at(i).adjacencyList.end());
                
                newList.insert(newList.begin(), runningList.begin() + 1, runningList.end());
                
                // sets running list for new items
                runningList.clear();
                runningList.insert(runningList.begin(), newList.begin(), newList.end()); // converts runningList to the newList (with the appended values from the current node)
                std::cout << "Checking node n" << all.at(i).numID << ". Disc Config: " << all.at(i).configuration << std::endl;
            }
            else {
                newList.clear();
                
                newList.insert(newList.end(), runningList.begin() + 1, runningList.end());
                
                // sets running list for new items
                runningList.clear();
                runningList.insert(runningList.begin(), newList.begin(), newList.end());
            }
            
        }
        checkedNodes.clear();
        std::cout << "Solution found!" << std::endl << std::endl;
    }
    
}




#endif /* search_h */
