#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

void printLog(const std_msgs::String::ConstPtr& message)
{
    ROS_INFO("Listener heard: %s", message->data.c_str());
}

int main(int argc, char** argv)
{
    ros::init(argc, argv, "listener");
    ros::NodeHandle listener_node;
    ros::Subscriber chatter_subsriber = listener_node.subscribe("chatter", 1000, printLog);
    ros::spin();

    return 0;
}
