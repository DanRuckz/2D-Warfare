# 2D-Warfare — vision proposals

Every suggestion, one per line, with the owner's decision. Accepted and changed items are written up in
`docs/VISION.md`; this file keeps the record of what was proposed and why it changed.

Status: `proposed` · `accepted` · `changed` (accepted with the owner's change, see note) · `dropped` · `new` (added by the owner)

## Core idea

| # | Proposal | Status | Owner's note |
|---|---|---|---|
| C1 | Pitch: every vehicle has a hunter and a prey, and terrain decides who wins | changed | The hunter/prey premise exists, balanced, but it is not the core concept of the game |
| C2 | Keep the counter triangle: AA beats Chopper, Chopper beats Tank, Tank beats AA | changed | True one-on-one, but more vehicle types are coming. Each vehicle gets general and specialised abilities, like the real world (some APCs only have machine guns, some fire rockets, some do limited anti-air or anti-tank). Arcade-ish with some realism mixed in |
| C3 | Soft counters instead of hard ones | changed | Replaced by the role system of C2 (see C6) |
| C4 | Rename Hind to Chopper | accepted | |
| C5 | Fictional conflict and factions | accepted | |
| C6 | Counters come from weapons against armour classes, not from a list of who beats whom: every weapon has a damage profile per armour class (light, medium, heavy, air low, air high), and every vehicle carries a mix | accepted | Must be balanced |

## Mechanics

| # | Proposal | Status | Owner's note |
|---|---|---|---|
| M1 | Terrain changes matchups | changed | Terrain and map change how people play and should play: tactics, surprises. They do not decide who wins. Maps are both hand-made and generated |
| M2 | Line of sight | accepted | |
| M3 | Chopper altitude, low or high | changed | A low chopper that is detected (or guessed) still takes damage from ground units |
| M4 | Shadow shows altitude | accepted | |
| M5 | Fog of war and spotting | changed | A match setting, not forced; both modes must be interesting |
| M6 | Tank armour depends on facing | accepted | |
| M7 | Hull and turret are separate parts | accepted | |
| M8 | One ability slot per vehicle | changed | Some vehicles will have several; start with one |
| M9 | Tank abilities: smoke, overdrive, dozer blade | accepted | |
| M10 | Chopper abilities: flares, rocket pods, winch | changed | The winch also carries away destroyed or damaged vehicles, one at a time |
| M11 | AA abilities: radar ping, flak burst, decoy | accepted | |
| M12 | Swappable weapon loadouts | accepted | |
| M13 | Terrain you can change | changed | Also generated |
| M14 | Pickups and call-ins earned from objectives | dropped | Abilities are not earned. Swappable modules (e.g. a dozer blade to flatten trees) are installed at specialised points on the map |
| M15 | More support vehicles: jeeps that carry parts to repair tanks and restore HP; long-range rockets that are expensive and easily shot down by AA | new | What "expensive" means is open (Q6) |
| M16 | Vehicles rearm, and are repaired with items or at maintenance points (garages) | new | |
| M17 | AI command set, kept small: attack (a target or area), defend (a point), follow me, hold position, return to rearm | accepted | Follows from Q16 |
| M18 | Chopper evasive manoeuvre: the chopper can break away and dodge, which helps it avoid shots. It cannot evade while committed to an attack (firing a salvo) or when caught by surprise, so those are the best moments to catch it | new, future | Owner's idea for later |

## Units (roster)

| # | Proposal | Status |
|---|---|---|
| U1 | First release: Tank, Chopper, AA | accepted |
| U2 | Artillery / SCUD with a spotter | accepted |
| U3 | Scout jeep | accepted |
| U4 | Heavy tank | accepted |
| U5 | Gunboats | accepted |
| U6 | Infantry, later | accepted |
| U7 | APCs in several variants (machine gun only, rockets, limited anti-air, limited anti-tank) | new |
| U8 | Supply jeep carrying repair parts (M15) | new |
| U9 | Long-range rocket launcher, expensive and vulnerable to AA (M15) | new |

## Modes

| # | Proposal | Status | Owner's note |
|---|---|---|---|
| G1 | Singleplayer and coop share story missions | accepted | |
| G2–G5 | Missions: SCUD hunt, convoy escort, pilot rescue, hold the hill | accepted | |
| G6 | Story via briefings, radio chatter, campaign map | accepted | |
| G7 | Coop roles fit together; difficulty scales | accepted | |
| G8 | Skirmish vs bots | accepted | |
| G9–G11 | Conquest, Convoy, Team Deathmatch, King of the Hill | accepted | |
| G12 | 2v2 to 8v8, bots fill slots | accepted | |
| G13 | Large battle: many units on each side, possibly more than two factions in one round. AI units either take orders or are assigned automatically; they launch attacks and guard important objects | new | Which objects are "important" is open (Q9) |

## Maps and AI

| # | Proposal | Status | Owner's note |
|---|---|---|---|
| A1 | Hand-made maps from an editor | changed | Hand-made and generated |
| A2 | Separate pathfinding for ground and air | accepted | |
| A3 | Bots use cover, line of sight, know their counters | accepted | |
| A4 | Bot squads in missions | accepted | |

## Art and audio

| # | Proposal | Status | Owner's note |
|---|---|---|---|
| R1 | Top-down pixel art | changed | Replaced by low-poly 3D seen through a fixed isometric camera (Q5) |
| R2 | 2D lighting: shadows, muzzle flashes, scorch marks | accepted | |
| R3 | Desert as first biome | accepted | |
| R4 | Replace ripped assets before release | accepted | |
| R5 | Original or licensed music and sound | accepted | |

## Technology

| # | Proposal | Status |
|---|---|---|
| T1 | Godot 4 | accepted |
| T2 | Rewrite, carry over the design not the code | accepted |
| T3 | Vehicles built from reusable parts | accepted |
| T4 | Stats in data files | accepted |
| T5 | Modding later | accepted |
| T6 | Server-authoritative, one player hosts at first | accepted |
| T7 | Networking early | accepted |

## Order of work

| # | Proposal | Status |
|---|---|---|
| P1–P5 | Vision → "is it fun?" prototype → two-player coop and PvP → content → art and audio | accepted |

## Questions

| # | Question | Answer / leaning |
|---|---|---|
| Q1 | Pacing | **Answered:** balanced, between arcade and tactical, adjustable per session (fast = more arcade, slow = more tactical) |
| Q2 | Control | **Answered:** one vehicle per player, who can command AI units if they choose |
| Q3 | Perspective | **Answered:** isometric, done really well |
| Q4 | Engine | **Answered:** move to a better technology (Godot, T1) |
| Q5 | How to draw isometric: (a) hand-drawn isometric sprites, 8–16 directions per hull and turret; (b) 3D models pre-rendered into sprites; (c) real low-poly 3D with a fixed isometric camera, gameplay still on a flat 2D plane | **Answered:** (c), with free 360° rotation of hulls and turrets, angles calculated as in the original game (no fixed set of directions) |
| Q6 | What "expensive" means for strong weapons: a per-match supply budget, tickets, or only long reload and rearm times | **Answered:** long reload and rearm, and rearming means driving back to the main base or having a logistics vehicle bring supplies |
| Q7 | Map size and match scale: players and AI units per match, especially for G13 | **Answered:** varies; a setting per map and mode (technical limits still to be measured) |
| Q8 | Factions: how many per round (2–4?), and do they share one roster or each have their own vehicles? | **Answered:** varies; a setting per map and mode |
| Q9 | Which objects are "important" (things to guard and attack): HQ, garage/workshop, ammo depot, radar, helipad, bridges, artillery positions? | **Partly answered:** for now there are maintenance stations and a main base. No HQ yet; which buildings exist and what each is for is still to be invented |
| Q10 | How a player gets a vehicle: free choice at respawn (today), limited by budget or slots, or only at bases the team holds | **Open.** For testing: free choice of one vehicle after each death, as today |
| Q11 | Which modes use generated maps and which use hand-made ones (e.g. competitive = hand-made and balanced, skirmish and battle = generated) | **Answered:** that split as the default, but both kinds stay available in every mode; options that playtesting shows are irrelevant or not fun are removed over time |
| Q12 | Setting and story: who the factions are, what the war is about, the tone (serious, pulpy, satirical), the first campaign arc | **Open.** Needs its own study and proposals; must fit the art style and the game's overall message |
| Q13 | Buildings: what each structure does (e.g. radar reveals an area, helipad rearms choppers, workshop fits modules, bridge controls a route) | **Answered for now:** one main base, plus service points that can be built or captured, where vehicles are repaired, rearmed and resources are delivered from. More later |
| Q14 | How a match is won, per mode: tickets, objectives, destroying the main base | **Partly answered:** one way is taking control of the enemy main base; the rest later |
| Q15 | First vehicle sheets: stats, weapons and armour class for Tank, Chopper and AA, and a first draft of the damage table (C6). The prototype starts from these | **Proposed:** `docs/VEHICLE-SHEETS.md`. Settled so far: the AA can fire on ground targets (weakly); the tank cannon cannot hit choppers |
| Q16 | Controls: mouse and keyboard, gamepad support, and how orders are given to AI units | **Answered:** WASD and mouse. AI orders are simple: pick a group, give a command. Built-in group presets (tanks, choppers, AA, more; mixed groups for assault and for defence), and players can make their own presets. Group size varies with game size and mode |
