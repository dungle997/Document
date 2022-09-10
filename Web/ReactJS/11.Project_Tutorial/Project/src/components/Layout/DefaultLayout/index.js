import './DefaultLayout.scss'
import Header from '../common/Header'
import Sidebar from './SidebarLeft'
import SidebarRight from './SidebarRight';
import SidebarLeft from './SidebarLeft';

function DefaultLayout( {children} ) {
    return (  
        <div className="default">
            <SidebarLeft />
            <div className="container">
                <Header />
                <div className='content'>
                        {children}
                </div>
            </div>
            <SidebarRight />
                
        </div>
    );
}

export default DefaultLayout;