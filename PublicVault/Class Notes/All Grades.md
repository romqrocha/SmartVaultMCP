
```dataviewjs
dv.pages("#classIntro")
		.where(p => "grades" in p.file.frontmatter)
		.forEach(p => {
			let grades = p.file.frontmatter.grades;
			let keys = Object.keys(grades)
			let tableData = [];
			for(const key in keys){
				var temp = {}
				let keyName = keys[key];
				temp.type = keyName;
				temp = Object.assign(temp, grades[keyName]);
				tableData.push([
					temp.type,
					temp.percent, 
					temp.count, 
					temp.count > 0 ? temp.percent / temp.count : 0
				]);
			}
			dv.el("h3", p.file.folder)
			dv.table(["type", "percent", "count", "% per"],tableData)
		}
	)

```

