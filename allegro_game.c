/****************************************************
* Instituto Federal de Santa Catarina - Florianópolis
* Alunos: Emmily Boesing e Marcos Fernandes
* Turma: 722 - Eletrônica
* Projeto: Jogo em C com a biblioteca Allegro5
****************************************************/

/*********************OBSERVAÇÃO*********************
* O jogo esta incompleto, falta colisão entre
* personagens, morte dos personagens e game over.
* Porém ele esta com a jogabilidade básica,
* tentaremos adicionar o restante até o dia da
* apresentação, quinta-feira
*****************************************************/

/******** Mais informações no bloco de notas ********/

#include "declaracoes.h"

const int FPS = 60; // Frames por segundo
const int num_inimigos = 3; // Numero de inimigos
enum keys {PULO, ESQUERDA, DIREITA, ESPACO, DIRECAO};

bool keys[5] = {false ,false , false, false, true};

ALLEGRO_DISPLAY* display = NULL; // Janela
ALLEGRO_EVENT_QUEUE* fila_eventos = NULL; // Fila de eventos
ALLEGRO_TIMER* timer = NULL; // Timer

ALLEGRO_AUDIO_STREAM* musica = NULL; // Musica de fundo
ALLEGRO_BITMAP* elisabeth_png = NULL; // Folha de sprite da Elisabeth
ALLEGRO_BITMAP* jack_png = NULL; // Folha de sprite do Jack
ALLEGRO_BITMAP* fundo_png = NULL; // Fundo do mapa
ALLEGRO_BITMAP* folha_bloco = NULL; // Folha de sprite dos blocos
ALLEGRO_BITMAP* inimigos_png[3] = { NULL, NULL }; // Folha de sprite dos inimigos

