#include <Flip.h>

class Sandbox : public Flip::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Flip::Application* Flip::CreateApplication()
{
	return new Sandbox;
}