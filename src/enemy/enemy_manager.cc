#include "enemy_manager.h"
#include "godot_cpp/classes/node2d.hpp"
#include "godot_cpp/classes/object.hpp"
#include "godot_cpp/classes/packed_scene.hpp"
#include "godot_cpp/classes/scene_tree.hpp"
#include "godot_cpp/classes/timer.hpp"
#include "godot_cpp/core/class_db.hpp"
#include "godot_cpp/core/math.hpp"
#include "godot_cpp/core/object.hpp"
#include "godot_cpp/core/property_info.hpp"
#include "godot_cpp/variant/callable.hpp"
#include "godot_cpp/variant/callable_method_pointer.hpp"
#include "godot_cpp/variant/utility_functions.hpp"
#include "godot_cpp/variant/variant.hpp"
#include "godot_cpp/variant/vector2.hpp"

using namespace ::godot;

void EnemyManager::_bind_methods() {
  ClassDB::bind_method(D_METHOD("on_spawn_timeout"),
                       &EnemyManager::on_spawn_timeout);
  ClassDB::bind_method(D_METHOD("get_enemy_scene"),
                       &EnemyManager::get_enemy_scene);
  ClassDB::bind_method(D_METHOD("set_enemy_scene"),
                       &EnemyManager::set_enemy_scene);
  ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "enemy_scene",
                            PROPERTY_HINT_RESOURCE_TYPE, "PackedScene"),
               "set_enemy_scene", "get_enemy_scene");
}

void EnemyManager::_ready() {
  this->timer = get_node<Timer>("Timer");
  if (this->timer) {
    this->timer->connect("timeout",
                         callable_mp(this, &EnemyManager::on_spawn_timeout));
  }
}

void EnemyManager::on_spawn_timeout() {
  auto player =
      Object::cast_to<Node2D>(get_tree()->get_first_node_in_group("player"));
  if (!player || enemy_scene.is_null())
    return;
  float angle = UtilityFunctions::randf_range(0.0f, Math_PI * 2.0f);
  Vector2 direction = Vector2(1, 0).rotated(angle);
  Vector2 spawnd_position =
      player->get_global_position() + direction * this->spawn_radius;
  Node *instance = enemy_scene->instantiate();
  Node2D *enemy = Object::cast_to<Node2D>(instance);
  if (!enemy) {
    UtilityFunctions::print("Enemy instanc is not Node2D");
    return;
  }
  get_parent()->add_child(enemy);
  enemy->set_global_position(spawnd_position);
}
void EnemyManager::set_enemy_scene(const Ref<PackedScene> &scene) {
  enemy_scene = scene;
}
Ref<PackedScene> EnemyManager::get_enemy_scene() const { return enemy_scene; }