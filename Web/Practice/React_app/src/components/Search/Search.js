import {MdSearch} from 'react-icons/md'
import './Search.css'
function Search(){
    return (
        <div className="search">
            <MdSearch className="search-icon" size="1.4em"/>
            <input className="search-input" type="text" placeholder="Search for your notes..."/>
        </div>
    )
}

export default Search

