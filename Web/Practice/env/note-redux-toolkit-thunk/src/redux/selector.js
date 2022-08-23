import { createSelector } from "reselect"
export const noteList = state => state.noteList.notes
export const searchText = state => state.search.search

export const noteListRemaining = createSelector(noteList, searchText, (todos, search)=>{
    console.log('[todo]',todos)
    console.log('[search]',search)

    return todos.filter(todo => todo.text.includes(search))
})