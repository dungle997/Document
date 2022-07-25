import './Header.css'

function Header({setBackGround}) {
    const handleOnclick = () => {
        setBackGround(prevState => !prevState)
    }
    return (
        <div className="header">
            <h1>
                <span className="title">React </span> 
                Notes
            </h1>
            <button 
                style = {{fontSize: 15}} 
                className="change-mode"
                onClick = {handleOnclick}
            >
                Toggle Mode
            </button>
        </div>
    )
}

export default Header

