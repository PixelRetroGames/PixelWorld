#ifndef NPC_H
#define NPC_H

#include "library.h"
#include<bitset>
#include<vector>

#ifndef PLAYER_H
const int NUMBER_OF_MAX_KEYS=10;
#endif // PLAYER_H

#ifndef TEXT_LENGTH_MAX_DEFINED
const int TEXT_LENGTH_MAX=101;
#define TEXT_LENGTH_MAX_DEFINED
#endif // TEXT_LENGTH_MAX_DEFINED

class Non_Playable_Character
{
 private:
 char name[TEXT_LENGTH_MAX]={NULL};
 int map_positionX=0,map_positionY=0;
 int type=0;
 char script_name[TEXT_LENGTH_MAX],shop_name[TEXT_LENGTH_MAX];
 std::vector<std::pair<int,int> > map_accessible_positions;
 int chance_to_move=0;
 SDL_Surface *skin_image=NULL;
 SDL_Rect skin_image_position;
 std::bitset<NUMBER_OF_MAX_KEYS> keys_to_give;
 bool is_blocked=false;
 int last_dir=0;

 public:
 void Clear();
 void Set_name(char *_name);
 int Set_map_positionX(int _map_positionX);
 int Set_map_positionY(int _map_positionY);
 int Get_chance_to_move();
 bool Is_accessible(int x,int y);
 bool Is_static();
 bool Is_blocked();
 int Get_skinW();
 int Get_skinH();
 int Get_map_positionX();
 int Get_map_positionY();
 int Get_last_dir();
 int Get_type();
 char *Get_script_name();
 void Update_skin(int dir);
 void Block();
 void Unblock();
 void Load(std::bitset<NUMBER_OF_MAX_KEYS> *key);
 void Load(char *_name,std::bitset<NUMBER_OF_MAX_KEYS> *key);
 //void Interact(char *player_name);
 void Print_skin(int x,int y,int mapX,int mapY,SDL_Surface *_screen);
};

#endif // NPC_H
