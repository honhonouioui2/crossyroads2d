#include "TileMap.h"

using namespace std;

// need to add robustness *
void TileMap::fetchTileMapMetaData(string filePath) {
	cout << "File:" << filePath << endl;
	ifstream file(filePath.c_str(), ios::out);

	if (!file.is_open()) {
		cerr << "could not open" << endl << "'" << filePath << "'" << endl;
		return;
	}

	string line;
	int bufferSize = _imageBuffer.size(),
		x = 0,
		y = -bufferSize,
		segment_length_y = 0;
	queue<string> binary;

	while (getline(file, line)) { // read file, place into queue
		binary.push(line);
	}
	file.close();

	segment_length_y = binary.size();
	while (!binary.empty()) {
		line = binary.front();
		cout << endl << "Line:'" << line << "'" << endl;

		vector<pair<TileData, TileData>> row;
		pair<TileData, TileData> cell;

		do {
			cout << "|";
			for (int tileN = 0; tileN < 2; ++tileN) {
				string bytes = "";
				for (int i = 0; i < 8; i++) {
					bytes.insert(bytes.end(), line[i]);
				}
				line = line.substr(8, line.length());

				// robustesse***
				TileData tile = TileData(_xmlData[stoi(bytes, 0, 2)]); // can cause error if bad data
				cout << "\\id:" << stoi(bytes, 0, 2) << "\\x(" << x << "):" << tile.sprite.getPosition().x << "\\y(" << y << "):" << tile.sprite.getPosition().y;
				
				int spr_width = tile.sprite.getGlobalBounds().width;
				
				int offset_x = spr_width * x, offset_y = spr_width * y;
				offset_y = (SCREEN_HEIGHT - spr_width * segment_length_y) + offset_y;

				if (tileN) {
					// layer tile (first)
					cell.first = tile;
					cell.first.sprite.setPosition(offset_x, offset_y);
					cell.first.decorSprite.setPosition(offset_x, cell.first.sprite.getPosition().y - cell.first.decorSprite.getGlobalBounds().height);
				}
				else {
					// top tile (second)
					cell.second = tile;
					cell.second.sprite.setPosition(offset_x, offset_y);
					cell.second.decorSprite.setPosition(offset_x, offset_y - cell.second.decorSprite.getGlobalBounds().height);
				}

				/*switch (tile.id) {
				case 15:
					// car spawner
					// push
					///carSpawnerEntity car(_data);// = carSpawnerEntity(_data);
					//tile.tileEntity = new carSpawnerEntity(_data);
					break;
				case 17:
					// log spawner
					break;
				case 18:
					// water lily
					break;
				default:
				}*/
			}
			row.push_back(cell);

			x++;
			cout << "|	";
		} while (!line.empty());
		binary.pop();
		_imageBuffer.push_back(row);

		y++;
		x = 0;
		cout << endl << endl << endl;
	}
}

void TileMap::parseXMLData() {
	xml_document<> document;
	xml_node<>* begin_node;

	ifstream file("TileData.xml");
	vector<char> buffer((istreambuf_iterator<char>(file)), istreambuf_iterator<char>());
	buffer.push_back('\0'); //cstring
	document.parse<0>(&buffer[0]);
	begin_node = document.first_node("data");

	for (xml_node<>* node = begin_node->first_node("tile"); node; node = node->next_sibling())
	{
		TileData tile;
		Sprite sprite;

		tile.id = strtol(node->first_node("id")->value(), 0, 10);
		tile.type = node->first_node("type")->value();

		if (node->first_node("texture") == nullptr)
			continue;
		
		tile.textureName = node->first_node("texture")->value();
		tile.collision = node->first_node("collision")->value();
		
		_data->assets.loadTexture(tile.textureName, "Resources/tiles/" + tile.textureName + ".png");
		sprite.setTexture(_data->assets.getTexture(tile.textureName));
		
		float scale = SCREEN_WIDTH / sprite.getLocalBounds().width / 10;
		sprite.setScale(scale, scale);
		
		if (node->first_node("decor")) {
			tile.decorTextureName = node->first_node("decor")->value();
			_data->assets.loadTexture(tile.decorTextureName, "Resources/tiles/" + tile.decorTextureName + ".png");
			tile.decorSprite.setTexture(_data->assets.getTexture(tile.decorTextureName));
			tile.decorSprite.setScale(scale, scale);
		}

		tile.sprite = sprite;
		_xmlData[tile.id] = tile;
	}
}

TileMap::TileMap(gameDataRef data) : _data(data)
{
	//_xmlData = nullptr;
}

TileMap::~TileMap()
{
	delete []_xmlData;
}

void TileMap::init()
{
	//_xmlData = new TileData[N_TILE_TYPES];
	parseXMLData();
}

void TileMap::draw() {
	//_data->view.move(Vector2f(0, 0));
	//_data->window.setView(_data->view);

	_decorSpritesBuffer.clear();
	for (int row_it = 0; row_it < _imageBuffer.size(); row_it++) {
		vector<pair<TileData, TileData>> row = _imageBuffer.at(row_it);
		pair<TileData, TileData> first_cell = row.front();
		
		//bottom
		int spr_width = first_cell.first.sprite.getGlobalBounds().width;
		if ((_data->view.getCenter().y + (_data->view.getSize().y / 2)) < first_cell.first.sprite.getPosition().y || (_data->view.getCenter().y - (_data->view.getSize().y / 2)) > first_cell.first.sprite.getPosition().y + spr_width) {
			continue;
		}

		for (int cell_it = 0; cell_it < row.size(); cell_it++) {
			pair<TileData, TileData> cell = row.at(cell_it);
			_data->window.draw(cell.first.sprite);
			_data->window.draw(cell.second.sprite);

			if (cell.second.decorTextureName.size() > 0) {
				pair<int, int> elem;
				elem.first = row_it;
				elem.second = cell_it;
				_decorSpritesBuffer.push_back(elem);
			}
		}
	}
}


// need robustness***
void TileMap::drawDecor() {
	for (auto it : _decorSpritesBuffer) {
		_data->window.draw(_imageBuffer[it.first][it.second].second.decorSprite);
	}
}


const vector<vector<pair<TileData, TileData>>> TileMap::getImageBuffer() const {
	return _imageBuffer;
}