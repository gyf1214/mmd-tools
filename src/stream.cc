#include "stream.hpp"

static const int iconvSize = 64;

namespace mmd {

    void Stream::read(size_t len, void *ptr) {
        if (!len) return;
        int ret = fread(ptr, len, 1, file);
        CHECK_EQ(ret, 1) << "read failed!";
    }

    template <typename T>
    T Stream::read() {
        T ret;
        read(sizeof(T), &ret);
        return ret;
    }

    template<>
    vec2 Stream::read() {
        vec2 ret;
        read(2 * sizeof(float), &ret.x);
        return ret;
    }

    template<>
    vec3 Stream::read() {
        vec3 ret;
        read(3 * sizeof(float), &ret.x);
        return ret;
    }

    template<>
    vec4 Stream::read() {
        vec4 ret;
        read(4 * sizeof(float), &ret.x);
        return ret;
    }

    void Stream::skip(size_t len) {
        fseek(file, len, SEEK_CUR);
    }

    int Stream::readInt()               { return read<int>();            }
    unsigned Stream::readUInt()         { return read<unsigned>();       }
    short Stream::readShort()           { return read<short>();          }
    unsigned short Stream::readUShort() { return read<unsigned short>(); }
    unsigned char Stream::readByte()    { return read<unsigned char>();  }
    char Stream::readSByte()            { return read<char>();           }
    float Stream::readFloat()           { return read<float>();          }
    vec2 Stream::readVec2()             { return read<vec2>();           }
    vec3 Stream::readVec3()             { return read<vec3>();           }
    vec4 Stream::readVec4()             { return read<vec4>();           }
    void Stream::skipStr() {
        int len = readInt();
        skip(len);
    }

    void Stream::readUTF16(std::string &str) {
        std::string temp;
        readUTF8(temp);
        encode(utf16, temp, str);
    }

    void Stream::readJIS(int size, std::string &str) {
        std::string temp;
        temp.resize(size);
        read(size, &temp[0]);
        for (size = 0; temp[size]; ++size);
        temp.resize(size);
        encode(jis, temp, str);
    }

    void Stream::encode(iconv_t conv, std::string &temp, std::string &str) {
        char output[iconvSize];
        char *out = output;
        char *in = &temp[0];
        size_t inLeft = temp.size();
        size_t outLeft = iconvSize;
        str.clear();
        while (inLeft) {
            iconv(conv, &in, &inLeft, &out, &outLeft);
            CHECK(!inLeft || !outLeft) << "iconv failed!";
            str.append(output, iconvSize - outLeft);
            out = output, outLeft = iconvSize;
        }
    }

    void Stream::readUTF8(std::string &str) {
        int len = readInt();
        str.resize(len);
        read(len, &str[0]);
    }

    void Stream::readStr(std::string &str, int text) {
        if (!text) {
            readUTF16(str);
        } else {
            readUTF8(str);
        }
    }

    int Stream::readIndex(int size) {
        switch (size) {
            case 1:
            return readSByte();
            break;
            case 2:
            return readShort();
            break;
            case 4:
            return readInt();
            break;
            default:
            FAIL << "Invalid index size!";
        }
        return -1;
    }

    unsigned Stream::readUIndex(int size) {
        switch (size) {
            case 1:
            return readByte();
            break;
            case 2:
            return readUShort();
            break;
            case 4:
            return readUInt();
            break;
            default:
            FAIL << "Invalid index size!";
        }
        return -1;
    }

    Stream::Stream(const char *path) {
        file = fopen(path, "rb");
        utf16 = iconv_open("UTF-8", "UTF-16LE");
        CHECK_NQ(utf16, (iconv_t)-1) << "iconv_open utf16 failed!";
        jis = iconv_open("UTF-8", "SHIFT_JIS");
        CHECK_NQ(jis, (iconv_t)-1) << "iconv_open jis failed!";
        CHECK_NQ(file, NULL) << "Open file " << path << " failed!";
    }

    void Stream::close() {
        fclose(file);
        file = NULL;
        int ret = iconv_close(utf16);
        int ret2 = iconv_close(jis);
        CHECK(ret == 0 && ret2 == 0) << "iconv_close failed!";
    }

    Stream::~Stream() {
        if (file) close();
    }

    Fs::~Fs() {}

    Fs *Fs::open(const char *path) {
        return new Stream(path);
    }

} /* mmd */
