#ifndef _ROS_cartographer_ros_msgs_LandmarkEntry_h
#define _ROS_cartographer_ros_msgs_LandmarkEntry_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "geometry_msgs/Pose.h"

namespace cartographer_ros_msgs
{

  class LandmarkEntry : public ros::Msg
  {
    public:
      typedef const char* _id_type;
      _id_type id;
      typedef geometry_msgs::Pose _tracking_from_landmark_transform_type;
      _tracking_from_landmark_transform_type tracking_from_landmark_transform;
      typedef double _translation_weight_type;
      _translation_weight_type translation_weight;
      typedef double _rotation_weight_type;
      _rotation_weight_type rotation_weight;

    LandmarkEntry():
      id(""),
      tracking_from_landmark_transform(),
      translation_weight(0),
      rotation_weight(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_id = strlen(this->id);
      varToArr(outbuffer + offset, length_id);
      offset += 4;
      memcpy(outbuffer + offset, this->id, length_id);
      offset += length_id;
      offset += this->tracking_from_landmark_transform.serialize(outbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_translation_weight;
      u_translation_weight.real = this->translation_weight;
      *(outbuffer + offset + 0) = (u_translation_weight.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_translation_weight.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_translation_weight.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_translation_weight.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_translation_weight.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_translation_weight.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_translation_weight.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_translation_weight.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->translation_weight);
      union {
        double real;
        uint64_t base;
      } u_rotation_weight;
      u_rotation_weight.real = this->rotation_weight;
      *(outbuffer + offset + 0) = (u_rotation_weight.base >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (u_rotation_weight.base >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (u_rotation_weight.base >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (u_rotation_weight.base >> (8 * 3)) & 0xFF;
      *(outbuffer + offset + 4) = (u_rotation_weight.base >> (8 * 4)) & 0xFF;
      *(outbuffer + offset + 5) = (u_rotation_weight.base >> (8 * 5)) & 0xFF;
      *(outbuffer + offset + 6) = (u_rotation_weight.base >> (8 * 6)) & 0xFF;
      *(outbuffer + offset + 7) = (u_rotation_weight.base >> (8 * 7)) & 0xFF;
      offset += sizeof(this->rotation_weight);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_id;
      arrToVar(length_id, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_id; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_id-1]=0;
      this->id = (char *)(inbuffer + offset-1);
      offset += length_id;
      offset += this->tracking_from_landmark_transform.deserialize(inbuffer + offset);
      union {
        double real;
        uint64_t base;
      } u_translation_weight;
      u_translation_weight.base = 0;
      u_translation_weight.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_translation_weight.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_translation_weight.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_translation_weight.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_translation_weight.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_translation_weight.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_translation_weight.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_translation_weight.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->translation_weight = u_translation_weight.real;
      offset += sizeof(this->translation_weight);
      union {
        double real;
        uint64_t base;
      } u_rotation_weight;
      u_rotation_weight.base = 0;
      u_rotation_weight.base |= ((uint64_t) (*(inbuffer + offset + 0))) << (8 * 0);
      u_rotation_weight.base |= ((uint64_t) (*(inbuffer + offset + 1))) << (8 * 1);
      u_rotation_weight.base |= ((uint64_t) (*(inbuffer + offset + 2))) << (8 * 2);
      u_rotation_weight.base |= ((uint64_t) (*(inbuffer + offset + 3))) << (8 * 3);
      u_rotation_weight.base |= ((uint64_t) (*(inbuffer + offset + 4))) << (8 * 4);
      u_rotation_weight.base |= ((uint64_t) (*(inbuffer + offset + 5))) << (8 * 5);
      u_rotation_weight.base |= ((uint64_t) (*(inbuffer + offset + 6))) << (8 * 6);
      u_rotation_weight.base |= ((uint64_t) (*(inbuffer + offset + 7))) << (8 * 7);
      this->rotation_weight = u_rotation_weight.real;
      offset += sizeof(this->rotation_weight);
     return offset;
    }

    const char * getType(){ return "cartographer_ros_msgs/LandmarkEntry"; };
    const char * getMD5(){ return "133f8dd7259f83a87eb4d78b301c0b70"; };

  };

}
#endif
