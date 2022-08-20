import {forwardRef, useRef, useImperativeHandle} from 'react'
import video from './video/download.mp4'
// import {useRef} from 'react'

function Video(props, ref){ // ref = videoRef bên file App
    console.log(props)
    // console.log(ref)
    const videoRef1 = useRef()

    useImperativeHandle(ref, () => ({
        play(){
            videoRef1.current.play() // có nghĩa là videoRef1 = videoRef ở file App
        },
        pause(){
            videoRef1.current.pause()
        }
    }))
    // Khi viết như vậy thì bên ngoài thằng videoRef bên component App sẽ nhận được 2 method ở trong này
    return(
        <video 
            ref = {videoRef1}
            // ref = {ref}. Truyền trực tiếp từ ref nhận đc bên App
            src={video}
            height={500}   
            // controls
        />
    )
}

export default forwardRef(Video)