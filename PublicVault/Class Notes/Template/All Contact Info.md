---
Class:
---
```dataviewjs
dv.pages("#classIntro")
	.where(p => p.file.path.includes(dv.current().file.folder))
	.forEach(p => dv.el("p", "![[" + p.file.link.path + "#Contact Info]]"))
```
