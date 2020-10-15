#include "declaracoes.h"

void animacao_beth_jack(struct Personagem* beth_jack, int acao, bool jack)
{
	beth_jack->animacao[acao].frames_min++;

	beth_jack->y_folha = beth_jack->animacao[acao].lin_atual * beth_jack->altura_sprite;

	if (beth_jack->animacao[acao].frames_min >= beth_jack->animacao[acao].frames_max)
	{
		beth_jack->animacao[acao].frames_min = 0;
		beth_jack->animacao[acao].col_atual++;

		if (beth_jack->animacao[acao].col_atual >= beth_jack->animacao[acao].col_folha)
		{
			// Animação do jack é diferente
			if (jack)
			{
				beth_jack->animacao[acao].col_atual = beth_jack->animacao[acao].col_atual_old;
			}
			else
			{
				beth_jack->animacao[acao].col_atual = 0;
			}
		}

		beth_jack->x_folha = beth_jack->animacao[acao].col_atual * beth_jack->largura_sprite;
	}
}

void animacao_inimigos(struct Personagem inimigos[], int acao, int indice)
{

	inimigos[indice].animacao[acao].frames_min++;
	inimigos[indice].y_folha = inimigos[indice].animacao[acao].lin_atual * inimigos[indice].altura_sprite;

		if (inimigos[indice].animacao[acao].frames_min >= inimigos[indice].animacao[acao].frames_max)
		{

			inimigos[indice].animacao[acao].frames_min = 0;
			inimigos[indice].animacao[acao].col_atual++;

			if (inimigos[indice].animacao[acao].col_atual >= inimigos[indice].animacao[acao].col_folha)
			{
				// Animação do Esqueleto e diferente por conta da folha de sprites ter apenas uma linha
				if (inimigos[indice].animacao[acao].esqueleto)
				{
					inimigos[indice].animacao[acao].col_atual = inimigos[indice].animacao[acao].col_atual_old;
				}
				else
				{
					inimigos[indice].animacao[acao].col_atual = 0;
				}
			}

			inimigos[indice].x_folha = inimigos[indice].animacao[acao].col_atual * inimigos[indice].largura_sprite;
		}

}
