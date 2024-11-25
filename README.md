# 文件说明

<br>


## /ros_lib
---
该文件是一个的ros的代码生成包，可以在无ros环境的windows中直接使用，和ros进行socket通讯。

### 1. 将ros_lib内的非目录文件拷贝出来调用，
* ros.h
* duration.cpp
* timp.cpp
* WindowsSocke.h
* WindowsSocket.cpp

### 2. 添加附加包含目录

【项目】>【属性】 > 【C/C++】 > 【附加包含目录】：选择ros_lib文件夹

<br>

## RosTest
---
这是我用ros_lib写的通讯测试，调整一下应该就可以直接运行。

### 1. /ros_lib：

如前文所述

### 2. /launch：

turtlebot_node.launch，在ros环境中启动的文件，是边缘端的程序。可以在一个含任意版本ros1的虚拟机或者容器中，使用`roslaunch turtlebot_node.launch`来启动。如果该ros中缺少程序包，可以用以下方式安装：

```bash
sudo apt-get install ros-<ros版本>-turtlesim
sudo apt-get install ros-<ros版本>-rosserial-server
```
ros版本可能是kinetic（Ubuntu16），melodic（Ubuntu18），或者neotic（Ubuntu20）。

turtlesim是机器人仿真程序包，rosserial-server是支持socket通讯和串口通讯的服务。

rosserial的通讯有限制，因为原本要和单片机进行串口通讯，所以缓冲区不超过512字节。可以修改ros_lib包中的文件增大缓冲区容量。 ros_lib/ros/node_handle.h，代码部分如下：
```c++
/* Node Handle */
template<class Hardware,
         int MAX_SUBSCRIBERS = 25,
         int MAX_PUBLISHERS = 25,
         int INPUT_SIZE = 512,
         int OUTPUT_SIZE = 512>
```
如果我们要传输图片，后期肯定要修改容量。

### 3. RosTest.cpp
示例文件：

#### 连接到远程边缘端的ROS节点。
```c++
#include "ros.h"
ros::NodeHandle nh;
char* ros_master = (char*)"10.13.0.166";
printf("Connecting to server at %s\n", ros_master);
nh.initNode(ros_master);
```

#### 数据类型定义：
```c++
#include <geometry_msgs/Twist.h>
#include <geometry_msgs/Pose.h>
#include <turtlesim/Pose.h>
#include <std_msgs/String.h>

geometry_msgs::Twist twist_msg;
geometry_msgs::Pose pose;
```

socket传输的数据类型，在ros_lib包中可查，也可以传输基本数据类型如字符串。
如果定义新的数据类型，需要修改边缘端并在边缘端编译和安装程序，数据类型也可以由我们后期自定义。

已有的数据类型全在ros_lib中。

### 收发数据测试：

该例子只使用了Topic的订阅/发布模式，详见JHLRosTest.cpp内部。

发送数据：
```c++
// Receive Message Test
receiveMsgTest(nh);
```

接收数据，接收数据有回调函数`receiveMsgCallback`

```c++
// Send Message Test
sendMsgTest(nh);
```

## Ros信息传输方式的简要解释

通过tcp socket接口传输

### 1. Topic
话题，订阅/发布模式，同步通讯。
接口详见 ros_lib\ros\中的publisher.h和subscriber.h

### 2. Service
服务，请求/响应模式，异步通讯。
接口详见 ros_lib\ros\中的service_server.h和service_client.h

### 3. Action
一套由目标话题，反馈话题，结果话题组成的高级协议。

本接口只含有Topic和Service。

## 注意：

在ros_lib时

* 不要使用预编译头#include "stdafx.h"
* rosserial server不支持Unicode
* 订阅或发布信息之后使用spinOnce()


# 附录

[Rosserial wiki](http://wiki.ros.org/rosserial/)
