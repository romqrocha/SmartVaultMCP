---
Class:
---

```dataview
TABLE WITHOUT ID prof.name as "Name", prof.email as "Email", prof.hours as "Hours"
WHERE contains(file.folder, this.file.folder) AND contains(file.frontmatter, "prof")
FLATTEN hours
```
