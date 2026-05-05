#include <stdio.h>
#include <conio2.h>
#include <locale.h>

#define TAMANHOCHAR 255

void menu_submenu(int tipo_menu) {
    int x = 44, y = 15, tecla = 0, n2 = 0;

    // Mostra o submenu na tela
    gotoxy(x, 15); printf("1-Listar");
    gotoxy(x, 17); printf("2-Pesquisar");
    gotoxy(x, 19); printf("3-Editar");
    gotoxy(x, 21); printf("4-Excluir");
    gotoxy(x, 23); printf("5-Voltar");

    while (tecla != 13) { // ENTER
        gotoxy(x-2, y); textcolor(LIGHTCYAN); printf("»");
        tecla = getch();

        // Limpar seta da posição anterior
        if (tecla == 72) { // cima
            gotoxy(x-2, y); printf(" ");
            y -= 2;
            if (y < 15) y = 23;
        } else if (tecla == 80) { // baixo
            gotoxy(x-2, y); printf(" ");
            y += 2;
            if (y > 23) y = 15;
        }
    }

    // Quando ENTER for pressionado, define n2
    switch(y) {
        case 15: n2 = 1; break;
        case 17: n2 = 2; break;
        case 19: n2 = 3; break;
        case 21: n2 = 4; break;
        case 23: n2 = 5; break;
    }

    // Aqui você faz a ação do submenu
    switch(tipo_menu) {
        case 1: // Componentes
            if(n2 == 1) printf("Listando Componentes\n");
            if(n2 == 2) printf("Pesquisando Componentes\n");
            if(n2 == 3) printf("Editando Componentes\n");
            if(n2 == 4) printf("Excluindo Componentes\n");
            if(n2 == 5) printf("Voltando...\n");
            break;
        case 2: // Funcionários
            if(n2 == 1) printf("Listando Funcionários\n");
            if(n2 == 2) printf("Pesquisando Funcionários\n");
            if(n2 == 3) printf("Editando Funcionários\n");
            if(n2 == 4) printf("Excluindo Funcionários\n");
            if(n2 == 5) printf("Voltando...\n");
            break;
        // ... você pode adicionar os outros casos para Posto e Operações
    }

    getch(); // esperar usuário ver mensagem
}

int main() {
    setlocale(LC_ALL, "portuguese");
    int x = 44, y = 15, tecla = 0, n1 = 0;

    // Menu principal
    gotoxy(44,15); printf("COMPONENTES");
    gotoxy(44,17); printf("FUNCIONÁRIOS");
    gotoxy(44,21); printf("POSTO DE TRABALHO");
    gotoxy(44,23); printf("OPERAÇÕES");

    while (n1 != 5) {
        tecla = 0;
        y = 15; // seta começa na primeira opção

        while (tecla != 13) { // ENTER
            // Mostra seta
            gotoxy(x-2, y); textcolor(LIGHTCYAN); printf("»");
            tecla = getch();

            if (tecla == 72) { // cima
                gotoxy(x-2, y); printf(" ");
                y -= 2;
                if (y < 15) y = 23;
            } else if (tecla == 80) { // baixo
                gotoxy(x-2, y); printf(" ");
                y += 2;
                if (y > 23) y = 15;
            }

            // Atualiza cor das opções
            textcolor(WHITE);
            gotoxy(x,15); printf("COMPONENTES");
            gotoxy(x,17); printf("FUNCIONÁRIOS");
            gotoxy(x,21); printf("POSTO DE TRABALHO");
            gotoxy(x,23); printf("OPERAÇÕES");

            textcolor(LIGHTCYAN);
            gotoxy(x,y); 
            if(y==15) printf("COMPONENTES");
            if(y==17) printf("FUNCIONÁRIOS");
            if(y==21) printf("POSTO DE TRABALHO");
            if(y==23) printf("OPERAÇÕES");
        }

        // Define n1 baseado na posição da seta
        switch(y) {
            case 15: n1 = 1; break;
            case 17: n1 = 2; break;
            case 21: n1 = 3; break;
            case 23: n1 = 4; break;
        }

        if(n1 >= 1 && n1 <= 4) menu_submenu(n1);
        if(n1 == 5) break; // sair
    }

    return 0;
}