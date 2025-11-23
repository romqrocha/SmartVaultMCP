---
tags:
  - Python
---
# Enums
- `enum.auto` can be used to auto assign values to an enum
- bookmark enums can be used to segment enums into types
```python
from enum import Enum, auto
class ClothingID(Enum):
	SHOE_BEGIN = SHOE_1 = auto() # SHOE_BEGIN and SHOE_1 have the same value
	SHOE_2 = auto()
	SHOE_3 = auto()
	SHOE_END = PANTS_BEGIN = PANT_1 = auto()
	PANTS_2 = auto()
	PANTS_3 = auto()
	PANTS_END = NUM_CLOTHES = auto()
```
- Good approach if you're pulling data from a database, bad approach if you're manually entering