#include "Aurora/Renderer/Texture2D.h"
#include <SDL3/SDL.h>

namespace Aurora
{
    class SDLTexture2D
        : public Texture2D
    {
    public:
        explicit SDLTexture2D(
            const std::string &path);

        ~SDLTexture2D();

        uint32_t GetWidth() const override;

        uint32_t GetHeight() const override;

        bool IsLoaded() const override;

        const std::string &
        GetPath() const override;

    private:
        SDL_Texture *m_Texture = nullptr;

        uint32_t m_Width = 0;

        uint32_t m_Height = 0;

        std::string m_Path;
    };
}
