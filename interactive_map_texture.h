#ifndef INTERACTIVE_MAP_TEXTURE_H
#define INTERACTIVE_MAP_TEXTURE_H

#include "library.h"
#include<vector>

#ifndef TEXT_LENGHT_MAX_DEFINED
const int TEXT_LENGHT_MAX=101;
#define TEXT_LENGHT_MAX_DEFINED
#endif // TEXT_LENGHT_MAX_DEFINED

class Map_texture_id
{
 private:
 int id;
 int duration=0,remaining_duration=0;
 int frame=0;
 char map_name[TEXT_LENGHT_MAX]={NULL};
 int player_map_pos_x,player_map_pos_y;

 public:
 Map_texture_id();
 void Set_id(int _id);
 void Set_duration(int _duration);
 void Set_frame(int _frame);
 void Set_player_map_pos(int x,int y);
 void Set_map_name(char *_map_name);
 int Get_id();
 int Get_frame();
 int Get_player_map_pos_x();
 int Get_player_map_pos_y();
 char *Get_map_name();
 bool Is_done();
 void Decrease_remaining_duration();
 void Update_frame(int _number_of_frames);
};

class Interactive_map_texture
{
 private:
 int id;
 std::vector<std::pair<int,int> > target_map_position;
 std::vector<Map_texture_id> map_textures_ids;
 int current_map_texture_id_position,number_of_map_textures_ids_positions;
 bool done=false;

 public:
 Interactive_map_texture();
 ~Interactive_map_texture();
 void Clear();
 void Load();
 void Load(int _id);
 void Set_id(int _id);
 void Set_texture_frame(int _frame);
 void Set_texture_player_map_pos(int _texture,int x,int y);
 void Set_texture_map_name(int _texture,char *_map_name);
 int Get_texture_id();
 void Get_all_textures_ids(std::vector<Map_texture_id> &textures_ids);
 void Get_all_targets_map_positions(std::vector<std::pair<int,int> > &_target_map_position);
 int Get_texture_frame();
 int Get_texture_player_map_pos_x();
 int Get_texture_player_map_pos_y();
 char *Get_texture_map_name();
 bool Is_done();
 void Decrease_remaining_duration();
 void Update_texture_frame(int _number_of_frames);

 void Add_target(int x,int y);
 void Trigger();
};

#endif // INTERACTIVE_MAP_TEXTURE_H