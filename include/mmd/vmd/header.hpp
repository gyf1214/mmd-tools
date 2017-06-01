#ifndef __MMD_VMD_HEADER
#define __MMD_VMD_HEADER

#include "../fs.hpp"

namespace mmd {
    namespace vmd {

        struct MMDAPI Header {
            static const int SignLength = 30;

            char sign[SignLength];
            std::string name;

            void load(Fs *fs);
        };

    } /* vmd */
} /* mmd */

#endif
