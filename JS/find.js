function getPathIndexFor(element)
{
    let index = 0;
    let parent = element.parentNode;

    for(let e of parent.children)
    {
        if(e.id !== selection_id && e.tagName === element.tagName)
        {
            if(e.isSameNode(element))
            {
                return index; 
            }

            index++;
        }
    }

    return -1;
}

function element_path(element)
{
    let path = '';

    for(let e = element; e.tagName !== 'body'.toUpperCase(); e = e.parentNode)
    {
        path = e.tagName.toUpperCase() + '[' + getPathIndexFor(e) + ']/' + path;
    }

    return path;
}

function parse_path(path)
{
    let elements = path.split('/');
    let result = [];
    elements.pop();

    for(let e of elements)
    {
        let splitted = e.split('[');
        let tag = splitted[0].toUpperCase();
        let index = splitted[1].slice(0, -1);

        if(tag !== 'BODY')
        {
            result.push({
                _tag : tag,
                _index : (index !== '*' ? parseInt(index, 10) : -1) 
            });
        }
    }

    return result;
}

function dynamic_forward(tags)
{
    var candidates = [];
    var anonimus = function (depth, element)
    {
        if(depth !== tags.length)
        {
            for(var e of element.children)
            {
                if(e.id !== selection_id && e.tagName === tags[depth]._tag)
                {
                    anonimus(depth + 1, e);
                }
            }
        }
        else 
        {
            candidates.push(parse_path(element_path(element)));
        }
    }

    anonimus(0, document.body);
    candidates.sort(function (a, b) {
        for(let i = 0; i < Math.min(a.length, b.length, tags.length); i++)
        {
            if(a[i]._index !== tags[i]._index && b[i]._index === tags[i]._index)
            {
                return 1;
            }
            else if(a[i]._index === tags[i]._index && b[i]._index !== tags[i]._index)
            {
                return -1;
            }
        }

        return 0;
    });

    if(candidates.length === 0) 
    {
        return null;
    }
    else
    {
        return fast_forward(candidates[0]);
    }
}

function fast_forward(tags)
{
    let e = document.body;

    for(let i = 0; i < tags.length; i++)
    {
        let has_tag = false;
        let count_index = 0;
        for(let child of e.children)
        {
            if(child.id !== selection_id && child.tagName === tags[i]._tag)
            {
                has_tag = true;
                
                if(count_index === tags[i]._index)
                {
                    e = child;
                    break;
                }
                else
                {
                    count_index++;
                }
            }
        }

        if(has_tag !== true || count_index !== tags[i]._index)
        {
            return null;
        }
    }

    return e;
}

function fast_forward_array(path) 
{
    let tags = parse_path(path);

    let result = [];
    let anonimus = function (e, depth)
    {
        for(let i = depth; i < tags.length; i++)
        {
            if(tags[i]._index === -1)
            {
                if(i + 1 !== tags.length)
                {
                    for(let child of e.children)
                    {
                        anonimus(child, i + 1);
                    }
                }
                else
                {
                    for(let child of e.children)
                    {
                        result.push(child);
                    }
                }

                return;
            }
            else
            {
                let has_tag = false;
                let count_index = 0;
                for(let child of e.children)
                {
                    if(child.id !== selection_id && child.tagName === tags[i]._tag)
                    {
                        has_tag = true;
                
                        if(count_index === tags[i]._index)
                        {
                            e = child;
                            break;
                        }
                        else
                        {
                            count_index++;
                        }
                    }
                }

                if(has_tag !== true || count_index !== tags[i]._index)
                {
                    return;
                }
            }
        }

        result.push(e);
    }

    anonimus(document.body, 0);

    return result;
}

function element_by_path(path)
{
    let elements = parse_path(path);
    let element = fast_forward(elements);

    if(element == null)
    {
        return dynamic_forward(elements); 
    }
    else
    {
        return element;
    }
}

// TEST
// function test()
// {
//     let elements = document.body.getElementsByTagName('*');

//      for(let e of elements)
//      {
//         if(e.id !== null && e.id !== '' && e.id !== selection_id)
//         {
//             let test_e = parse_path(element_path(e));
//             let dynamic = dynamic_forward(test_e);
//             let fast = fast_forward(test_e);
//             let array = fast_forward_array(test_e)[0];

//             if(!e.isSameNode(dynamic) || !e.isSameNode(fast) || !e.isSameNode(array))
//             {
//                 console.log('Error: ' + e.id + ' req: ' + (e.isSameNode(dynamic)) + ' forward: ' + (e.isSameNode(fast)) + ' array: ' + (e.isSameNode(array)));
//                 console.log(e);
//                 console.log(dynamic);
//                 console.log(fast);
//                 console.log(array);
//             }
//         }
//      }

//      console.log('Test has been ended');
// }

// function testFindElement()
// {
//     console.log('All');
//     let elements = document.body.getElementsByTagName('*');

//     for(let e of elements)
//     {
//         if(e.id !== null && e.id !== '' && e.id !== selection_id)
//         {
//             if(!e.isSameNode(element_by_path(element_path(e))))
//             {
//                 console.log('Error');
//                 console.log(e);
//             }
//         }
//     }

//     console.log('Test has been ended'); 
// }

// test();
// //testFindElement();

//TEST END UP HERE