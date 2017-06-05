#include "mmd/pmx.hpp"
#include "stream.hpp"

namespace mmd {
    namespace pmx {

        template <class T>
        static void loadArray(T &x, Stream *stream,
            Header *header, const char *tip) {

            LOG << "Load " << tip;
            int n = stream->readInt();
            x.resize(n);
            LOG << "---------------------";
            LOG << tip << " infomation";
            LOG << "---------------------";
            LOG << tip << " size: " << n;
            LOG << "---------------------";
            for (int i = 0; i < n; ++i) {
                LOG << tip << " " << i;
                LOG << "---------------------";
                x[i].load(stream, header);
                LOG << "---------------------";
            }
        }

        void Model::load(Fs *fs) {
            Stream *stream = (Stream *)fs;
            header.load(fs);
            mesh.load(fs, &header);
            textures.load(fs, &header);

            loadArray(materials, stream, &header, "Material");
            loadArray(bones, stream, &header, "Bone");
            loadArray(morphs, stream, &header, "Morph");
            loadArray(displays, stream, &header, "Display");
            loadArray(rigids, stream, &header, "Rigid");
        }

    } /* pmx */
} /* mmd */
