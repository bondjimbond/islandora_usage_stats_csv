# Islandora Usage Stats CSV

## Overview

Provides a CSV file containing all stats for an object collected by [Islandora Usage Stats](https://github.com/Islandora/islandora_usage_stats). This file includes the number of time the object was viewed and the total number times the object's datastreams were downloaded, broken down by month, e.g.:

```
Type,Title,URL,2017-10,2017-11,2018-01,2018-03
Views,"Hastings Street, Vancouver, B.C.",http://localhost:8000/islandora/object/islandora:7,0,1,0,270
Downloads,,,2,2,1,14
```


## Dependencies

* [Islandora](https://github.com/Islandora/islandora)
* [Islandora Usage Stats](https://github.com/Islandora/islandora_usage_stats)

## Installation

Install as usual, see [this](https://drupal.org/documentation/install/modules-themes/modules-7) for further information.

## Configuration

This module has no configuration options.

* [Mark Jordan](https://github.com/mjordan)

## Development and feedback

Bug reports, use cases, feature requests, and pull requests are welcome. If you want to open a pull request, please open an issue first, and use the pull request template.

## License

* [GPLv3](http://www.gnu.org/licenses/gpl-3.0.txt)
