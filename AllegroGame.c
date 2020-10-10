#include "declaracoes.h"

const int FPS = 60;
enum keys { PULO, ESQUERDA, DIREITA, ESPACO, DIRECAO, GRAVIDADE};
bool keys[6] = { false ,false , false, false, true, false };

ALLEGRO_DISPLAY* display = NULL;
ALLEGRO_EVENT_QUEUE* fila_eventos = NULL;
ALLEGRO_TIMER* timer = NULL;
ALLEGRO_BITMAP* folha_sprites = NULL;
ALLEGRO_BITMAP* fundo = NULL;
ALLEGRO_BITMAP* folha_bloco = NULL;

int mapa1[] = {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
                     5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
                     5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
                     5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
                     3, 3, 3, 3, 3, 3, 3, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
                     5, 5, 5, 5, 5, 5, 5, 5, 5, 2, 3, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5,
                     5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
                     5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 2, 3, 3, 3, 3, 3, 3, 3, 3,
                     1, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
                     1, 1, 5, 5, 5, 5, 5, 5, 5, 1, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
                     3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 5, 5, 5, 5, 1,
                     5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 1, 1,
                     5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 1, 1, 1,
                     5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 1, 1, 1, 1,
                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int mapa2[] = {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
                     5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
                     5, 5, 5, 5, 5, 5, 5, 5, 5, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
                     5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
                     5, 5, 5, 5, 5, 5, 2, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
                     5, 5, 5, 5, 5, 5, 5, 5, 5, 2, 3, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5,
                     5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
                     5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 2, 3, 3, 3, 4, 5, 5, 5,
                     5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
                     5, 5, 5, 5, 5, 5, 5, 5, 2, 3, 3, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5,
                     5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
                     5, 5, 5, 5, 2, 3, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
                     5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
                     5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int mapa3[] = {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
                     5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
                     5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
                     5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
                     5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
                     5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
                     5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
                     5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
                     5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
                     5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
                     5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
                     5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
                     5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
                     5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int main()
{
	bool redraw = true;
	bool done = false;
	int level=1;

    struct Cenario mapa;
	struct Sprite mulher;
	struct Personagem principal;

	init_mulher(&mulher, &principal);
	InitCenario(&mapa);

	if (inicializar() != 1)
	{
		error_msg("Falha ao inicializar o jogo");
		return -1;
	}

	while (!done)
	{
		ALLEGRO_EVENT evento;
		al_wait_for_event(fila_eventos, &evento);
		bool parado = true;
		int pos_y_atual = 0;

		if (evento.type == ALLEGRO_EVENT_TIMER)
		{
			redraw = true;

			if (parado)
			{
				animacao(&mulher, &principal, 6, 0, 0, 0);
			}

			if (keys[PULO])
			{
				int col_acao = 8, linha_acao = 1, linha_atual2 = 1, col_atual2 = 1;
				parado = false;
				animacao(&mulher, &principal, 8, 1, 1, 1);
				principal.pos_y_sprite -= principal.vel_y_sprite;
				pos_y_atual = principal.pos_y_sprite;
				keys[GRAVIDADE] = true;
			}
			if (!keys[PULO])
			{
				principal.pos_y_sprite += principal.vel_y_sprite;
				if (pos_y_atual <= height / 2)
					principal.pos_y_sprite = height / 2;
			}

			if (keys[ESQUERDA])
			{
				int col_acao = 8, linha_acao = 1, linha_atual2 = 1, col_atual2 = 1;
				parado = false;
				keys[DIRECAO]= false;
				animacao(&mulher, &principal, col_acao, col_atual2, linha_acao, linha_atual2);
				principal.pos_x_sprite -= principal.vel_x_sprite;
			}
			if (keys[DIREITA])
			{
				parado = false;
				keys[DIRECAO] = true;
				int col_acao = 8, linha_acao = 1, linha_atual2 = 1, col_atual2 = 1;
				animacao(&mulher, &principal, col_acao, col_atual2, linha_acao, linha_atual2);
				principal.pos_x_sprite += principal.vel_x_sprite;
			}

			if (keys[ESPACO])
			{
				printf("oi");
			}
		}

		else if (evento.type == ALLEGRO_EVENT_KEY_DOWN)
		{
			switch (evento.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				done = true;
				break;
			case ALLEGRO_KEY_UP:
				keys[PULO] = true;
				break;
			case ALLEGRO_KEY_LEFT:
				keys[ESQUERDA] = true;
				break;
			case ALLEGRO_KEY_RIGHT:
				keys[DIREITA] = true;
				break;
			case ALLEGRO_KEY_SPACE:
				keys[ESPACO] = true;
				break;
			}
		}
		else if (evento.type == ALLEGRO_EVENT_KEY_UP)
		{
			switch (evento.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				done = true;
				break;
			case ALLEGRO_KEY_UP:
				keys[PULO] = false;
				break;
			case ALLEGRO_KEY_LEFT:
				keys[ESQUERDA] = false;
				break;
			case ALLEGRO_KEY_RIGHT:
				keys[DIREITA] = false;
				break;
			case ALLEGRO_KEY_SPACE:
				keys[ESPACO] = false;
				break;
			}
		}
		else if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_DOWN)
		{
			if (evento.mouse.x <= width && evento.mouse.x >= 0 &&
				evento.mouse.y <= height && evento.mouse.y >= 0)
				printf("click");
		}
		else if (evento.type == ALLEGRO_EVENT_MOUSE_BUTTON_UP)
		{
			if (evento.mouse.x <= width && evento.mouse.x >= 0 &&
				evento.mouse.y <= height && evento.mouse.y >= 0)
				printf("click");
		}

		else if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			done = true;
		}

		if (redraw && al_is_event_queue_empty(fila_eventos))
		{
			redraw = false;

			al_draw_scaled_bitmap(fundo, 0, 0, 576, 324, 0, 0,width,height, 0);

			switch(level){
        case 1:
            for (int i = 0; i<mapa.MapaTam; i++)
            {
                al_draw_scaled_bitmap(folha_bloco, (mapa.BlocoTam) * (mapa1[i]), 0, mapa.BlocoTam, mapa.BlocoTam,
                ((mapa.BlocoTam)+((mapa.BlocoTam)/2)) * (i%(mapa.MapaColuna)), ((mapa.BlocoTam)+((mapa.BlocoTam)/2)) * (i/(mapa.MapaColuna)),
                 (mapa.BlocoTam)+((mapa.BlocoTam)/2), (mapa.BlocoTam)+((mapa.BlocoTam)/2), 0);
			}
			if(principal.pos_y_sprite<0 && principal.pos_x_sprite<0){
              level++;}
              break;
        case 2:
			for (int j = 0; j<mapa.MapaTam; j++)
            {
                al_draw_scaled_bitmap(folha_bloco, (mapa.BlocoTam) * (mapa2[j]), 0, mapa.BlocoTam, mapa.BlocoTam,
                ((mapa.BlocoTam)+((mapa.BlocoTam)/2)) * (j%(mapa.MapaColuna)), ((mapa.BlocoTam)+((mapa.BlocoTam)/2)) * (j/(mapa.MapaColuna)),
                 (mapa.BlocoTam)+((mapa.BlocoTam)/2), (mapa.BlocoTam)+((mapa.BlocoTam)/2), 0);
			}
			if(principal.pos_y_sprite<0 && principal.pos_x_sprite>1000){
              level++;}
			break;
        case 3:
            for (int i = 0; i<mapa.MapaTam; i++)
            {
                al_draw_scaled_bitmap(folha_bloco, (mapa.BlocoTam) * (mapa3[i]), 0, mapa.BlocoTam, mapa.BlocoTam,
                ((mapa.BlocoTam)+((mapa.BlocoTam)/2)) * (i%(mapa.MapaColuna)), ((mapa.BlocoTam)+((mapa.BlocoTam)/2)) * (i/(mapa.MapaColuna)),
                 (mapa.BlocoTam)+((mapa.BlocoTam)/2), (mapa.BlocoTam)+((mapa.BlocoTam)/2), 0);
			}
              break;
        }

			if (keys[DIRECAO])
			{
				// Boneco para um lado
				al_draw_scaled_bitmap(folha_sprites,
					mulher.regiao_x_folha, mulher.regiao_y_folha,
					principal.largura_sprite, principal.altura_sprite,
					principal.pos_x_sprite + principal.largura_sprite, principal.pos_y_sprite,
					principal.largura_sprite + 80, principal.altura_sprite + 80, 0);
			}
			else
			{
				// Boneco ao contrario
				al_draw_scaled_bitmap(folha_sprites,
					mulher.regiao_x_folha, mulher.regiao_y_folha,
					principal.largura_sprite, principal.altura_sprite,
					principal.pos_x_sprite + principal.largura_sprite, principal.pos_y_sprite,
					principal.largura_sprite + 80 , principal.altura_sprite + 80, ALLEGRO_FLIP_HORIZONTAL);
			}
			al_flip_display();
			redraw = 0;

		}
	}

	al_destroy_display(display);
	al_destroy_timer(timer);
	al_destroy_bitmap(folha_sprites);
	al_destroy_bitmap(folha_bloco);
	al_destroy_event_queue(fila_eventos);

	return 0;
}

int inicializar()
{

	if (!al_init()) //Inicializando o Allegro
	{
		error_msg("O Allegro nao foi inicializado");
		return -1;
	}

	if (!al_init_image_addon())  // Inicializando a biblioteca de imagem
	{
		error_msg("A addon de imagens nao foi inicializada");
		return -1;
	}

	if (!al_install_keyboard())  // Instalando o teclado
	{
		error_msg("O teclado nao foi instalado");
		return -1;
	}

	if (!al_install_mouse()) // Instalando o mouse
	{
		error_msg("O mouse nao foi instalado");
		return -1;
	}

	display = al_create_display(width, height);  // Criando o display
	if (!display)
	{
		error_msg("Falha ao criar a janela");
		return -1;
	}


	timer = al_create_timer(1.0 / FPS); // Criando o timer
	if (!timer)
	{
		error_msg("Falha ao criar o timer");
		return -1;
	}

	fila_eventos = al_create_event_queue(); // Criando a fila de eventos
	if (!fila_eventos)
	{
		error_msg("Falha ao criar a fila de eventos");
		return -1;
	}

	folha_sprites = al_load_bitmap("sprites/Mulher-aventureira.png"); // Carregando a folha de sprites
	if (!folha_sprites)
	{
		error_msg("Falha ao carregar a folha de sprites");
		return -1;
	}

	folha_bloco = al_load_bitmap("sprites/blocos.png"); //Carrega blocos
	if (!folha_bloco)
	{
		error_msg("Falha ao carregar a folha de blocos");
		return -1;
	}

	fundo = al_load_bitmap("sprites/background1.png"); //Carregando o background do jogo
	if (!fundo)
	{
		error_msg("Falha ao carregar o fundo do jogo");
		return -1;
	}

	al_register_event_source(fila_eventos, al_get_timer_event_source(timer)); // Registrando uma fonte de eventos do timer
	al_register_event_source(fila_eventos, al_get_keyboard_event_source()); // Registrando fonte de eventos do teclado
	al_register_event_source(fila_eventos, al_get_mouse_event_source()); // Registrando fonte de eventos do mouse
	al_start_timer(timer); // Iniciando o timer


	return 1;
}
