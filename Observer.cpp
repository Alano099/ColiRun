#include "Observer.h"

namespace Observers {
    Observer::Observer()
    {
        this->pGE = Gerenciadores::Gerenciador_Eventos::get_instance();
        this->pEG = Gerenciadores::Gerenciador_Estado::get_instance();
        this->pGG = Gerenciadores::Gerenciador_Grafico::get_instance();
    }

    Observer::~Observer()
    {
        pGE->detach(this);
    }
}