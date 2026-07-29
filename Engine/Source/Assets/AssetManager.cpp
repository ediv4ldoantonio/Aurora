#include "Aurora/Assets/AssetManager.h"

namespace Aurora
{
    std::shared_ptr<Texture2D>
    AssetManager::LoadTexture(
        const std::string &path)
    {
        auto it = m_Textures.find(path);

        if (it != m_Textures.end())
            return it->second;

        auto texture =
            Texture2D::Create(path);

        m_Textures[path] = texture;

        return texture;
    }
}
