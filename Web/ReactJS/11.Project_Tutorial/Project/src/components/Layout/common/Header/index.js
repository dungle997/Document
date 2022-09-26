import './Header.scss'
import {Button, Typography, Image} from 'antd'
function Header() {
    return (  
        <div className="header">
            <div className="header__inner">
           
                    <Button type="primary" style={{ background: "rgb(28, 28, 30)", border: "none", fontSize: "19px"}}>TV Show</Button>;
                    <Button type="primary" style={{ background: "rgb(28, 28, 30)", border: "none", fontSize: "19px"}}>Movie</Button>;
                    <Typography style={{color: "#fff",  fontSize: "19px"}}>Anonymous</Typography>
                    <Image
                        width={50}
                        src="https://moonlight-films.vercel.app/defaultAvatar.jpg"
                    />
                    <img style={{width: "50px"}} src="./src/assets/img/header/defaultAvatar.jpg"/>
            </div>
        </div>
    );
}

export default Header;