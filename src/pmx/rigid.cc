#include "mmd/pmx/rigid.hpp"
#include "../stream.hpp"

namespace mmd {
    namespace pmx {

        void Rigid::load(Fs *fs, Header *header) {
            Stream *stream = (Stream *)fs;

            stream->readStr(name, header->text);
            stream->skipStr();
            bone = stream->readIndex(header->bone);

            group = stream->readSByte();
            mask = stream->readUShort();
            shape = (Shape)stream->readSByte();

            int n = (char *)&mode - (char *)&size[0];
            stream->read(n, &size[0]);

            mode = stream->readSByte();

            LOG << "name: "     << name;
            LOG << "bone: "     << bone;
            LOG << "group: "    << (int)group;
            LOG << "mask: "     << mask;
            LOG << "shape: "    << (int)shape;
            LOG << "size: "     << size;
            LOG << "position: " << position;
            LOG << "rotation: " << rotation;
            LOG << "mass: "     << mass;
            LOG << "moveDamping: " << moveDamping;
            LOG << "rotateDamping: " << rotateDamping;
            LOG << "repulsion: " << repulsion;
            LOG << "friction: " << friction;
            LOG << "mode: "     << (int)mode;
        }

    } /* pmx */
} /* mmd */
