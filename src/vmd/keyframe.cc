#include "mmd/vmd/keyframe.hpp"
#include "../stream.hpp"

static const int boneSize = 15;

namespace mmd {
    namespace vmd {

        void Keyframe::load(Fs *fs) {
            Stream *stream = (Stream *)fs;

            stream->readJIS(boneSize, bone);

            int size = (char *)end - (char *)&frame;
            stream->read(size, &frame);
        }

    } /* vmd */
} /* mmd */
