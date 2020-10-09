#include "declaracoes.h"

void error_msg(char *mensagem)
{
	al_show_native_message_box(NULL, "Mensagem de Erro",
		"Ocorreu o seguinte erro:", mensagem, NULL, ALLEGRO_MESSAGEBOX_ERROR);
}
void init_elisabeth(struct Sprite* elisabeth, struct Personagem* principal)
{
	principal->altura_sprite = 32;
	principal->largura_sprite = 32;
	principal->frames_sprite = 9;
	principal->pos_x_sprite = 200;
	principal->pos_y_sprite = height/2;
	principal->vel_x_sprite = 5;
	principal->vel_y_sprite = 8;
	principal->cont_frames = 0;
	elisabeth->coluna_atual = 0;
	elisabeth->linhas_folha = 0;
}


void animacao(struct Sprite* sprite, struct Personagem* beth_jack, int coluna_max, int linha_atual_2)
{
	beth_jack->cont_frames++;
	sprite->linha_atual = linha_atual_2;
	sprite->colunas_folha = coluna_max;
	sprite->regiao_y_folha = sprite->linha_atual * beth_jack->altura_sprite;

	if (beth_jack->cont_frames >= beth_jack->frames_sprite)
	{
		beth_jack->cont_frames = 0;

		sprite->coluna_atual++;

		if (sprite->coluna_atual >= sprite->colunas_folha)
		{
			sprite->coluna_atual = 0;
		}

		sprite->regiao_x_folha = sprite->coluna_atual * beth_jack->largura_sprite;
	}
	
}

void init_inimigos(struct Sprite monstro[], struct Personagem secundario[], int indice)
{

		if (indice == 0)
		{ 
			monstro[indice].coluna_atual = 0; // Ciclope
			monstro[indice].linhas_folha = 0; // Ciclop
			monstro[indice].regiao_x_folha = 0;
			monstro[indice].regiao_y_folha = 0;
			secundario[indice].altura_sprite = 32; // Ciclope
			secundario[indice].largura_sprite = 38; // Ciclope
			secundario[indice].frames_sprite = 8; // Ciclope
			secundario[indice].vel_x_sprite = 5; // Ciclope
			secundario[indice].vel_y_sprite = 8; // Ciclope
			secundario[indice].cont_frames = 0; // Ciclope
		
		}
		else
		{
			monstro[indice].coluna_atual = 0; // Minotauro
			monstro[indice].linhas_folha = 0; // Minotauro
			monstro[indice].regiao_x_folha = 0;
			monstro[indice].regiao_y_folha = 0;
			secundario[indice].altura_sprite = 96; // Minotauro
			secundario[indice].largura_sprite = 96; // Minotauro
			secundario[indice].frames_sprite = 8; // Minotauro
			secundario[indice].vel_x_sprite = 5; // Minotauro
			secundario[indice].vel_y_sprite = 8; // Minotauro
			secundario[indice].cont_frames = 0; // Minotauro
		}


}
void animacao2(struct Sprite sprite[], struct Personagem inimigo[], int coluna_max, int linha_atual_2, int indice)
{
	if (indice == 0)
	{
		inimigo[indice].cont_frames++;
		sprite[indice].linha_atual = linha_atual_2;
		sprite[indice].colunas_folha = coluna_max;
		sprite[indice].regiao_y_folha = sprite[indice].linha_atual * inimigo[indice].altura_sprite;

		if (inimigo[indice].cont_frames >= inimigo[indice].frames_sprite)
		{
			inimigo[indice].cont_frames = 0;

			sprite[indice].coluna_atual++;

			if (sprite[indice].coluna_atual >= sprite[indice].colunas_folha)
			{
				sprite[indice].coluna_atual = 0;
			}

			sprite[indice].regiao_x_folha = sprite[indice].coluna_atual * inimigo[indice].largura_sprite;
		}
	}
	else
	{
		inimigo[indice].cont_frames++;
		sprite[indice].linha_atual = linha_atual_2;
		sprite[indice].colunas_folha = coluna_max;
		sprite[indice].regiao_y_folha = sprite[indice].linha_atual * inimigo[indice].altura_sprite;

		if (inimigo[indice].cont_frames >= inimigo[indice].frames_sprite)
		{
			inimigo[indice].cont_frames = 0;

			sprite[indice].coluna_atual++;

			if (sprite[indice].coluna_atual >= sprite[indice].colunas_folha)
			{
				sprite[indice].coluna_atual = 0;
			}

			sprite[indice].regiao_x_folha = sprite[indice].coluna_atual * inimigo[indice].largura_sprite;
		}
	}

}
void desenha_inimigo(ALLEGRO_BITMAP* sprite_monstro[], struct Sprite monstro[], struct Personagem secundario[], int pos_x, int pos_y, int indice)
{
	if (indice == 0)
	{
		printf("passei aqui");
		al_draw_scaled_bitmap(sprite_monstro[indice],
			monstro[indice].regiao_x_folha, monstro[indice].regiao_y_folha,
			secundario[indice].largura_sprite, secundario[indice].altura_sprite,
			pos_x + secundario[indice].largura_sprite, pos_y,
			secundario[indice].largura_sprite + 80, secundario[indice].altura_sprite + 80, 0);
	}
	else if (indice == 1)
	{
		printf("passei aqui tbm");
		al_draw_scaled_bitmap(sprite_monstro[indice],
			monstro[indice].regiao_x_folha, monstro[indice].regiao_y_folha,
			secundario[indice].largura_sprite, secundario[indice].altura_sprite,
			pos_x + secundario[indice].largura_sprite, pos_y,
			secundario[indice].largura_sprite, secundario[indice].altura_sprite + pos_y, 0);
	}
}