import './App.css'
import {SET_JOB, ADD_JOB, DELETE_JOB} from './store'
import {actions, useStore} from './store'

function App(){
  const [state, dispatch] = useStore()
  const {todos, todoInput} = state

  // console.log('state = ',state)
  // console.log('dispatch = ', dispatch)
  const handleOnchange = (input) => {
    // console.log(typeof actions)
    dispatch(actions.setJob(input)) 
  }
  return (
    <div style = {{padding: 50}}>
        <input
          value = {todoInput}
          placeholder="Enter todo..."
          onChange = {e => handleOnchange(e.target.value)}
        />
        <h1>{todoInput}</h1>
    </div>
  )
}



export default App;

