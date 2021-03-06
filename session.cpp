#include "core.h"

extern std::ofstream log_file;
extern game_session* session;

game_session::game_session(std::vector<int> starting_resources, int starting_honour, int enemies, std::vector<int> natural_resources_amount, int mountains_amount) 
	: unlocked_buildings(set_unlocked_warehouse()), game_started(false)
{
	map_generator generator;
	tile_list = generator.generate(natural_resources_amount, mountains_amount, (int)(std::chrono::system_clock::now().time_since_epoch() / std::chrono::milliseconds(1)));
	//tile_list(generate_map(natural_resources_amount, mountains_amount));	//uncomment to use old map_generator
	
	std::vector<resources> all_resources;
	for(int i=0; i<NUMBER_OF_RESOURCES; ++i)
		all_resources.push_back(static_cast<resources>(i));
	
	global_stock = boost::shared_ptr<carrier_output>(new carrier_output(std::numeric_limits<int>::max(), all_resources, all_resources, 0));
	
	global_stock->save_list(starting_resources);
	honour = starting_honour;
	switch(enemies)
	{
		case(0):
		{
			time_to_invasion = -1;
			invasion_interval = -1;
		}
		break;
		case(1):
		{
			time_to_invasion = 3600*game_info::fps;		//first_invasion - 1 hour
			invasion_interval = 1800*game_info::fps;	
		}
		break;
		case(2):
		{
			time_to_invasion = 2400*game_info::fps;		//40 minutes
			invasion_interval = 1200*game_info::fps;
		}
		break;
		case(3):
		{
			time_to_invasion = 1200*game_info::fps;		//20 minutes
			invasion_interval = 600*game_info::fps;
		}
		break;
		case(4):
		{
			time_to_invasion = 600*game_info::fps;		//10 minutes
			invasion_interval = 300*game_info::fps;
		}
		break;
		default:
			throw std::exception();
	}

	frames_from_start = 0;
	happiness = 100;
	honour = starting_honour;
	starving = false;
	invasion_number = 0;
	game_started = false;
	
	button::set_basic_button_list(true);
}

void game_session::update(game_mouse* mouse, bool& done)
{
	if(!game_started)
	{
		if(building_list.size() > 0)
		{
			game_started = true;
			button::set_basic_button_list(false);
			mouse->unchoose_button();
			unlocked_buildings = game_session::set_unlocked_buildings();
		}
		return;
	}

	bool warehouse_exist = false;
	for(int i=0; i<building_list.size(); ++i)
	{
		if(building_list[i]->show_type() == WAREHOUSE)
		{
			warehouse_exist = true;
			break;
		}
	}
	
	if(!warehouse_exist)
	{
		LOG("warehouse destroyed - end of game");
		done = true;
		return;
	}


	ai.update();

	LOG("happiness");
	update_happiness();
	
	LOG("invasion");
	{
		if(time_to_invasion > 0)
			time_to_invasion--;

		else if(time_to_invasion == 0)
		{
			time_to_invasion = invasion_interval;
			invasion();
		}
	}
			
	frames_from_start++;

	LOG("end");
	return;
}

int game_session::update_happiness()
{
	if((frames_from_start % TIME_TO_UPDATE_HAPPINESS) != 0)
		return 0;

	int happiness_equilibrium = 100;
	for(int i=0; i<building_list.size(); ++i)
	{
		if(building_list[i]->type == HOUSE)
		{
			house* house_ptr = dynamic_cast<house*>(building_list[i].get());
			happiness_equilibrium += house_ptr->show_happiness_modifier();
		}
	}

	if(happiness < happiness_equilibrium)
		happiness++;
	
	else if(happiness > happiness_equilibrium)
		happiness--;

	if(happiness < 1)
		happiness = 1;

	return 0;
}
		
int game_session::invasion()
{
	LOG("invasion");

	int x = rand() % MAP_WIDTH;
	int y = rand() % MAP_HEIGHT;
	int side = rand() % 4;

	switch(side){		//move to map borders
	case(0):
		x = 0;
		break;
	case(1):
		x = MAP_WIDTH - 1;
		break;
	case(2):
		y = 0;
		break;
	case(3):
		y = MAP_HEIGHT - 1;
		break;
	}
	
	int number_of_enemies = 5*pow(2, invasion_number) + rand() % 5*pow(2, invasion_number);
	
	invasion_number++;

	for(int i=0; i<number_of_enemies; i++)
	{
		people_type t;
		switch(rand() % std::min(invasion_number, 5))
		{
			case(0):
				t = SPEARMAN;
				break;
			case(1):
				t = AXEMAN;
				break;
			case(2):
				t = CATAPULT;
				break;
			case(3):
				t = BOWMAN;
				break;
			case(4):
				t = SWORDSMAN;
				break;
			default:
			{
				throw std::exception();
				return 0;
			}
		}
		warrior_born_near(t, x, y, RED_PLAYER);
	}

	ai.register_units();

	LOG("number_of_people: " << people_list.size() << " number_of_enemies " << number_of_enemies);
	
	return 0;
}

std::vector<bool> game_session::set_unlocked_warehouse()
{
	std::vector<bool> unlocked(NUMBER_OF_BUILDINGS, false);
	unlocked[WAREHOUSE] = true;
	
	
	return unlocked;
}

std::vector<bool> game_session::set_unlocked_buildings()
{
	std::vector<bool> unlocked(NUMBER_OF_BUILDINGS, false);

	unlocked[HOUSE] = true;
	unlocked[MARKET] = true;
	unlocked[QUARRY] = true;
	unlocked[WOODCUTTER] = true;
	unlocked[FISHERMAN] = true;
	unlocked[HUNTER] = true;
	unlocked[APPLE_FARM] = true;
	unlocked[GREAT_HALL] = true;

	return unlocked;
}

void game_session::finish_serialization()
{
	button::set_basic_button_list(false);
	
	for(int i=0; i<session->tile_list.size(); ++i)
	{
		for(int j=0; j<session->tile_list[i].size(); ++j)
			session->tile_list[i][j]->finish_serialization();
	}
}


