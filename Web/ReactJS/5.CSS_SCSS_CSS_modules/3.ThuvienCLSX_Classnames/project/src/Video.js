import {forwardRef, useRef, useImperativeHandle} from 'react'
import video from './video/download.mp4'
// import {useRef} from 'react'

function Video(props, ref){ // ref = videoRef bên file App
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
    return(
        <video 
            ref = {videoRef1}
            src={video}
            height={500}   
            // controls
        />
    )
}

export default forwardRef(Video)