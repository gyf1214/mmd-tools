#ifndef __MMD_PMX_ALL
#define __MMD_PMX_ALL

#include "common.hpp"
#include "pmx/header.hpp"
#include "pmx/mesh.hpp"
#include "pmx/texture.hpp"
#include "pmx/material.hpp"
#include "pmx/bone.hpp"
#include "pmx/morph.hpp"
#include "pmx/display.hpp"
#include "pmx/rigid.hpp"
#include "pmx/joint.hpp"

namespace mmd {
    namespace pmx {

        struct MMDAPI Model {
            Header header;
            Mesh mesh;
            Texture textures;
            std::vector<Material> materials;
            std::vector<Bone> bones;
            std::vector<Morph> morphs;
            std::vector<Display> displays;
            std::vector<Rigid> rigids;
            std::vector<Joint> joints;

            void load(Fs *fs);
        };

    } /* pmx */
} /* mmd */

#endif
