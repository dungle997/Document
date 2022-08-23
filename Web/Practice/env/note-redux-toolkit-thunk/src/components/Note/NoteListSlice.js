import {nanoid} from 'nanoid'
import {createSlice, createAsyncThunk} from '@reduxjs/toolkit'
const date = new Date()


export default createSlice({
    name: 'noteList',
    initialState: {status: 'idle', notes: []},
    reducers: {
        addNote: (state, action) => {
            const newNote = {
                id: nanoid(),
                text: action.payload,
                date: date.toLocaleDateString()
            }
            state.push(newNote)
        },
        deleteNote: (state, action) => {
            state.forEach((todo, index) => {
                if (todo.id === action.payload) {
                    state.splice(index, 1)
                }
            })
        },
        editNote: (state, action) => {
            state = state.map(todo => {
                if (todo.id === action.payload.id){
                    return todo.text = action.payload.text
                }
                return todo
            })
        },
        reloadNote: (state, action) => {
            state = action.payload
        }
    },
    extraReducers: builder => {
        builder.addCase(loadDatas.pending, (state, action) => {
            state.status = 'loading'
        })
        .addCase(loadDatas.fulfilled, (state, action) => {
            state.status = 'idle'
            state.notes = action.payload
        })
        // .addCase(loadDatas.rejected, (state, action) => {
        //     state.status = 'idle'
        //     state.notes = []
        // })
        .addCase(addDatas.fulfilled, (state, action) => {
            state.notes.push(action.payload)
        })
        .addCase(editDatas.fulfilled, (state, action) => {
            state.notes.map(note => {
                if (action.payload.id === note.id){
                    note.text = action.payload.text
                    return note
                }
                return note
            })
        })
        .addCase(deleteDatas.fulfilled, (state, action) => {
            state.notes = state.notes.filter(note => note.id !== action.payload)
        })
    }
})

export const loadDatas = createAsyncThunk('notes/loadDatas', () => {
    const data = JSON.parse(localStorage.getItem('react-app-note-data'))
    return data
})

export const addDatas = createAsyncThunk('notes/addDatas', (text) => {
    const newNote = {
        id: nanoid(),
        text: text,
        date: date.toLocaleDateString()
    }
    // handle storage
    const oldDatas = JSON.parse(localStorage.getItem('react-app-note-data'))
    console.log('hello = ',oldDatas)
    oldDatas.push(newNote)
    localStorage.setItem('react-app-note-data', JSON.stringify(oldDatas))
    console.log(oldDatas)
    return newNote
})

export const editDatas = createAsyncThunk('notes/editDatas', (edit) =>{
    const datas = JSON.parse(localStorage.getItem('react-app-note-data'))
    datas.map(data => {
        // C1
        // if (data.id === edit.id) {
        //     data.text = edit.text
        //     return data
        // }
        // return data
        // C2
        const a = data.id === edit.id ? data.text = edit.text : data
        // console.log(a) 
        return a
    })
    // console.log(datas)
    localStorage.setItem('react-app-note-data', JSON.stringify(datas))
    
    return edit
})

export const deleteDatas = createAsyncThunk('notes/deleteDatas', (id) => {
    console.log('id',id)
    const datas = JSON.parse(localStorage.getItem('react-app-note-data'))
    console.log(datas)
    const deleteNote = datas.filter(data => data.id !== id)
    console.log(deleteNote)
    localStorage.setItem('react-app-note-data', JSON.stringify(deleteNote))
    return id
})


