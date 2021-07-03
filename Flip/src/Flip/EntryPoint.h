#pragma once

#ifdef FP_PLATFORM_WINDOWS

extern Flip::Application* Flip::CreateApplication();

int main(int argc, char** argv)
{
	Flip::Log::Init();
	//Flip::Log::GetCoreLogger()->warn("Initialized Log!");
	//Flip::Log::GetClientLogger()->info("Initialized Log!");

	FP_CORE_WARN("Initialized Log!");
	FP_INFO("Initialized Log!");

	auto app = Flip::CreateApplication();
	app->Run();
	delete app;
}

#endif