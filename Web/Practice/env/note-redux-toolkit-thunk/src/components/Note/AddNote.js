import './AddNote.css'
import {useState} from 'react'
import {useDispatch} from 'react-redux'
import noteListSlice, { addDatas } from './NoteListSlice'


function AddNote(){
    const dispatch = useDispatch()
    let limit = 300
    const [text, setText] = useState('')
    const handleOnChange = (e) => {
        if (limit - e.target.value.length >= 0){
            setText(e.target.value)
        }
    }
    const handleOnClick = () => {
        if (text.trim().length > 0){
            // dispatch(noteListSlice.actions.addNote(text))
            dispatch(addDatas(text))
            setText('')
        }
    }
    return (
        <div className="note">
            <textarea 
                className="textarea"
                rows= '8'
                cols= "10"
                placeholder="Type to add a new note..."
                value={text}
                onChange={handleOnChange}
            >   
            </textarea>
            <div className="note-footer">
                <span> {limit - text.length} remaining</span>
                <button 
                    className="save-btn"
                    onClick={handleOnClick}
                >
                    Save
                </button>
            </div>
            
        </div>
    )
}

export default AddNote