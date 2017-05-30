#ifndef __MMD_PMX_MESH
#define __MMD_PMX_MESH

#include "../fs.hpp"
#include "header.hpp"

namespace mmd {
    namespace pmx {

        struct MMDAPI Vertex {
            glm::vec3 position;
            glm::vec3 normal;
            glm::vec2 uv;
            glm::vec4 addition[4];
            char boneType;
            union {
                struct {
                    int bone[4];
                    float weight[4];
                } BDEF;
                struct {
                    int bone[2];
                    float weight[2];
                    glm::vec3 C;
                    glm::vec3 R0;
                    glm::vec3 R1;
                } SDEF;
            };
            float edge;

            Vertex();
            void load(Fs *fs, Header *header);
        };

        struct MMDAPI Surface {
            unsigned A, B, C;

            void load(Fs *fs, Header *header);
        };

        struct MMDAPI Mesh {
            std::vector<Vertex> vertex;
            std::vector<Surface> surface;

            void load(Fs *fs, Header *header);
        };

    } /* pmx */
} /* mmd */
#endif
