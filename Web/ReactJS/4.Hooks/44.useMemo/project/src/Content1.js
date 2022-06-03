
import {memo} from 'react'

function Content1({onIncrease}){
    // console.log(onIncrease)
    console.log('re-render')
    return (
        <>
           <h1>Hello Anh Em Code Thủ</h1>
           <button onClick={onIncrease}>Click me!</button>
        </>

    )
}

export default memo(Content1)
// export default Content1
