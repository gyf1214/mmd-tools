#include "mmd/pmx/texture.hpp"
#include "../stream.hpp"

namespace mmd {
    namespace pmx {

        void Texture::load(Fs *fs, Header *header) {
            LOG << "Load Texture";
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
            LOG << "---------------------";
        }

        std::string &Texture::operator [](int index) {
            return path[index];
        }

        const std::string &Texture::operator [](int index) const {
            return path[index];
        }

    } /* pmx */
} /* mmd */
