#include "declaracoes.h"

// Ainda sera utilizado
/*void colisao_personagens(struct Personagem* elisabeth, struct Personagem inimigos[], int indice)
{
	if (inimigos[indice].vivo == 1)
	{
		if (indice == 0)
		{
			 if (elisabeth->inicio_x + elisabeth->largura_sprite_tela + elisabeth->pos_x_sprite - 30
				> (width / 2) - 100 && elisabeth->inicio_x + elisabeth->pos_x_sprite < width / 2
				&& elisabeth->inicio_y + elisabeth->altura_sprite_tela + elisabeth->pos_y_sprite > height - 180 &&
				elisabeth->inicio_y + 30 + elisabeth->pos_y_sprite < height - 80)
			{
				elisabeth->vidas_1--;
			}
		}
	}
}*/

int colisao_blocos(struct Personagem* elisabeth, int caindo, int level)
{
    int chaoy = 675; // Chao fixo
    int nBloco = 48; // Tamanho do bloco

    if(elisabeth->inicio_y + elisabeth->pos_y_sprite + elisabeth->altura_sprite + 80 >= chaoy)//Chao dos mapas
        {
            caindo=0;
        }

        switch (level){
        case 1: // MAPA 1
            // Escada no canto direito
            if((elisabeth->inicio_y + elisabeth->pos_y_sprite + elisabeth->altura_sprite + 80 >= chaoy-nBloco &&
                elisabeth->inicio_x + elisabeth->pos_x_sprite + elisabeth->largura_sprite - 30 >= 760) ||
               (elisabeth->inicio_y + elisabeth->pos_y_sprite + elisabeth->altura_sprite + 80 >= chaoy-(nBloco*2) &&
                elisabeth->inicio_x + elisabeth->pos_x_sprite + elisabeth->largura_sprite - 30 >= 808) ||
               (elisabeth->inicio_y + elisabeth->pos_y_sprite + elisabeth->altura_sprite + 80 >= chaoy-(nBloco*3) &&
                elisabeth->inicio_x + elisabeth->pos_x_sprite + elisabeth->largura_sprite - 30 >= 856) ||
               (elisabeth->inicio_y + elisabeth->pos_y_sprite + elisabeth->altura_sprite + 80 >= chaoy-(nBloco*4) &&
                elisabeth->inicio_x + elisabeth->pos_x_sprite + elisabeth->largura_sprite - 30 >= 904))
            {
                caindo=0;
            }
            // Primeira plataforma
            if (elisabeth->inicio_y + elisabeth->pos_y_sprite + elisabeth->altura_sprite + 80 >= chaoy-(nBloco*4) &&
                elisabeth->inicio_x + elisabeth->pos_x_sprite + elisabeth->largura_sprite - 30 <= 760 &&
                elisabeth->inicio_y + elisabeth->pos_y_sprite + elisabeth->altura_sprite + 80 <= chaoy-(nBloco*3))
            {
                caindo=0;
            }
            // Bloco em cima da plataforma
            if (elisabeth->inicio_y + elisabeth->pos_y_sprite + elisabeth->altura_sprite + 80 >= chaoy-(nBloco*5) &&
                elisabeth->inicio_x + elisabeth->pos_x_sprite + elisabeth->largura_sprite - 30 >= 376 &&
                elisabeth->inicio_y + elisabeth->pos_y_sprite + elisabeth->altura_sprite + 80 <= chaoy-(nBloco*4) &&
                elisabeth->inicio_x + elisabeth->pos_x_sprite + elisabeth->largura_sprite - 30 <= 424)
            {
                caindo=0;
            }
            // Segunda plataforma
            if (elisabeth->inicio_y + elisabeth->pos_y_sprite + elisabeth->altura_sprite + 80 >= chaoy-(nBloco*7) &&
                elisabeth->inicio_x + elisabeth->pos_x_sprite + elisabeth->largura_sprite - 30 >= 472 &&
                elisabeth->inicio_y + elisabeth->pos_y_sprite + elisabeth->altura_sprite + 80 <= chaoy-(nBloco*6))
            {
                caindo=0;
            }
            // Plataforma flutuante
            if (elisabeth->inicio_y + elisabeth->pos_y_sprite + elisabeth->altura_sprite + 80 >= chaoy-(nBloco*9) &&
                elisabeth->inicio_x + elisabeth->pos_x_sprite + elisabeth->largura_sprite - 30 >= 376 &&
                elisabeth->inicio_y + elisabeth->pos_y_sprite + elisabeth->altura_sprite + 80 <= chaoy-(nBloco*8) &&
                elisabeth->inicio_x + elisabeth->pos_x_sprite + elisabeth->largura_sprite - 30 <= 472)
            {
                caindo=0;
            }
            // Terceira plataforma
            if (elisabeth->inicio_y + elisabeth->pos_y_sprite + elisabeth->altura_sprite + 80 >= chaoy-(nBloco*10) &&
                elisabeth->inicio_x + elisabeth->pos_x_sprite + elisabeth->largura_sprite - 30 <= 328 &&
                elisabeth->inicio_y + elisabeth->pos_y_sprite + elisabeth->altura_sprite + 80 <= chaoy-(nBloco*9))
            {
                caindo=0;
            }
            // Quarta plataforma
            if (elisabeth->inicio_y + elisabeth->pos_y_sprite + elisabeth->altura_sprite + 80 >= chaoy-(nBloco*12) &&
                elisabeth->inicio_x + elisabeth->pos_x_sprite + elisabeth->largura_sprite - 30 >= 376 &&
                elisabeth->inicio_y + elisabeth->pos_y_sprite + elisabeth->altura_sprite + 80 <= chaoy-(nBloco*11))
            {
                caindo=0;
            }
            break;
        case 2: // MAPA 2
            //Primeira plataforma
            if (elisabeth->inicio_y + elisabeth->pos_y_sprite + elisabeth->altura_sprite + 80 >= chaoy-(nBloco*12) &&
                elisabeth->inicio_x + elisabeth->pos_x_sprite + elisabeth->largura_sprite - 30 <= 520 &&
                elisabeth->inicio_y + elisabeth->pos_y_sprite + elisabeth->altura_sprite + 80 <= chaoy-(nBloco*11))
            {
                caindo=0;
            }
            //Plataforma flutuante 1
             if (elisabeth->inicio_y + elisabeth->pos_y_sprite + elisabeth->altura_sprite + 80 >= chaoy-(nBloco*10) &&
                elisabeth->inicio_x + elisabeth->pos_x_sprite + elisabeth->largura_sprite - 30 >= 568 &&
                elisabeth->inicio_y + elisabeth->pos_y_sprite + elisabeth->altura_sprite + 80 <= chaoy-(nBloco*9) &&
                elisabeth->inicio_x + elisabeth->pos_x_sprite + elisabeth->largura_sprite - 30 <= 664)
            {
                caindo=0;
            }
            //Plataforma flutuante 2
             if (elisabeth->inicio_y + elisabeth->pos_y_sprite + elisabeth->altura_sprite + 80 >= chaoy-(nBloco*9) &&
                elisabeth->inicio_x + elisabeth->pos_x_sprite + elisabeth->largura_sprite - 30 >= 376 &&
                elisabeth->inicio_y + elisabeth->pos_y_sprite + elisabeth->altura_sprite + 80 <= chaoy-(nBloco*8) &&
                elisabeth->inicio_x + elisabeth->pos_x_sprite + elisabeth->largura_sprite - 30 <= 520)
            {
                caindo=0;
            }
            //Plataforma flutuante 3
            if (elisabeth->inicio_y + elisabeth->pos_y_sprite + elisabeth->altura_sprite + 80 >= chaoy-(nBloco*7) &&
                elisabeth->inicio_x + elisabeth->pos_x_sprite + elisabeth->largura_sprite - 30 >= 88 &&
                elisabeth->inicio_y + elisabeth->pos_y_sprite + elisabeth->altura_sprite + 80 <= chaoy-(nBloco*6) &&
                elisabeth->inicio_x + elisabeth->pos_x_sprite + elisabeth->largura_sprite - 30 <= 328)
            {
                caindo=0;
            }
            //Plataforma flutuante 4
            if (elisabeth->inicio_y + elisabeth->pos_y_sprite + elisabeth->altura_sprite + 80 >= chaoy-(nBloco*5) &&
                elisabeth->inicio_x + elisabeth->pos_x_sprite + elisabeth->largura_sprite - 30 >= 376 &&
                elisabeth->inicio_y + elisabeth->pos_y_sprite + elisabeth->altura_sprite + 80 <= chaoy-(nBloco*4) &&
                elisabeth->inicio_x + elisabeth->pos_x_sprite + elisabeth->largura_sprite - 30 <= 568)
            {
                caindo=0;
            }
            //Plataforma flutuante 5
            if (elisabeth->inicio_y + elisabeth->pos_y_sprite + elisabeth->altura_sprite + 80 >= chaoy-(nBloco*3) &&
                elisabeth->inicio_x + elisabeth->pos_x_sprite + elisabeth->largura_sprite - 30 >= 616 &&
                elisabeth->inicio_y + elisabeth->pos_y_sprite + elisabeth->altura_sprite + 80 <= chaoy-(nBloco*2) &&
                elisabeth->inicio_x + elisabeth->pos_x_sprite + elisabeth->largura_sprite - 30 <= 760)
            {
                caindo=0;
            }
            break;
        }
    return caindo;
}
