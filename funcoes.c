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
	principal->frames_sprite = 10;
	principal->pos_x_sprite = 200;
	principal->pos_y_sprite = height/2;
	principal->vel_x_sprite = 5;
	principal->vel_y_sprite = 8;
	principal->cont_frames = 0;
	mulher->regiao_x_folha = 0;
	mulher->regiao_y_folha = 0;
	mulher->colunas_folha = 6;
	mulher->coluna_atual = 0;
	mulher->linhas_folha = 1;
	mulher->linha_atual = 0;
}
void animacao(struct Sprite* padrao, struct Personagem* qualquer, int coluna_acao, int linha_acao, int linha_atual2, int coluna_atual2)
{
	qualquer->cont_frames++;
	padrao->linha_atual = linha_atual2;
	padrao->colunas_folha = coluna_acao;
	padrao->linhas_folha = linha_acao;
	padrao->regiao_y_folha = padrao->linha_atual * qualquer->altura_sprite;

	if (qualquer->cont_frames >= qualquer->frames_sprite)
	{
		qualquer->cont_frames = 0;

		padrao->coluna_atual++;

		if (padrao->coluna_atual >= padrao->colunas_folha)
		{
			padrao->coluna_atual = 0;
		}

		padrao->regiao_x_folha = padrao->coluna_atual * qualquer->largura_sprite;
	}

}
void InitCenario(struct Cenario *mapa){
    mapa->MapaColuna = 21;
    mapa->MapaTam = 315;
    mapa->BlocoTam = 32;
}
