#include "declaracoes.h"

void error_msg(char *mensagem)
{
	al_show_native_message_box(NULL, "Mensagem de Erro",
		"Ocorreu o seguinte erro:", mensagem, NULL, ALLEGRO_MESSAGEBOX_ERROR);
}
void init_mulher(struct Sprite* mulher, struct Personagem* principal)
{
	principal->altura_sprite = 32;
	principal->largura_sprite = 32;
	principal->frames_sprite = 5;
	principal->pos_x_sprite = 50;
	principal->pos_y_sprite = 150;
	principal->vel_x_sprite = 5;
	principal->vel_y_sprite = 2;
	principal->cont_frames = 0;
	mulher->regiao_x_folha = 0;
	mulher->regiao_y_folha = 0;
	mulher->colunas_folha = 6;
	mulher->coluna_atual = 0;
	mulher->linhas_folha = 1;
	mulher->linha_atual = 0;
}


void sprites(struct Sprite* mulher, struct Personagem* principal)
{
	principal->cont_frames++;
	if (principal->cont_frames >= principal->frames_sprite)
	{
		principal->cont_frames = 0;

		mulher->coluna_atual++;

		if (mulher->coluna_atual >= mulher->colunas_folha)
		{
			mulher->coluna_atual = 0;

			mulher->linha_atual = (mulher->linha_atual + 1) % mulher->linhas_folha;

			mulher->regiao_y_folha = mulher->linha_atual * principal->altura_sprite;
		}

		mulher->regiao_x_folha = mulher->coluna_atual * principal->largura_sprite;
	}
	if (principal->pos_x_sprite + principal->largura_sprite > 800 - 20 || principal->pos_x_sprite < 20)
	{
		principal->vel_x_sprite = -principal->vel_x_sprite;
	}
}