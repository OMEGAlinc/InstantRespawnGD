#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

class $modify(InstantRespawn, PlayLayer) {
    void destroyPlayer(PlayerObject* player, GameObject* obj) {
        PlayLayer::destroyPlayer(player, obj); // Call original function

        // Ensure instant respawn only happens when the player actually dies
        if (player->m_isDead && !this->m_hasCompletedLevel) {
            this->resetLevel(); // Instantly restart the level
        }
    }
};
