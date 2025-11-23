---
Class: <% tp.user.getParentFolder(tp.file.folder(true)) %>
Created: '[[<% tp.date.now("YYYY MM DD") %>]]'
tags: 
Reviewed: false
---
<%*
	let title = tp.file.title
	if (title.startsWith("Untitled")) {
		title = await tp.system.prompt("Title:");
		await tp.file.rename(`${title}`);
	}
%>