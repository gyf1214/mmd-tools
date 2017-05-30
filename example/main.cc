#include "mmd/pmx.hpp"
#include "../src/log.hpp"

using namespace mmd;

int main(int argc, char **argv) {
    CHECK(argc > 1) << "No path given!";

    Fs *fs = Fs::open(argv[1]);
    pmx::Model model;
    model.load(fs);

    delete fs;

    return 0;
}
