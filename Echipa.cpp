#include "Echipa.h"
#include "Exceptii.h"
#include  <vector>
#include <fstream>
#include <cstring>

Echipa::Echipa(int len_, std::vector<std::string>Lista_) : len{len_},  ListaEchipe{std::move(Lista_)} {
    ///std::cout << "echipa";
}
///constructor de copiere

void Echipa :: Echipe()
{
    ///std::fstream f
    ///f.open("echipe.txt", std::ios::in);
    std :: ifstream f("echipe.txt");
    for(int i = 0; i < len; i++)
    {
        char s[NMAX];
        f.getline(s, len);
        if(strcmp(s, "") != 0)
            ListaEchipe.emplace_back(s);
    }
    if(ListaEchipe.empty())
        throw noteams_error("Nu exista echipe: Fisierul echipe.txt este gol sau nu exista");
    f.close();
}
std::string Echipa :: RandomTeam(int index)
{
    int x = rand() % len;
    if(index == 0 && x % 2 == 1)

        x = x-1;
    else if(index == 1 && x % 2 == 0)
        x = x+1;
    if(x >= len)
        throw wrongteam_error("Nu exista echipa cu acest indice in fisierul echipe.txt");
    return ListaEchipe[x];
}
