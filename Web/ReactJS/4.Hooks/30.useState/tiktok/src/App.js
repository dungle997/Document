import {useState} from 'react'
function App() {
  const [counter, setCounter] = useState(1)
  const handleIncrease = () => {
    setCounter(counter + 1)
    setCounter(counter + 1)
    setCounter(counter + 1)

  }
  console.log("code ")
  return (
    <div className="App" style = {{padding: '20px'}}>
        <h1>{counter}</h1>
        <button onClick = {handleIncrease}>Increase</button>
    </div>
  )
}
export default App;



// ### Lưu ý

// import {useState} from 'react'

// function Component(){
//     const [state, setState] = useState(initState)


// - Component được re-render sau khi `setState` => dòng log "code " được in ra 2 lần 
// - Initial state chỉ dùng cho lần đầu 
// - Set state với callback?
// - Initial state với callback?
// - Set state là thay thế state bằng giá trị mới 