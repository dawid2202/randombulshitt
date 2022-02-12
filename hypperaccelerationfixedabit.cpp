#include <stdafx.h>

float velocityMultiplierPerSec = 1.05f; //Determines the multiplier for the velocity of entities every second.
static DWORD64 lastTick = 0;

static void OnTick()
{
	std::vector<Entity> entities;

	for (Ped ped : GetAllPeds())
	{
		entities.push_back(ped);
	}

	for (Vehicle veh : GetAllVehs())
	{
		entities.push_back(veh);
	}

	for (Entity prop : GetAllProps())
	{
		entities.push_back(prop);
	}

	DWORD64 curTick = GET_GAME_TIMER();
	if (curTick > lastTick + 50)
	{
		lastTick = curTick;
		for (Entity entity : entities)
		{
			Vector3 entityVel = GET_ENTITY_VELOCITY(entity);
			if (IS_ENTITY_A_PED(entity))
			{
				if (IS_PED_IN_ANY_VEHICLE(entity, false))
				{
					Vehicle pedVeh = GET_VEHICLE_PED_IS_IN(entity, false);
					if (!IS_VEHICLE_SEAT_FREE(pedVeh, -1, false))
					{
						Ped driver = GET_PED_IN_VEHICLE_SEAT(pedVeh, -1, false);
						if (driver == entity)
						{
							SET_ENTITY_VELOCITY(pedVeh, entityVel.x + entityVel.x / 2.f * velocityMultiplierPerSec, entityVel.y + entityVel.y / 2.f * velocityMultiplierPerSec, entityVel.z + entityVel.z / 2.f * velocityMultiplierPerSec);
						}
					}
				}
				else
				{
					SET_ENTITY_VELOCITY(entity, entityVel.x + entityVel.x * velocityMultiplierPerSec, entityVel.y * velocityMultiplierPerSec, entityVel.z + entityVel.z * velocityMultiplierPerSec);
				}
			}
		}
	}
}

static RegisterEffect registerEffect(EFFECT_MISC_HYPERACCEL, nullptr, nullptr, OnTick, EffectInfo
	{
		.Name = "Hyper Acceleration",
		.Id = "misc_hyperaccel",
		.IsTimed = true
	}
);