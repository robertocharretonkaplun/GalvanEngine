#pragma once
#include "Prerequisites.h"

class NotificationService {
private:
  // Constructor privado para evitar instancias múltiples
  NotificationService() {}

  // Eliminar el operador de copia y asignación para evitar duplicaciones
  NotificationService(const NotificationService&) = delete;
  NotificationService& operator=(const NotificationService&) = delete;

public:
  static NotificationService& getInstance() {
    static NotificationService instance;
    return instance;
  }

  void addMessage(ConsolErrorType code, const std::string& message) {
    m_programMessages[code] = message;
  }

  std::string getMessage(ConsolErrorType code) const {
    auto it = m_programMessages.find(code);
    if (it != m_programMessages.end()) {
      return it->second;
    }
    else {
      return "Message not found";
    }
  }

  void showAllMessages() const {
    for (const auto& pair : m_programMessages) {
      std::cout << "Code: " << pair.first << " - Message: " << pair.second << std::endl;
    }
  }

  // Método para guardar los mensajes en un archivo
  void saveMessagesToFile(const std::string& filename) const {
    std::ofstream file(filename);
    if (!file.is_open()) {
      std::cerr << "No se pudo abrir el archivo para guardar los mensajes." << std::endl;
      return;
    }

    for (const auto& pair : m_programMessages) {
      file << "Code: " << pair.first << " - Message: " << pair.second << "\n";
    }

    file.close();
    std::cout << "Mensajes guardados en el archivo: " << filename << std::endl;
  }

  std::map<ConsolErrorType, std::string>& getNotifications() {
    return m_programMessages;
  }

private:
  // Mapa para almacenar los mensajes del programa
  std::map<ConsolErrorType, std::string> m_programMessages;
};