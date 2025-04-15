#include "register_all_classes.h"

#include "base_enemy.h"
#include "gd_enemy/enemy_manager.h"
#include "gd_player.h"

namespace godot {

void register_all_classes() {
  ClassDB::register_class<GDPlayer>();
  ClassDB::register_class<GDBaseEnemy>();
  ClassDB::register_class<EnemyManager>();
}

} // namespace godot
