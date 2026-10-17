# 2D-Warfare — vision proposals

Everything suggested so far, one item per line, so each can be accepted, changed or dropped by number.
Status: `proposed` until the owner decides. Accepted items move into `docs/VISION.md`.

## Core idea

| # | Proposal | Status |
|---|---|---|
| C1 | Pitch: *a top-down combined-arms game where every vehicle has a hunter and a prey, and terrain decides who wins the fight* | proposed |
| C2 | Keep the counter triangle as the spine: AA beats Chopper, Chopper beats Tank, Tank beats AA | proposed |
| C3 | Make counters soft, not hard: every unit can fight every other, just at a disadvantage against its counter | proposed |
| C4 | Rename Hind to Chopper everywhere (code, assets, UI) | proposed |
| C5 | Fictional conflict and factions, no real-world nations or politics | proposed |

## Mechanics

| # | Proposal | Status |
|---|---|---|
| M1 | Terrain changes matchups: ridges, valleys, forests, buildings, water | proposed |
| M2 | Line of sight: AA needs a clear view of its target; ridges and buildings block shots and sight | proposed |
| M3 | Chopper altitude, low or high. Low: hidden behind terrain, hittable by tank machine guns. High: sees far and spots for the team, exposed to AA | proposed |
| M4 | A ground shadow that moves away from the chopper as it climbs, so altitude is readable at a glance | proposed |
| M5 | Fog of war and spotting: you see only what your team sees; smoke, forest and buildings block sight | proposed |
| M6 | Tank armor depends on facing (strong front, weak sides and rear), which rewards flanking | proposed |
| M7 | Hull and turret stay separate parts (already in the code), possibly with separate damage | proposed |
| M8 | One active ability slot per vehicle, chosen in a loadout | proposed |
| M9 | Tank abilities: smoke, overdrive engine, dozer blade | proposed |
| M10 | Chopper abilities: flares, rocket pods, winch (carry crates and soldiers, rescue pilots) | proposed |
| M11 | AA abilities: radar ping (reveals air on the map), flak burst, decoy | proposed |
| M12 | Swappable weapon loadouts per vehicle | proposed |
| M13 | Terrain you can change: craters, flattened trees, collapsing buildings that open flanking paths | proposed |
| M14 | Pickups and call-ins earned from objectives: repair, ammo, airstrike, recon drone | proposed |

## Units (roster)

| # | Proposal | Status |
|---|---|---|
| U1 | First release: Tank, Chopper, AA | proposed |
| U2 | Artillery / SCUD: indirect fire that needs a spotter (sprite already in `assets/`) | proposed |
| U3 | Scout jeep: fast, fragile, spots for the team | proposed |
| U4 | Heavy tank: slow anchor unit (sprite already in `assets/`) | proposed |
| U5 | Gunboats for water maps (sprite already in `assets/etc`) | proposed |
| U6 | Infantry, later: anti-tank soldiers, capture squads, pilots who bail out and can be rescued | proposed |

## Modes

| # | Proposal | Status |
|---|---|---|
| G1 | Singleplayer and coop (1–4 players) share the same story missions | proposed |
| G2 | Mission: destroy SCUD launchers before the launch timer, slipping through radar coverage | proposed |
| G3 | Mission: escort a convoy through an ambush valley | proposed |
| G4 | Mission: rescue a downed pilot with the chopper's winch while tanks hold the landing zone | proposed |
| G5 | Mission: hold a hill until reinforcements arrive | proposed |
| G6 | Story told through mission briefings, radio chatter during play and a campaign map | proposed |
| G7 | Coop roles fit together (chopper spots, tank holds the line); difficulty scales with player count | proposed |
| G8 | Skirmish vs bots: today's free-for-all, kept as the sandbox mode | proposed |
| G9 | Multiplayer Conquest: capture points with tickets | proposed |
| G10 | Multiplayer Convoy: asymmetric attack and defend | proposed |
| G11 | Multiplayer Team Deathmatch and King of the Hill as quick modes | proposed |
| G12 | Match size 2v2 up to 8v8, bots fill empty slots | proposed |

## Maps and AI

| # | Proposal | Status |
|---|---|---|
| A1 | Hand-made maps built in an editor (tilemaps with terrain painting), not generated in code | proposed |
| A2 | Separate pathfinding for ground units (avoid water and cliffs) and air units (go anywhere) | proposed |
| A3 | Bot AI that uses cover and line of sight, and knows its counters (seek prey, avoid hunters) | proposed |
| A4 | Bots act in squads for missions (ambushes, patrols, convoys) | proposed |

## Art and audio

| # | Proposal | Status |
|---|---|---|
| R1 | Clean top-down pixel art in the spirit of *Desert Strike* or *Cannon Fodder* | proposed |
| R2 | Engine 2D lighting: shadows for altitude, muzzle flashes at night, lasting scorch marks | proposed |
| R3 | Desert as the first biome; forest, snow and urban later | proposed |
| R4 | Replace all ripped assets before any release: *Desert War* sprites, *Heroes & Generals* music | proposed |
| R5 | Original or properly licensed music and sound | proposed |

## Technology

| # | Proposal | Status |
|---|---|---|
| T1 | Move to Godot 4 (2D tilemaps, built-in navigation and multiplayer, exports to Windows, Linux and web) | proposed |
| T2 | Rewrite rather than refactor: carry over the design and the ideas, not the SFML code | proposed |
| T3 | A vehicle built from reusable parts: movement (tracks, wheels, rotor), turret, weapons, armor, sensor, AI brain | proposed |
| T4 | Unit and weapon stats in data files: a new vehicle is a sprite plus a data file, not new code | proposed |
| T5 | Modding support later, built on T4 | proposed |
| T6 | Server-authoritative networking; one player hosts at first, dedicated servers later | proposed |
| T7 | Networking built early, before content, because adding it afterwards is painful | proposed |

## Order of work

| # | Proposal | Status |
|---|---|---|
| P1 | Finish the vision document (`docs/VISION.md`) | proposed |
| P2 | "Is it fun?" prototype: one map with hills and forest, three vehicles, soft counters, line of sight and altitude, vs bots | proposed |
| P3 | Two-player coop and PvP working | proposed |
| P4 | Content: modes, next units, mission scripting, a 3-mission campaign slice | proposed |
| P5 | Art and audio pass | proposed |

## Open questions for the owner

| # | Question | Leaning |
|---|---|---|
| Q1 | Pacing: arcade (fast, cheap deaths) or tactical (slow, spotting-heavy)? | arcade-tactical: quick to play, depth from terrain |
| Q2 | Control: one vehicle per player, or command a small squad too (RTS hybrid)? | one vehicle; squads maybe later |
| Q3 | Perspective: stay pure top-down? | yes |
| Q4 | Engine: Godot (GDScript or C#), or stay in C++? | Godot |
