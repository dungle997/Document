import './Header.css'

function Header() {
    return (
        <div className="header">
            <h1>
                <span className="title">React </span> 
                Notes
            </h1>
            <button style = {{fontSize: 15}} className="change-mode">Toggle Mode</button>
        </div>
    )
}

export default Header

