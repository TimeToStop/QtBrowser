function tree(element)
{
    const tag_to_ignore = [
        'script',
        'noscript',
        'style',
        'meta',
        'link',
        'g',
        'scv'
    ];
    
    let children_json = [];
    let class_list = [];

    for(let child of element.children)
    {
        if(!tag_to_ignore.includes(child.tagName.toLowerCase()) && child.id !== selection_id)
        {
            children_json.push(tree(child));
        }
    }

    for(let c of element.classList)
    {
        class_list.push(c);
    }

    return {
        tag : element.tagName.toLowerCase(),
        id :  element.id,
        classList : class_list,
        children : children_json
    };
}

function source()
{
    return JSON.stringify(tree(document.body));
}
