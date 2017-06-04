#include "mmd/vmd/face.hpp"
#include "../stream.hpp"

static const int faceSize = 15;

namespace mmd {
    namespace vmd {

        void Face::load(Fs *fs) {
            Stream *stream = (Stream *)fs;

            stream->readJIS(faceSize, morph);
            int size = end - (char *)&frame;
            stream->read(size, &frame);
        }

    } /* vmd */
} /* mmd */
