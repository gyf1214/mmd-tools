#ifndef __STREAM
#define __STREAM

#include "ext.hpp"
#include "mmd/fs.hpp"

namespace mmd {

    class Stream : public Fs {
        FILE *file;
    public:
        Stream(const char *path);
        ~Stream();

        void read(size_t len, void *ptr);
        template <typename T>
        T read();
        void skip(size_t len);

        int readInt();
        unsigned readUInt();
        short readShort();
        unsigned short readUShort();
        unsigned char readByte();
        char readSByte();
        float readFloat();
        vec2 readVec2();
        vec3 readVec3();
        vec4 readVec4();
        int readIndex(int size);
        unsigned readUIndex(int size);
        void skipStr();
        void readUTF16(std::string &str);
        void readUTF8(std::string &str);
        void readStr(std::string &str, int text);

        void close();
    };

} /* mmd */
#endif
