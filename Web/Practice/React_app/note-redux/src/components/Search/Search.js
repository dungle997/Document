import './Search.css'
import {MdSearch} from 'react-icons/md'
function Search({handleSearch}){
    const handleOnChange = (e) => {
        handleSearch(e.target.value)
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