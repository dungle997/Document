import './App.css'
import Button from './components/Button/'
import GlobalStyles from './components/GlobalStyles/'

function App(){
  // console.log('Heading')


  return (
    <GlobalStyles>
      <div style = {{padding: 50}}>
        <Button primary/>
    </div>
    </GlobalStyles>
  )
}

export default App;

// Vấn đề: Khi Css với các component khác nhau mà đặt trùng tên class hay selector thì các thuộc tính sẽ bị ảnh hưởng 

// 2 cách giải quyết
// CSS module

// Styled component

// Đặt tên selector theo kiểu camel Case để dễ dùng trong JSX

