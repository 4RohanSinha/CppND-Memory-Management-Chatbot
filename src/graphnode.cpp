#include "graphedge.h"
#include "graphnode.h"

GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    ////

//the segmentation fault in the warmup task was caused by the initial delete chatBot_ in this destructor
    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

//TASK 4
void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge) {
    _childEdges.emplace_back(std::move(edge)); //move edge to _childEdges
}
//// STUDENT CODE
////
//TASK 5 - use ordinary instance of ChatBot to move
void GraphNode::MoveChatbotHere(ChatBot chatbot)
{
    _chatBot = std::move(chatbot);
    _chatBot.SetCurrentNode(this); //use dot operator because _chatBot is a stack-allocated variable
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode) 
{
	//TASK 5 - pass _chatBot to GraphNode::MoveChatBotHere(ChatBot chatbot) with move semantics
    newNode->MoveChatbotHere(std::move(_chatBot));
//_chatBot is a stack-allocated variable, nullptr cannot be assigned to it
//_chatBot already moved, so no need to invalidate it
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    //TASK 4 - return raw pointer to avoid transferring ownership to caller of this method
    return _childEdges[index].get();


    ////
    //// EOF STUDENT CODE
}
