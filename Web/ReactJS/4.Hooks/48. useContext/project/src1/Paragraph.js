import {useContext} from 'react'
import {ThemeContext} from './ThemeContext'
function Paragraph(){
    const theme = useContext(ThemeContext)
    // console.log('asdfasd ',theme)
    return (
        <p className={theme.theme}>
            Khi nào bạn cần may áo giáp sắt, Nhìn sang của hàng á phi âu
        </p>
    )
}

export default Paragraph