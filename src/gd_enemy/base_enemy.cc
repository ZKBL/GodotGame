#include "base_enemy.h"
#include "godot_cpp/classes/area2d.hpp"
#include "godot_cpp/classes/node.hpp"
#include "godot_cpp/classes/object.hpp"
#include "godot_cpp/classes/scene_tree.hpp"
#include "godot_cpp/core/class_db.hpp"
#include "godot_cpp/variant/vector2.hpp"

using namespace godot;

void GDBaseEnemy::_bind_methods() {
  ClassDB::bind_method(D_METHOD("on_area_entered"),
                       &GDBaseEnemy::on_area_entered);
}
GDBaseEnemy::GDBaseEnemy() {}
GDBaseEnemy::~GDBaseEnemy() {}

void GDBaseEnemy::_ready() {
  Area2D *area = get_node<Area2D>("Area2D");
  if (area) {
    area->connect("area_entered", Callable(this, "on_area_entered"));
  }
  auto sencen_tree = get_tree();
  Node *candidate = sencen_tree->get_first_node_in_group("player");
  this->player = Object::cast_to<Node2D>(candidate);
}
void GDBaseEnemy::_process(double delta) {
  Vector2 direction = this->get_directioon_to_player();
  this->set_velocity(direction * this->MAX_SPEED);
  this->move_and_slide();
}
Vector2 GDBaseEnemy::get_directioon_to_player() {
  if (player) {
    return (player->get_global_position() - this->get_global_position())
        .normalized();
  }
  return Vector2(0, 0);
}

void GDBaseEnemy::on_area_entered(Area2D *area) { queue_free(); }