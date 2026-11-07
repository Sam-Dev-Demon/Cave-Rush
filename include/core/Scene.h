#pragma once
#include <optional>

class Scene
{
	public:
		Scene();
		virtual ~Scene() = 0;
		virtual void input(std::optional & event);
		virtual void process(
};