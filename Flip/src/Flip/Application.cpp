#include "fppch.h"
#include "Application.h"

#include "Flip/Events/ApplicationEvent.h"
#include "Flip/Log.h"

namespace Flip
{

	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			FP_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			FP_TRACE(e);
		}

	}
}