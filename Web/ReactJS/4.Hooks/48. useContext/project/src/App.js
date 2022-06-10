
import Content from "./Content"
import './App.css'
import {ThemeContext} from './ThemeContext'
import {useContext} from 'react'



function App(){
  const input = useContext(ThemeContext)
  return (
      <div style={{padding: '32px 50px'}}>
        <button onClick={input.handleOnclick}>Toggle</button>
        <Content/>
      </div>
  )

}

export default App