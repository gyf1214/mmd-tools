#include "mmd/pmx/material.hpp"
#include "../stream.hpp"

namespace mmd {
    namespace pmx {

        void Material::load(Fs *fs, Header *header) {
            Stream *stream = (Stream *)fs;
            stream->skipStr();
            stream->readStr(name, header->text);
            int headerSize = (char *)(&flag) - (char *)(&diffuse.x);
            stream->read(headerSize, &diffuse.x);

            flag = stream->readSByte();
            edge = stream->readVec4();
            edgeWidth = stream->readFloat();

            texture = stream->readIndex(header->texture);
            environment = stream->readIndex(header->texture);
            blend = stream->readSByte();
            toonType = stream->readSByte();
            if (toonType) {
                toon = stream->readSByte();
            } else {
                toon = stream->readIndex(header->texture);
            }

            stream->skipStr();
            count = stream->readInt();

            LOG << "name: " << name;
            LOG << "diffuse color: " << diffuse;
            LOG << "specular color: " << specular;
            LOG << "sharpness: " << sharpness;
            LOG << "ambient color: " << ambient;
            LOG << "flag: " << (int)flag;
            LOG << "edge color: " << edge;
            LOG << "edge width: " << edgeWidth;
            LOG << "texture: " << texture;
            LOG << "environment texture: " << environment;
            LOG << "blend mode: " << (int)blend;
            LOG << "toon type: " << (int)toonType;
            LOG << "toon index: " << toon;
            LOG << "surfaces: " << count;
        }

    } /* pmx */
} /* mmd */
