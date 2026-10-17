# Vehicle sheets — first proposal (Q15)

Status: **proposed**. The starting point for the prototype; balancing is ongoing (C6).

The numbers start from the original SFML game (`src/Tank.h`, `src/AA.h`, `src/Hind.h` and the shell headers) so the
feel carries over, then change where the new design needs it. Every change from the original is marked **changed**.

## Armour classes (C6)

| Class | Who | Notes |
|---|---|---|
| Light | Jeeps, scout, supply jeep | Fast, fragile |
| Medium | AA, APCs, artillery | |
| Heavy | Tanks | Facing matters (below) |
| Air low | Chopper flying low | Hidden behind terrain, but hittable by ground guns when seen or guessed (M3) |
| Air high | Chopper flying high | Sees far; only anti-air weapons reach it |

**Facing (M6), for heavy armour only, against penetrating weapons (cannon, rockets):** front ×0.7 · side ×1.0 ·
rear ×1.5. Machine guns and flak ignore facing.

## Damage table (multiplier on a weapon's base damage)

| Weapon type | Light | Medium | Heavy | Air low | Air high |
|---|---|---|---|---|---|
| Cannon (tank shell) | 1.0 | 1.0 | 1.0 | 0 | 0 |
| Machine gun | 1.0 | 0.5 | 0.05 | 0.2 | 0 |
| Flak (AA) | 0.6 | 0.3 | 0.05 | 1.0 | 1.0 |
| Rockets (chopper) | 1.0 | 1.0 | 1.0 | 0 | 0 |
| Autocannon (chopper nose gun) | 1.0 | 0.4 | 0.05 | 0.5 | 0.3 |

A new weapon type is one more row; a new vehicle picks its weapons from the rows.

## Tank — heavy

| | Original | Proposed |
|---|---|---|
| HP | 3000 | 3000 |
| Speed / turn rate (relative) | 20 / 5 | 1.0 / 1.0 (the slowest) |
| Sight | 1300 | 1300 |
| Main gun | Cannon, 1000 per shell, 1 shot/s | Same. **Changed:** 30 shells, then rearm (M16) |
| Second weapon | Machine gun, 50 per round, 1 round per 0.17 s, hits only the chopper | Machine gun, same rate, hits everything by the table. **Changed:** range 600, shorter than the chopper's rockets; 600 rounds |
| Ability (M9) | — | Smoke: blocks sight in an area for 8 s; 2 charges |
| Module slots | — | 1 (e.g. dozer blade, fitted at a service point) |

## Chopper (was Hind) — air low / air high

| | Original | Proposed |
|---|---|---|
| HP | 1000 | 1000 |
| Speed / turn rate (relative) | 33 / 10 | 1.65 / 2.0 (the fastest) |
| Sight | 1300 | Low: 1100, blocked by terrain · High: 1800 |
| Main weapon | Rockets, 200 each, salvo of 5 (0.15 s apart), 4 s reload | Same. **Changed:** range 900; 20 rockets (4 salvos), then rearm |
| Second weapon | — | **New:** autocannon, 30 per round, 1 round per 0.1 s, range 700; 400 rounds |
| Altitude (M3) | — | Switch low/high in 1.5 s; the shadow shows the height (M4) |
| Ability (M10) | — | Flares: break AA lock for 3 s; 3 charges. Or winch (carry one vehicle) as an alternative loadout |
| Module slots | — | 1 |

## AA — medium

| | Original | Proposed |
|---|---|---|
| HP | 1500 | 1500 |
| Speed / turn rate (relative) | 25 / 7 | 1.25 / 1.4 |
| Sight | 1200 | 1200 on the ground; radar sees air high up to 2000, air low only in line of sight |
| Weapon | Flak, 150 per shell, 1 shell per 0.25 s | Same, damage by the table (limited against ground). **Changed:** range 1400 against air, 600 against ground; 200 shells |
| Ability (M11) | — | Radar ping: shows all aircraft within 3000 to the team for 5 s; 30 s cooldown |
| Module slots | — | 1 |

## Check: the old triangle still appears one on one

Rough time to kill, everything hitting, no terrain:

| Fight | Attacker's damage per second | Defender HP | Time to kill | Result |
|---|---|---|---|---|
| Tank → AA | Cannon 1000 × 1.0 / 1 s = 1000 | 1500 | ~2 s | **Tank wins** |
| AA → Tank | Flak 600 × 0.05 = 30 | 3000 | ~100 s | AA must run |
| Chopper → Tank (front) | Rockets ~210 × 0.7 = 147 | 3000 | ~20 s | **Chopper wins from standoff range** |
| Chopper → Tank (rear) | ~210 × 1.5 = 315 | 3000 | ~10 s | Flanking pays |
| Tank → Chopper (low, inside 600) | MG 294 × 0.2 = 59 | 1000 | ~17 s | Tank wins only if the chopper comes close |
| AA → Chopper | Flak 600 × 1.0 | 1000 | ~2 s | **AA wins** |
| Chopper → AA | Rockets ~210 × 1.0 | 1500 | ~7 s | Chopper must stay out of sight |

The counters come out of the table, ranges, terrain and altitude, not from a list of who beats whom. Ammo limits
mean a chopper kills about one tank per load before it has to rearm, which ties combat to logistics.

## To decide or test

- These numbers are first guesses. The prototype should show them as live-tunable values.
- Should the AA be able to fire on ground targets at all? This proposal says yes, weakly.
- Should the tank cannon hit low choppers at a small multiplier (e.g. 0.1)? This proposal says no.
