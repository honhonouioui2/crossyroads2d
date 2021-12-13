#include "game.h"
#include "DEFINITIONS.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include "rapidxml.hpp"

using namespace std;
using namespace rapidxml;
using namespace sf;

int main()
{
    
    cout << "\nParsing Tile data (TileData.xml)" << endl;

    xml_document<> doc;
    xml_node<>* root_node = NULL;

    ifstream theFile("TileData.xml");
    vector<char> buffer((istreambuf_iterator<char>(theFile)), istreambuf_iterator<char>());
    buffer.push_back('\0');

    doc.parse<0>(&buffer[0]);
    root_node = doc.first_node("data");

    for (xml_node<>* node = root_node->first_node("tile"); node; node = node->next_sibling())
    {
        cout << "\nTextureName =   " << node->first_node("texture")->value();
        cout << "\nCollision =   " << node->first_node("collision")->value();
        cout << "\nTileType =   " << node->first_node("type")->value();
        cout << "\nTileID =   " << node->first_node("id")->value();
        cout << endl;
    }
    
	//game crossyRoads2D(SCREEN_WIDTH, SCREEN_HEIGHT, "CrossyRoads2D");
	//return EXIT_SUCCESS;
}
