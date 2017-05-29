#include "mmd/pmx/texture.hpp"
#include "../stream.hpp"

namespace mmd {
    namespace pmx {

        void Texture::load(Fs *fs, Header *header) {
            LOG << "load Texture";
            Stream *stream = (Stream *)fs;
            int n = stream->readInt();
            path.resize(n);
            LOG << "---------------------";
            LOG << "Texture infomation";
            LOG << "---------------------";
            LOG << "texture size: " << n;
            for (int i = 0; i < n; ++i) {
                stream->readStr(path[i], header->text);
                LOG << "texture " << i << ": " << path[i];
            }
        }

    } /* pmx */
} /* mmd */
