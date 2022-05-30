#include <iostream>
#include <fstream>


#define SENHASMAX 100
#define CARACMAX 100

using namespace std;

int gerarsenha(int vezes, int quan, char opces);
void salvartxt(int vezes);

struct infosenha {

    string senhas;
} sen[100];

int main()
{

    srand(time(0));

    int vezes = 1;
    int quan = 1;
    char opces;

    cout << " ================ Bem vindo ao gerador de senhas ============" << endl;

    cout << "Digite quantas senhas deseja gerar? ";
    cin >> vezes;

    cout << "\nQuantos caracteres deseja na senha? ";
    cin >> quan;


    while (1)
    {
        if (vezes <= 0 || vezes > SENHASMAX)
        {
            cout << "Quantidade de senhas invalida digite novamente" << endl;
            cin >> vezes;
            getchar();


        }
        else if (quan <= 0 || quan > CARACMAX)
        {
            cout << "Quantidade de caracteres invalida digite novamente" << endl;
            cin >> quan;
            getchar();
        }
        else
        {
            break;
        }

    }

    cout << "Deseja caracteres especiais na senha? S/N: ";
    cin >> opces;

    cout << "\nO Sistema ira gerar sua senha aleatoria. " << endl;


    while (1)
    {
        if (gerarsenha(vezes, quan, opces) == false)
        {
            cout << "Opcao invalida, Digite se deseja caracteres especiais S/N: ";
            cin >> opces;
            getchar();

        }
        else
        {
            break;
        }

    }

    salvartxt(vezes);

    return 0;
}

void salvartxt(int vezes)
{
    ofstream arq;
    char opces;

    cout << "Deseja Salvar as senhas no bloco de notas? S/N: " << endl;
    cin >> opces;

    switch (opces)
    {
    case 'S':
    case 's':

        
            arq.open("Anota.txt");

            if (arq.is_open())
            {
                for (int i = 0; i <= vezes; i++)
                {
                    arq << sen[i].senhas << endl;
                }
            }
            cout << "Senhas anotadas com sucesso\n\n";
            arq.close();

            system("PAUSE");

        
        break;
    default:
        cout << "Nao foi salvo as senhas no bloco de notas " << endl;
        system("PAUSE");
        return;

    }

}
int gerarsenha(int vezes, int quan, char opces)
{
    string  pass = "ABCDEFGHIJKLMNOPQRSXYWZ" "abcdefghijklmnopqrsxywz" "0123456789" "!@#$%¨&*";

    for (int i = 0; i < vezes; i++)
    {
        for (int in = 0; in <= quan; in++)
        {
            if (opces == 'S' || opces == 's')
            {
                sen[i].senhas += pass[rand() % pass.length()];
            }
            else if (opces == 'N' || opces == 'n')
            {
                sen[i].senhas += pass[rand() % (pass.length() - 8)];
            }
            else
            {
                return false;
            }
        }

        cout << "Sua Senha numero " << i + 1 << ": " << sen[i].senhas << endl;


    }

    return true;
}
