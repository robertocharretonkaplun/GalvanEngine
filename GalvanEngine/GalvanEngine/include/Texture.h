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
			std::cout << "Error de carga de textura: " << m_textureName << "." << m_extension << std::endl;
		}
	}

	virtual
	~Texture() = default;

	sf::Texture& getTexture() {
		return m_texture;
	}

	// Implementación de los métodos virtuales puros
	void update(float deltaTime) override {
		// Lógica de actualización de la textura (si es necesario)
	}

	void render(Window window) override {
		// Lógica de renderizado de la textura (si es necesario)
	}
private:
	std::string m_textureName;
	std::string m_extension;
	sf::Texture m_texture;
};