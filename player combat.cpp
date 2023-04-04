// Player combat function
void playerCombat(Enemy& enemy) {
    // Check if the player and enemy are within attacking range
    if (isWithinRange(player, enemy)) {
        // Player attacks first
        enemy.health -= player.attackDamage;
        // Check if the enemy is still alive
        if (enemy.health > 0) {
            // Enemy attacks back
            player.health -= enemy.attackDamage;
            // Check if the player is still alive
            if (player.health <= 0) {
                // Player is dead, end game
                gameOver();
            }
        }
        else {
            // Enemy is dead, player wins
            player.winCount++;
            enemyCount--;
        }
    }
}

// Function to check if the player and enemy are within attacking range
bool isWithinRange(Player& player, Enemy& enemy) {
    float distance = sqrt(pow(player.position.x - enemy.position.x, 2) + pow(player.position.y - enemy.position.y, 2));
    if (distance <= player.attackRange) {
        return true;
    }
    else {
        return false;
    }
}
