import { nanoid } from "nanoid"
import './Note.css'
import {MdDeleteForever} from 'react-icons/md'
const id =  nanoid()
const text = "This is my first note"
const date = "03/11/2021"

function Note(){
    return (
        <div className="note">
            <span>{text}</span>
            <div className="note-footer">
                <span>{date}</span>
                <MdDeleteForever/>
            </div>    
        </div>
    )   
}

export default Note