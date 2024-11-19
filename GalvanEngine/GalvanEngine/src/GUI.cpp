#include "imgui_internal.h"
#include "GUI.h"
#include "Window.h"
#include "Actor.h"

void 
GUI::init() {
	// Setup GUI Style
	setupGUIStyle();

	selectedActorIndex = 0;
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

void 
GUI::barMenu() {
	if (ImGui::BeginMainMenuBar()) {

		// Menú Archivo
		if (ImGui::BeginMenu("File")) {
			if (ImGui::MenuItem("New")) {
				// Acción para nuevo archivo
			}
			if (ImGui::MenuItem("Open", "Ctrl+O")) {
				// Acción para abrir archivo
			}
			if (ImGui::MenuItem("Save", "Ctrl+S")) {
				// Acción para guardar archivo
			}
			if (ImGui::MenuItem("Save As..")) {
				// Acción para guardar como
			}
			ImGui::Separator();
			if (ImGui::MenuItem("Exit", "Alt+F4")) {
				// Acción para salir
				exit(1);
			}
			ImGui::EndMenu();
		}

		// Menú Editar
		if (ImGui::BeginMenu("Edit")) {
			if (ImGui::MenuItem("Undo", "Ctrl+Z")) {
				// Acción para deshacer
			}
			if (ImGui::MenuItem("Redo", "Ctrl+Y")) {
				// Acción para rehacer
			}
			ImGui::Separator();
			if (ImGui::MenuItem("Cut", "Ctrl+X")) {
				// Acción para cortar
			}
			if (ImGui::MenuItem("Copy", "Ctrl+C")) {
				// Acción para copiar
			}
			if (ImGui::MenuItem("Paste", "Ctrl+V")) {
				// Acción para pegar
			}
			ImGui::EndMenu();
		}

		// Menú Ver
		if (ImGui::BeginMenu("View")) {
			if (ImGui::MenuItem("Show Console")) {
				// Acción para mostrar la consola
			}
			if (ImGui::MenuItem("Show Hierarchy")) {
				// Acción para mostrar la jerarquía
			}
			ImGui::EndMenu();
		}

		// Menú Herramientas
		if (ImGui::BeginMenu("Tools")) {
			if (ImGui::MenuItem("Options")) {
				// Acción para mostrar opciones
			}
			ImGui::EndMenu();
		}

		// Menú Ayuda
		if (ImGui::BeginMenu("Help")) {
			if (ImGui::MenuItem("Documentation")) {
				// Acción para abrir documentación
			}
			if (ImGui::MenuItem("About")) {
				// Acción para mostrar información sobre el programa
			}
			ImGui::EndMenu();
		}

		ImGui::EndMainMenuBar();
	}
}

void
GUI::Outliner(const std::vector<EngineUtilities::TSharedPointer<Actor>>& actors) {
	ImGui::Begin("Hierarchy");

	// Barra de búsqueda
	static ImGuiTextFilter filter;
	filter.Draw("Search...", 180.0f); // Barra de búsqueda con ancho ajustable

	ImGui::Separator();

	// Recorrer y mostrar cada actor que pase el filtro de búsqueda
	for (int i = 0; i < actors.size(); ++i) {
		const auto& actor = actors[i];

		// Obtener el nombre del actor o asignar un nombre genérico
		std::string actorName = actor ? actor->getName() : "Unnamed Actor";

		// Verificar si el actor pasa el filtro de búsqueda
		if (!filter.PassFilter(actorName.c_str())) {
			continue; // Saltar actores que no coincidan con el filtro
		}

		// Si el actor es seleccionable
		ImGuiTreeNodeFlags flags = ImGuiTreeNodeFlags_OpenOnArrow | ImGuiTreeNodeFlags_OpenOnDoubleClick;
		if (selectedActorIndex == i)
			flags |= ImGuiTreeNodeFlags_Selected;

		// Crear un nodo de árbol para cada actor
		bool nodeOpen = ImGui::TreeNodeEx((void*)(intptr_t)i, flags, "%s", actorName.c_str());

		// Selección de actor
		if (ImGui::IsItemClicked()) {
			selectedActorIndex = i;
			// Aquí puedes llamar a alguna función para mostrar los detalles del actor en otra ventana
		}

		// Mostrar nodos hijos si el nodo está abierto
		if (nodeOpen) {
			//ImGui::Text("Position: %.2f, %.2f, %.2f", actor->getPosition().x, actor->getPosition().y, actor->getPosition().z);
			ImGui::TreePop();
		}
	}

	ImGui::End();
}

void
GUI::console(const std::map<ConsolErrorType, std::vector<std::string>>& programMessages) {
	ImGui::Begin("Console");

	static ImGuiTextFilter filter; // Filtro de búsqueda
	filter.Draw("Filter (\"error\", \"warning\", etc.)", 180.0f);

	ImGui::Separator();

	ImGui::BeginChild("ScrollingRegion", ImVec2(0, 0), false, ImGuiWindowFlags_HorizontalScrollbar);

	for (const auto& pair : programMessages) {
		// Establece color según el tipo de mensaje
		ImVec4 color;
		switch (pair.first) {
		case ConsolErrorType::ERROR:
			color = ImVec4(1.0f, 0.4f, 0.4f, 1.0f); // Rojo para errores
			break;
		case ConsolErrorType::WARNING:
			color = ImVec4(1.0f, 1.0f, 0.4f, 1.0f); // Amarillo para advertencias
			break;
		case ConsolErrorType::INFO:
		default:
			color = ImVec4(0.8f, 0.8f, 0.8f, 1.0f); // Gris para mensajes de información
			break;
		}

		for (const auto& message : pair.second) {
			if (!filter.PassFilter(message.c_str())) continue; // Filtrar mensajes según el filtro de búsqueda

			ImGui::PushStyleColor(ImGuiCol_Text, color);
			ImGui::Text("[%d] %s", pair.first, message.c_str());
			ImGui::PopStyleColor();
		}
	}

	// Desplazamiento automático al final
	if (ImGui::GetScrollY() >= ImGui::GetScrollMaxY())
		ImGui::SetScrollHereY(1.0f);

	ImGui::EndChild();
	ImGui::End();
}

void 
GUI::inspector(const std::vector<EngineUtilities::TSharedPointer<Actor>>& actors) {
	bool show_demo_window = true;
	ImGui::Begin("Inspector");
	// Checkbox para Static
	bool isStatic = false;
	ImGui::Checkbox("##Static", &isStatic);
	ImGui::SameLine();

	// Input text para el nombre del objeto
	char objectName[128];
	std::string name = actors[selectedActorIndex]->getName();
	std::copy(name.begin(), name.end(), objectName);
	objectName[name.size()] = '\0';  // Asegurarse de terminar la cadena

	//ImGui::SetNextItemWidth(ImGui::GetContentRegionAvailWidth() * 0.6f);
	ImGui::InputText("##ObjectName", objectName, IM_ARRAYSIZE(objectName));
	ImGui::SameLine();

	// Icono (este puede ser una imagen, aquí solo como ejemplo de botón)
	if (ImGui::Button("Icon")) {
		// Lógica del botón de icono aquí
	}

	// Separador horizontal
	ImGui::Separator();

	// Dropdown para Tag
	const char* tags[] = { "Untagged", "Player", "Enemy", "Environment" };
	static int currentTag = 0;
	//ImGui::SetNextItemWidth(ImGui::GetContentRegionAvailWidth() * 0.5f);
	ImGui::Combo("Tag", &currentTag, tags, IM_ARRAYSIZE(tags));
	ImGui::SameLine();

	// Dropdown para Layer
	const char* layers[] = { "Default", "TransparentFX", "Ignore Raycast", "Water", "UI" };
	static int currentLayer = 0;
	//ImGui::SetNextItemWidth(ImGui::GetContentRegionAvailWidth() * 0.5f);
	ImGui::Combo("Layer", &currentLayer, layers, IM_ARRAYSIZE(layers));

	ImGui::Separator();

	// Transform elements
	vec2Control("Position", actors[selectedActorIndex]->getComponent<Transform>()->getPosData());
	vec2Control("Rotation", actors[selectedActorIndex]->getComponent<Transform>()->getRotData());
	vec2Control("Scale", actors[selectedActorIndex]->getComponent<Transform>()->getScaData());
	
	ImGui::End();
}

void 
GUI::vec2Control(const std::string& label, 
								 float* values, 
								 float resetValue, 
								 float columnWidth) {
	ImGuiIO& io = ImGui::GetIO();
	auto boldFont = io.Fonts->Fonts[0];

	ImGui::PushID(label.c_str());

	ImGui::Columns(2);
	ImGui::SetColumnWidth(0, columnWidth);
	ImGui::Text(label.c_str());
	ImGui::NextColumn();

	ImGui::PushMultiItemsWidths(3, ImGui::CalcItemWidth());
	ImGui::PushStyleVar(ImGuiStyleVar_ItemSpacing, ImVec2{ 0, 0 });

	float lineHeight = GImGui->Font->FontSize + GImGui->Style.FramePadding.y * 2.0f;
	ImVec2 buttonSize = { lineHeight + 3.0f, lineHeight };

	ImGui::PushStyleColor(ImGuiCol_Button, ImVec4{ 0.8f, 0.1f, 0.15f, 1.0f });
	ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4{ 0.9f, 0.2f, 0.2f, 1.0f });
	ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4{ 0.8f, 0.1f, 0.15f, 1.0f });
	ImGui::PushFont(boldFont);
	if (ImGui::Button("X", buttonSize)) values[0] = resetValue;
	ImGui::PopFont();
	ImGui::PopStyleColor(3);

	ImGui::SameLine();
	ImGui::DragFloat("##X", &values[0], 0.1f, 0.0f, 0.0f, "%.2f");
	ImGui::PopItemWidth();
	ImGui::SameLine();

	ImGui::PushStyleColor(ImGuiCol_Button, ImVec4{ 0.2f, 0.7f, 0.2f, 1.0f });
	ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ImVec4{ 0.3f, 0.8f, 0.3f, 1.0f });
	ImGui::PushStyleColor(ImGuiCol_ButtonActive, ImVec4{ 0.2f, 0.7f, 0.2f, 1.0f });
	ImGui::PushFont(boldFont);
	if (ImGui::Button("Y", buttonSize)) values[1] = resetValue;
	ImGui::PopFont();
	ImGui::PopStyleColor(3);

	ImGui::SameLine();
	ImGui::DragFloat("##Y", &values[1], 0.1f, 0.0f, 0.0f, "%.2f");
	ImGui::PopItemWidth();
	ImGui::SameLine();

	ImGui::PopStyleVar();
	ImGui::Columns(1);

	ImGui::PopID();
}
