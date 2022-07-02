# HELP THE PRISONERS SURVIVE

Saw this youtube math problem, and wanted to check the solution by monte-carlo.

https://www.youtube.com/watch?v=iSNsgj1OCLA

In summary:
- 100 prisoners numbered 1 - 100
- Slips with their numbers are randomly placed in 100 boxes in a room (the boxes are numbered too, but not related to the slip inside)
- Each prisoner may enter the room one at a time and check 50 boxes
- They must leave the room exactly as they found it and can't communicate with the others afterwards
- If all 100 prisoners find their number during their turn in the room, they will all be freed. But if even one fails, they will all be executed
- What is their best strategy to survive?

# Running the simulator
```bash
./compile_run.sh
```

# Conclusion
What do you know, it actually works! Borderline witchcraft.