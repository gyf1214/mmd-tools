#ifndef __MMD_FS
#define __MMD_FS

#include "common.hpp"

namespace mmd {

    class MMDAPI Fs {
    public:
        virtual ~Fs();
        virtual void close() = 0;
        static Fs *open(const char *path);
    };

} /* mmd */
#endif
