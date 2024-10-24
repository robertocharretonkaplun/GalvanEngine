#include "GUI.h"
#include "Window.h"
void 
GUI::init() {
	// Setup GUI Style
	setupGUIStyle();
}

void GUI::update()
{
}

void GUI::render()
{
}

void 
GUI::destroy() {
}

void 
GUI::setupGUIStyle() {
	ImGuiStyle& style = ImGui::GetStyle();
	ImVec4* colors = style.Colors;

	// Configuración de los colores basados en el estilo de Unreal Engine 5
	colors[ImGuiCol_WindowBg] = ImVec4(0.10f, 0.10f, 0.10f, 1.00f);  // Fondo de ventana
	colors[ImGuiCol_Border] = ImVec4(0.40f, 0.40f, 0.40f, 0.50f);  // Bordes
	colors[ImGuiCol_FrameBg] = ImVec4(0.16f, 0.16f, 0.16f, 1.00f);  // Fondo de cuadros
	colors[ImGuiCol_FrameBgHovered] = ImVec4(0.24f, 0.24f, 0.24f, 1.00f);  // Hover sobre cuadros
	colors[ImGuiCol_FrameBgActive] = ImVec4(0.34f, 0.34f, 0.34f, 1.00f);  // Cuadro activo
	colors[ImGuiCol_TitleBg] = ImVec4(0.06f, 0.06f, 0.06f, 1.00f);  // Fondo del título
	colors[ImGuiCol_TitleBgActive] = ImVec4(0.20f, 0.20f, 0.20f, 1.00f);  // Título activo
	colors[ImGuiCol_MenuBarBg] = ImVec4(0.14f, 0.14f, 0.14f, 1.00f);  // Fondo de la barra de menú
	colors[ImGuiCol_Button] = ImVec4(0.20f, 0.20f, 0.20f, 1.00f);  // Botón inactivo
	colors[ImGuiCol_ButtonHovered] = ImVec4(0.30f, 0.30f, 0.30f, 1.00f);  // Botón hover
	colors[ImGuiCol_ButtonActive] = ImVec4(0.40f, 0.40f, 0.40f, 1.00f);  // Botón activo
	colors[ImGuiCol_Text] = ImVec4(0.85f, 0.85f, 0.85f, 1.00f);  // Texto principal
	colors[ImGuiCol_TextDisabled] = ImVec4(0.55f, 0.55f, 0.55f, 1.00f);  // Texto deshabilitado
	colors[ImGuiCol_Header] = ImVec4(0.24f, 0.24f, 0.24f, 1.00f);  // Encabezado
	colors[ImGuiCol_HeaderHovered] = ImVec4(0.34f, 0.34f, 0.34f, 1.00f);  // Encabezado hover
	colors[ImGuiCol_HeaderActive] = ImVec4(0.45f, 0.45f, 0.45f, 1.00f);  // Encabezado activo
	colors[ImGuiCol_ScrollbarBg] = ImVec4(0.08f, 0.08f, 0.08f, 1.00f);  // Fondo scrollbar
	colors[ImGuiCol_ScrollbarGrab] = ImVec4(0.30f, 0.30f, 0.30f, 1.00f);  // Scrollbar inactivo
	colors[ImGuiCol_ScrollbarGrabHovered] = ImVec4(0.40f, 0.40f, 0.40f, 1.00f); // Scrollbar hover
	colors[ImGuiCol_ScrollbarGrabActive] = ImVec4(0.50f, 0.50f, 0.50f, 1.00f); // Scrollbar activo
	colors[ImGuiCol_CheckMark] = ImVec4(0.85f, 0.85f, 0.85f, 1.00f);  // Marca de check

	// Ajustes de estilo general
	style.WindowRounding = 5.0f;   // Redondeo de bordes de ventanas
	style.FrameRounding = 5.0f;   // Redondeo de bordes de cuadros
	style.ScrollbarRounding = 5.0f;   // Redondeo de bordes de scrollbar
	style.GrabRounding = 5.0f;   // Redondeo de bordes de botones de agarrar
	style.FrameBorderSize = 1.0f;   // Grosor del borde de cuadros
	style.WindowBorderSize = 1.0f;   // Grosor del borde de ventanas
	style.PopupBorderSize = 1.0f;   // Grosor del borde de popups
}
