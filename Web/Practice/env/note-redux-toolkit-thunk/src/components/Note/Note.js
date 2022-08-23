import './Note.scss'
import {MdDeleteForever} from 'react-icons/md'
import {MdEditNote} from 'react-icons/md'
import {useState} from 'react'
import {useDispatch} from 'react-redux'
import noteListSlice, { deleteDatas, editDatas } from './NoteListSlice'

function Note({id, text, date}){
    const dispatch = useDispatch() 
    const [state, setState] = useState(false)
    const [input, setInput] = useState(text)
    let limit = 300
    const handleOnClick = () => {
        // dispatch(noteListSlice.actions.deleteNote(id))
        dispatch(deleteDatas(id))
    }
    const handleEditClick = () => {
        setState(true)
    }
    const handleOnChange = (e) => {
        if (limit - e.target.value.length >= 0){
            setInput(e.target.value)
        }
    }
    const handleSaveClick = () => {
        if (input.trim().length > 0){
            // dispatch(noteListSlice.actions.editNote({id, text: input}))
            dispatch(editDatas({id, text: input}))
            setState(false)
        }
    }
    const handleCancelClick = () => {
        setInput(text)
        setState(false)
    }
    if(!state){
        return (
            <div className="note">
                <span>{text}</span>
                <div className='note-footer'>
                    <span>{date}</span>
                    <MdEditNote className="edit-icon" onClick={handleEditClick} size = "1.4rem"/>
                    <MdDeleteForever size = "1.4rem" onClick={handleOnClick}/>
                </div>
            </div>
        )
    }
    else{
        return (
        <div className="note">
            <textarea 
                className="textarea"
                rows= '8'
                cols= "10"
                placeholder="Type to add a new note..."
                value={input}
                onChange={handleOnChange}
            >   
            </textarea>
            <div className="note-footer">
                <span> {limit - input.length} remaining</span>
                <button 
                    className="save-btn"
                    onClick={handleCancelClick}
                >
                    Cancel
                </button>
                <button 
                    className="save-btn"
                    onClick={handleSaveClick}
                >
                    Save
                </button>
            </div>
            
        </div>
        )
    }
}

export default Note