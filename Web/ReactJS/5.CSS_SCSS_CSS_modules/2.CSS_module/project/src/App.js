import './App.css'
import Heading from './components/Heading'
import Paragraph from './components/Paragraph'
import GlobalStyles from './components/GlobalStyles/'

function App(){
  // console.log('Heading')


  return (
    <GlobalStyles>
          <div style = {{padding: 50}}>
        <Heading/>
        <Paragraph/>
        {/* <h1 className="heading">CSS</h1> */}  
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

// Css module thì không thể module đc các thẻ (tag, *), nếu viết ở cấp 1 thì vẫn ảnh hưởng tất cả. Nhưng nếu được viết trong nested thì vẫn đc (sử dụng scss)

