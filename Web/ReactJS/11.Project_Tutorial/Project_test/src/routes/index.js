import HeaderOnly from "../components/Layouts/HeaderOnly"
import Contact from "../components/pages/Contact"
import Following from "../components/pages/Following"
import Home from "../components/pages/Home"
import Upload from "../components/pages/Upload"

const publicRoutes = [
    {path: "/", component: Home},
    {path: "/contact", component: Contact, layout: HeaderOnly},
    {path: "/following", component: Following},
    {path: "/upload", component: Upload, layout: null},
]

const privateRoutes = [

]

export {publicRoutes, privateRoutes} 

