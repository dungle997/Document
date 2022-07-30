const date = new Date()

export const addNote = (data) => {
    const newNote = {
        id: nanoid(),
        text: data,
        date: date.toLocaleDateString()
    }
    return {
        type: 'noteList/addNote',
        payload: newNote
    }
}

export const deleteNote = (id) => {
    return {
        type: 'noteList/deleteNote',
        payload: id
    }
}

export const editNote = (id, text) => {
    return {
        type: 'noteList/editNote',
        payload: {
            id,
            text
        }
    }
}