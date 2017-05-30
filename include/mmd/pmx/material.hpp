#ifndef __MMD_PMX_MATERIAL
#define __MMD_PMX_MATERIAL

#include "../fs.hpp"
#include "header.hpp"

namespace mmd {
    namespace pmx {

        struct MMDAPI Material {
            enum {
                DoubleSided = 0x01,
                DropShadow = 0x02,
                RenderShadow = 0x04,
                ReceiveShadow = 0x08,
                HasEdge = 0x10
            };

            std::string name;
            glm::vec4 diffuse;
            glm::vec3 specular;
            float sharpness;
            glm::vec3 ambient;
            char flag;
            glm::vec4 edge;
            float edgeWidth;
            int texture;
            int environment;
            char blend;
            char toonType;
            int toon;
            int count;

            void load(Fs *fs, Header *header);
        };


    } /* pmx */
} /* mmd */


#endif
