#include "ros/ros.h"
#include "std_msgs/String.h"
#include <gmstx_bb/Num1.h>

//void cb(const gmstx_bb::Num1::ConstPtr& msg)
void cb(const std_msgs::String::ConstPtr& msg)
{
	ROS_INFO("Published str: [%s]",msg->data.c_str());
	//ROS_INFO("Published msg: [%d]",msg->num);
}

int main(int argc, char** argv)
{
	ros::init(argc,argv,"sub1_cpp");
	ros::NodeHandle nh;
	ros::Subscriber cpp_sub = nh.subscribe("cpp1_msg",1000,cb);
	ros::spin();
	return 0;
}
