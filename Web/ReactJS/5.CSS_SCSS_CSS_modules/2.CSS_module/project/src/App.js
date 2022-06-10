import './App.css'
import Heading from './components/Heading'
import Paragraph from './components/Paragraph'

function App(){
  // console.log('Heading')


  return (
    <div style = {{padding: 50}}>
        <Heading/>
        <Paragraph/>
        {/* <h1 className="heading">CSS</h1> */}
    </div>
  )
}

export default App;

// Development: npm start / yarn start => CSS internal

// Production: npm run build / yarn build -> CSS external

