
/**
 * \file object.h
 * \brief Contains game_object class which represents all objects on game map.
 */

#ifndef object_h_bedas_guard
#define object_h_bedas_guard

#include "core.h"

class chosen_mouse;

class tile;

extern std::ofstream log_file;

int compute_game_x(int tile_x, int tile_y);		//defined in core.h
int compute_game_y(int tile_x, int tile_y);

/**
 * \brief Represents any ingame object which can be drawn.
 */
class game_object {
public:
	game_object(int tile_x, int tile_y, int surface_height, bool is_real, picture image, int number_of_floors, game_object_type type_of_object);
	virtual ~game_object() {}
	void update(int tile_x, int tile_y, int surface_height);		///< Sets new position of object.
	virtual std::vector<game_object*> draw(int screen_position_x, int screen_position_y) = 0;	///< Draws the object and returns any objects above on the same coordinates.
	int show_surface_height() {return surface_height;}
	int show_current_drawing_height() {return surface_height + drawing_floor;}
	int show_tile_x() {return tile_x;}
	int show_tile_y() {return tile_y;}
	int show_game_x() {return compute_game_x(tile_x, tile_y);}
	int show_game_y() {return compute_game_y(tile_x, tile_y);}
	virtual bool show_visible() {return true;}
	virtual void set_surface_height(int height);	
	virtual void rotate(int tile_x, int tile_y, bool clockwise) {update(tile_x, tile_y, this->surface_height);}
	
	static int highest_surface;
	bool draw_green;			///< Used when player is choosing location of new building. New building is green, if it can be build on given location.
	game_object_type type_of_object;	
	
	friend class boost::serialization::access;

	template <class Archive>
	void serialize(Archive & ar, const unsigned int version)
	{
		LOG("serializing");
		
		using boost::serialization::make_nvp;
		
		ar & make_nvp("highest_surface", highest_surface);
		ar & make_nvp("draw_green", draw_green);
		ar & make_nvp("type_of_object", type_of_object);
		ar & make_nvp("tile_x", tile_x);
		ar & make_nvp("tile_y", tile_y);
		ar & make_nvp("game_x", game_x);
		ar & make_nvp("game_y", game_y);
		ar & make_nvp("number_of_floors", number_of_floors);
		ar & make_nvp("drawing_floor", drawing_floor);
		ar & make_nvp("is_real", is_real);
		ar & make_nvp("image", image);
		ar & make_nvp("surface_height", surface_height);
	}

protected:
	int tile_x;		///< Second index to tile_list and x coordinate in map, where x axes is diagonal, lower values on upper-left, higher on lower-right. 
	int tile_y;		///< First index to tile_list and y coordinate in map, where y axes is diagonal, lower values on upper-right, higher on lower-left. 
	int game_x;		///< Pixels from the most left point of the map.
	int game_y;		///< Pixels from the highest point of the map. 
	int number_of_floors;	///< Some higher objects are drawn one floor at a time to achieve right perspective.
	int drawing_floor;	///< Which floor will be drawn next.
	bool is_real;		///< Unreal objects don't interact with the rest of the game but must be drawed in right place.
	picture image;
	game_object() {}		//for boost serialization

private:
	int surface_height;
};

#endif
