
import {memo} from 'react'

function Content1({count}){
    // console.log(count)
    console.log('re-render')
    return (
        <h1>Hello Anh Em Code Thủ {count}</h1>
    )
}

export default memo(Content1)
// export default Content1
