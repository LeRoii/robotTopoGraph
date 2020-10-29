#include "robottoponode.h"

robotTopoNode::robotTopoNode(const pugi::xml_node xmlNode)
{
    m_id = xmlNode.attribute("id").value();
    m_propertyNum = xmlNode.attribute("property_num").as_int();

    pugi::xml_node location = xmlNode.child("location");
    m_location.x = location.attribute("x").as_float();
    m_location.y = location.attribute("y").as_float();
    m_location.z = location.attribute("z").as_float();

    pugi::xml_node properties = xmlNode.child("properties");
    for(pugi::xml_node property = properties.first_child(); property; property = property.next_sibling())
    {
        robotTopoElementProperty nodeProperty;
        nodeProperty.name = property.child_value("name");
        nodeProperty.value = property.child("value").text().as_float();
        nodeProperty.propertyTypename = property.child_value("typename");
        nodeProperty.description = property.child_value("description");
        m_properties.push_back(nodeProperty);
    }
}

robotTopoNode::~robotTopoNode()
{

}

// const std::string robotTopoNode::Id() const
// {
//     return m_id;
// }

// inline const int robotTopoNode::propertyNum() const
// {
//     return m_propertyNum;
// }

// inline const robotTopoNodeLocation robotTopoNode::location() const
// {
//     return m_location;
// }

// inline const std::vector<robotTopoElementProperty>& robotTopoNode::properties() const
// {
//     return m_properties;
// }

robotTopoEdge::robotTopoEdge(const pugi::xml_node xmlNode, const std::vector<std::shared_ptr<robotTopoNode>>& vecNodes)
{
    m_id = xmlNode.attribute("id").value();
    m_edgeLevel = xmlNode.attribute("edge_level").as_int();
    m_node1Id = xmlNode.attribute("edge_node1").value();
    m_node2Id = xmlNode.attribute("edge_node2").value();

    for(auto &pNode:vecNodes)
    {
        if(pNode->Id() == m_node1Id)
        {
            m_pNode1 = pNode.get();
        }

        if(pNode->Id() == m_node2Id)
        {
            m_pNode2 = pNode.get();
        }
    }

}

robotTopoEdge::~robotTopoEdge()
{

}

// inline const std::string robotTopoEdge::Id() const
// {
//     return m_id;
// }

// inline const int robotTopoEdge::edgeLevel() const
// {
//     return m_edgeLevel;
// }

// inline const robotTopoNode* robotTopoEdge::node1() const
// {
//     return m_pNode1;
// }

// inline const robotTopoNode* robotTopoEdge::node2() const
// {
//     return m_pNode2;
// }