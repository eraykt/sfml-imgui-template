#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp> 
#include <SFML/System.hpp>
#include <imgui.h> 
#include <imgui-SFML.h>

int main()
{
	sf::Event event;
	sf::Clock clock;
	sf::Time deltaTime;
	sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "Window", sf::Style::Default);
	ImGui::SFML::Init(window);

	while (window.isOpen())
	{
		deltaTime = clock.restart();
		while (window.pollEvent(event))
		{
			ImGui::SFML::ProcessEvent(window, event);
			if (event.type = sf::Event::Closed)
			{
				window.close();
			}
		}

		ImGui::SFML::Update(window, deltaTime);
		window.clear();

		if (ImGui::Begin("Example Window"))
		{
			ImGui::Text("Hello");
			ImGui::End();
		}

		ImGui::SFML::Render(window);
		window.display();
	}
	return 0;

}