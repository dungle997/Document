import { useRef} from 'react'
import Video from './Video'
function App(){
  const videoRef = useRef()
  console.log(videoRef.current)
  const handlePlay = ()=>{
    // videoRef.current.remove()
    videoRef.current.play()
  }
  const handlePause = ()=>{
    videoRef.current.pause()
  }
  return (
    <div style = {{padding: 50}}>
        <Video ref={videoRef}/>
        <button onClick={handlePlay}>Play</button>
        <button onClick={handlePause}>Pause</button>

    </div>
  )
}

export default App;

