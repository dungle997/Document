// export default function html([first, ...strings], ...values){
//     const a =  values.reduce(
//         (acc, cur) => acc.concat(cur, strings.shift()),
//         [first]
//     )
//     console.log('a = ', a)
//     const b = a.filter(x => x && x !== true || x === 0 )
//     console.log('a = ', b)

//     // .filter()
//     // .join('')
// }


export default function html([first, ...strings], ...values){
    return values.reduce(
        (acc, cur) => acc.concat(cur, strings.shift()),
        [first]
    )
    .filter(x => x && x !== true || x === 0 )
    .join('')
}

export function createStore(reducer){
    let state = reducer()
    const roots = new Map()
    // Map là một object đặc biệt. Khác object thường bởi:
    // - tính chất lặp qua
    // - Đặt key của object bằng bất kì kiểu dũ liệu trong JS. Object thông thường chỉ đặt được key là string
    function render(){
        for(const [root, component] of roots){
            const output = component()
            root.innerHTML = output
        }
    }

    return {
        attach(component, root){
            roots.set(root, component)
            render()
        },
        connect(selector = (state) => state){
            return component => (props, ...args) =>
                component(Object.assign({}, props, selector(state), ...args))
        },
        dispatch(action, ...args){
            state = reducer(state, action, args)
            render()
        }
    }
}
