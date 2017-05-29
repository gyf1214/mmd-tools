#include "mmd/pmx.hpp"
#include "../src/log.hpp"

using namespace mmd;

int main(int argc, char **argv) {
    CHECK(argc > 1) << "No path given!";

    Fs *fs = Fs::open(argv[1]);
    pmx::Header header;
    header.load(fs);
    pmx::Mesh mesh;
    mesh.load(fs, &header);
    pmx::Texture texture;
    texture.load(fs, &header);

    delete fs;

    return 0;
}
