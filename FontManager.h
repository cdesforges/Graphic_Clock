//
// Created by Chandler Desforges on 10/15/24.
//

#ifndef GRAPHIC_CLOCK_FONTMANAGER_H
#define GRAPHIC_CLOCK_FONTMANAGER_H

#include <string>
#include <SFML/Graphics.hpp>
#include <map>
#include <exception>

class FontManager
{
private:
    std::map<std::string, sf::Font> m_fontMap;

public:
    static FontManager& getInstance();

    const sf::Font* getFont(const std::string& filePath);

private:
    FontManager() = default;

    FontManager(const FontManager&) = delete;
    FontManager operator=(const FontManager&) = delete;
};


#endif //GRAPHIC_CLOCK_FONTMANAGER_H
