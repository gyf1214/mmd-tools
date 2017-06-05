#include "mmd/pmx/display.hpp"
#include "../stream.hpp"

namespace mmd {
    namespace pmx {

        void Display::load(Fs *fs, Header *header) {
            Stream *stream = (Stream *)fs;

            stream->readUTF16(name);
            stream->skipStr();
            flag = stream->readSByte();
            int n = stream->readInt();
            frames.resize(n);
            for (int i = 0; i < n; ++i) {
                frames[i].type = stream->readSByte();
                if (frames[i].type) {
                    frames[i].index = stream->readIndex(header->morph);
                } else {
                    frames[i].index = stream->readIndex(header->bone);
                }
            }

            LOG << "name: " << name;
            LOG << "frames: " << n;
        }

    } /* pmx */
} /* mmd */
