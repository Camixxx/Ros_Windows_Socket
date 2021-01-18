// JHLRosTest.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//#include "stdafx.h"

#include <string>
#include <stdio.h>
#include "ros.h"
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/Pose.h>
#include <turtlesim/Pose.h>
#include <std_msgs/String.h>
#include <windows.h>
#include <iostream>
using std::string;


int sendMsgTest(ros::NodeHandle nh)
{
    printf("/cmd_vel.\n");
    geometry_msgs::Twist twist_msg;
    ros::Publisher cmd_vel_pub("/turtle1/cmd_vel", &twist_msg);
    nh.advertise(cmd_vel_pub);

    printf("Send message to robot.\n");
    while (1)
    {
        twist_msg.linear.x = 0.4;
        twist_msg.linear.y = 0;
        twist_msg.linear.z = 0;
        twist_msg.angular.x = 0;
        twist_msg.angular.y = 0;
        twist_msg.angular.z = 0.2;
        cmd_vel_pub.publish(&twist_msg);

        nh.spinOnce();
        Sleep(100);
    }
    return 0;
}

void receiveMsgCallback(const turtlesim::Pose& pose) {
    printf("Received value Pose:");
    printf("  {%f, %f, %f }\n",
        pose.x, pose.y, pose.theta);
}

int receiveMsgTest(ros::NodeHandle nh)
{
    printf("pose.\n");
    ros::Subscriber < turtlesim::Pose >
        poseSub("/turtle1/pose",  &receiveMsgCallback);
    nh.subscribe(poseSub);
    while (1) {
        nh.spinOnce();
        Sleep(100);
    }
    printf("Received message\n");

    return 0;
}

int main(int argc, CHAR* argv[])
{
    ros::NodeHandle nh;
    //char* ros_master = (char*)"10.13.0.166";
    char* ros_master = (char*)"127.0.0.1";
  
    printf("Connecting to server at %s\n", ros_master);
    nh.initNode(ros_master);

    // Receive Message Test
    receiveMsgTest(nh);

    // Send Message Test
    //sendMsgTest(nh);

   
    printf("All done!\n");
    return 0;
}
