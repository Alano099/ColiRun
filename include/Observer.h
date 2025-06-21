#pragma once

#include "Subject.h"

#include <SFML/Graphics.hpp>

namespace Observers
{
	class Observer
	{
	protected:
		Gerenciadores::Subject* pSubject;

	public:
		Observer();
		virtual ~Observer();

		virtual void notifyPressed(std::string key) = 0;

		virtual void notifyReleased(std::string key) = 0;
	};
}