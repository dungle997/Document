
import {useState, useMemo, useRef} from 'react'

// 1. memo() -> Higher Order Component (HOC)
// 2. useCallback()
    // - Reference types
    // - React memo()
// 3. Các cách chuyển string về number trong JS 
// - Number(var)
// - +var
// - parseInt(var)

function Content(){
    const [name, setName] = useState('')
    const [price, setPrice] = useState('')
    const [products, setProducts] = useState([])
    // console.log(products)
    const refName = useRef()
    const handleOnclick = () =>{
        setProducts(
            [...products, {
                name,
                price: +price,
            }]
            ) 
        setName('')
        setPrice('')
        refName.current.focus()
    }
    const total = useMemo(()=>{
        const result = products.reduce((result ,product) =>{
            console.log('Tinh toan ....')
            return result + product.price
        } ,0)

        return result
    }, [products])
        
     
    return (
        <div style={{padding: '10px 32px'}}>
            <input
                ref ={refName}
                value = {name}
                placeholder='Enter name...'
                onChange = {e =>setName(e.target.value)}
                />
            <br/>
            <input
                value = {price}
                placeholder='Enter price...'
                onChange = {e =>setPrice(e.target.value)}
            />
            <br/>

            <button 
                onClick = {handleOnclick}
            >
                Add
            </button>
            <h1>Total: {total}</h1>
            <ul>
                {products.map((product, index) => {
                    return (
                        <li key={index}>{product.name} : {product.price}</li>
                    )
                })}
            </ul>
           
            
        </div>
    )
}






// ====================================
export default Content