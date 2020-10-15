#include "declaracoes.h"

// Ainda sera utilizado
bool colisao_personagens(struct Personagem* elisabeth, struct Personagem inimigos[], int indice, int level, bool keys[], int ATAQUE)
{
    if (elisabeth->vidas_1 == 0)
    {
        return true;
    }
    else
    {
        // Se o inimigo estiver vivo na respectiva fase
        if (inimigos[indice].vivo_1[level - 1] == 1)
        {
            if (elisabeth->hitbox.x1 > inimigos[indice].hitbox.x0 &&
                elisabeth->hitbox.x0 < inimigos[indice].hitbox.x1 &&
                elisabeth->hitbox.y1 > inimigos[indice].hitbox.y0 &&
                elisabeth->hitbox.y0 < inimigos[indice].hitbox.y1)
            {
                if (keys[ATAQUE])
                {
                    inimigos[indice].vidas_1--;
                    if (inimigos[indice].vidas_1 == 0)
                    {
                        inimigos[indice].vivo_1[level - 1] = 0;
                    }
                }
                // Se não estiver
                else
                {
                    elisabeth->vidas_1--;
                    
                    inimigos[indice].vidas_1--;
                    if (inimigos[indice].vidas_1 == 0)
                    {
                        inimigos[indice].vivo_1[level - 1] = 0;
                    }
                }
            }
                
        }
        if (inimigos[indice].vivo_2[level - 1] == 1)
        {
            if (elisabeth->hitbox.x1 > inimigos[indice].hitbox.x2 &&
                elisabeth->hitbox.x0 < inimigos[indice].hitbox.x3 &&
                elisabeth->hitbox.y1 > inimigos[indice].hitbox.y2 &&
                elisabeth->hitbox.y0 < inimigos[indice].hitbox.y3)
            {
                // Se estiver atacando
                if (keys[ATAQUE])
                {
                    inimigos[indice].vidas_2--;
                    if (inimigos[indice].vidas_2 == 0)
                    {
                        inimigos[indice].vivo_2[level - 1] = 0;
                    }
                }
                // Se não estiver
                else
                {
                    elisabeth->vidas_1--;
                    inimigos[indice].vidas_2--;
                    if (inimigos[indice].vidas_2 == 0)
                    {
                        inimigos[indice].vivo_2[level - 1] = 0;
                    }
                }
            }
        }        
        return false;
    }
}

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

void limite_elisabeth(struct Personagem* elisabeth)
{
    elisabeth->hitbox.x0 = elisabeth->inicio_x + elisabeth->pos_x_sprite + 20;
    elisabeth->hitbox.x1 = elisabeth->inicio_x + elisabeth->largura_sprite_tela + elisabeth->pos_x_sprite - 35;
    elisabeth->hitbox.y0 = elisabeth->inicio_y + elisabeth->pos_y_sprite + 35;
    elisabeth->hitbox.y1 = elisabeth->inicio_y + elisabeth->altura_sprite_tela + elisabeth->pos_y_sprite;
}

void limite_inimigos(struct Personagem inimigos[], int level)
{
    if (level == 3)
    {
        // Hitbox Fixo Minotauro 
        inimigos[1].hitbox.x0 = inimigos[1].pos_x_sprite + 120;
        inimigos[1].hitbox.x1 = inimigos[1].pos_x_sprite + inimigos[1].largura_sprite_tela - 110;
        inimigos[1].hitbox.y0 = inimigos[1].pos_y_sprite + 95;
        inimigos[1].hitbox.y1 = inimigos[1].pos_y_sprite + inimigos[1].altura_sprite_tela - 120;
    }

    else
    {
        // Hitbox Fixo Dwarf 1
        inimigos[0].hitbox.x0 = inimigos[0].pos_x_sprite + 40;
        inimigos[0].hitbox.x1 = inimigos[0].pos_x_sprite + inimigos[0].largura_sprite_tela - 25;
        inimigos[0].hitbox.y0 = inimigos[0].pos_y_sprite + 30;
        inimigos[0].hitbox.y1 = inimigos[0].pos_y_sprite + inimigos[0].altura_sprite_tela + 5;

        // Hitbox Fixo Dwarf 2
        inimigos[0].hitbox.x2 = inimigos[0].pos_x_sprite_2 + 40;
        inimigos[0].hitbox.x3 = inimigos[0].pos_x_sprite_2 + inimigos[0].largura_sprite_tela - 25;
        inimigos[0].hitbox.y2 = inimigos[0].pos_y_sprite_2 + 30;
        inimigos[0].hitbox.y3 = inimigos[0].pos_y_sprite_2 + inimigos[0].altura_sprite_tela + 5;

        // Hitbox Fixo Esqueleto 1
        inimigos[2].hitbox.x0 = inimigos[2].pos_x_sprite + 85;
        inimigos[2].hitbox.x1 = inimigos[2].pos_x_sprite + inimigos[2].largura_sprite_tela - 80;
        inimigos[2].hitbox.y0 = inimigos[2].pos_y_sprite + 70;
        inimigos[2].hitbox.y1 = inimigos[2].pos_y_sprite + inimigos[2].altura_sprite_tela - 105;

        // Hitbox Fixo Esqueleto 2
        inimigos[2].hitbox.x2 = inimigos[2].pos_x_sprite_2 + 85;
        inimigos[2].hitbox.x3 = inimigos[2].pos_x_sprite_2 + inimigos[2].largura_sprite_tela - 80;
        inimigos[2].hitbox.y2 = inimigos[2].pos_y_sprite_2 + 70;
        inimigos[2].hitbox.y3 = inimigos[2].pos_y_sprite_2 + inimigos[2].altura_sprite_tela - 105;
    }

}
