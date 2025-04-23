#include "register_all_classes.h"

#include "enemy/base_enemy.h"
#include "enemy/enemy_manager.h"
#include "player/player.h"

namespace godot {

void register_all_classes() {
  ClassDB::register_class<GDPlayer>();
  ClassDB::register_class<GDBaseEnemy>();
  ClassDB::register_class<EnemyManager>();
}

} // namespace godot
