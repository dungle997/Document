import './App.css';
import Header from './components/Header/Header'
import Search from './components/Search/Search' 
import NoteList from './components/Note/NoteList' 
import {useState, useEffect} from 'react'
import {nanoid} from 'nanoid'
function App() {

  const [notes, setNotes] = useState([
    {
      id: nanoid(),
      text: 'this is my first note',
      date: 'today, 21/07/2022'
    },
    {
      id: nanoid(),
      text: 'this is my lucky note',
      date: 'today, 21/07/2022'
    },
    {
      id: nanoid(),
      text: 'this is my lucky note',
      date: 'today, 21/07/2022'
    }  
  ])
  const [search, setSearch] = useState('')
  const [darkMode, setDarkMode] = useState(false)
  // save data to local storage
  useEffect(() => {
    const data = (window.localStorage.getItem('data'))
    // console.log(data)
    if (data){
      setNotes(JSON.parse(data))
    }
  }, [])
  useEffect(() => {
    window.localStorage.setItem('data', JSON.stringify(notes))
    // console.log(notes)
  }, [notes])

  const addNote = (input) => {
      const date = new Date
      const newNote = {
        id: nanoid(),
        text: input,
        date: date.toLocaleDateString()
      }
      const newNotes = [...notes, newNote]
      setNotes(newNotes)
  } 

  const deleteNote = (id) => {
      const newNotes = notes.filter(note => {
        return note.id !== id
      })
      setNotes(newNotes)
  }

  const editNote = (id, text) => {
      const newNotes = notes.map(note => {
        if (note.id == id) {
          note.text = text 
        }  
        return note
      })
      setNotes(newNotes)
  }


  return (
    <div className= { `${darkMode && 'dark-mode'}`}>
      <div className="App">
        <Header setBackGround = {setDarkMode}/>
        <Search saveSearch = {setSearch}/>
        <NoteList datas={notes} 
                  handleAddNote= {addNote}
                  handleDeteleNote = {deleteNote}
                  handleEditNote = {editNote}
        />
      </div>  
    </div>
  );
}

export default App;
