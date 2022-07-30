import './App.css';
import Header from './components/Header/Header'
import NoteList from './components/Note/NoteList'
import Search from './components/Search/Search'
import {nanoid} from 'nanoid'
import {useState, useEffect} from 'react'


function App() {
    const [notes, setNotes] = useState([
        {
            id: nanoid(),
            text: 'This is the first note',
            date: '15/05/2055'
        },
        {
            id: nanoid(),
            text: 'This is the first note',
            date: '15/05/2055'
        },
        {
            id: nanoid(),
            text: 'This is the first note',
            date: '15/05/2055'
        },
    ])
    
    useEffect(() => {
        const oldNotes = JSON.parse(localStorage.getItem('react-app-note-data'))
        if (oldNotes){
            setNotes(oldNotes)
        }
    }, [])
    useEffect(() => {
        localStorage.setItem('react-app-note-data', JSON.stringify(notes))
        }, [notes])

    const addNotes = (input) => {
        const date = new Date()
        const newNote = {
            id: nanoid(),
            text: input,
            date: date.toLocaleDateString(),
        }

        const newNotes = [...notes, newNote]
        setNotes(newNotes)
    }

    const deleteNotes = (id) => {
        const newNotes = notes.filter(note => {
            return note.id !== id
        })

        setNotes(newNotes)
    }

    const editNotes = (id, text) => {
        const newNotes = notes.map(note => {
            if (note.id === id){
                const date = new Date()
                const newNote = {
                    id: id,
                    text: text,
                    date: date.toLocaleDateString()
                }
                return newNote
            }
            return note

        })
        setNotes(newNotes)
    }

    const [search, setSearch] = useState('')
    const [darkMode, setDarkMode] = useState(false)

    const notesFilter = notes.filter(note => {
        return note.text.includes(search)
    })
    // console.log(notesFilter)
    return (
        <div className={`${darkMode && 'dark-mode'}`}>
            <div className='App'>
                <Header handleDarkMode={setDarkMode}/>
                <Search handleSearch={setSearch}/>
                <NoteList 
                    // datas={notes}
                    datas={notesFilter}
                    handleAddNote={addNotes}
                    handleDeleteNote={deleteNotes}  
                    handleEditNote={editNotes} 
                />
            </div>
        </div>
    )
}
export default App;
