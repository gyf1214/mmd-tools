#ifndef __MMD_PMX_DISPLAY
#define __MMD_PMX_DISPLAY

#include "../fs.hpp"
#include "header.hpp"

namespace mmd {
    namespace pmx {

        struct MMDAPI Display {
            std::string name;
            char flag;

            struct Frame {
                char type;
                int index;
            };

            std::vector<Frame> frames;

            void load(Fs *fs, Header *header);
        };

    } /* pmx */
} /* mmd */

#endif
