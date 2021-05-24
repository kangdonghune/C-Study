#pragma once

namespace GAMEOBJECT
{
	enum Object {PLAYER_BULLET, MONSTER_BULLET, GRENADE , PLAYER, MONSTER, BOSS , GUN, BOSSGUN, ITEM, UI, END };
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