import './NoteList.css'
import Note from './Note'
import AddNote from './AddNote'
import {useSelector} from 'react-redux'
import {todosRemainingSelector} from '../../redux/selectors'
function NoteList(){
    const datas = useSelector(todosRemainingSelector)
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