#ifndef _ROBOTTOPONODE_H_
#define _ROBOTTOPONODE_H_

#include <string>
#include <vector>
#include <memory>
#include "pugixml.hpp"

struct robotTopoElementProperty
{
    std::string name;
    float value;
    std::string propertyTypename;
    std::string description;
};

struct robotTopoNodeLocation
{
    float x;
    float y;
    float z;
};

class robotTopoNode
{
    public:
    robotTopoNode(const pugi::xml_node xmlNode);
    ~robotTopoNode();

    const std::string Id() const {return m_id;};
    const int propertyNum() const {return m_propertyNum;};
    const robotTopoNodeLocation location() const {return m_location;};
    const std::vector<robotTopoElementProperty>& properties() const {return m_properties;};

    private:
    std::string m_id;
    int m_propertyNum;
    robotTopoNodeLocation m_location;
    std::vector<robotTopoElementProperty> m_properties;
};

class robotTopoEdge
{
    public:
    robotTopoEdge(const pugi::xml_node xmlNode, const std::vector<std::shared_ptr<robotTopoNode>>& vecNodes);
    ~robotTopoEdge();

    const std::string Id() const {return m_id;};
    const int edgeLevel() const {return m_edgeLevel;};
    const robotTopoNode* node1() const {return m_pNode1;};
    const robotTopoNode* node2() const {return m_pNode2;};

    private:
    std::string m_id;
    int m_edgeLevel;
    std::string m_node1Id;
    std::string m_node2Id;
    robotTopoNode* m_pNode1;
    robotTopoNode* m_pNode2;
};

#endif