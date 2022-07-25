import '../Note/Note.css'
import './AddNote.css'
import {MdDeleteForever} from 'react-icons/md'
import { useState } from 'react'
function AddNote({handleAddNote}){
    const [text, setText] = useState('')
    const limit = 300
    // console.log(text)
    const handleOnChange = (e) => {
        if(limit - e.target.value.length>=0){
            setText(e.target.value)
        }
    }
    const handleOnClick = () => {
        if (text.trim().length > 0){
            handleAddNote(text)
            setText('')
        }
    }
    return (
        <div className="note">
            <textarea 
                className='text-note' 
                placeholder="Type to add a new note..."
                rows= "8"
                cols = "10"
                value={text}
                onChange={handleOnChange}
            >
            </textarea>
            <div className="note-footer">
                <span>{limit - text.length} remaining</span>
                <button className="save-button" onClick={handleOnClick}>Save</button>
            </div>    
        </div>
    )
}

export default AddNote