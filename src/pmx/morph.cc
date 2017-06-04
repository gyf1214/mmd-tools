#include "mmd/pmx/morph.hpp"
#include "../stream.hpp"

namespace mmd {
    namespace pmx {

        void Morph::load(Fs *fs, Header *header) {
            Stream *stream = (Stream *)fs;
            stream->readUTF16(name);
            stream->skipStr();
            panel = stream->readSByte();
            type = (MorphType)stream->readByte();
            CHECK_EQ(type, VertexMorph) << "only support vertex morph!";
            int n = stream->readInt();
            offsets.resize(n);
            for (int i = 0; i < n; ++i) {
                offsets[i].index = stream->readIndex(header->vertex);
                offsets[i].translate = stream->readVec3();
            }

            LOG << "name: " << name;
            LOG << "panel: " << (int)panel;
            LOG << "type: " << type;
            LOG << "offsets: " << n;
        }

    } /* pmx */
} /* mmd */
