# filler
Create your player to fight other students on the famous (or not) Filler board. The rules are simple: two players fight on a board and, in turn, must place the piece given to them by the game master (a Ruby executable), thereby scoring points. The game ends when a piece cannot be placed. A small fun game project.

![graded](./README/images/graded.png)

An example of how to run this program:
```
make
./resources/filler_vm -f resources/maps/map01 -p2 ./resources/players/carli.filler -p1 ./rodrodri.filler 
```

And if you want to visualize the game:
```
./resources/filler_vm -f resources/maps/map01 -p2 ./resources/players/carli.filler -p1 ./rodrodri.filler | ./visualizer
```

![visualizer](./README/images/filler.mpg)

Above is what the `visualizer` looks like. I did it with [ncurses](https://en.wikipedia.org/wiki/Ncurses), but as soon as I get some free time, I'm planning to come back to this project, to implement the visualizer using web technologies.

## Strategy
The strategy for this project can be outlined in a few stages:

1. **Parsing** and **Allocating memory** for the **board** and the **pieces**.
2. Traversing board and piece in order to find the optimal position.
3. Printing the coordinates.

### 1. Parsing and Allocating Memory
The parsing part was seemingly the simplest stage, but the one that gave me more trouble since the Ruby script in charge or randomly generating the pieces and printing the map, wasn't printing well formed lines. What I ended up doing is taking a **character-based** approach, instead of the original **line-based** one.

> The Ruby script can be found in the `./resources/filler_vm`. There are several versions, since one was problematic in some scenarios.

Once the size of the **board** was parsed, the next step was to allocate space in the **heap** for a two-dimensional array of characters to store the characters of the board. The same dimensions were used to allocate space in memory for the **heatmap**, which was another two-dimensional array of type `int` this time.

![heatmap](./README/images/heatmap.mpg)

In the image above it's visible my approach for the **heatmap**, basically layering integers, onion-style around the pieces of the opponent.

> The heatmap was created in two stages: first assign the value `-1` to all the opponent pieces, then build upon that to create the layers.

A similar approach to the board was taken for the **pieces**, only that in this case, I had to be careful releasing the memory to the system once I was done with their placement (in order to avoid **memory leaks**).

### 2. Placing the pieces
The pieces had to be placed respecting some constraints:

* We can't place our piece on top of any opponent's piece.
* We must place our piece in a way that we get a **one cell** overlap with any of our already placed pieces.

With these two limitations in mind, I just tried to place the pieces in the hotter areas of the heatmap, the ones with smaller values. The goal of this was to place our pieces the closer to the enemy as possible, in order to block its movements.

### 3. Printing the Pieces Coordinates
Finally, once the optimal position of the piece was found, we just had to print its coordinates to **standard output**, where the **Ruby script** was in charge or registering them, and placing them on the map.

### Logging to a File
One of the most important things I learned doing this project, was how to deal with a seemingly **black box** (the Ruby script). As we said in the beginning, the **parsing** stage was problematic because I was trusting that the **Ruby script** was generating well-formed lines, but this wasn't the case.

> The functions for doing that are in the `srcs/logging.c.test` file. I had to take them out of the way because I was using *illegal* functions in it (according to the 42 Norm).

The way I discovered that was by printing what my program was reading from **standard input** (the stdout of the script) to a file.