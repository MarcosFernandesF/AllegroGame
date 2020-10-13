#include "declaracoes.h"

void colisao_personagens(struct Personagem* elisabeth, struct Personagem inimigos[], int indice)
{
	if (inimigos[indice].vivo == 1)
	{
		if (indice == 0)
		{
			/*if (elisabeth->inicio_x + elisabeth->largura_sprite_tela + elisabeth->pos_x_sprite - 30
		> inimigos[indice].pos_x_sprite + 30 && elisabeth->inicio_x < inimigos[indice].pos_x_sprite + inimigos[indice].largura_sprite_tela
				&& elisabeth->inicio_y + elisabeth->altura_sprite_tela > inimigos[indice].pos_y_sprite + 30 &&
				elisabeth->inicio_y + 30 < inimigos[indice].pos_y_sprite + inimigos[indice].altura_sprite_tela);*/
			if (elisabeth->inicio_x + elisabeth->largura_sprite_tela + elisabeth->pos_x_sprite - 30
		> (width / 2) - 100 && elisabeth->inicio_x < width / 2 
				&& elisabeth->inicio_y + elisabeth->altura_sprite_tela > height - 180 &&
				elisabeth->inicio_y + 30 < height - 80)
			{
				elisabeth->vidas_1--;
			}
		}
	}
}
