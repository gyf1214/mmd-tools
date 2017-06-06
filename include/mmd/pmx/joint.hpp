#ifndef __MMD_PMX_JOINT
#define __MMD_PMX_JOINT

#include "../fs.hpp"
#include "header.hpp"

namespace mmd {
    namespace pmx {

        struct MMDAPI Joint {
            std::string name;
            enum JointType {
                Spring = 0,
                DOF6,
                P2P,
                ConeTwist,
                Slider,
                Hinge
            } type;

            int rigidA;
            int rigidB;
            glm::vec3 position;
            glm::vec3 rotation;
            glm::vec3 posMin;
            glm::vec3 posMax;
            glm::vec3 rotMin;
            glm::vec3 rotMax;
            glm::vec3 posSpring;
            glm::vec3 rotSpring;
            char end[0];

            void load(Fs *fs, Header *header);
        };

    } /* pmx */
} /* mmd */

#endif
