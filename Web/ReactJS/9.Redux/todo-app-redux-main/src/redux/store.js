import { createStore } from 'redux' 
import rootReducer from './reducer'
// const store = createStore(rootReducer, initValue, enhancers)
const store = createStore(rootReducer)


export default store