import { nanoid } from "nanoid"
import './Note.css'
import {MdDeleteForever} from 'react-icons/md'
import {MdEdit} from 'react-icons/md'
import {useState} from 'react'

function Note({id, text, date, handleDeteleNote, handleEditNote}){
    // console.log(id, text, date)
    const [data, setData] = useState(text)
    const [editFlag, setEditFlag] = useState(false)
    const handleOnChange = (e) => {
        setData(e.target.value)
    }
    const handleSaveClick = () =>{
        handleEditNote(id, data)
        setEditFlag(prev => !prev)
    }
    const handleCancelClick = () => {
        handleEditNote(id, text)
        setEditFlag(prev => !prev)
        setData(text)
    }

    const editMode = () =>{
        setEditFlag(prev => !prev)
    }
    let limit = 300
    if (!editFlag){
        return (
                <div  className="note">
                    <span>{text}</span>
                    <div className="note-footer">
                        <span>{date}</span>
                        <MdEdit onClick={editMode} className="edit-icon"size="1.3rem"/>
                        <MdDeleteForever className="delete-icon" onClick={() => handleDeteleNote(id)} size="1.3rem"/>
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
                    value={data}
                    onChange={handleOnChange}
                >
                </textarea>
                <div className="note-footer">
                    <span>{limit - text.length} remaining</span>
                    <button 
                        className="save-button"
                        onClick={handleSaveClick}
                    >
                        Save
                    </button>
                    <button 
                        className="save-button"
                        onClick={handleCancelClick}
                    >
                        Cancel
                    </button>
                </div>    
            </div>
        )
    }
}

export default Note