#!/usr/bin/python3
"""Technical interview preparation"""


def island_perimeter(grid):
    """function that calculate perimeter
        and return the value
    args:
        grid - a list of list of integers
    """
    height = len(grid) - 1
    if height == 0:
        return 0
    width = len(grid[0]) - 1
    if width == 0:
        return 0
    perimeter = 0
    for i in range(width + 1):
        for j in range(height + 1):
            if grid[j][i] == 1:
                if i == width or grid[j][i + 1] == 0:
                    perimeter += 1
                if i == 0 or grid[j][i - 1] == 0:
                    perimeter += 1
                if j == height or grid[j + 1][i] == 0:
                    perimeter += 1
                if j == 0 or grid[j - 1][i] == 0:
                    perimeter += 1
    return perimeter
