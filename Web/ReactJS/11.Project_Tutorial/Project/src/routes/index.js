import Following from "../components/pages/Following"
import Home from "../components/pages/Home"
import Profile from "../components/pages/Profile"
import Upload from "../components/pages/Upload"
import HeaderOnly from "../components/Layout/HeaderOnly"
import Contact from "../components/pages/Contact"
const publicRoutes = [
    {path: '/', component: Home },
    {path: '/following', component: Following},
    {path: '/profile', component: Profile},
    {path: '/upload', component: Upload, layout: HeaderOnly},
    {path: '/contact', component: Contact, layout: null},


]

const privateRoutes = [

]

export {publicRoutes, privateRoutes}