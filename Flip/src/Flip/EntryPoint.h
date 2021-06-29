#pragma once

#ifdef FP_PLATFORM_WINDOWS

extern Flip::Application* Flip::CreateApplication();

int  main(int argc, char** argv)
{
	auto app = Flip::CreateApplication();
	app->Run();
	delete app;
}

#endif