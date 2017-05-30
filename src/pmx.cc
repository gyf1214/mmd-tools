#include "mmd/pmx.hpp"
#include "stream.hpp"

namespace mmd {
    namespace pmx {

        void Model::load(Fs *fs) {
            Stream *stream = (Stream *)fs;
            header.load(fs);
            mesh.load(fs, &header);
            textures.load(fs, &header);

            LOG << "Load Material";
            int n = stream->readInt();
            materials.resize(n);
            LOG << "---------------------";
            LOG << "Material infomation";
            LOG << "---------------------";
            LOG << "Material size: " << n;
            LOG << "---------------------";
            for (int i = 0; i < n; ++i) {
                LOG << "Material " << i;
                LOG << "---------------------";
                materials[i].load(fs, &header);
                LOG << "---------------------";
            }
        }

    } /* pmx */
} /* mmd */
