#pragma once

namespace GAMEOBJECT
{
	enum Object { MONSTER_BULLET, PLAYER, PLAYER_BULLET, MONSTER, BOSS , GUN, BOSSGUN, GRENADE, ITEM, UI, END };
}

namespace MAPOBJECT
{
	enum Object {TILE, CELLING ,WALL, PORTAL, BUTTON, END};
}

namespace MAPOBJECTTYPE
{
	enum TYPE {PASS, NONEPASS, END};
}

namespace MONSTER
{
	enum Name { TURTLE, BOSS, END };
}

namespace ITEM
{
	enum Name { PISTOL, MACHINGUN, SHOTGUN, BOSSGUN, GRENADE, END};
}