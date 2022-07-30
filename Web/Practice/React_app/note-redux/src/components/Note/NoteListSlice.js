import {nanoid} from 'nanoid'
const initState = [
    {
        id: nanoid(),
        text: 'This is the first note',
        date: '15/05/2055'
    },
    {
        id: nanoid(),
        text: 'This is the first note',
        date: '15/05/2055'
    },
    {
        id: nanoid(),
        text: 'This is the first note',
        date: '15/05/2055'
    },
]

const noteListReducer = (state = initState, action) => {
    switch(action.type){
        case 'noteList/addNote':
            return [...state, action.payload]
        case 'noteList/editNote':
            const newNotes = state.map(note => {
                // if (note.id === action.payload.id){
                //     note.text = action.payload.text
                // }
                // return note
                
            })
            return newNotes
        case'noteList/deleteNote':
            const newNotes = state.filter(note => note.id !== action.payload)
            return newNotes
        default: 
            return state

    }

}

export default noteListReducer