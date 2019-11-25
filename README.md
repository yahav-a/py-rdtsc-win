# py-rdtsc-win
Minimalist python extension exposing rdtsc instruction API.
There are similar projects on github for linux or Windows x86-64, this extension works for Windows x86 *and* x86-64.
Build using MSVC.

# Running
```python
from rdtsc_win import rdtsc

print(rdtsc())
```
