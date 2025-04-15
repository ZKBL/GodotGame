#ifndef __GD_ENEMY_MANAGER_H__
#define __GD_ENEMY_MANAGER_H__
#include "godot_cpp/classes/node.hpp"
#include "godot_cpp/classes/packed_scene.hpp"
#include "godot_cpp/classes/timer.hpp"

namespace godot {

class EnemyManager : public Node {
  GDCLASS(EnemyManager, Node)

private:
  Ref<PackedScene> enemy_scene;
  Timer *timer;
  static constexpr float spawn_radius = 350.0f;

protected:
  static void _bind_methods();

public:
  EnemyManager() = default;
  ~EnemyManager() = default;

  void _ready() override;
  void on_spawn_timeout();
  void set_enemy_scene(const Ref<PackedScene> &scene);
  Ref<PackedScene> get_enemy_scene() const;
};

} // namespace godot

#endif