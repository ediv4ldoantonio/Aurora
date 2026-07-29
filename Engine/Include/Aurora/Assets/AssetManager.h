#pragma once

#include "Aurora/Renderer/Texture2D.h"

#include <memory>
#include <string>
#include <unordered_map>

namespace Aurora
{

    class AssetManager
    {
    public:
        std::shared_ptr<Texture2D>
        LoadTexture(const std::string &path);

    private:
        std::unordered_map<
            std::string,
            std::shared_ptr<Texture2D>>
            m_Textures;
    };

}