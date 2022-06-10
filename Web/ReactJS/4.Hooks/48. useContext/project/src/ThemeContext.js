import {createContext} from 'react'
import { useState } from "react"



const ThemeContext = createContext()

function ThemeProvider({children}){

    const [theme, setTheme] = useState('dark')
    const handleOnclick = () => {
      setTheme(theme === 'dark' ? 'light' : 'dark')
    }

    return(
        <ThemeContext.Provider value={{theme, handleOnclick}}>
            {children}
        </ThemeContext.Provider>       
    )
}

export {ThemeProvider, ThemeContext}