// Mapa 1
int mapa1[] = {5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
                     5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
                     5, 5, 5, 5, 5, 5, 5, 5, 5, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3,
                     5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
                     3, 3, 3, 3, 3, 3, 3, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
                     5, 5, 5, 5, 5, 5, 5, 5, 5, 2, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
                     5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
                     5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3,
                     1, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
                     1, 1, 5, 5, 5, 5, 5, 5, 5, 1, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
                     3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 5, 5, 5, 1,
                     5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 1, 1,
                     5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 1, 1, 1,
                     5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 1, 1, 1, 1,
                     0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

// Mapa 2
int mapa2[] = { 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
					 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
					 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5,
					 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
					 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 2, 4, 5, 5, 5, 5, 5, 5,
					 5, 5, 5, 5, 5, 5, 5, 5, 5, 2, 3, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5,
					 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
					 5, 5, 5, 2, 3, 3, 3, 4, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
					 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
					 5, 5, 5, 5, 5, 5, 5, 5, 5, 2, 3, 3, 4, 5, 5, 5, 5, 5, 5, 5, 5,
					 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
					 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 2, 3, 4, 5, 5, 5, 5,
					 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
					 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5,
					 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

// Mapa 3
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
	bool redesenhar = true; // Variavel de controle para redesenhar algo
	bool done = false; // Utilizado no laço principal
	bool parado = true; // Variavel para saber se esta parado ou nao
	int level = 1; // Variavel para saber qual a fase atual
	int indice, indice2;  // Indices utilizados em todo o codigo
	int acao; // Utilizado para saber qual a a��o necessaria do personagem
    int vel_gravidade = 0; // Velocidade da gravidade
    int caindo=1; // Variavel que controla se ta caindo
    int gravidade = 1; // Gravidade
    int pulo = 0; // Variavel de controle para o pulo
    int pulo_limite = 0; // Posicao anterior ao pular

	struct Personagem elisabeth;  // Personagem Elisabeth
	struct Personagem jack; // Personagem Jack
	struct Personagem inimigos[3]; // Personagem secundario
    struct Cenario mapa; // Mapa

	init_elisabeth(&elisabeth);	//Inicialização da Elisabeth
	init_jack(&jack); // Inicialização do Jack
	init_dwarf(inimigos); // Inicialização do Dwarf
	init_minotauro(inimigos); // Inicialização do Minotauro
	init_esqueleto(inimigos); // Inicialização do Esqueleto
    init_cenario(&mapa); // Inicializando mapa

	// Inicializando
	if (inicializar() != 1)
	{
		error_msg("Falha ao inicializar o jogo");
		return -1;
	}

	while (!done)
	{
		ALLEGRO_EVENT evento; // Variavel para armazenar evento
		al_wait_for_event(fila_eventos, &evento); // Espera por eventos e armazena na fila de eventos

		// Dependendo do level inicio em um lugar diferente
		switch (level)
		{
		case 2:
			elisabeth.inicio_x = -100;
			elisabeth.inicio_y = -10;
			break;
		case 3:
			elisabeth.inicio_x = -100;
			elisabeth.inicio_y = 675 - elisabeth.altura_sprite_tela;
			break;
		}

		if (evento.type == ALLEGRO_EVENT_TIMER)
		{
			redesenhar = true;

			limite_elisabeth(&elisabeth);

			animacao_beth_jack (&jack, 1, true); // Animação do Jack na fase 3

			 for (indice = 0; indice < num_inimigos; indice++)
			{
				switch (indice)
				{
				case 0:
					// Animação do anão
					animacao_inimigos(inimigos, 2, indice);
					break;
					
				case 1:
					// Animação do minotauro
					animacao_inimigos(inimigos, 2, indice);
					break;
				case 2:
					// Animação do esqueleto
					animacao_inimigos(inimigos, 2, indice);
					break;
				}
			}
			 for (indice2 = 0; indice2 < num_inimigos; indice2++)
			 {
				done = colisao_personagens(&elisabeth, inimigos, indice2, level, keys, ESPACO);
			 }

			if (parado) // Parado realiza animação padrão
			{
				acao = 0;
				animacao_beth_jack(&elisabeth, acao, false);
			}

			if (keys[ESQUERDA]) // Vai para a esquerda
			{
				acao = 1;
				parado = false;
				keys[DIRECAO] = false;

				animacao_beth_jack(&elisabeth, acao, false);
				elisabeth.pos_x_sprite -= elisabeth.vel_x_sprite;

			}
			if (keys[DIREITA]) // Vai para a direita
			{
				acao = 1;
				parado = false;
				keys[DIRECAO] = true;

				animacao_beth_jack(&elisabeth, acao, false);
				elisabeth.pos_x_sprite += elisabeth.vel_x_sprite;

			}

			if (keys[ESPACO]) // Comando para bater
			{
				printf("%d", inimigos[2].vivo_1[0]);
				acao = 2;
				parado = false;
				animacao_beth_jack(&elisabeth, acao, false);
			}

			// Logica do pulo
			if(pulo && elisabeth.pos_y_sprite > pulo_limite - 10)
			{
                elisabeth.pos_y_sprite += vel_gravidade;
                vel_gravidade = -elisabeth.vel_y_sprite;
                caindo = 1;
			}
			// Gravidade 
			else if(caindo == 1)
			{
                pulo = 0;
                vel_gravidade += gravidade;
                elisabeth.pos_y_sprite += vel_gravidade;
			}
			else 
			{
                pulo = 0;
                vel_gravidade = 0;
			}
			caindo = 1;

			// Colisão do personagem com os blocos
			caindo = colisao_blocos(&elisabeth, caindo, level);
		}

		else if (evento.type == ALLEGRO_EVENT_KEY_DOWN) // Se a tecla for pressionada
		{
			switch (evento.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				done = true;
				break;
			case ALLEGRO_KEY_UP:
			    if(!pulo && !vel_gravidade)
                {
			    pulo_limite = elisabeth.pos_y_sprite;
			    pulo = 1;
			    }
				break;
			case ALLEGRO_KEY_LEFT:
				keys[ESQUERDA] = true;
				break;
			case ALLEGRO_KEY_RIGHT:
				keys[DIREITA] = true;
				break;
			case ALLEGRO_KEY_SPACE:
				printf("%d", elisabeth.vidas_1);
				keys[ESPACO] = true;
				break;
			}
		}
		else if (evento.type == ALLEGRO_EVENT_KEY_UP) // Se a tecla for solta
		{
			switch (evento.keyboard.keycode)
			{
			case ALLEGRO_KEY_ESCAPE:
				done = true;
				break;
			case ALLEGRO_KEY_UP:
				caindo = 1;
				break;
			case ALLEGRO_KEY_LEFT:
				keys[ESQUERDA] = false;
				parado = true;
				break;
			case ALLEGRO_KEY_RIGHT:
				keys[DIREITA] = false;
				parado = true;
				break;
			case ALLEGRO_KEY_SPACE:
				keys[ESPACO] = false;
				break;
			}
		}

		else if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			done = true;
		}

		if (redesenhar && al_is_event_queue_empty(fila_eventos))
		{
			redesenhar = false;

			// Desenha o fundo
			al_draw_scaled_bitmap(fundo_png, 0, 0, 576, 324, 0, 0,width,height, 0);

			// Dependendo do level desenha blocos diferentes
			switch(level)
			{
			case 1:
				for (int i = 0; i<mapa.MapaTam; i++)
				{
					al_draw_scaled_bitmap(folha_bloco, (mapa.BlocoTam) * (mapa1[i]), 0, mapa.BlocoTam, mapa.BlocoTam,
					((mapa.BlocoTam)+((mapa.BlocoTam)/2)) * (i%(mapa.MapaColuna)), ((mapa.BlocoTam)+((mapa.BlocoTam)/2)) * (i/(mapa.MapaColuna)),
					 (mapa.BlocoTam)+((mapa.BlocoTam)/2), (mapa.BlocoTam)+((mapa.BlocoTam)/2), 0);
				}
				// Transição de Fase
				if(elisabeth.pos_x_sprite + elisabeth.inicio_x > width &&
					elisabeth.pos_y_sprite + elisabeth.inicio_y < height - 680)
				{
					elisabeth.pos_x_sprite = 0;
					elisabeth.pos_y_sprite = 0;
					level++;
				}
				  break;
			case 2:
				for (int j = 0; j<mapa.MapaTam; j++)
				{
					al_draw_scaled_bitmap(folha_bloco, (mapa.BlocoTam) * (mapa2[j]), 0, mapa.BlocoTam, mapa.BlocoTam,
					((mapa.BlocoTam)+((mapa.BlocoTam)/2)) * (j%(mapa.MapaColuna)), ((mapa.BlocoTam)+((mapa.BlocoTam)/2)) * (j/(mapa.MapaColuna)),
					 (mapa.BlocoTam)+((mapa.BlocoTam)/2), (mapa.BlocoTam)+((mapa.BlocoTam)/2), 0);
				}
				// Transição de Fase
				if(elisabeth.pos_x_sprite + elisabeth.inicio_x > width &&
					elisabeth.pos_y_sprite + elisabeth.inicio_y < height - 75)
				{
					elisabeth.pos_x_sprite = 0;
					elisabeth.pos_y_sprite = 0;
					level++;
				}
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

			// Desenha inimigos em lugares do mapa dependendo do level
			desenha_inimigos(inimigos_png, jack_png, inimigos, &jack, level);

			// Desenha Elisabeth
			desenha_elisabeth(elisabeth_png, &elisabeth, keys, DIRECAO);

			al_draw_line(elisabeth.inicio_x + elisabeth.largura_sprite_tela + elisabeth.pos_x_sprite - 35,
				elisabeth.inicio_y + elisabeth.altura_sprite_tela + elisabeth.pos_y_sprite,
				inimigos[0].pos_x_sprite + inimigos[0].largura_sprite_tela - 25,
				inimigos[0].pos_y_sprite_2 + inimigos[0].altura_sprite_tela + 5, al_map_rgb(255, 255, 255), 2);

			al_flip_display();
			redesenhar = 0;

		}
	}

	al_destroy_display(display);
	al_destroy_timer(timer);

	al_destroy_bitmap(elisabeth_png);
	al_destroy_bitmap(jack_png);
	al_destroy_bitmap(inimigos_png[0]);
	al_destroy_bitmap(inimigos_png[1]);
	al_destroy_bitmap(inimigos_png[2]);

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

	al_init_primitives_addon();

	if (!al_install_audio()) // Instalando o áudio
	{
		error_msg("Falha ao instalar o audio");
		return 0;
	}

	if (!al_init_acodec_addon())  // Inicializando codec de audio
	{
		error_msg("Falha ao inicializar o codec de audio");
		return 0;
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

	al_set_window_title(display, "O Resgate de Jack");

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

	if (!al_reserve_samples(1)) // Reserva uma faixa de audio
	{
		error_msg("Falha ao reservar faixa de audio");
		return 1;
	}

	musica = al_load_audio_stream("musicas/musica_principal.mp3", 4, 1024);
	if (!musica)
	{
		error_msg("Audio não carregado");
		return -1;
	}

	al_attach_audio_stream_to_mixer(musica, al_get_default_mixer()); // Pega o mixer com a musica

	al_set_audio_stream_playmode(musica, ALLEGRO_PLAYMODE_LOOP); // Deixa a musica em LOOP

	al_set_audio_stream_gain(musica, 0);

	elisabeth_png = al_load_bitmap("sprites/Principais/Elisabeth.png"); // Carregando a folha de sprites
	if (!elisabeth_png)
	{
		error_msg("Falha ao carregar a Elisabeth.png");
		return -1;
	}

	jack_png = al_load_bitmap("sprites/Principais/Jack.png"); // Carregando a folha de sprites
	if (!jack_png)
	{
		error_msg("Falha ao carregar Jack.png");
		return -1;
	}


	inimigos_png[0] = al_load_bitmap("sprites/Inimigos/Dwarf.png"); // Carregando Dwarf
	inimigos_png[1] = al_load_bitmap("sprites/Inimigos/Minotauro.png"); // Carregando Minotauro
	inimigos_png[2] = al_load_bitmap("sprites/Inimigos/Esqueleto.png"); // Carregando Esqueleto

	if (!inimigos_png[0])
	{
		error_msg("Falha ao carregar um ou mais inimigos.png");
		return -1;
	}

	if (!inimigos_png[1])
	{
		error_msg("Falha ao carregar um ou mais inimigos");
		return -1;
	}

	if (!inimigos_png[2])
	{
		error_msg("Falha ao carregar um ou mais inimigos");
		return -1;
	}

	folha_bloco = al_load_bitmap("sprites/fundo/blocos.png"); //Carrega blocos
	if (!folha_bloco)
	{
		error_msg("Falha ao carregar a folha de blocos");
		return -1;
	}

	fundo_png = al_load_bitmap("sprites/fundo/Background.png"); //Carregando o background do jogo
	if (!fundo_png)
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
