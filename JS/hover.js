const tags_to_hover_handle = [
    'input',
    'label',
    'textarea',
    'span',
    'a',
    'legend'
];

const selection_id = 'element-selection-div-to-ignore';
var selected_element = null;

function hoverSelection(){
    var elements = document.body.getElementsByTagName('*');

    window.addEventListener('scroll', function(event) {
        console.log('scroll');
        if(selected_element != null) {
            drawSelection(selected_element);
        }
    })

    for(var e of elements) {
        e.addEventListener('mouseover', function(event) {
            drawSelection(event.target);
        });
    }
}


function drawSelection(element) {
    var rect = document.getElementById(selection_id);

    if(rect == null){
        rect = document.createElement("div");
        rect.id = selection_id;
        document.body.insertBefore(rect, document.body.childNodes[0]);
    }

    $(rect).css({
        'position' : 'fixed',
        'top'    : '' + element.getBoundingClientRect().top + 'px',
        'left'   : '' + element.getBoundingClientRect().left + 'px',
        'width'  : '' + element.getBoundingClientRect().width + 'px',
        'height' : '' + element.getBoundingClientRect().height + 'px',
        'border' : 'red 1px solid',
        'z-index': '' + (maxZIndex() + 1),
        'display': '',
        'pointer-events' : 'none'
    });

    selected_element = element;
    sendHoverDataToCpp(element);
}

function maxZIndex() {
    var elements = document.body.getElementsByTagName('*');
    var highest = 0;

    for(var element of elements) {
        if(element.id !== selection_id) {
            var zindex = document.defaultView.getComputedStyle(element,null).getPropertyValue("z-index");
            if ((zindex > highest) && (zindex != 'auto')) {
              highest = zindex;
            }
        }
    }

    return highest;
}

function sendHoverDataToCpp(element) {
    var classes = ''
    
    for(var i = 0; i < element.classList.length - 1; i++) {
        classes += '\"' + element.classList[i].toString() + '\",'
    }

    if(element.classList.length != 0) {
        classes += '\"' + element.classList[element.classList.length - 1].toString() + '\"'
    }

    let element_info = {
        tag : element.tagName.toString().toLowerCase(),
        id : element.id,
        _class : classes,
        inner : element.innerHTML 
    }

    let json = JSON.stringify(element_info);
    window.hover_handler.onHovered(json);
}

hoverSelection();