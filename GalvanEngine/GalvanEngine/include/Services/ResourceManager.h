#pragma once
#include "Prerequisites.h"
#include "Texture.h"

class 
ResourceManager {
private:
	ResourceManager() = default;
	~ResourceManager() = default;

	// Deshabilitar copiado y asignacion
	ResourceManager(const ResourceManager&) = delete;
	ResourceManager& operator=(const ResourceManager&) = delete;

public:
	static ResourceManager& getInstance() {
		static ResourceManager instance;
		return instance;
	}
	
	bool 
	loadTexture(const std::string& fileName, const std::string& extension) {
		// Verificar si la textura ua esta cargada
		if (m_textures.find(fileName) != m_textures.end()) {
			return true;
		}
		// Crear y cargar la textura
		EngineUtilities::TSharedPointer<Texture> texture = EngineUtilities::MakeShared<Texture>(fileName, extension);
		m_textures[fileName] = texture;
	}

	EngineUtilities::TSharedPointer<Texture> 
	getTexture(const std::string& fileName) {
		// Verificar si la textura existe
		auto it = m_textures.find(fileName);
		if (it != m_textures.end()) {
			return it->second; // Devolver la textura
		}

		std::cout << "Texture not found: " << fileName << std::endl;
		// Crear y cargar la textura
		EngineUtilities::TSharedPointer<Texture> texture = EngineUtilities::MakeShared<Texture>("Default", "png");
		m_textures["Default"] = texture;
		return texture;
	}

private:
	std::unordered_map<std::string, EngineUtilities::TSharedPointer<Texture>> m_textures;
};