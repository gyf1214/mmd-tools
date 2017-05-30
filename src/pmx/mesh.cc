#include "mmd/pmx/mesh.hpp"
#include "../stream.hpp"

namespace mmd {
    namespace pmx {

        void Vertex::load(Fs *fs, Header *header) {
            Stream *stream = (Stream *)fs;
            position = stream->readVec3();
            normal = stream->readVec3();
            uv = stream->readVec2();
            for (int i = 0; i < header->additional; ++i) {
                addition[i] = stream->readVec4();
            }
            boneType = stream->readByte();
            switch (boneType) {
                case 0:
                BDEF.bone[0] = stream->readIndex(header->bone);
                break;

                case 1:
                BDEF.bone[0] = stream->readIndex(header->bone);
                BDEF.bone[1] = stream->readIndex(header->bone);
                BDEF.weight[0] = stream->readFloat();
                BDEF.weight[1] = 1.0f - BDEF.weight[0];
                break;

                case 2:
                case 4:
                for (int i = 0; i < 4; ++i) {
                    BDEF.bone[i] = stream->readIndex(header->bone);
                }
                for (int i = 0; i < 4; ++i) {
                    BDEF.weight[i] = stream->readFloat();
                }
                break;

                case 3:
                SDEF.bone[0] = stream->readIndex(header->bone);
                SDEF.bone[1] = stream->readIndex(header->bone);
                SDEF.weight[0] = stream->readFloat();
                SDEF.weight[1] = 1.0f - SDEF.weight[0];
                SDEF.C = stream->readVec3();
                SDEF.R0 = stream->readVec3();
                SDEF.R1 = stream->readVec3();
                break;

                default:
                FAIL << "Invalid bone type!";
            }
            edge = stream->readFloat();
        }

        void Surface::load(Fs *fs, Header *header) {
            Stream *stream = (Stream *)fs;
            A = stream->readUIndex(header->vertex);
            B = stream->readUIndex(header->vertex);
            C = stream->readUIndex(header->vertex);
        }

        void Mesh::load(Fs *fs, Header *header) {
            LOG << "load Mesh";
            Stream *stream = (Stream *)fs;
            int n = stream->readInt();
            vertex.resize(n);
            for (int i = 0; i < n; ++i) {
                vertex[i].load(fs, header);
            }
            n = stream->readInt() / 3;
            surface.resize(n);
            for (int i = 0; i < n; ++i) {
                surface[i].load(fs, header);
            }

            LOG << "---------------------";
            LOG << "Mesh infomation";
            LOG << "---------------------";
            LOG << "vertices: " << vertex.size();
            LOG << "surfaces: " << surface.size();
        }

    } /* pmx */
} /* mmd */
