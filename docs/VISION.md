# 2D-Warfare — vision

Draft. Built from the decisions in `docs/VISION-PROPOSALS.md` (item numbers in brackets). Open points are marked
**open** and listed there as questions.

## The game in one paragraph

An isometric combined-arms battle game. Each player drives one vehicle (a tank, a chopper, an AA truck, an APC, a
supply jeep, …) and can command AI units around them. Every vehicle is good at some jobs and weak at others, as in a
real army, but played in a quick, arcade-ish way with some realism mixed in. Terrain shapes how a fight is played,
vehicles have to rearm and get repaired, and battles can be small duels or large fights with many units and several
factions. Singleplayer and coop tell a story through missions; multiplayer is team modes and big battles.

## Pillars

1. **Combined arms.** No vehicle wins alone. Each has a role, strengths and weaknesses, and teams that mix roles
   win. (C2, C6)
2. **Terrain shapes tactics.** Maps create cover, ambushes, surprises and routes. They change how people play, not
   who wins. (M1, M2, M13)
3. **Logistics matter.** Ammo runs out, damage adds up, and modules need a workshop. Supply vehicles and maintenance
   points are part of the fight. (M14, M15, M16)
4. **You lead, if you want.** One vehicle per player, plus AI units that follow orders or act on their own. (Q2, G13)
5. **Pace is a setting.** Fast sessions play more like an arcade game, slow ones more tactically. (Q1)

## Combat

- **Roles, not a fixed triangle.** Damage depends on the weapon and the target's armour class (light, medium,
  heavy, air low, air high). A machine gun shreds jeeps and low choppers and only scratches a tank; an anti-tank
  rocket is the opposite; flak only hits air. Vehicles carry a mix, so most can fight most things, with a clear best
  and worst use. (C2, C6, proposed)
- **The original triangle still holds one-on-one:** AA beats Chopper, Chopper beats Tank, Tank beats AA. It is one
  result of the role system, not the core concept. (C1, C2)
- **Facing and parts.** Tank armour is strong at the front and weak at the sides and rear. Hull and turret are
  separate parts. (M6, M7)
- **Line of sight.** Ridges, buildings and forests block shots and sight. (M2)
- **Altitude.** Choppers fly low or high. Low hides them behind terrain, but a detected or guessed chopper still takes
  ground fire. High sees far and is exposed to AA. The ground shadow shows the altitude. (M3, M4)
- **Fog of war** is a match setting. Both on and off must be fun. (M5)

## Vehicles

- **Abilities and loadouts.** Each vehicle starts with one ability slot; some will get more later. Weapons can be
  swapped. Examples: tank smoke, overdrive or dozer blade; chopper flares, rocket pods or winch; AA radar ping, flak
  burst or decoy. (M8–M12)
- **The winch** carries crates and soldiers, and can haul one destroyed or damaged vehicle away. (M10)
- **Modules are installed, not earned.** A dozer blade or a new weapon is fitted at a specialised point on the map.
  (M14)
- **Roster:** Tank, Chopper (the old "Hind") and AA first. Then artillery/SCUD with a spotter, scout jeep, heavy tank,
  APC variants (machine gun, rockets, limited anti-air or anti-tank), supply jeep, long-range rockets, gunboats.
  Infantry later. (U1–U9, C4)
- **Strong weapons cost something.** Long-range rockets are powerful but expensive and easy for AA to shoot down.
  What "expensive" means is **open**. (M15, Q6)

## Logistics

- Vehicles **rearm** and are **repaired** with carried parts or at maintenance points such as garages. (M16)
- **Supply jeeps** bring parts to the front to repair vehicles and restore HP. (M15)
- Workshops, garages and depots are places worth guarding and attacking. (G13, Q9)

## Terrain and maps

- Hills, ridges, valleys, forests, buildings, rivers and bridges. Trees can be flattened, buildings collapse,
  craters stay. (M1, M13)
- **Hand-made and generated maps.** Hand-made maps are balanced and designed; generated maps give variety, and
  destruction can be generated too. Which modes use which is **open**. (A1, M13, Q11)
- Ground and air units have separate pathfinding. (A2)

## AI and command

- Bots use cover and line of sight, and know what they are good and bad against. (A3)
- AI units fight in squads. (A4)
- In large battles, AI units take a player's orders (attack, guard, follow, hold) or are assigned automatically.
  They attack when it makes sense and guard important objects. (G13, Q2)

## Modes

**Singleplayer and coop (1–4 players):** story missions, the same for one player or a team (G1–G7):
- Destroy SCUD launchers before the launch timer runs out.
- Escort a convoy through an ambush valley.
- Rescue a downed pilot with the chopper's winch.
- Hold a hill until reinforcements arrive.

The story is told through mission briefings, radio chatter during play and a campaign map. Coop roles fit together,
and difficulty scales with the number of players.

**Skirmish** against bots: the original game, kept as the sandbox. (G8)

**Multiplayer:** Conquest, Convoy, Team Deathmatch and King of the Hill, from 2v2 up to 8v8, with bots filling empty
slots. (G9–G12)

**Large battle:** many units per side, possibly more than two factions, with AI units under command. Scale is
**open**. (G13, Q7, Q8)

## Pace

Balanced between arcade and tactical by default. Session settings move it either way: respawn time, damage,
rearm and repair time, fog of war. Map size is **open**. (Q1, Q7)

## Look and sound

- **Isometric view, done really well.** How it is drawn is **open**: sprites, pre-rendered models, or 3D with a fixed
  isometric camera. (Q3, Q5)
- Lighting: shadows for altitude, muzzle flashes at night, lasting scorch marks. Desert first, then forest, snow and
  urban. (R2, R3)
- All ripped sprites and music are replaced before any release with original or licensed work. (R4, R5)
- Fictional factions, no real-world nations. (C5)

## Technology

- **Godot 4.** A rewrite: the design carries over, the SFML code does not. (T1, T2)
- **Vehicles are built from parts:** movement, turret, weapons, armour, sensor and AI brain. Stats live in data files,
  so a new vehicle is mostly data and art. Modding support later. (T3–T5)
- **Networking:** the server is authoritative, and one player hosts at first. It is built early, before content. (T6, T7)

## Order of work

1. Finish this vision.
2. "Is it fun?" prototype: one map, three vehicles, the role-based damage model, line of sight, altitude, bots.
3. Two-player coop and PvP.
4. Content: modes, more units, missions, a three-mission campaign slice.
5. Art and audio pass.
