#ifndef __MMD_VMD_FACE
#define __MMD_VMD_FACE

#include "../fs.hpp"

namespace mmd {
    namespace vmd {

        struct MMDAPI Face {
            std::string morph;
            int frame;
            float scalar;
            char end[0];

            void load(Fs *fs);
        };

    } /* vmd */
} /* mmd */

#endif
