#ifndef _ROS_std_msgs_MultiArrayLayout_h
#define _ROS_std_msgs_MultiArrayLayout_h

#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"
#include "std_msgs/MultiArrayDimension.h"

namespace std_msgs
{

  class MultiArrayLayout : public ros::Msg
  {
    public:
      uint32_t dim_length;
      typedef std_msgs::MultiArrayDimension _dim_type;
      _dim_type st_dim;
      _dim_type * dim;
      typedef uint32_t _data_offset_type;
      _data_offset_type data_offset;

    MultiArrayLayout():
      dim_length(0), st_dim(), dim(nullptr),
      data_offset(0)
    {
    }

    virtual ~MultiArrayLayout() {
      delete[] dim;
    }

    virtual int serialize(unsigned char *outbuffer) const override
    {
      int offset = 0;
      *(outbuffer + offset + 0) = (this->dim_length >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->dim_length >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->dim_length >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->dim_length >> (8 * 3)) & 0xFF;
      offset += sizeof(this->dim_length);
      for(uint32_t i = 0; i < dim_length; i++) {
        offset += this->dim[i].serialize(outbuffer + offset);
      }
      *(outbuffer + offset + 0) = (this->data_offset >> (8 * 0)) & 0xFF;
      *(outbuffer + offset + 1) = (this->data_offset >> (8 * 1)) & 0xFF;
      *(outbuffer + offset + 2) = (this->data_offset >> (8 * 2)) & 0xFF;
      *(outbuffer + offset + 3) = (this->data_offset >> (8 * 3)) & 0xFF;
      offset += sizeof(this->data_offset);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer) override
    {
      int offset = 0;
      uint32_t dim_lengthT = ((uint32_t) (*(inbuffer + offset))); 
      dim_lengthT |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1); 
      dim_lengthT |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2); 
      dim_lengthT |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3); 
      offset += sizeof(this->dim_length);

      if (dim_lengthT != dim_length) {
        delete[] this->dim;  // Libère l'ancienne mémoire
        this->dim = new std_msgs::MultiArrayDimension[dim_lengthT];  // Alloue de la nouvelle mémoire
      }
      dim_length = dim_lengthT;
      for(uint32_t i = 0; i < dim_length; i++) {
        offset += this->dim[i].deserialize(inbuffer + offset);
      }
      
      this->data_offset =  ((uint32_t) (*(inbuffer + offset)));
      this->data_offset |= ((uint32_t) (*(inbuffer + offset + 1))) << (8 * 1);
      this->data_offset |= ((uint32_t) (*(inbuffer + offset + 2))) << (8 * 2);
      this->data_offset |= ((uint32_t) (*(inbuffer + offset + 3))) << (8 * 3);
      offset += sizeof(this->data_offset);

      return offset;
    }

    virtual const char * getType() override { return "std_msgs/MultiArrayLayout"; }
    virtual const char * getMD5() override { return "0fed2a11c13e11c5571b4e2a995a91a3"; }

  };

}
#endif
