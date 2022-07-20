import './App.css';
import Header from './components/Header/Header'
import Search from './components/Search/Search' 
import Note from './components/Note/Note' 
function App() {
  return (
    <div className="App">
        <Header/>
        <Search/>
        <Note/>
    </div>
  );
}

export default App;
