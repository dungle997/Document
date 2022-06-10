import {ThemeContext} from './ThemeContext'
import {useContext} from 'react'

function Paragraph(){
    const theme = useContext(ThemeContext)

    return (
        <p className={theme.theme}>
            3. Đời người thì làm gì có chuyện mọi việc đều như ý. Cuộc sống cũng đâu thể nào hài lòng hết thảy. Vì vậy, đừng so đo với người khác, bởi vì không đáng; đừng quá nghiêm khắc với bản thân, bởi vì sẽ tự tổn thương mình; cũng đừng tính toán chuyện cũ.
        </p>
    )
}

export default Paragraph