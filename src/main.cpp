// Simple Motion for Mobile Robot
#include "ros/ros.h"
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/Twist.h>
#include "sensor_msgs/Joy.h"

using namespace std;
void initialize_parameters(ros::NodeHandle n);
// declare message parameters
geometry_msgs::Twist tw_msg;
std::string cmd_topic;
double t = 0;
double how_long = 0;
double v = 0;

void joy_back(const sensor_msgs::Joy msg)
{
    if(msg.buttons[2]==1)
    {
        t = 0;
        v = 0.2;
    }
    else if(msg.buttons[0]==1)
    {
        t = 0;
        v = -0.2;
    }
}

void initialize_parameters(ros::NodeHandle n)
{
    n.getParam("how_long",   how_long);
}

int main(int argc, char **argv) {
 
    ros::init(argc, argv, "simple_motion");
    ros::NodeHandle n;

    initialize_parameters(n);
    // Define the publishers and sunscribers
    ros::Publisher      cmd_pub  = n.advertise<geometry_msgs::Twist> ("cmd_vel", 1);
    ros::Subscriber     jou_sub  = n.subscribe  ("/joy_teleop/joy", 5, joy_back);
    ros::Rate loop_rate(10); // ros spins 10 frames per second
 
    while (ros::ok()) {

        t = t + 0.1;
    if(t <= how_long)
    {
        tw_msg.linear.x = v;
    }
    else
    {
        tw_msg.linear.x = 0;
    }
    tw_msg.angular.z = 0;
  
    cmd_pub.publish(tw_msg);
   
    ros::spinOnce();
    loop_rate.sleep();
    }
    return 0;
}
