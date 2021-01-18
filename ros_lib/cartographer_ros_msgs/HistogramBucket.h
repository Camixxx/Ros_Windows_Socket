#ifndef _ROS_cartographer_ros_msgs_HistogramBucket_h
#define _ROS_cartographer_ros_msgs_HistogramBucket_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace cartographer_ros_msgs
{

  class HistogramBucket : public ros::Msg
  {
    public:
      typedef double _bucket_boundary_type;
      _bucket_boundary_type bucket_boundary;
      typedef double _count_type;
      _count_type count;

    HistogramBucket():
      bucket_boundary(0),
      count(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_bucket_boundary;
      u_bucket_boundary.real = this->bucket_boundary;
      *(outbuffer + offset + 0) = (u_bucket_boundary.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_bucket_boundary.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_bucket_boundary.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_bucket_boundary.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_bucket_boundary.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_bucket_boundary.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_bucket_boundary.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_bucket_boundary.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->bucket_boundary);
      union {
        double real;
        uint64_t base;
      } u_count;
      u_count.real = this->count;
      *(outbuffer + offset + 0) = (u_count.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_count.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_count.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_count.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_count.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_count.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_count.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_count.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->count);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        double real;
        uint64_t base;
      } u_bucket_boundary;
      u_bucket_boundary.base = 0;
      u_bucket_boundary.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_bucket_boundary.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_bucket_boundary.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_bucket_boundary.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_bucket_boundary.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_bucket_boundary.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_bucket_boundary.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_bucket_boundary.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->bucket_boundary = u_bucket_boundary.real;
      offset += sizeof(this->bucket_boundary);
      union {
        double real;
        uint64_t base;
      } u_count;
      u_count.base = 0;
      u_count.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_count.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_count.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_count.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_count.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_count.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_count.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_count.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->count = u_count.real;
      offset += sizeof(this->count);
     return offset;
    }

    const char * getType(){ return "cartographer_ros_msgs/HistogramBucket"; };
    const char * getMD5(){ return "b579df35b32758cf09f65ae223aea0ad"; };

  };

}
#endif
