#include <iostream>
#include <unordered_map>
#include <map>
#include <stdexcept>
#include <string>
#include <list>
#include <vector>

using namespace std;


using cancion = string;
using artista = string;
using info = pair<artista, int>;

class iPud {
public:

	void addSong(cancion song, artista artist, int duracion);
	void addToPlaylist(cancion song);
	cancion current();
	void play();
	int totalTime();
	vector<cancion> recent(int numero);
	void deleteSong(cancion song);

private:

	

	unordered_map<cancion, info> memoria;

	list<cancion> playlist;
	list<cancion> reproducidas;
};

void iPud::addSong(cancion song, artista artist, int duracion)
{
	if (memoria.count(song) != 0)
	{
		throw invalid_argument("addSong");
	}
	else
	{
		memoria[song] = {artist , duracion};
	}


}

void iPud::addToPlaylist(cancion song)
{
	bool encontrado = false;
	if(memoria.count(song) == 0)
	{
		throw invalid_argument("addToPlaylist");

	}
	else
	{
		auto it = playlist.begin();

		while (it != playlist.end() && encontrado == false)
		{
			if (*it == song)
			{
				encontrado = true;
			}
			it++;
		}

		if (!encontrado)
		{
			playlist.push_back(song);
		}
	}
}

cancion iPud::current()
{
	if (playlist.empty())
	{
		throw invalid_argument("current");
	}
	else
	{
		return playlist.front();
	}


}

void iPud::play()
{
	if (!playlist.empty())
	{
		reproducidas.push_back(playlist.front());
		playlist.pop_front();
	}

}

int iPud::totalTime()
{
	int minutos = 0;

	auto it = playlist.begin();

	while (it != playlist.end())
	{
		
		auto it2 = memoria.find(*it);
		
		if (it2 != memoria.end())
		{
			minutos += it2->second.second;

		}
		
		it++;
	}

	return minutos;
}

vector<cancion> iPud::recent(int numero)
{
	int aux = numero;
	auto it = reproducidas.rbegin();
	vector<cancion> canciones;

	bool encontrado = false;

	

	do
	{
		auto it2 = canciones.begin();
		while (it2 != canciones.end() && encontrado == false)
		{
			if (*it2 == *it)
			{
				encontrado = true;
			}
			it2++;
		}

		if (!encontrado)
		{
			canciones.push_back(*it);
			aux--;
		}
		else
		{
			encontrado = false;
		}
		
		++it;

	} while (aux > 0 && it != reproducidas.rend());

	return canciones;
}

void iPud::deleteSong(cancion song)
{
	bool eliminado = false;
	auto it = reproducidas.begin();
	
	if (!reproducidas.empty())
	{
		while (eliminado == false && it != reproducidas.end())
		{
			if (*it == song)
			{
				reproducidas.erase(it);
				eliminado = true;
			}
			else
			{
				++it;
			}

		}
	}

	
	eliminado = false;

	auto it2 = playlist.begin();


	if (!playlist.empty())
	{
		while (eliminado == false && it2 != playlist.end())
		{
			if (*it2 == song)
			{
				playlist.erase(it2);
				eliminado = true;
			}
			else
			{
				++it2;
			}
		}
	}


	memoria.erase(song); 



}
