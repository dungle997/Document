import './Search.css'
import {MdSearch} from 'react-icons/md'
import {useDispatch} from 'react-redux'
import searchSlice from './SearchSlice'
function Search(){
    const dispatch = useDispatch()
    const handleOnChange = (e) => {
        dispatch(searchSlice.actions.addSearch(e.target.value))
    }
    return (
        <div className="search">
            <MdSearch size='1.4em'/>
            <input 
                className="search-input"
                placeholder="Search for your notes ......"
                onChange={handleOnChange}
            />
                


            
        </div>
    )
}

export default Search