import Note from './Note'
import './NoteList.css'
import AddNote from '../AddNote/AddNote'

function NoteList({datas, handleAddNote, handleDeteleNote, handleEditNote}){
    // console.log(datas, handleAddNote, handleDeteleNote)
    return (
    <div className='note-list'>
        {/* {console.log('a')} */}
            {datas.map(data => {
                return (
                <Note 
                    key  ={data.id}
                    id   ={data.id} 
                    text ={data.text} 
                    date ={data.date}
                    handleDeteleNote = {handleDeteleNote}
                    handleEditNote = {handleEditNote}
                />
                )
            })}
            <AddNote handleAddNote={handleAddNote}/>

    </div>)
}

export default NoteList