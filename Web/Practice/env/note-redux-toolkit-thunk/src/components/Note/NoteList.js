import './NoteList.css'
import Note from './Note'
import AddNote from './AddNote'
import {useSelector} from 'react-redux'
import {noteListRemaining} from '../../redux/selector'
function NoteList(){
    const datas = useSelector(noteListRemaining)
    // const datas = useSelector( state => state.noteList)
    return (
        <div className="note-list" >
            {datas.map(data => {
                return (
                    <Note 
                        key  = {data.id}
                        id   = {data.id}
                        text = {data.text}
                        date = {data.date}    
                    />
                )
            })}
            <AddNote/>
        </div>
    )
}

export default NoteList