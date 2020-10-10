#include "declaracoes.h"

void error_msg(char* mensagem)
{
	al_show_native_message_box(NULL, "Mensagem de Erro",
		"Ocorreu o seguinte erro:", mensagem, NULL, ALLEGRO_MESSAGEBOX_ERROR);
}

void morte_inimigo(struct Sprite monstro[], struct Personagem secundario[], int indice)
{
	secundario[indice].altura_sprite = 0;
	secundario[indice].largura_sprite = 0;
}
