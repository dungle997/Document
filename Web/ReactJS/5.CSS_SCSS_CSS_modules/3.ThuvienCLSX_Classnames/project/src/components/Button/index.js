import style from './Button.module.css'
import clsx from 'clsx'
// console.log(style)
function Button({primary}){
    // console.log(primary)
    const classes = clsx(style.active, 'd-flex',{
        [style.primary]: primary
    })

    return (
        <>
            {/* <button>Click me!</button> */}
            {/* <button className={`${style.button} ${style.active}`}>Click me!</button> */}
            {/* <button className={[style.button,style.active].join(' ')}>Click me!</button> */}
            {/* Cách làm cũ, sử dụng string literal hoặc sử dụng join 1 mảng ra => chuỗi string */}

            {/* <button className={clsx(style.button,style.active, style.active1)}>Click me!</button> */}
            <button className={classes}>Click me!</button>


        </>
    )
}

export default Button

// clsx sử dụng với class động