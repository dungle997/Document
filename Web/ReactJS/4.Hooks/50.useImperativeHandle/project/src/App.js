import { useRef} from 'react'
import Video from './Video'
function App(){
  const videoRef = useRef()
  console.log(videoRef.current)
  const handlePlay = ()=>{
    // videoRef.current.remove()
    videoRef.current.play() // gọi đến method play trong imperativeHandle
  }
  const handlePause = ()=>{
    videoRef.current.pause() // gọi đến method pause trong imperativeHandle
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


// Lưu ý là function component không có ref, chỉ nhưng element như h1, p, input mới có ref thôi
// Không thể truyền ref cho một function component
// React không hỗ trợ truyền ref từ component cha xuống component con
// => Sử dụng HOC

// Tại sao lại dùng: 
// Do tính đóng gói và tính bảo mật của dữ liệu nên ta cần dùng 
// thằng video chỉ cần kéo ra 2 thuộc tính play và pause thôi
// Vì nếu để ref = {ref} bên file Video thì ở bên file App sử dụng đến cũng thay đổi trực tiêp trong Video. 
// => Gây mất tòan vẹn dữ liệu ở component video, nên phải dùng 1 thằng 