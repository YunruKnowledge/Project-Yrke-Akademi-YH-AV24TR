To stash your changes with a custom message, use:

It means to stash the "CURRENT CHANGES":
git stash push -m "aIdentificationName"
---
This way, you not only save your changes but also label them for easy identification later. Once you're ready to apply the stash, you can use:

git stash apply stash@{0}
---

git stash save "stash1"
git stash apply

This should avoid that error and do the job. Stashing done right! 😎
---