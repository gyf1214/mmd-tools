#include "mmd/vmd.hpp"
#include "stream.hpp"

namespace mmd {
    namespace vmd {

        template <class T>
        bool cmp(T *k1, T *k2) {
            return k1->frame < k2->frame;
        }

        template <class T, class U, class P, class Q>
        void loadFrames(T &frames, U &remap, Stream *stream,
                        P cmp, Q getKey, const char *tip) {

            LOG << "Load " << tip;
            int n = stream->readInt();
            frames.resize(n);
            LOG << "---------------------";
            LOG << tip << " infomation";
            LOG << "---------------------";
            LOG << tip << " size: " << n;
            for (int i = 0; i < n; ++i) {
                frames[i].load(stream);
                const auto &str = getKey(frames[i]);
                remap[str].push_back(&frames[i]);
            }
            for (auto &t : remap) {
                if (t.second.size() > 1) {
                    std::sort(t.second.begin(), t.second.end(), cmp);
                    LOG << t.first << " frames: " << t.second.size();
                }
            }
            LOG << "---------------------";
        }

        const std::string &getBone(const Keyframe &k) {
            return k.bone;
        }

        const std::string &getFace(const Face &f) {
            return f.morph;
        }

        void Motion::load(Fs *fs) {
            Stream *stream = (Stream *)fs;

            header.load(fs);

            loadFrames(keyframes, bones, stream,
                       cmp<Keyframe>, getBone, "Keyframe");
            loadFrames(faceKeys, faces, stream, cmp<Face>, getFace, "Face");
        }

    } /* vmd */
} /* mmd */
