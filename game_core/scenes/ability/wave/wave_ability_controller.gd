extends Node
@export var wave_ability:PackedScene

func _ready() -> void:
	$Timer.timeout.connect(on_timer_timeout)
	
func euclidean_distance(p1: Vector2, p2: Vector2) -> float:
	return p1.distance_to(p2)
func on_timer_timeout():
	var player = get_tree().get_first_node_in_group("player")  as Node2D
	if player == null:
		return
	var enemies = get_tree().get_nodes_in_group("enemy").filter(func(enemy:Node2D):
		return enemy.global_position.distance_squared_to(player.global_position) < pow(150,2)
	)
	if enemies.size() ==0:
		return 
	enemies.sort_custom(func(a:Node2D,b:Node2D): 
		var a_distance = a.global_position.distance_squared_to(player.global_position)
		var b_distance = b.global_position.distance_squared_to(player.global_position)
		return a_distance < b_distance
	)
	var wave_instance = wave_ability.instantiate() as Node2D
	player.get_parent().add_child(wave_instance)
	wave_instance.global_position = enemies[0].global_position
