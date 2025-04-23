#include "player.h"
#include "godot_cpp/classes/engine.hpp"
#include "godot_cpp/classes/input.hpp"

using namespace godot;

void GDPlayer::_bind_methods() {}
GDPlayer::GDPlayer() {}
GDPlayer::~GDPlayer() {}

Vector2 GDPlayer::_get_movement_vector() {
  auto input = Input::get_singleton();
  auto x_movement = input->get_action_strength("move_right") -
                    input->get_action_strength("move_left");
  auto y_movement = input->get_action_strength("move_down") -
                    input->get_action_strength("move_up");
  return Vector2(x_movement, y_movement);
}
void GDPlayer::_process(double delta) {
  if (Engine::get_singleton()->is_editor_hint())
    return;
  auto movement_vector = this->_get_movement_vector();
  auto direction = movement_vector.normalized();
  auto target_velocity =
      this->get_velocity().lerp(direction * this->max_speed,
                                1 - exp(-delta * this->acceleration_smoothing));
  this->set_velocity(direction * this->max_speed);
  this->move_and_slide();
}