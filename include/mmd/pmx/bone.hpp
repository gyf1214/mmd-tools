#ifndef __MMD_PMX_BONE
#define __MMD_PMX_BONE

#include "../fs.hpp"
#include "header.hpp"

namespace mmd {
    namespace pmx {

        struct MMDAPI Bone {
            enum {
                ConnectIndex = 0x01,
                Rotatable = 0x02,
                Movable = 0x04,
                Visible = 0x08,
                Enable = 0x10,
                IsIK = 0x20,
                AdditionalRotation = 0x0100,
                AdditionalLocation = 0x0200,
                FixedAxis = 0x0400,
                LocalCoordinate = 0x0800,
                Phisics = 0x1000,
                ExternalParent = 0x2000
            };

            std::string name;
            glm::vec3 position;
            int parent;
            int order;
            int flag;
            union {
                glm::vec3 tailPosition;
                int tailIndex;
            };
            int additionalParent;
            float additionalWeight;
            glm::vec3 axis;
            glm::vec3 xAxis;
            glm::vec3 zAxis;
            int externalParent;

            struct IKInfo {
                int target;
                int loopCount;
                float constraint;

                struct IKLink {
                    int bone;
                    char limit;
                    glm::vec3 min;
                    glm::vec3 max;
                };

                std::vector<IKLink> links;
            } IK;

            Bone();
            void load(Fs *fs, Header *header);
        };

    } /* pmx */
} /* mmd */

#endif
