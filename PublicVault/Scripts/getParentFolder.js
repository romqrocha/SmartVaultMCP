function getParentFolder (folder) {
    const knownChildren = ["Assignment", "Lecture", "Lab", "Atom"]

    const folders = folder.split('/');
    let parentFolder = folders[folders.length - 1];
    if(knownChildren.includes(parentFolder)){
        parentFolder = folders[folders.length -2];
    }
    
    return parentFolder;
}

module.exports = getParentFolder;