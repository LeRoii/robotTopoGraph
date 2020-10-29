#include "pugixml.hpp"

#include <string.h>
#include <iostream>
#include <vector>

struct stRmapElementProperty
{
    std::string name;
    float value;
    std::string propertyTypename;
    std::string description;
};

struct stRmapNodeLocation
{
    float x;
    float y;
};

struct stRmapNode
{
    std::string id;
    int propertyNum;
    stRmapNodeLocation loc;
    std::vector<stRmapElementProperty> properties;
};

struct stRmapEdge
{
    std::string id;
    int propertyNum;
    std::string headNodeId;
    std::string taileNodeId;
    std::vector<stRmapElementProperty> properties;
};

struct stRmap
{
    std::vector<stRmapNode> nodes;
    std::vector<stRmapEdge> edges;
};

int main()
{
    stRmap rmap;
    std::cout << "node num:" << rmap.nodes.size() << ", edges num:" << rmap.edges.size() << std::endl; 
    pugi::xml_document doc;
    if (!doc.load_file("/space/code/pugixml-1.10/test/map.xml")) 
    {
        printf("open xml failed\n");
        return -1;
    }

    pugi::xml_node nodes = doc.child("topological_map").child("nodes");

    // tag::basic[]
    for (pugi::xml_node node = nodes.first_child(); node; node = node.next_sibling())
    {
        std::cout << "node:";

        stRmapNode rmapNode;
        rmapNode.id = node.attribute("id").value();
        rmapNode.propertyNum = node.attribute("property_num").as_int();
        pugi::xml_node location = node.child("location");
        rmapNode.loc.x = location.attribute("x").as_float();
        rmapNode.loc.y = location.attribute("y").as_float();

        pugi::xml_node properties = node.child("properties");

        for(pugi::xml_node property = properties.first_child(); property; property = property.next_sibling())
        {
            stRmapElementProperty nodeProperty;
            nodeProperty.name = property.attribute("name").value();
            nodeProperty.value = property.attribute("value").as_float();
            nodeProperty.propertyTypename = property.attribute("typename").value();
            nodeProperty.description = property.attribute("description").value();
            rmapNode.properties.push_back(nodeProperty);
        }

        rmap.nodes.push_back(rmapNode);





        for (pugi::xml_attribute attr = node.first_attribute(); attr; attr = attr.next_attribute())
        {
            std::cout << " " << attr.name() << "=" << attr.value();
        }
        // pugi::xml_node location = node.child("location");
        std::cout << ", x:" << location.attribute("x").as_float() << ", ";
        std::cout << "y:" << location.attribute("y").as_float() << std::endl;

        std::cout << std::endl;
    }
    // end::basic[]

    std::cout << std::endl;










    // // tag::data[]
    // for (pugi::xml_node tool = tools.child("Tool"); tool; tool = tool.next_sibling("Tool"))
    // {
    //     std::cout << "Tool " << tool.attribute("Filename").value();
    //     std::cout << ": AllowRemote " << tool.attribute("AllowRemote").as_bool();
    //     std::cout << ", Timeout " << tool.attribute("Timeout").as_int();
    //     std::cout << ", Description '" << tool.child_value("Description") << "\n";
    // }
    // // end::data[]

    // std::cout << std::endl;

    // // tag::contents[]
    // std::cout << "Tool for *.dae generation: " << tools.find_child_by_attribute("Tool", "OutputFileMasks", "*.dae").attribute("Filename").value() << "\n";

    // for (pugi::xml_node tool = tools.child("Tool"); tool; tool = tool.next_sibling("Tool"))
    // {
    //     std::cout << "Tool " << tool.attribute("Filename").value() << "\n";
    // }
    // // end::contents[]
}

// vim:et
