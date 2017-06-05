#ifndef __MMD_PMX_RIDIG
#define __MMD_PMX_RIDIG

#include "../fs.hpp"
#include "header.hpp"

namespace mmd {
    namespace pmx {

        struct MMDAPI Rigid {
            std::string name;
            int bone;
            char group;
            unsigned short mask;

            enum Shape {
                RigidSphere = 0,
                RigidBox,
                RigidCapsule
            } shape;

            glm::vec3 size;
            glm::vec3 position;
            glm::vec3 rotation;

            float mass;
            float moveDamping;
            float rotateDamping;
            float repulsion;
            float friction;
            char mode;

            void load(Fs *fs, Header *header);
        };

    } /* pmx */
} /* mmd */

#endif
