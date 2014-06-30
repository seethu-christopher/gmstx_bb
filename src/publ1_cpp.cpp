#include "ros/ros.h"
#include "std_msgs/String.h"
#include <gmstx_bb/Num1.h>
#include <sstream>

int main(int argc,char **argv)
{
  ros::init(argc,argv,"pub1_cpp");
  ros::NodeHandle nh;
  ros::Publisher cpp_pub = nh.advertise<gmstx_bb::Num1>("cpp1_msg",1000);
  //ros::Publisher cpp_pub = nh.advertise<std_msgs::String>("cpp1_msg", 1000);
  ros::Rate loop_rate(10);
  int cnt = 0;
  while(ros::ok())
  {
     std_msgs::String msg1;
     gmstx_bb::Num1 msg2;
	 std::stringstream strm;
     strm << "Hello" << ++cnt;
     msg1.data = strm.str();
     msg2.num = cnt;
     //cpp_pub.publish(msg1);
	 cpp_pub.publish(msg2);
     //ROS_INFO("%s",msg1.data.c_str());
	 ROS_INFO("%d",msg2.num);
	 //ros::spinOnce();
     loop_rate.sleep();
	 
  }

  return 0;
}
