import {useState, createContext} from 'react'


const ThemeContext = createContext()

function ThemeProvider({children}){
    const [theme, setTheme] = useState('dark')

    const handleOnclick = () =>{
    setTheme(theme==='dark' ? 'light' : 'dark')
    }

  return (
    <ThemeContext.Provider 
        value={{
                theme,
                handleClick: handleOnclick
            }}
    >
        {children}
    </ThemeContext.Provider>
  )
}



export {ThemeContext, ThemeProvider}
