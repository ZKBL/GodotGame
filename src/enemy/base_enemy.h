#ifndef __GD_BASE_ENEMY_H__
#define __GD_BASE_ENEMY_H__

#include "godot_cpp/classes/area2d.hpp"
#include "godot_cpp/classes/character_body2d.hpp"
#include "godot_cpp/classes/node2d.hpp"
#include "godot_cpp/variant/vector2.hpp"

namespace godot {
class GDBaseEnemy : public CharacterBody2D {
  GDCLASS(GDBaseEnemy, CharacterBody2D)
private:
  static constexpr float MAX_SPEED = 50.0;
  Node2D *player = nullptr;

protected:
  static void _bind_methods();

public:
  GDBaseEnemy();
  ~GDBaseEnemy();
  void _ready() override;
  void _process(double delta) override;
  void on_area_entered(Area2D *other_area);
  Vector2 get_directioon_to_player();
};
} // namespace godot
#endif