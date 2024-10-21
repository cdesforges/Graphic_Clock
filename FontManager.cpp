//
// Created by Chandler Desforges on 10/15/24.
//

#include "FontManager.h"

FontManager &FontManager::getInstance()
{
    static FontManager instance;
    return instance;
}

const sf::Font* FontManager::getFont(const std::string& filePath)
{
    auto [it, inserted] = m_fontMap.try_emplace(filePath, sf::Font());

    if(inserted)
        if(!it->second.loadFromFile(filePath))
            throw std::runtime_error("Font failed to load from file");

    return &it->second;
}
