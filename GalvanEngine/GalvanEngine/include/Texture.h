#pragma once
#include "Prerequisites.h"
#include "Component.h"

class 
Texture : public Component {
public:
	Texture() = default;

	Texture(std::string textureName, std::string extension) : m_textureName(textureName), 
																														m_extension(extension), 
																														Component(ComponentType::TEXTURE) {
		if (!m_texture.loadFromFile(m_textureName + "." + m_extension)) {
			std::cout << "Error de carga de textura" << std::endl;
		}
		else {
			m_textureName = "Default";
			m_extension = "png";
			if (!m_texture.loadFromFile(m_textureName + "." + m_extension)) {
				std::cout << "Error de carga de textura" << std::endl;
			}
		}
	}

	virtual
	~Texture() = default;

	sf::Texture& getTexture() {
		return m_texture;
	}
private:
	std::string m_textureName;
	std::string m_extension;
	sf::Texture m_texture;
};