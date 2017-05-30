#include "../ext.hpp"
#include "../stream.hpp"
#include "mmd/pmx/bone.hpp"

namespace mmd {
    namespace pmx {

        Bone::Bone() {}

        void Bone::load(Fs *fs, Header *header) {
            Stream *stream = (Stream *)fs;
            stream->skipStr();
            stream->readStr(name, header->text);
            position = stream->readVec3();
            parent = stream->readIndex(header->bone);
            order = stream->readInt();
            flag = stream->readUShort();

            LOG << "name: " << name;
            LOG << "position: " << position;
            LOG << "parent: " << parent;
            LOG << "order: " << order;
            LOG << "flag: " << flag;

            if (flag & ConnectIndex) {
                tailIndex = stream->readIndex(header->bone);
                LOG << "tail: bone " << tailIndex;
            } else {
                tailPosition = stream->readVec3();
                LOG << "tail: " << tailPosition;
            }

            if ((flag & AdditionalLocation) || (flag & AdditionalRotation)) {
                additionalParent = stream->readIndex(header->bone);
                additionalWeight = stream->readFloat();
                LOG << "additional parent: " << additionalParent
                    << " x " << additionalWeight;
            }

            if (flag & FixedAxis) {
                axis = stream->readVec3();
                LOG << "fixed axis: " << axis;
            }

            if (flag & LocalCoordinate) {
                xAxis = stream->readVec3();
                zAxis = stream->readVec3();
                LOG << "local x: " << xAxis;
                LOG << "local z: " << zAxis;
            }

            if (flag & ExternalParent) {
                externalParent = stream->readInt();
            }

            if (flag & IsIK) {
                IK.target = stream->readIndex(header->bone);
                IK.loopCount = stream->readInt();
                IK.constraint = stream->readFloat();

                LOG << "IK target: " << IK.target;
                LOG << "IK loopCount: " << IK.loopCount;
                LOG << "IK constraint: " << IK.constraint;

                int n = stream->readInt();
                IK.links.resize(n);

                LOG << "IK link size: " << n;

                for (int i = 0; i < n; ++i) {
                    IK.links[i].bone = stream->readIndex(header->bone);

                    LOG << "IK link " << i << ": " << IK.links[i].bone;

                    int t = stream->readByte();
                    if (t) {
                        IK.links[i].min = stream->readVec3();
                        IK.links[i].max = stream->readVec3();

                        LOG << "IK link " << i << " constraints: "
                            << IK.links[i].min << "-" << IK.links[i].max;
                    }
                }
            }
        }

    } /* pmx */
} /* mmd */
