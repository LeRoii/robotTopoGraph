#include <iostream>
#include "robottopograph.h"

robotTopoGraph::robotTopoGraph(pugi::xml_document &xmlDoc)
{
    pugi::xml_node nodes = xmlDoc.child("topological_map").child("nodes");
    pugi::xml_node edges = xmlDoc.child("topological_map").child("edges");

    for (pugi::xml_node node = nodes.first_child(); node; node = node.next_sibling())
    {
        std::cout << "node:";
        std::shared_ptr<robotTopoNode> pNode (new robotTopoNode(node));
        std::cout << "node id:" << pNode->Id() << std::endl;
        m_nodes.push_back(pNode);
    }

    for (pugi::xml_node edge = edges.first_child(); edge; edge = edge.next_sibling())
    {
        std::cout << "edge:";
        std::shared_ptr<robotTopoEdge> pEdge (new robotTopoEdge(edge, m_nodes));
        m_edges.push_back(pEdge);
    }
}

robotTopoGraph::~robotTopoGraph()
{

}

const std::shared_ptr<robotTopoNode> robotTopoGraph::getNode(const std::string nodeId) const
{
    for(auto &node:m_nodes)
    {
        if(node->Id() == nodeId)
            return node;
    }

    return nullptr;
}

const std::shared_ptr<robotTopoEdge> robotTopoGraph::getEdge(const std::string edgeId) const
{
    for(auto &edge:m_edges)
    {
        if(edge->Id() == edgeId)
            return edge;
    }

    return nullptr;
}
