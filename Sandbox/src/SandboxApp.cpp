#include <Flip.h>

class ExampleLayer : public Flip::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		FP_INFO("ExampleLayer::Update");
	}

	void OnEvent(Flip::Event& event) override
	{
		FP_TRACE("{0}", event);
	}

};

class Sandbox : public Flip::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
	}

	~Sandbox()
	{

	}
};

Flip::Application* Flip::CreateApplication()
{
	return new Sandbox;
}