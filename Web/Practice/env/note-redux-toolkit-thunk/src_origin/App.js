import './App.css';
import Header from './components/Header/Header'
import NoteList from './components/Note/NoteList'
import Search from './components/Search/Search'
import {useState, useEffect} from 'react'
import {useDispatch, useSelector} from 'react-redux'
import {reloadNote} from './redux/actions'


function App() {
    const dispatch = useDispatch()
    useEffect(() => {
        const oldNotes = JSON.parse(localStorage.getItem('react-app-note-data'))
        if (oldNotes){
            dispatch(reloadNote(oldNotes))           
        }
    }, [])

    const todoLists = useSelector(state => state.noteList)
    useEffect(() => {
        console.log('voday')
        localStorage.setItem('react-app-note-data', JSON.stringify(todoLists))
        }, [todoLists])

    
    const [darkMode, setDarkMode] = useState(false)
    return (
        <div className={`${darkMode && 'dark-mode'}`}>
            <div className='App'>
                <Header handleDarkMode={setDarkMode}/>
                <Search/>
                <NoteList/>
            </div>
        </div>
    )
}
export default App;
