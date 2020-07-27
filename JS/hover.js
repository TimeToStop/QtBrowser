const tags_to_hover_handle = [
    'input',
    'label',
    'textarea',
    'span',
    'a',
    'legend'
];

// Draw on hovered elements
function hover() {
    for(var handle of tags_to_hover_handle) {
        var elements  = document.body.getElementsByTagName(handle);

        for(var e of elements) {
            e.addEventListener('mouseover', function () {
                $(this).css('background-color', 'red');
            });
            
            e.addEventListener('mouseout', function() {
                $(this).css('background-color', '');
            });
        }
    }
}

hover();

// Send data to c++ about hover
function hoverElementData() {
    var elements  = document.body.getElementsByTagName('*');

    for(var e of elements) {
        var found = false;
        for(var handle of tags_to_hover_handle) {
            if(handle === e.tagName.toLowerCase()) {
                found = true;
            }
        }

        if(found) {
            e.addEventListener('mouseover', function() {
                var classes = ''
    
                for(var i = 0; i < this.classList.length - 1; i++) {
                    classes += '\"' + this.classList[i].toString() + '\",'
                }
    
                if(e.classList.length != 0) {
                    classes += '\"' + this.classList[e.classList.length - 1].toString() + '\"'
                }
    
                let element = {
                    tag : this.tagName.toString().toLowerCase(),
                    id : this.id,
                    _class : classes,
                    inner : this.innerHTML 
                }

                let json = JSON.stringify(element);
                window.hover_handler.onHovered(json);
            });
        }
    }
}

hoverElementData();