# 42Project: so_long - Pac-Man

## Overview

This project is a 2D game developed as part of the [so_long](https://cdn.intra.42.fr/pdf/pdf/168864/en.subject.pdf) project at 42. Its purpose is to work on textures, sprites and other basic game elements.

The project use the school’s graphical library: [MiniLibX](https://cdn.intra.42.fr/document/document/35895/minilibx-linux.tgz). This library was developed internally and includes basic necessary tools to open a window, create images and deal with keyboard and mouse events.

My implementation is inspired by a classic arcade game: Pac-Man. The code and assets were created by hand by me. However, I do not own any rights to the Pac-Man license. This project has a simple educational purpose.

## Command-Line Flags

My so_long project supports optional flags to modify the game's behavior. These flags can be used to manage multiple maps, bypass validation, or enable developer tools.

**Usage:** `./so_long [options] <map> [<map> ...]`

|  Flags         | Description                                                                           |
| :------------: | :-----------------------------------------------------------------------------------: |
| `-h` `--help`  | Displays a help message with all available flags and exits.                           |
| `-l` `--loop`  | When provided with multiple maps, the game will endlessly loop through them.          |
| `-f` `--force` | Bypasses map validation checks and attempts to run the game regardless of map format. |
| `--debug`      | Enables developer mode, which unlocks special debug keybindings.                      |

> **Force (`-f` `--force`) warning**<br/>
> When you run the game with the `--force` flag, you may encounter undefined behavior or crashes with invalid maps.

> **Debug (`--debug`) keybindings**<br/>
> When you run the game with the `--debug` flag, you can use the following keys to test different game scenarios :
> - **`F1`** : Teleports Pac-Man back to his spawn position.
> - **`F2`** : Makes Pac-Man "eat" all remaining pellets on the map.
> - **`F3`** : Maximizes Pac-Man's score and move count.
> - **`F4`** : Kills Pac-Man.
> - **`F5`** : Kills all ghosts on the map.
