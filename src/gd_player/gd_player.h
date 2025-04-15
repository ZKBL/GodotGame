#ifndef __GD_PLAYER_H_
#define __GD_PLAYER_H_
#include "godot_cpp/classes/character_body2d.hpp"
#include "godot_cpp/variant/vector2.hpp"

namespace godot {
class GDPlayer : public CharacterBody2D {
  GDCLASS(GDPlayer, CharacterBody2D)
private:
  int max_speed = 150;
  float acceleration_smoothing = 25;

protected:
  static void _bind_methods();

public:
  GDPlayer();
  ~GDPlayer();
  void _process(double delta) override;
  Vector2 _get_movement_vector();
};

} // namespace godot
#endif