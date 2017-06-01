#ifndef __EXT
#define __EXT

#include "mmd/common.hpp"
#include <iconv.h>

using glm::vec2;
using glm::vec3;
using glm::vec4;

#define Offset(type, member)    ((void *)(&(((type *)0)->member)))

inline std::ostream &operator <<(std::ostream &o, const vec2 &v) {
    o << "(" << v.x << ", " << v.y << ")";
    return o;
};

inline std::ostream &operator <<(std::ostream &o, const vec3 &v) {
    o << "(" << v.x << ", " << v.y << ", " << v.z << ")";
    return o;
};

inline std::ostream &operator <<(std::ostream &o, const vec4 &v) {
    o << "(" << v.x << ", " << v.y << ", " << v.z << ", " << v.w << ")";
    return o;
};

#include "log.hpp"

#endif
