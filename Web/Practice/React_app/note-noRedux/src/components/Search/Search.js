import {MdSearch} from 'react-icons/md'
import './Search.css'
function Search({saveSearch}){
    const handleOnChange = (e) => {
        // console.log(e.target.value)
        saveSearch(e.target.value)
    }
    return (
        <div className="search">
            <MdSearch className="search-icon" size="1.4em"/>
            <input className="search-input" 
                   type="text"
                   placeholder="Search for your notes..."
                   onChange={handleOnChange}
            />
        </div>
    )
}

export default Search

