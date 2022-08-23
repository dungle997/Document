import './App.css';
import Header from './components/Header/Header'
import NoteList from './components/Note/NoteList'
import Search from './components/Search/Search'
import {useState, useEffect} from 'react'
import {useDispatch, useSelector} from 'react-redux'
import noteListSlice, { loadDatas } from './components/Note/NoteListSlice'


function App() {
    const dispatch = useDispatch()
    useEffect(() => {
        const data = JSON.parse(localStorage.getItem('react-app-note-data'))
        if (!data){
            localStorage.setItem('react-app-note-data', JSON.stringify([]))
        }
    }, [])
    useEffect(() => {
        dispatch(loadDatas())
    }, [])
    const [darkMode, setDarkMode] = useState(false)
    return (
        <div className={`${darkMode && 'dark-mode'}`}>
            <div className='App'>
                <Header handleDarkMode={setDarkMode}/>
                <Search/>
                <NoteList />
            </div>
        </div>
    )
}
export default App;
