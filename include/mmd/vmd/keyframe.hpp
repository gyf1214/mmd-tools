#ifndef __MMD_VMD_KEYFRAME
#define __MMD_VMD_KEYFRAME

#include "../fs.hpp"

namespace mmd {
    namespace vmd {

        struct MMDAPI Keyframe {
            std::string bone;
            unsigned frame;
            glm::vec3 position;
            glm::vec4 rotation;
            glm::mat4 curve;
            char end[0];

            void load(Fs *fs);
        };

    } /* vmd */
} /* mmd */

#endif
