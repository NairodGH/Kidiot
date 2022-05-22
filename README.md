# Kidiot

20/05/2022 Epitech Rennes Game Jam project by Dorian AYOUL and Xavier TONNELLIER.
Basically a 2d "Who's your daddy" coded in C with raylib.

## Map (floors) example

- b = baby spawn point
- m = mom spawn point

- B = Bathtub
- C = Cactus
- E = Electric outlet
- F = Fridge
- M = Microwave
- O = Oven
- T++ = Table (no interaction, collision)
- S = Staircase
- V = Vacuum cleaner
- W = WC
- Z = Zzz (no interaction, collision)

first_floor.txt
```
#######################
#W     B#M  E  F  E  O#
#       #             #
#E     C#             #
#### ####     T++     #
#       #             #
#       #             #
#       #  C       C  #
#       ####### #######
#                     #
#                     #
### ###      T++mb    #
#    C#              S#
#     #               #
#EV   #               #
#######################
```

second_floor.txt
```
#####################
#E   Z    #    Z   E#
#         #         #
#         #         #
#C        #        C#
##### ######### #####
#                   #
#         ######### #
#         #W     C# #
#         #       #S#
#         #       ###
#         #E       B#
#                   #
#####################
```

You can modify them as you please but keep the basics in place to not break it:
- 1 baby spawn point
- 1 mom spawn point
- 1 WC downstairs if 1 WC upstairs and vice versa

## Balancing

As the baby:
- Bathtub = press once to fill up then stay 4secs in it to drown
- Cactus = press once to take 10 damage, 5secs cooldown
- Electric outlet = stay on it for 5secs to electrocute
- Fridge = press once to open and stay in it to take 10 damage per second
- Microwave = press once to open then stay 3secs in it to gain a speed boost
- Oven = press once to open then stay 3secs in it to take 1 damage per second
- Vacuum cleaner = press once to vacuum the mom into it for 3secs no matter where she was
- WC = press once to teleport to the other toilet

As the mom:
- Bathtub = press once on it to empty the bath
- Cactus = press once on it to cut it (disables it)
- Electric outlet = press once on it to cancel the baby's electrocution
- Fridge = press once on it to cancel the baby's freeze
- Microwave = press once on on the baby to cancel its speedboost
- Oven = press once on it on the baby to extinguish it
- WC = press once on it (disables it)