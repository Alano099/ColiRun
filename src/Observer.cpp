#include "../include/Observer.h"

namespace Observers {
    Observer::Observer()
    {
		this->pSubject = Gerenciadores::Subject::get_instance();
		pSubject->attach(this);
    }

    Observer::~Observer()
    {
        pSubject->detach(this);
    }
}