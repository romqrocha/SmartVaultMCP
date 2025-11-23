---
Class: <% tp.user.getParentFolder(tp.file.folder(true)) %>
status: Not Started
Created: '[[<% tp.date.now("YYYY MM DD") %>]]'
startDate: '[[<% tp.date.now("YYYY MM DD") %>]]'
priority: 
dueDate: 
tags:
  - "#task"
  - assignment
---
<%*
	let title = tp.file.title
	if (title.startsWith("Untitled")) {
		title = await tp.system.prompt("Title:")
		await tp.file.rename(`${title}`)
	}
%>