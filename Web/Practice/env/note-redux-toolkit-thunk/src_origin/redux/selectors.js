import {createSelector} from 'reselect'
export const todoListSelector = state => state.noteList
export const searchSelector = state => state.search.search

export const todosRemainingSelector = createSelector(todoListSelector, searchSelector, (todoLists, searchText) => {
   return todoLists.filter(todoList => {
        return (todoList.text.includes(searchText))
    })
}) 