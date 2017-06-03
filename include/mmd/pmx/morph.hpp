#ifndef __MMD_PMX_MORPH
#define __MMD_PMX_MORPH

#include "../fs.hpp"
#include "header.hpp"

namespace mmd {
    namespace pmx {

        struct MMDAPI Morph {
            enum MorphType {
                GroupMorph = 0,
                VertexMorph,
                BoneMorph,
                UVMorph, UVExt1, UVExt2, UVExt3, UVExt4,
                Material,
                Flip,
                Impulse
            };

            struct VertexOffset {
                unsigned index;
                glm::vec3 translate;
            };

            std::string name;
            char panel;
            MorphType type;
            std::vector<VertexOffset> offsets;

            void load(Fs *fs, Header *header);
        };

    } /* pmx */
} /* mmd */

#endif
