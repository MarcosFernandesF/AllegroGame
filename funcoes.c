
#include "declaracoes.h"

void error_msg(char* mensagem)
{
	al_show_native_message_box(NULL, "Mensagem de Erro",
		"Ocorreu o seguinte erro:", mensagem, NULL, ALLEGRO_MESSAGEBOX_ERROR);
}

void InitCenario(struct Cenario *mapa){
    mapa->MapaColuna = 21;
    mapa->MapaTam = 315;
    mapa->BlocoTam = 32;
}
