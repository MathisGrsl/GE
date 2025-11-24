#include <GL/glew.h>
#include <string>

namespace ge {

    inline ge::v3 camPos(0, 1.7, 0);
    inline ge::v3 camDir(1, 0, 0);
    inline float camDegX = 0;
    inline float camDegY = 0;
    inline float fov = 70;

    inline int perfMode = 0;

    inline int screenWidth;
    inline int screenHeight;

    struct texture {
        GLuint ambientOcclusion;
        GLuint baseColor;
        GLuint metallic;
        GLuint normal;
        GLuint roughness;
        float width;
        float height;
        GLuint preview;
    };
    inline std::vector<texture> textures;

    struct object {
        GLuint vao, vbo, instancesVBO;
        std::vector<float> vertices;
        std::vector<int> texturesUse;
        struct instanceData {
            ge::v3 position;
            ge::v3 rotation;
            float angle;
            ge::v3 scale;
            ge::v2 uvScale;
            float texture;
            float isLight;
        };
        std::vector<instanceData> instances;
    };

    inline std::vector<ge::object> objects;
}