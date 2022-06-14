import style from './Heading.module.css'

function Heading(){

    return (
        <>
            <h1 className={style.headingTitle}>Tĩnh tâm là gì?</h1>
            <div className="d-flex">
                <div>Item 1</div>
                <div>Item 2</div>
            </div>
        </>

    )
}

export default Heading