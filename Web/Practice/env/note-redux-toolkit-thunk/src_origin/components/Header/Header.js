import './Header.css'
function Header({handleDarkMode}){
    const handleOnClick = () => {
        handleDarkMode(prev => !prev)
    }
    return (
        <div className="header">
            <h1>
                <span className="title">React </span>
                Notes
            </h1>
            <button 
                className="background-btn"
                onClick={handleOnClick}
            >
                Toggle Mode
            </button>
        </div>
    )
}

export default Header