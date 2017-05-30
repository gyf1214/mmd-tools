#ifndef __MMD_PMX_TEXTURE
#define __MMD_PMX_TEXTURE

#include "../fs.hpp"
#include "header.hpp"

namespace mmd {
    namespace pmx {

        struct MMDAPI Texture {
            std::vector<std::string> path;

            std::string &operator [](int index);
            const std::string &operator [](int index) const;

            void load(Fs *fs, Header *header);
        };

    } /* pmx */
} /* mmd */

#endif
