#ifndef GRAPHNODE_H_
#define GRAPHNODE_H_

#include <memory>
#include <vector>
#include <string>
#include "chatbot.h"


// forward declarations
class GraphEdge;

class GraphNode
{
private:
    //// STUDENT CODE
    ////

    // data handles (owned)
    // TASK 4
    // each GraphNode exclusively owns the child edge
    // exclusive ownership requires unique pointer
    std::vector<std::unique_ptr<GraphEdge>> _childEdges;

    // data handles (not owned)
    // non-owning reference, so it should be a regular raw pointer, as opposed to the _childEdges vector
    std::vector<GraphEdge *> _parentEdges; // edges to preceding nodes 

    //TASK 5 - use stack-allocated variable for ChatBot
    ChatBot _chatBot;

    ////
    //// EOF STUDENT CODE

    // proprietary members
    int _id;
    std::vector<std::string> _answers;

public:
    // constructor / destructor
    GraphNode(int id);
    ~GraphNode();

    // getter / setter
    int GetID() { return _id; }
    int GetNumberOfChildEdges() { return _childEdges.size(); }
    GraphEdge *GetChildEdgeAtIndex(int index);
    std::vector<std::string> GetAnswers() { return _answers; }
    int GetNumberOfParents() { return _parentEdges.size(); }

    // proprietary functions
    void AddToken(std::string token); // add answers to list
    void AddEdgeToParentNode(GraphEdge *edge);

    //TASK 4
    //add edge to _childNodes vector
    //must be a unique_ptr
    //will require moving the unique ptr to the vector
    void AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge);

    //// STUDENT CODE
    ////

    //TASK 5 - use ordinary instance of ChatBot
    void MoveChatbotHere(ChatBot chatbot);

    ////
    //// EOF STUDENT CODE

    void MoveChatbotToNewNode(GraphNode *newNode);
};

#endif /* GRAPHNODE_H_ */
