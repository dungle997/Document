import {BrowserRouter as Router, Routes, Route, Link} from 'react-router-dom'
import {publicRoutes} from './routes/index'
import DefaultLayout from './components/Layouts/DefaultLayout'
import {Fragment} from 'react'

function App() {
    return (
        <Router>
            <div className="App">
            <nav>
                <ul>
                    <li>
                        <Link to="/">Home</Link>
                    </li>

                    <li>
                        <Link to="/following">Following</Link>
                    </li>
    
                    <li>
                        <Link to="/contact">Contact</Link>
                    </li>
                    <li>
                        <Link to="/upload">Upload</Link>
                    </li>
                </ul>
            </nav>
                <Routes>
                    {publicRoutes.map((route, index) => {

                        let Layout = DefaultLayout
                        if (route.layout){
                            Layout = route.layout
                        } else if (route.layout === null){
                            Layout = Fragment
                        }
                        const Page = route.component
                        return (<Route 
                                key={index}
                                path={route.path}
                                element={
                                    <Layout>
                                        <Page />
                                    </Layout>
                                }    
                            />)
                        
                    })}   
                </Routes>
            </div>
        </Router>
        
    )
}
export default App;
