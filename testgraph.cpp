#include <opencv2/opencv.hpp>
#include "robottopograph.h"

int main()
{
    pugi::xml_document doc;
    if (!doc.load_file("../map.xml")) 
    {
        printf("open xml failed\n");
        return -1;
    }

    auto graph = robotTopoGraph(doc);

    cv::Mat map(600, 600, CV_8UC3, cv::Scalar(255,255,255));
    for(auto &node:graph.getNodes())
    {
        cv::circle(map, cv::Point(node->location().x + 300,node->location().y + 300), 2, CV_RGB(0,0,0), -1);
    }

    for(auto &edge:graph.getEdges())
    {
        cv::Point node1(edge->node1()->location().x +300, edge->node1()->location().y +300);
        cv::Point node2(edge->node2()->location().x +300, edge->node2()->location().y +300);
        cv::line(map, node1, node2, CV_RGB(0,255,0), 1);
    }



    cv::imwrite("../map.png", map);

    doc.save_file("../save_file_output.xml");
    return 0;
}