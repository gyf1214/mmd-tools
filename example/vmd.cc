#include "mmd/vmd.hpp"
#include "../src/log.hpp"

using namespace mmd;

int main(int argc, char **argv) {
    CHECK(argc > 1) << "No path given!";

    Fs *fs = Fs::open(argv[1]);
    vmd::Motion motion;
    motion.load(fs);

    delete fs;

    return 0;
}
