#ifndef BEDAS_ENUM_H
#define BEDAS_ENUM_H

enum building_type{
	HOUSE,
	MARKET,
	WAREHOUSE,
	GREAT_HALL,
	CHURCH,
	STORE,
	BARRACKS,
	SCOUT,
	QUARRY,
	WOODCUTTER,
	HUNTER,
	FISHERMAN,
	APPLE_FARM,
	DAIRY_FARM,
	WHEAT_FARM,
	WINDMILL,
	CLAY_PIT,
	POTTERY_WORKSHOP,
	BRICKMAKER,
	MARBLE_QUARRY,	
	GOLD_MINE,
	COAL_MINE,
	IRON_MINE,
	SMITH,
	ARMOURER,
	FLETCHER,
	PALISADE,
	WALL,
	NORTHWEST_TOWER,
	NORTHEAST_TOWER,
	SOUTHEAST_TOWER,
	SOUTHWEST_TOWER,
	NORTHWEST_STAIRS,
	NORTHEAST_STAIRS,
	SOUTHEAST_STAIRS,
	SOUTHWEST_STAIRS,
	LEFT_GATE,
	RIGHT_GATE,
	NUMBER_OF_BUILDINGS
};

enum resources{	
	WOOD,
	STONE,
	MARBLE,
	BRICKS,
	MILK,
	FISH,
	MEAT,
	FRUIT,
	CLAY,
	POTTERY,
	IRON,
	WEAPONS,
	BOWS,
	COAL,
	PLATE_ARMOR,
	WHEAT,
	BREAD,
	GOLD,
	NUMBER_OF_RESOURCES
};

enum building_size{
	ONE_TILE_BUILDING,
	FOUR_TILE_BUILDING,
	NINE_TILE_BUILDING,
	LEFT_GATE_BUILDING,
	RIGHT_GATE_BUILDING
};

enum picture{
	HOUSE_IMAGE,
	MARKET_IMAGE,
	WAREHOUSE_IMAGE,
	GREAT_HALL_IMAGE,
	CHURCH_IMAGE,
	STORE_IMAGE,
	BARRACKS_IMAGE,
	SCOUT_IMAGE,
	QUARRY_IMAGE,
	WOODCUTTER_IMAGE,
	HUNTER_IMAGE,
	FISHERMAN_IMAGE,
	APPLE_FARM_IMAGE,
	DAIRY_FARM_IMAGE,
	WHEAT_FARM_IMAGE,
	WINDMILL_IMAGE,
	CLAY_PIT_IMAGE,
	POTTERY_WORKSHOP_IMAGE,
	BRICKMAKER_IMAGE,
	MARBLE_QUARRY_IMAGE,
	GOLD_MINE_IMAGE,
	COAL_MINE_IMAGE,
	IRON_MINE_IMAGE,
	SMITH_IMAGE,
	ARMOURER_IMAGE,
	FLETCHER_IMAGE,
	PALISADE_IMAGE,
	WALL_IMAGE,
	TOWER_IMAGE,
	STAIRS_IMAGE,
	GATE_IMAGE,
	
	AXEMAN_IMAGE,		//needed for barracks
	BOWMAN_IMAGE,
	SPEARMAN_IMAGE,
	SWORDSMAN_IMAGE,
	CATAPULT_IMAGE,
	CARRIER_IMAGE,
	ARROW_IMAGE,
	ARCHERS_ARROW_IMAGE,
	CATAPULT_SHOT_IMAGE,
	TEXTURE_GREY_IMAGE,
	GRASS_IMAGE,
	PATHS_IMAGE,
	ROTATE_RIGHT_IMAGE,
	ROTATE_LEFT_IMAGE,
	REMOVE_BUILDING_IMAGE,
	STOP_WORKING_IMAGE,
	FEAST_IMAGE,
	NAVIGATION_BUTTONS_IMAGE,
	UPGRADE_IMAGE,
	LOCK_IMAGE,
	DETAILS_IMAGE,
	SMILE_IMAGE,
	HONOUR_IMAGE,
	STAR_IMAGE,
	TREE_IMAGE,
	RESOURCES_IMAGE,
	OPEN_GATE_IMAGE,
	ROCK_RESOURCES_IMAGE,
	FERTILE_IMAGE,
	//STONE_IMAGE,
	//IRON_IMAGE,
	WATER_IMAGE,
	NO_WORKERS_IMAGE,
	CLOSE_WINDOW_IMAGE,
	BUILDING_SELECTION_IMAGE, 
	NO_IMAGE,
	LAST_IMAGE
};


