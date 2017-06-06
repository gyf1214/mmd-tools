#include "mmd/pmx/joint.hpp"
#include "../stream.hpp"

namespace mmd {
    namespace pmx {

        void Joint::load(Fs *fs, Header *header) {
            Stream *stream = (Stream *)fs;
            stream->readStr(name, header->text);
            stream->skipStr();
            type = (JointType)stream->readSByte();
            rigidA = stream->readIndex(header->rigid);
            rigidB = stream->readIndex(header->rigid);
            int n = (char *)end - (char *)&position[0];
            stream->read(n, &position[0]);

            LOG << "name: " << name;
            LOG << "type: " << type;
            LOG << "rigid: " << rigidA << " - " << rigidB;
            LOG << "position: " << position;
            LOG << "rotation: " << rotation;
            LOG << "position range: " << posMin << " - " << posMax
                << " <" << posSpring << ">";
            LOG << "rotation range: " << rotMin << " - " << rotMax
                << " <" << rotSpring << ">";
        }

    } /* pmx */
} /* mmd */
