#include "mmd/vmd.hpp"
#include "stream.hpp"

namespace mmd {
    namespace vmd {

        bool cmp(Keyframe *k1, Keyframe *k2) {
            return k1->frame < k2->frame;
        }

        void Motion::load(Fs *fs) {
            Stream *stream = (Stream *)fs;

            header.load(fs);

            LOG << "Load Keyframes";
            int n = stream->readInt();
            keyframes.resize(n);
            LOG << "---------------------";
            LOG << "Keyframe infomation";
            LOG << "---------------------";
            LOG << "Keyframe size: " << n;
            for (int i = 0; i < n; ++i) {
                keyframes[i].load(stream);
                const auto &str = keyframes[i].bone;
                bones[str].push_back(&keyframes[i]);
            }
            for (auto &t : bones) {
                if (t.second.size() > 1) {
                    std::sort(t.second.begin(), t.second.end(), cmp);
                    LOG << "bone " << t.first << " frames: " << t.second.size();
                }
            }
            LOG << "---------------------";
        }

    } /* vmd */
} /* mmd */
