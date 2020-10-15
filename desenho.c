#include "declaracoes.h"

void desenha_inimigos(ALLEGRO_BITMAP* monstro_png[], ALLEGRO_BITMAP* jack_png, struct Personagem inimigos[], struct Personagem* jack, int level)
{
	if (level == 1)
	{
		inimigos[0].pos_x_sprite = (width / 2);   // dwarf 1
		inimigos[0].pos_y_sprite = (height - 180);  // dwarf 1

		inimigos[0].pos_x_sprite_2 = 500;   // dwarf 2
		inimigos[0].pos_y_sprite_2 = (height / 2);  // dwarf 2


		inimigos[2].pos_x_sprite = (width / 2) +  146;  // Esqueleto 1
		inimigos[2].pos_y_sprite = (height / 2) - 192;  // Esqueleto 1

		inimigos[2].pos_x_sprite_2 = (width / 2) - 380;  // Esqueleto 2
		inimigos[2].pos_y_sprite_2 = (height / 2) - 336;  // Esqueleto 2

		limite_inimigos(inimigos, level);

		// dwarf 1
		al_draw_scaled_bitmap(monstro_png[0],
			inimigos[0].x_folha, inimigos[0].y_folha,
			inimigos[0].largura_sprite, inimigos[0].altura_sprite,
			inimigos[0].pos_x_sprite, inimigos[0].pos_y_sprite,
			inimigos[0].largura_sprite_tela * inimigos[0].vivo_1[0], inimigos[0].altura_sprite_tela * inimigos[0].vivo_1[0], ALLEGRO_FLIP_HORIZONTAL);

		// dwarf 2
		al_draw_scaled_bitmap(monstro_png[0],
			inimigos[0].x_folha, inimigos[0].y_folha,
			inimigos[0].largura_sprite, inimigos[0].altura_sprite,
			inimigos[0].pos_x_sprite_2, inimigos[0].pos_y_sprite_2,
			inimigos[0].largura_sprite_tela * inimigos[0].vivo_2[0], inimigos[0].altura_sprite_tela * inimigos[0].vivo_2[0], 0);


		// esqueleto 1
		al_draw_scaled_bitmap(monstro_png[2],
			inimigos[2].x_folha, inimigos[2].y_folha,
			inimigos[2].largura_sprite, inimigos[2].altura_sprite,
			inimigos[2].pos_x_sprite, inimigos[2].pos_y_sprite,
			inimigos[2].largura_sprite_tela * inimigos[2].vivo_1[0], inimigos[2].altura_sprite_tela * inimigos[2].vivo_1[0], ALLEGRO_FLIP_HORIZONTAL);

		// esqueleto 2
		al_draw_scaled_bitmap(monstro_png[2],
			inimigos[2].x_folha, inimigos[2].y_folha,
			inimigos[2].largura_sprite, inimigos[2].altura_sprite,
			inimigos[2].pos_x_sprite_2, inimigos[2].pos_y_sprite_2,
			inimigos[2].largura_sprite_tela * inimigos[2].vivo_2[0], inimigos[2].altura_sprite_tela * inimigos[2].vivo_2[0], 0);
	}
	else if (level == 2)
	{
		inimigos[0].pos_x_sprite = (width / 2) + 186;   // Dwarf 1
		inimigos[0].pos_y_sprite = (height - 325);  // Dwarf 1
		

		inimigos[0].pos_x_sprite_2 = (width / 2) - 300;   // Dwarf 2
		inimigos[0].pos_y_sprite_2 = (height / 2) - 144;  // Dwarf 2

		inimigos[2].pos_x_sprite = (width / 2) + 80;  // Esqueleto 1
		inimigos[2].pos_y_sprite = (height / 2) - 336;  // Esqueleto 1
		

		inimigos[2].pos_x_sprite_2 = (width / 2) - 200;  // Esqueleto 2
		inimigos[2].pos_y_sprite_2 = (height / 2) - 432;  // Esqueleto 2

		limite_inimigos(inimigos, level);

		// Dwarf 1
		al_draw_scaled_bitmap(monstro_png[0],
			inimigos[0].x_folha, inimigos[0].y_folha,
			inimigos[0].largura_sprite, inimigos[0].altura_sprite,
			inimigos[0].pos_x_sprite , inimigos[0].pos_y_sprite ,
			inimigos[0].largura_sprite_tela * inimigos[0].vivo_1[1], inimigos[0].altura_sprite_tela * inimigos[0].vivo_1[1], ALLEGRO_FLIP_HORIZONTAL);

		// Dwarf 2
		al_draw_scaled_bitmap(monstro_png[0],
			inimigos[0].x_folha, inimigos[0].y_folha,
			inimigos[0].largura_sprite, inimigos[0].altura_sprite,
			inimigos[0].pos_x_sprite_2, inimigos[0].pos_y_sprite_2,
			inimigos[0].largura_sprite_tela * inimigos[0].vivo_2[1], inimigos[0].altura_sprite_tela * inimigos[0].vivo_2[1], 0);


		// Esqueleto 1
		al_draw_scaled_bitmap(monstro_png[2],
			inimigos[2].x_folha, inimigos[2].y_folha,
			inimigos[2].largura_sprite, inimigos[2].altura_sprite,
			inimigos[2].pos_x_sprite , inimigos[2].pos_y_sprite ,
			inimigos[2].largura_sprite_tela * inimigos[2].vivo_1[1], inimigos[2].altura_sprite_tela * inimigos[2].vivo_1[1], ALLEGRO_FLIP_HORIZONTAL);

		// Esqueleto 2
		al_draw_scaled_bitmap(monstro_png[2],
			inimigos[2].x_folha, inimigos[2].y_folha,
			inimigos[2].largura_sprite, inimigos[2].altura_sprite,
			inimigos[2].pos_x_sprite_2 , inimigos[2].pos_y_sprite_2 ,
			inimigos[2].largura_sprite_tela * inimigos[2].vivo_2[1], inimigos[2].altura_sprite_tela * inimigos[2].vivo_2[1], ALLEGRO_FLIP_HORIZONTAL);
	}
	else if (level == 3)
	{

		inimigos[1].pos_x_sprite = (width / 2) - 150;  // Minotauro
		inimigos[1].pos_y_sprite = (height) - 336;  // Minotauro

		jack->pos_x_sprite = (width / 2) + 250; // Jack
		jack->pos_y_sprite = (height) - 180; // Jack

		limite_inimigos(inimigos, level);

		// Minotauro
		al_draw_scaled_bitmap(monstro_png[1],
			inimigos[1].x_folha, inimigos[1].y_folha,
			inimigos[1].largura_sprite, inimigos[1].altura_sprite,
			inimigos[1].pos_x_sprite, inimigos[1].pos_y_sprite,
			inimigos[1].largura_sprite_tela* inimigos[1].vivo_1[2], inimigos[1].altura_sprite_tela* inimigos[1].vivo_1[2], ALLEGRO_FLIP_HORIZONTAL);

		// Jack
		al_draw_scaled_bitmap(jack_png,
			jack->x_folha, jack->y_folha,
			jack->largura_sprite, jack->altura_sprite,
			jack->pos_x_sprite, jack->pos_y_sprite,
			jack->largura_sprite_tela, jack->altura_sprite_tela, ALLEGRO_FLIP_HORIZONTAL);
	}

}

void desenha_elisabeth(ALLEGRO_BITMAP* elisabeth_png, struct Personagem* elisabeth, bool keys[], int DIRECAO)
{
	if (keys[DIRECAO])
			{
				// Boneco para um lado
				al_draw_scaled_bitmap(elisabeth_png,
					elisabeth->x_folha, elisabeth->y_folha,
					elisabeth->largura_sprite, elisabeth->altura_sprite,
					elisabeth->inicio_x + elisabeth->pos_x_sprite
					, elisabeth-> inicio_y + elisabeth->pos_y_sprite,
					elisabeth->largura_sprite_tela, elisabeth->altura_sprite_tela, 0);
			}
			else
			{
				// Boneco ao contrario
				al_draw_scaled_bitmap(elisabeth_png,
					elisabeth->x_folha, elisabeth->y_folha,
					elisabeth->largura_sprite, elisabeth->altura_sprite,
					elisabeth->inicio_x + elisabeth->pos_x_sprite
					, elisabeth->inicio_y + elisabeth->pos_y_sprite,
					elisabeth->largura_sprite_tela, elisabeth->altura_sprite_tela, ALLEGRO_FLIP_HORIZONTAL);
			}
}
