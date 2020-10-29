#include "ros/ros.h"
#include "std_msgs/String.h"
#include <sstream>

int main(int argc, char** argv)
{
    ros::init(argc, argv, "talker");
    ros::NodeHandle talker_node;
    ros::Publisher chatter_publisher = talker_node.advertise<std_msgs::String>("chatter", 1000);
    ros::Rate loop_rate(10);

    for (int counter = 0; ros::ok(); ++counter)
    {
        std_msgs::String message;
        std::stringstream ss;
        
        ss << "Talker says hi # " << counter;
        message.data = ss.str();
        
        ROS_INFO("%s", message.data.c_str());

        chatter_publisher.publish(message);
        
        ros::spinOnce();
        loop_rate.sleep();
    }

    return 0;
}
