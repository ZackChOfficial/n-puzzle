function swap(node1, node2) {
    const afterNode2 = node2.nextElementSibling;
    const parent = node2.parentNode;
    if (node1 === afterNode2) {
        parent.insertBefore(node1, node2);
    } else {
        node1.replaceWith(node2);
        parent.insertBefore(node1, afterNode2);
    }
}

export default function move(direction) {
    let children = document.getElementById("board").children;
    let zero;
    for (let i = 0; i < children.length; i++) {
        if (children[i].id == 'zero') {
            zero = i;
            break;
        }
    }
    switch (direction) {
        case "U":
            if (zero - 4 >= 0)
                swap(children[zero], children[zero - 4]);
            break;
        case "R":
            if ((zero + 1)%4 != 0)
                swap(children[zero], children[zero + 1]);
            break;
        case "D":
            if (zero + 4 < children.length)
                swap(children[zero], children[zero + 4]);
            break;
        case "L":
            if ((zero)%4  != 0)
                swap(children[zero], children[zero - 1]);
            break;

    }
}