#include "../ext.hpp"
#include "../stream.hpp"
#include "mmd/pmx/header.hpp"

using namespace std;

namespace mmd {
    namespace pmx {

        void Header::load(Fs *fs) {
            LOG << "Load PMX header";

            Stream *stream = (Stream *)fs;
            stream->read(end - sign, &this->sign[0]);
            CHECK_EQ(memcmp(this->sign, "PMX ", 4), 0) << "Invalid PMX header!";
            CHECK_EQ(globals, 8) << "Invalid PMX global count!";
            stream->readStr(name, text);
            stream->skipStr();
            stream->skipStr();
            stream->skipStr();

            LOG << "---------------------";
            LOG << "PMX header infomation";
            LOG << "---------------------";
            LOG << "PMX version: " << version;
            LOG << "text encoding: " << (text ? "UTF8" : "UTF16");
            LOG << "name: " << name;
            LOG << "additional uv: " << (int)additional;
            LOG << "vertex: " << (int)vertex;
            LOG << "texture: " << (int)texture;
            LOG << "material: " << (int)material;
            LOG << "bone: " << (int)bone;
            LOG << "morph: " << (int)morph;
            LOG << "rigid: " << (int)rigid;
            LOG << "---------------------";
        }

    } /* pmx */
} /* mmd */
