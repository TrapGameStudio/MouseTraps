# MouseTraps
Mouse Traps is a progressive level arcade game were mice and other vermin walk around a maze with the objective of reproducing to the point of world conquest. Your job as the player is too kill as many pests, with as few traps, as possible in order to prevent the fall of mankind.

# FAQ
## failed to open file for reading on Visual Studio
Because the working directory is in the visualc15 folder, you need to create a junction to link ../Graphics to Graphics in the visualc15 folder. Try doing
```
mklink /J Graphics ../Graphics
```
in cmd in the visualc15 folder, and it should fix the problem.