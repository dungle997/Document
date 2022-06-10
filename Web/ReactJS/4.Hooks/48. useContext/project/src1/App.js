import Content from './Content'
import './App.css'
import {useContext} from 'react'
import {ThemeContext} from './ThemeContext'

// console.log(ThemeContext)
// Context
// CompA => CompB => CompC

// 1. Create context
// 2. Provider
// 3. Consumer


function App(){
  const handle = useContext(ThemeContext)
  // console.log(handle)
  return (
      <div style = {{padding: 50}}>
          <button onClick={handle.handleClick}>Toggle</button>
          {<Content/>}
      </div>
  )
}



export default App;