enum player{
	BLUE_PLAYER,
	RED_PLAYER
};

enum rotation{
	NO_ROTATION,
	RIGHT_ROTATION,
	LEFT_ROTATION
};


enum chosen{
	NOTHING_CHOSEN,
	PEOPLE_CHOSEN,
	BUILDING_CHOSEN,
	ACTION_CHOSEN
};


enum game_object_type{
	TILE,
	BUILDING,
	PEOPLE
};


enum missile_type{
	ARROW,			//this is from TOWER
	ARCHERS_ARROW,
	CATAPULT_SHOT
};


enum possible_borders
{
	NORMAL_BORDER,
	RAMP_BORDER,
	DOWN_BORDER,
	DOUBLE_DOWN_BORDER
};

enum people_type
{
	AXEMAN,
	BOWMAN,
	SPEARMAN,
	SWORDSMAN,
	CATAPULT,
	CARRIER,
	NUMBER_OF_PEOPLE
};


enum elevation{
	DOWN_ELEVATION,
	NO_ELEVATION,
	UP_ELEVATION
};


enum direction{
	NO_DIRECTION,
	NORTH,
	NORTHEAST,
	EAST,
	SOUTHEAST,
	SOUTH,
	SOUTHWEST,
	WEST,
	NORTHWEST
};

enum tile_type{
	GRASS,
	RAMP,
//	WATER
};

enum object_on_tile{
	NOTHING,
	IRON_TILE,
	MARBLE_TILE,
	COAL_TILE,
	GOLD_TILE,
	TREE_TILE,
	WATER_TILE,
	NUMBER_OF_TILE_OBJECTS
};

enum borders{	//you can see picures at grass.png - first enum is first picure
	GROUND_LEVEL,
	NO_BORDERS,
	NORTHEAST_BORDER,		
	SOUTHEAST_BORDER,
	SOUTHWEST_BORDER,
	NORTHWEST_BORDER,
	NORTH_BORDER,				//these have borders on two sides here for example on northwest and northeast
	EAST_BORDER,
	SOUTH_BORDER,
	WEST_BORDER,
	NORTHEAST_SOUTHWEST_BORDER,
	NORTHWEST_SOUTHEAST_BORDER,
	NORTH_INSIDE_BORDER,
	EAST_INSIDE_BORDER,
	SOUTH_INSIDE_BORDER,	
	WEST_INSIDE_BORDER,
	ALL_BORDERS,
	UNKNOWN_BORDERS
};

enum button_type{
	BUTTON_BUILD,
	BUTTON_PATH,
	NAVIGATION_BUTTON,
};

enum navigation_button_type{
	FOOD,
	ECONOMY,
	INDUSTRY,
	MILITARY,
	BACK,
	FORWARD
};

enum upgrade_level
{
	NO_UPGRADE,
	FIRST_UPGRADE,
	SECOND_UPGRADE,
	THIRD_UPGRADE
};

enum transaction_type
{
	IN_TRANSACTION,
	OUT_TRANSACTION
};

enum class resource_status
{
	NOT_TRADING,
	BUYING,
	SELLING
};

enum class target_priority
{
	NO_TARGET,
	AI_BUILDING_TARGET,
	ENEMY_NEARBY,
	FRIENDLY_UNIT_ATTACKED,
	ATTACKED_BY_ENEMY,
	PLAYER_ORDER
};

enum class game_state
{
	GAME,
	MAIN_MENU,
	SETTINGS,
	INGAME_MENU,
	SAVE_MENU,
	RANDOM_GAME_SETTINGS,
	END_OF_GAME,
	NUMBER_OF_STATES
};

enum class natural_resources
{
	WATER,
	WOOD,
	FERTILE_SOIL,
	IRON,
	COAL,
	MARBLE,
	GOLD
};

enum class can_build_output
{
	CAN_BUILD,
	MISSING_WOOD,
	MISSING_STONE,
	MISSING_BRICKS,
	MISSING_MARBLE,
	NO_TREES,
	NO_WATER,
	NO_FERTILE_LAND,
	NO_IRON,
	NO_COAL,
	NO_MARBLE,
	NO_GOLD,
	NO_ROCKS,
	NO_SPACE,
	ENEMIES_NEARBY
};

enum class production_building_status
{
	WORKING,
	NO_CAPACITY,
	NO_BASIC_RESOURCES,
	STOPPED,
	NO_WORKERS_NEARBY,
	NO_PATH,
};

#endif

