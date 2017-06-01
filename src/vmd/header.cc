#include "mmd/vmd/header.hpp"
#include "../stream.hpp"

static const int nameLength = 20;

namespace mmd {
    namespace vmd {
        static const char Magic[Header::SignLength]
            = "Vocaloid Motion Data 0002";
        static const char Magic2[Header::SignLength]
            = "Vocaloid Motion Data file";

        void Header::load(Fs *fs) {
            LOG << "Load VMD header";

            Stream *stream = (Stream *)fs;
            stream->read(SignLength, sign);
            CHECK(memcmp(sign, Magic, SignLength) == 0
               || memcmp(sign, Magic2, SignLength) == 0)
               << "Invalid VMD header!";

            stream->readJIS(nameLength, name);

            LOG << "---------------------";
            LOG << "VMD header infomation";
            LOG << "---------------------";
            LOG << "name: " << name;
            LOG << "---------------------";
        }

    } /* vmd */
} /* mmd */
