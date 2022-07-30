import './NoteList.css'
import Note from './Note'
import AddNote from './AddNote'
function NoteList({datas, handleAddNote, handleDeleteNote, handleEditNote}){
    return (
        <div className="note-list" >
            {datas.map(data => {
                return (
                    <Note 
                        key  = {data.id}
                        id   = {data.id}
                        text = {data.text}
                        date = {data.date}    
                        handleDeleteNote = {handleDeleteNote}
                        handleEditNote = {handleEditNote}
                    />
                )
            })}
            <AddNote handleAddNote={handleAddNote}/>
        </div>
    )
}

export default NoteList