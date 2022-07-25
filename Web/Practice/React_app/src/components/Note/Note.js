import { nanoid } from "nanoid"
import './Note.css'
import {MdDeleteForever} from 'react-icons/md'

function Note({id, text, date, handleDeteleNote, handleEditNote}){
    // console.log(id, text, date)
    const handleOnChange = (e) => {
        handleEditNote(id, e.target.value)
    }

    let state = false
    if (!state){
        return (
                <div className="note">
                    <span>{text}</span>
                    <div className="note-footer">
                        <span>{date}</span>
                        <MdDeleteForever onClick={() => handleDeteleNote(id)} size="1.3rem"/>
                    </div>    
                </div>
        )
    }
    else{
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
                {/* <span>{limit - text.length} remaining</span> */}
                <button className="save-button">Save</button>
            </div>    
        </div>
        )
    }
}

export default Note