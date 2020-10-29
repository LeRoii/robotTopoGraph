#ifndef _ROBOTTOPOGRAPH_H_
#define _ROBOTTOPOGRAPH_H_

#include <vector>


#include "robottoponode.h"

class robotTopoGraph
{
    public:
    robotTopoGraph(pugi::xml_document &xmlDoc);
    ~robotTopoGraph();

    const std::shared_ptr<robotTopoNode> getNode(const std::string nodeId) const;
    const std::shared_ptr<robotTopoEdge> getEdge(const std::string edgeId) const;

    const std::vector<std::shared_ptr<robotTopoNode>>& getNodes() const {return m_nodes;}
    const std::vector<std::shared_ptr<robotTopoEdge>>& getEdges() const {return m_edges;}

    private:
    std::vector<std::shared_ptr<robotTopoNode>> m_nodes;
    std::vector<std::shared_ptr<robotTopoEdge>> m_edges;
    
};

#endif