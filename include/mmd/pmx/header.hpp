#ifndef __MMD_PMX_HEADER
#define __MMD_PMX_HEADER

#include "../fs.hpp"

namespace mmd {
    namespace pmx {

        struct MMDAPI Header {
            std::string name;
            
            char sign[4];
            float version;
            char globals;
            char text;
            char additional;
            char vertex;
            char texture;
            char material;
            char bone;
            char morph;
            char rigid;
            char end[0];

            void load(Fs *fs);
        };

    } /* pmx */
} /* mmd */
#endif
